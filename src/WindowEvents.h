#pragma once

#include "Algorithms.h"
#include "Window.h"

namespace bilberry {

class WindowEvents {
 public:
  static void mouseCallBack(int event, int x, int y, int flags,
                            void* userdata) {
    if (event == cv::EVENT_LBUTTONDOWN) {
      auto window{static_cast<bilberry::Window*>(userdata)};
      window->savePointFromClick(x, y);
      window->printLastPoint();

      if (window->getSizeSelectedPoints() ==
          bilberry::constants::numberOfClicks) {
        window->drawLinesFromSelectedPoints();

        auto imagePointsSorted{window->getSelectedPoints()};
        std::sort(imagePointsSorted.begin(), imagePointsSorted.end(),
                  [](cv::Point2f a, cv::Point2f b) {
                    return ((a.x + a.y) < (b.x + b.y));
                  });

        Algorithms::findCameraPosition(
            bilberry::constants::objectPointSortedA4, imagePointsSorted,
            bilberry::constants::cameraMatrix,
            bilberry::constants::distortionCoef);
      }
    }
  }
};

}  // namespace bilberry