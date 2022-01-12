#include <iostream>

#include "Window.h"
#include "WindowEvents.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "[ERROR] One parameter : image path \n";
    return -1;
  }

  auto img{cv::imread(argv[1])};
  if (img.empty()) {
    std::cout << "[ERROR] Invalid image \n";
    return -1;
  }

  bilberry::Window windowView{img, "Bilberry Demo"};

  cv::setMouseCallback(windowView.getName(),
                       bilberry::WindowEvents::mouseCallBack,
                       static_cast<void*>(&windowView));

  cv::waitKey(0);

  cv::destroyAllWindows();

  return 0;
}
