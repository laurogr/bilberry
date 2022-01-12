#pragma once

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

namespace bilberry::constants {

inline constexpr auto numberOfClicks = 4;

// color
const cv::Scalar green{0, 255, 0};
const cv::Scalar red{0, 0, 255};
const cv::Scalar blue{255, 0, 0};

// thickness used for draw/writing
enum thickness { soft = 2, med = 4, thick = 8 };

// Intrinsic parameters definition
inline constexpr auto fx{3751.937744f};
inline constexpr auto fy{3821.977539f};
inline constexpr auto cx{1280.0f};
inline constexpr auto cy{960.0f};

// Distortion coefficients definition
inline constexpr auto k1{-1.20933f};
inline constexpr auto k2{-1.041786f};
inline constexpr auto k3{64.013991f};
inline constexpr auto k4{-0.556802f};
inline constexpr auto k5{-3.66386f};
inline constexpr auto k6{-78.030670f};
inline constexpr auto p1{-0.004819f};
inline constexpr auto p2{-0.002720f};

/*
Camera matrix 3x3 :
                (fx, 0.0, cx,
                0.0, fy, cy,
                0.0, 0.0, 1.0);
*/
const cv::Mat cameraMatrix =
    (cv::Mat_<float>(3, 3) << fx, 0.0, cx, 0.0, fy, cy, 0.0, 0.0, 1.0);

/*
Distortion coefficient vector 1x8 :
    (k1, k2, p1, p2, k3, k4, k5, k6)
*/
const cv::Mat distortionCoef =
    (cv::Mat_<float>(1, 8) << k1, k2, p1, p2, k3, k4, k5, k6);

/*
ObjectPoints (real coordinates) of the A4 sheet:
- in milimeters
- sorted by value (x+y)
- main use : solvePNP as first input parameters
*/
const std::vector<cv::Point3f> objectPointSortedA4{
    cv::Point3f(0.0f, 0.0f, 0.0f), cv::Point3f(0.0f, 210.0f, 0.0f),
    cv::Point3f(297.0f, 0.0f, 0.0f), cv::Point3f(297.0f, 210.0f, 0.0f)};


}  // namespace bilberry
