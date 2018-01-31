/*
 * Thresholder.hpp
 *
 *  Created on: Jan 30, 2018
 *      Author: mamendez
 */

#ifndef DICE_HPP_
#define DICE_HPP_

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "highgui/highgui.hpp"
using namespace cv;
using namespace std;

class Dice{
public:
	static Mat calculateDice(const Mat& umbralized, const Mat& groundtruth);
};
#endif /* DICE_HPP_ */
