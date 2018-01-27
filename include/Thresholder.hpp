/*
 * Thresholder.hpp
 *
 *  Created on: Jan 26, 2018
 *      Author: mamendez
 */

#ifndef THRESHOLDER_HPP_
#define THRESHOLDER_HPP_

using namespace cv;
using namespace std;

class Thresholder{
public:
	static Mat applyOtsu(const Mat& U);

};
#endif /* THRESHOLDER_HPP_ */
