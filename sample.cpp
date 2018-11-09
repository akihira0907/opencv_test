#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main() {
	cv::VideoCapture cap(0);
	if (!cap.isOpened()) {
		std::cout << "failed to open" << std::endl;
		return 1;
	}
	while (true) {
		cv::Mat img;
		cap >> img;
		if (img.empty()) continue;
		cv::imshow("img", img);
		cv::waitKey(1);
	}
	return 0;
}
