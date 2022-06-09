#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char**) {
    // read webcam from opencv
    //cv::VideoCapture cap(0);
    // cv::VideoCapture cap("gst-launch-1.0 v4l2src device=/dev/video0 ! mppvideodec ! rgaconvert output-io-mode=dmabuf-import capture-io-mode=dmabuf ! video/x-raw,format=BGR,width=1280,height=720,framerate=30/1 ! appsink", cv::CAP_GSTREAMER);
    cv::VideoCapture cap("v4l2src device=/dev/video0 ! image/jpeg, width=1280, height=720, framerate=30/1, format=MJPG ! nvv4l2decoder mjpeg=1 ! nvvidconv ! videoconvert ! video/x-raw, format=BGR ! appsink", cv::CAP_GSTREAMER);
    if (!cap.isOpened()) 
    {
        std::cout << "Cannot open camera" << std::endl;
        return -1;
    }


    cv::namedWindow("img", cv::WINDOW_NORMAL);
    while (true) 
    {
        cv::Mat frame;
        cap >> frame;
        cv::imshow("img", frame);
        if (cv::waitKey(1) == 27) {
            break;
        }
    }

    cv::destroyAllWindows();
    return 0;
}
