/*
 * Thresholder.hpp
 *
 *  Created on: Jan 30, 2018
 *      Author: mamendez
 */

#ifndef THRESHOLDER_HPP_
#define THRESHOLDER_HPP_

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "highgui/highgui.hpp"
using namespace cv;
using namespace std;

class Thresholder{
public:
	Mat applyOtsu(const Mat& U);
  Mat applyThreshold(const Mat& U, int t);
  Mat applyInverseThreshold(const Mat& U, int t);
};
#endif /* THRESHOLDER_HPP_ */
