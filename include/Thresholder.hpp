/*
 * Thresholder.hpp
 *
 *  Created on: Jan 26, 2018
 *      Author: mamendez
 */

#ifndef THRESHOLDER_HPP_
#define THRESHOLDER_HPP_

using namespace std;

class Thresholder{
public:
	static Mat applyOtsu(const Mat& U);

private:
	Mat thresholded;
};
#endif /* THRESHOLDER_HPP_ */
