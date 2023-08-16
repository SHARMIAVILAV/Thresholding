#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // Read the input image in grayscale
    cv::Mat inputImage = imread("/home/sharmi/Downloads/Thresholding/images/finger.png", cv::IMREAD_GRAYSCALE);

    if (inputImage.empty()) {
        cout << "Error: Could not open or find the image." << endl;
        return -1;
    }

    // Apply Otsu's thresholding
    double maxVal = 255.0;
    double thresholdVal = cv::threshold(inputImage, inputImage, 0, maxVal, THRESH_BINARY | THRESH_OTSU);

    cout << "Otsu's Threshold Value: " << thresholdVal << endl;

    // Display the original and thresholded images
    cv::imshow("Original Image", inputImage);
    cv::imshow("Otsu's Thresholded Image", inputImage);

    // Wait for a key press and then close the windows
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

