#pragma once

#include <array>

namespace aps
{
	namespace gl
	{
		class Color
		{
		public:
			Color();
			Color(double r, double g, double b, double a = 1);
			Color(const std::array<double, 4>& data);
			Color(const double data[4]);
			
			double r() const;
			double g() const;
			double b() const;
			double a() const;
			const double* data() const;
			
			void setR(double r);
			void setG(double g);
			void setB(double b);
			void setA(double a);
			
			double& operator[](int n);
			
		private:
			std::array<double, 4> data_;
		};
	}
}