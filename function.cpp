//
// Created by abdullah on 23.10.23.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include "function.h"
bool isTreeInFieldOfView(const std::tuple<double, double,double>& person, const std::tuple<double, double>& tree, double orientation, double halfAlpha) {
    double angleToTree = atan2(std::get<1>(tree) - std::get<1>(person), std::get<0>(tree) - std::get<0>(person)) * 180.0 / M_PI;
    double angleDifference = fabs(orientation - angleToTree);
   // std::cout<<"angle diff"<<angleDifference<<std::endl;
    return angleDifference <= halfAlpha;
}