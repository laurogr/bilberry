#pragma once

#include "constants.h"

namespace bilberry {

/*
 * Class controlling the view for the user, mainly used for window updates
 * */
class Window {
  cv::Mat image;
  std::vector<cv::Point2f> imageSelectedPoints;
  std::string name;

  static std::vector<cv::Point> movePoint2fToPoint(
      std::vector<cv::Point2f>& vectorPoint2Float);

 public:
  Window(cv::Mat& img, std::string name);
  void printPoint(const cv::Point& point);
  void printLastPoint();
  void savePointFromClick(int x, int y);
  void drawLinesFromSelectedPoints();
  std::vector<cv::Point2f> getSelectedPoints() const;
  std::string getName() const;
  int getSizeSelectedPoints() const;
};

}  // namespace bilberry
