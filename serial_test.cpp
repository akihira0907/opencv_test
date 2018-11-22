#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

int main(int argh, char* argv[]) {
  cv::VideoCapture cap(0); // open device

  if (!cap.isOpened()) 
  {  
       return -1; // error
  }

  for (int i=0; true; i++) 
  {
    cv::Mat frame;
    cap >> frame; //get a new frame from camera

    cv::imshow("window", frame); //display image

    int key = cv::waitKey(1);
    if (key == 113) //push q key
    {
      break;
    }
    else if (i % 10 == 0) // take pictures 
    {
      std::string num = std::to_string(i/10);
      cv::imwrite("images/img" + num + ".png", frame);
    }
  }

  cv::destroyAllWindows();
  return 0;
}

