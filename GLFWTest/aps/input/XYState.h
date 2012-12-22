//
//  XYState.h
//  GLFWTest
//
//  Created by taskie on 2012/12/22.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#pragma once

namespace aps
{
	namespace input
	{
		class XYState
		{
		public:
			XYState();
			void setXY(double x, double y);
			double x() const;
			double y() const;
			double circledX() const;
			double circledY() const;
			
		private:
			double x_, y_;
			double abs_;
		};
	}
}
