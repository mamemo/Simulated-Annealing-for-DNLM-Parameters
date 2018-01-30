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

};
#endif /* THRESHOLDER_HPP_ */
