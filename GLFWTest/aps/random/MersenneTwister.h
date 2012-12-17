//
//  MersenneTwister.h
//  GLFWTest
//
//  Created by taskie on 2012/12/07.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#ifndef __GLFWTest__MersenneTwister__
#define __GLFWTest__MersenneTwister__

#include <memory>

namespace aps
{
	namespace random
	{
		class MersenneTwister
		{
		public:
			MersenneTwister();
			MersenneTwister(unsigned int seed);
			unsigned int seed() const;
			double next();
			double next(double a, double b);
			int nextInt();
			int nextInt(double a, double b);
			
		private:
			class Impl;
			std::shared_ptr<Impl> pImpl_;
		};
	}
}

#endif /* defined(__GLFWTest__MersenneTwister__) */
