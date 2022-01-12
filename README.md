
# Bilberry C++ Tech Challenge


Given the C++ Tech challenge, we have two main tasks:

- Draw highlighted lines (Given selected points by user’s click) 
- Find the position of the camera


### Draw highlighted lines

- OpenCV was used to display the image
- OpenCV callback functionality used for mouse events
- Left click will save a point on the screen
- When we reach four clicks, the lines will be drawn
- Challenge found for this step:
    -  If the clicks are in order, we are able to execute simply an openCV function to draw the lines
    - However, if the clicks are out of order, we won't have necessarily a convex polygon drawn
    - Solution : before running the draw function, execute cv::convexHull so no matter the order, we will be able to draw the polygon



### Find the position of the camera
- For this task, I read/studied some references specially on pinhole camera model, camera calibration, opencv and algebra
- The main idea is that with the data below, we are able to calculate the extrinsics values:
    - given intrinsic values of the camera
    - getting image points (2d) from user’s click
    - using real world coordinate 3d points (A4 sheet size as reference, with Z=0) equivalent to the 2d points

- I used the algorithm that solves the Pose Estimation (cv::SolvePnp)
    - Important : to be able to calculate the pose, the 2d and 3d points should be correctly mapped one another, so the 3d points vector (A4 sheet size) was defined as a sorted constant and I sorted the 2d input points to match them correctly;
    - After that, I used some matrix manipulation to find the camera position in the world coordinate system;



### Tech Stack
- c++ version : c++17
- build system : cmake
- os : unix (macos, portable to linux)
- libs : opencv 4.5
- code formatter : clangformat
- linter : clangtidy
- IDE : clion/vs code


### TODO
- add unit test (google test)
- add references 
- add detailed documentation

