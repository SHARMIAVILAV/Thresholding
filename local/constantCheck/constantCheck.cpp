#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // Read the input image
    cv::Mat inputImage = imread("/home/sharmi/Desktop/C++_codes/flower.webp", cv::IMREAD_GRAYSCALE);

    if (inputImage.empty()) {
        cout << "Error: Could not open or find the image." << endl;
        return -1;
    }

    // Create a destination image for the thresholded result
    cv::Mat thresholded;

    // Perform adaptive mean thresholding with a block size of 11x11
    // The computed local threshold is the mean of the neighborhood minus a constant (C) value
    int blockSize = 11;
    int C = -5;// can change this value as 0,5 etc..
    adaptiveThreshold(inputImage, thresholded, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blockSize, C);

    // Display the original and thresholded images
    cv::imshow("Original Image", inputImage);
    cv::imshow("Mean Thresholded Image", thresholded);

    // Wait for a key press and then close the windows
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
