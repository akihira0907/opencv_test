#include "opencv2/opencv.hpp"

int main(int argh, char* argv[]) {
  cv::VideoCapture cap(0); // open device

  if (!cap.isOpened()) 
  {  
       return -1; // error
  }

  while (1) 
  {
    cv::Mat frame;
    cap >> frame; //get a new frame from camera

    cv::imshow("window", frame); //display image

    int key = cv::waitKey(1);
    if (key == 113) //push q key
    {
      break;
    }
    else if (key == 115) // push s key
    {
      cv::imwrite("img.png", frame);
    }
  }

  cv::destroyAllWindows();
  return 0;
}
