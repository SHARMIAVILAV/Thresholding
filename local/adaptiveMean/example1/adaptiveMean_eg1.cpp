#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat dst;

    // Create an image with a larger size (e.g., 300x300)
    cv::Mat image(cv::Size(3, 3), CV_8UC1);

    // Set the pixel values (You can use loop for larger images)
    image.at<uchar>(0, 0) = 122;
    image.at<uchar>(0, 1) = 80;
    image.at<uchar>(0, 2) = 30;
    image.at<uchar>(1, 0) = 216;
    image.at<uchar>(1, 1) = 12;
    image.at<uchar>(1, 2) = 88;
    image.at<uchar>(2, 0) = 100;
    image.at<uchar>(2, 1) = 198;
    image.at<uchar>(2, 2) = 200;
    int blockSize = 3; // Increase the block size for better results

    adaptiveThreshold(image, dst, 111, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blockSize, 0);

    // Save the output image instead of displaying it
    imwrite("output.png", image);
    system("eog output.png");
    imshow("image",image);
    return 0;
}
