/*
 * main.cpp
 *
 *  Modified on: JAN 26, 2018
 *      Authors: mamendez
 */
#include "Thresholder.hpp"

Mat Thresholder::applyOtsu(const Mat& U){
  Mat thresholded;
  U.convertTo(thresholded, CV_8UC1);
  cv::threshold(thresholded, thresholded, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
  return thresholded;
}
