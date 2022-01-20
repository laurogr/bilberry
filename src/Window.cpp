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

/*
 * Helper function to move float points vec to int points vec.
 * This is step is mandatory for the cv::polylines
 * if it is not done, cv::polylines will have an assertation error
 * */
std::vector<cv::Point> Window::movePoint2fToPoint(
    std::vector<cv::Point2f>& vectorPoint2f) {
  std::vector<cv::Point> vectorPoint;
  vectorPoint.reserve(vectorPoint2f.size());
  for (auto& point : vectorPoint2f) {
    vectorPoint.push_back(std::move(point));
  }
  return vectorPoint;
}

/*
 * After the selection of points by the user, a polygon will be drawn.
 * To correctly draw the convex polygon (ignoring the order of the points)
 * cv::convexHull is called making sure cv::polylines performs as expected
 * */
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
