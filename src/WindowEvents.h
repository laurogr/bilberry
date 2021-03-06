#pragma once

#include "Algorithms.h"
#include "Window.h"

namespace bilberry {

/*
 * Class controlling the events from user input, in this case with a callback
 * function for the mouse.
 * */
class WindowEvents {
 public:
  static void mouseCallBack(int event, int x, int y, int flags,
                            void* userdata) {
    if (event == cv::EVENT_LBUTTONDOWN) {
      auto window{static_cast<bilberry::Window*>(userdata)};
      window->savePointFromClick(x, y);
      window->printLastPoint();

      // Drawing the polygon and calculating position when the clicks are
      // reached
      if (window->getSizeSelectedPoints() ==
          bilberry::constants::numberOfClicks) {
        window->drawLinesFromSelectedPoints();

        // Sorting the imagePoints to match the objectPoints already sorted
        auto imagePointsSorted{window->getSelectedPoints()};
        std::sort(imagePointsSorted.begin(), imagePointsSorted.end(),
                  [](cv::Point2f a, cv::Point2f b) {
                    return ((a.x + a.y) < (b.x + b.y));
                  });

        Algorithms::findCameraPosition(
            constants::objectPointSortedA4, imagePointsSorted,
            constants::cameraMatrix, constants::distortionCoef);
      }
    }
  }
};

}  // namespace bilberry