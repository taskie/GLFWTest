//
//  MersenneTwister.cpp
//  GLFWTest
//
//  Created by taskie on 2012/12/07.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#include "MersenneTwister.h"

#include <ctime>
#include <random>

using namespace aps::random;

class MersenneTwister::Impl
{
public:
	Impl() : Impl(static_cast<unsigned int>(std::clock())) { }
	
	Impl(unsigned int seed) : seed_(seed), MersenneTwister_(seed_) { }
	
	unsigned int seed() const { return seed_; }
	
	double next()
	{
		return next(0, 1);
	}
	
	double next(double a, double b)
	{
		std::uniform_real_distribution<double> dist(a, b);
		return dist(MersenneTwister_);
	}
	
	int nextInt()
	{
		std::uniform_int_distribution<int> dist;
		return dist(MersenneTwister_);
	}
	
	int nextInt(double a, double b)
	{
		std::uniform_int_distribution<int> dist(a, b);
		return dist(MersenneTwister_);
	}
	
private:
	unsigned int seed_;
	std::mt19937 MersenneTwister_;
};

// class MersenneTwister

MersenneTwister::MersenneTwister() : pImpl_(new Impl()) {}
MersenneTwister::MersenneTwister(unsigned int seed) : pImpl_(new Impl(seed)) {}
unsigned int MersenneTwister::seed() const { return pImpl_->seed(); }
double MersenneTwister::next() { return pImpl_->next(); }
double MersenneTwister::next(double a, double b) { return pImpl_->next(a, b); }
int MersenneTwister::nextInt() { return pImpl_->nextInt(); }
int MersenneTwister::nextInt(double a, double b) { return pImpl_->nextInt(a, b); }
