/*
 * Main.cpp
 *
 *  Modified on: Nov 07, 2016
 *      Authors: mamendez
 */
#include "parallelDeWAFF.hpp"
//#include "Thresholder.hpp"
#include <ctime>

int main(int argc, char* argv[]){
    ParallelDeWAFF dnlm;

    //Check input arguments
    if (argc != 2){
        cout << "ERROR: Not enough parameters" << endl;
        cout
            << "------------------------------------------------------------------------------" << endl
            << "Usage:"                                                                         << endl
            << "./ParallelDeNLM inputImageName"                                                << endl
            << "------------------------------------------------------------------------------" << endl
            << endl;
        return -1;
    }else{

    //Open input video file
    const string inputFile = argv[1];
    // Find extension point
    string::size_type pAt = inputFile.find_last_of('.');

    // Form the new name with container
    const string outputFile = inputFile.substr(0, pAt) + "_OTSU.png";

    Mat U;
    U = imread(inputFile, CV_LOAD_IMAGE_GRAYSCALE);
    //Read one frame from input video
    if(!U.data){
      cout << "Could not read image from file." << endl;
      return -1;
    }

    int wRSize = 4;//21;
    int sigma_r = 310;//3; //13
    int lambda = 3;//1.7;

    //time start
    clock_t begin = clock();
    Mat newImage = dnlm.filter(U, wRSize, sigma_r, lambda);
    //Mat newImage = Thresholder::applyOtsu(U);
    clock_t end = clock();
    //time end

    //Write image to output file.
    imwrite(outputFile, newImage);
    double elapsed_secs =  ((double) (end - begin)) / CLOCKS_PER_SEC;
    cout << "Time to process an image: "  << elapsed_secs << endl;
    return 0;
    }
}
