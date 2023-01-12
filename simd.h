#ifndef SIMD_H
#define SIMD_H

#include "simde/simde/x86/avx2.h"
#include <cfloat>
#include <iostream>

template<typename F, int N>
struct SIMD;

template<>
struct SIMD<float, 8> {
	//Type of a simd register
	using type = simde__m256;

	using self = SIMD<float, 8>;

	//The data of the register
	type data;
    
	//Number of floats in the float register
	static const unsigned int lanes = 8;

	//Initialization methods:

	static self set(float val) {
		return {simde_mm256_set1_ps(val)};
	}

	static self load(const float* ptr) {
		return {simde_mm256_load_ps(ptr)};
	}

	static self loadU(const float* ptr) {
		return {simde_mm256_loadu_ps(ptr)};
	}

	//Storing to memory:

	void store(float* ptr) {
		simde_mm256_store_ps(ptr, data);
	}

	void storeU(float* ptr) {
		simde_mm256_storeu_ps(ptr, data);
	}

	//Unary arithmetic:

	self floor() {
		return {simde_mm256_floor_ps(data)};
	}

	self ceil() {
		return {simde_mm256_ceil_ps(data)};
	}

	self rcp() {
		return {simde_mm256_rcp_ps(data)};
	}

	self sqrt() {
		return {simde_mm256_sqrt_ps(data)};
	}

	self rsqrt() {
		return {simde_mm256_rsqrt_ps(data)};
	}

	//Binary arithmetic:

	self operator+(self other) {
		return {simde_mm256_add_ps(data, other.data)};
	}

	self operator-(self other) {
		return {simde_mm256_sub_ps(data, other.data)};
	}

	self operator*(self other) {
		return {simde_mm256_mul_ps(data, other.data)};
	}

	self operator/(self other) {
		return {simde_mm256_div_ps(data, other.data)};
	}

	self max(self other) {
		return {simde_mm256_max_ps(data, other.data)};
	}

	self min(self other) {
		return {simde_mm256_min_ps(data, other.data)};
	}

	//Binary bit op

	self operator|(self other) {
		return {simde_mm256_or_ps(data, other.data)};
	}

	self operator&(self other) {
		return {simde_mm256_and_ps(data, other.data)};
	}

	self operator^(self other) {
		return {simde_mm256_xor_ps(data, other.data)};
	}

};
#endif