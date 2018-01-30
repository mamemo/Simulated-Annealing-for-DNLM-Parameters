/*
 * Thresholder.cpp
 *
 *  Created on: Jan 30, 2018
 *      Authors: mamendez
 */
 #include "Thresholder.hpp"

 Mat Thresholder::applyOtsu(const Mat& U){
   Mat thresholded;
   U.convertTo(thresholded, CV_8UC1);
   threshold(thresholded, thresholded, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
   return thresholded;
 }
