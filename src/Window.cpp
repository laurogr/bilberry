#include "Window.h"

namespace bilberry {

Window::Window(cv::Mat& img, std::string windowName)
    : image{img}, name{std::move(windowName)} {
  cv::namedWindow(this->name, cv::WINDOW_AUTOSIZE);
  cv::imshow(this->name, this->image);
}

void Window::printPoint(const cv::Point& point) {
  auto textCoordinates{std::to_string(point.x) + "," + std::to_string(point.y)};

  cv::putText(this->image, textCoordinates, point, cv::FONT_HERSHEY_SIMPLEX, 1,
              constants::green, constants::thickness::med);
  cv::imshow(this->name, this->image);
}

void Window::printLastPoint() {
  this->printPoint(this->imageSelectedPoints.back());
}

void Window::savePointFromClick(int x, int y) {
  this->imageSelectedPoints.emplace_back(cv::Point(x, y));
}

std::vector<cv::Point> Window::movePoint2fToPoint(
    std::vector<cv::Point2f>& vectorPoint2f) {
  std::vector<cv::Point> vectorPoint;
  vectorPoint.reserve(vectorPoint2f.size());
  for (auto& point : vectorPoint2f) {
    vectorPoint.push_back(std::move(point));
  }
  return vectorPoint;
}

void Window::drawLinesFromSelectedPoints() {
  std::vector<cv::Point2f> outHull;
  cv::convexHull(this->imageSelectedPoints, outHull, true);
  cv::polylines(this->image, this->movePoint2fToPoint(outHull), true,
                constants::red, constants::thickness::thick);
  cv::imshow(this->name, this->image);
}

std::string Window::getName() const { return this->name; }

std::vector<cv::Point2f> Window::getSelectedPoints() const {
  return this->imageSelectedPoints;
}

int Window::getSizeSelectedPoints() const {
  return this->imageSelectedPoints.size();
}

}  // namespace bilberry
