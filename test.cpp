#include "simd.h"
#include <iostream>

int main() {
	auto reg = SIMD<float, 8>::set(4.5f);
	reg = reg.floor();
	std::cout << std::is_pod<SIMD<float, 8>>::value << std::endl;
}
