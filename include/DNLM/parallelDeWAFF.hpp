/*
 * ParallelDeWAFF.hpp
 *
 *  Created on: Nov 5, 2015
 *      Author: davidp
 */

#ifndef PARALLELDEWAFF_HPP_
#define PARALLELDEWAFF_HPP_

#include <string>
#include "nlmfilterDeceived.hpp"
#include "noAdaptiveLaplacian.hpp"
using namespace std;

class ParallelDeWAFF{
public:
	Mat filter(const Mat& U, int wSize, int sigma_r, int lambda);
	NoAdaptiveLaplacian* getNAL();

private:
	NoAdaptiveLaplacian nal;
	NLMFilterDeceived nlmfd;
	Mat filterDeceivedNLM(const Mat& U, int wSize, int wSize_n, double sigma_s, int sigma_r, int lambda);
};
#endif /* PARALLELDEWAFF_HPP_ */
