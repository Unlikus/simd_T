#include "simd.h"
#include <iostream>

using f8 = SIMD<float, 8>;

int main() {
	auto a = f8::set(4.5f);
	auto b = f8::set(5.0f);
	
	
	auto c = a.blend<15>(b);
	c.print();
}
