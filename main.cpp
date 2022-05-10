#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char**) {
    // read webcam from opencv
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) 
    {
        std::cout << "Cannot open camera" << std::endl;
        return -1;
    }
    while (true) 
    {
        cv::Mat frame;
        cap >> frame;
        cv::imshow("frame", frame);
        if (cv::waitKey(1) == 27) {
            break;
        }
    }
    return 0;
}
