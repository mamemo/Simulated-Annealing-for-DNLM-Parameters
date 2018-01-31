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

 Mat Thresholder::applyThreshold(const Mat& U, int t){
   Mat thresholded;
   U.convertTo(thresholded, CV_8UC1);
   threshold(thresholded, thresholded, t, 255, CV_THRESH_BINARY);
   return thresholded;
 }

 Mat Thresholder::applyInverseThreshold(const Mat& U, int t){
   Mat thresholded;
   U.convertTo(thresholded, CV_8UC1);
   threshold(thresholded, thresholded, t, 255, CV_THRESH_BINARY_INV);
   return thresholded;
 }
