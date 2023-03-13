#include<iostream>
#include <random>

#include "simd.h"

const int TEST_SIZE = 10000;

int main() {
	double *a = new double[4 * TEST_SIZE];
	std::uniform_real_distribution<double> unif(-1e10,1e10);
	std::default_random_engine re;
	for(unsigned int i = 0; i < TEST_SIZE * 4; i++) {
		a[i] = unif(re);
	}
	
	for(unsigned int i = 0; i < TEST_SIZE; i++) {
		auto v = SIMD<double>::loadU(a + 4 * i);
		double sum_avx = SIMD<double>::hsum(v);
		double sum_2 = SIMD<double>::partial_hsum_like_hsum(v);
		if(std::abs(sum_avx - sum_2) / std::abs(sum_2) > 1e-18) {
			std::cout << "Problem" << std::endl;
			std::cout << sum_avx << " " << sum_2 << std::endl;
		}
	}
	
	delete[] a;
}
