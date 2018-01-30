/*
 * main.cpp
 *
 *  Modified on: Nov 07, 2016
 *      Authors: manzumbado, davidp
 */
#include "parallelDeWAFF.hpp"
#include <ctime>
using namespace std;


Mat ParallelDeWAFF::filter(const Mat& U, int wRSize, int sigma_r, int lambda){
    //Create the Laplacian of Gaussian mask once
    NoAdaptiveLaplacian* nAL = getNAL();
    Mat h =  Tools::fspecialLoG(17, 0.005);
    nAL->setMask(-h);

    //Set parameters for processing
    int wSize_n=4;//1;
    double sigma_s = wRSize/1.5;

    Mat fDeceivedNLM = filterDeceivedNLM(U, wRSize, wSize_n, sigma_s, sigma_r, lambda);

    return fDeceivedNLM;
}

NoAdaptiveLaplacian* ParallelDeWAFF::getNAL(){
    return &(this->nal);
}

//Input image must be from 0 to 255
Mat ParallelDeWAFF::filterDeceivedNLM(const Mat& U, int wSize, int wSize_n, double sigma_s, int sigma_r, int lambda){
    Mat Unorm;
    //The image has to have values from 0 to 1
    U.convertTo(Unorm,CV_32FC3,1.0/255.0);
    //[L, alfaMat, Vnorm] = adaptiveLaplacian(Unorm, amps, trap1, trap2);

    Mat L = this->nal.noAdaptiveLaplacian(Unorm, lambda);
    Mat F = this->nlmfd.nlmfilterDeceived(Unorm, L, wSize, wSize_n, sigma_s, sigma_r);

    //putting back everything
    F.convertTo(F,CV_8UC1,255);
    return F;
}
