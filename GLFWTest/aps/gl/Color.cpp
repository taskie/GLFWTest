//
//  Color.cpp
//  GLFWTest
//
//  Created by taskie on 2012/12/05.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#include "Color.h"

#include <algorithm>

using namespace aps::gl;

Color::Color() : data_{{0, 0, 0, 0}} {}
Color::Color(double r, double g, double b, double a) : Color(std::array<double, 4>{{r, g, b, a}}) {}
Color::Color(const std::array<double, 4>& data) : data_(data) {}
Color::Color(const double data[4]) { std::copy(data, data + 4, data_.begin()); }

double Color::r() const { return data_[0]; }
double Color::g() const { return data_[1]; }
double Color::b() const { return data_[2]; }
double Color::a() const { return data_[3]; }
const double* Color::data() const { return &data_[0]; }

void Color::setR(double r) { data_[0] = r; }
void Color::setG(double g) { data_[1] = g; }
void Color::setB(double b) { data_[2] = b; }
void Color::setA(double a) { data_[3] = a; }

double& Color::operator[](int n) { return data_.at(n); }
