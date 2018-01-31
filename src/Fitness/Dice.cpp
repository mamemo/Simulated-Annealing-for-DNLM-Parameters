/*
 * Thresholder.cpp
 *
 *  Created on: Jan 30, 2018
 *      Authors: mamendez
 */
 #include "Dice.hpp"

 double Dice::calculateDice(const Mat& umbralized, const Mat& groundtruth){
   float intersection = 0.0;
   int cardinalityU = umbralized.rows * umbralized.cols;
   int cardinalityG = groundtruth.rows * groundtruth.cols;

   Size sizeGroundTruth = groundtruth.size();
   int sizeX = (int) sizeGroundTruth.width;
   int sizeY = (int) sizeGroundTruth.height;

   for (int x =0; x < sizeX; x++){
     for (int y = 0; y < sizeY; y++) {
       if (umbralized.at<double>(y, x) == groundtruth.at<double>(y, x)){
         intersection++;
       }
     }
   }

   return (2.0 * intersection) / ((double) cardinalityU + (double) cardinalityG);
 }
