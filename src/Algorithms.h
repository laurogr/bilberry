#pragma once

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

namespace bilberry {

class Algorithms {
 public:
  /*
   * findCameraPosition uses the same input of cv::solvePnP, but returns
   * the camera position in world coordinates in mm.
   * Steps :
   * - SolvePnP : find the extrinsics (rvec and tvec)
   * - Rodrigues : find the Rotation matrix from the rotation vector (rvec)
   * - Use the following formula to find the result
   *        C = -(transpose(rotMat) * tvec)
   * */
  static cv::Point3f findCameraPosition(
      const std::vector<cv::Point3f> objectPoints,
      const std::vector<cv::Point2f> imagePoints, const cv::Mat cameraMatrix,
      const cv::Mat distCoeffs) {
    cv::Mat rvec, tvec;
    cv::Mat rotMtxT;
    cv::Mat rotMtx;

    cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec,
                 tvec);
    cv::Rodrigues(rvec, rotMtxT);
    cv::transpose(rotMtxT, rotMtx);
    cv::Mat cameraPosition = -(rotMtx * tvec);

    std::cout << "[INFO] Camera Position = \n"
              << cameraPosition << "milimeters \n";

    return {cameraPosition.at<float>(0), cameraPosition.at<float>(1),
            cameraPosition.at<float>(2)};
  }
};

}  // namespace bilberry
