
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // Read the input grayscale image
    Mat image = imread("/home/sharmi/Downloads/Thresholding/images/gauss_real.jpg", IMREAD_GRAYSCALE);

    if (image.empty())
    {
        std::cerr << "Error: Could not read the image." << std::endl;
        return -1;
    }

    // Parameters for adaptive thresholding
    int blockSize = 15;  // Size of the local neighborhood
    double C = 5;        // Constant subtracted from the weighted mean

    // Apply adaptive thresholding with Gaussian window
    Mat binaryImage;
    adaptiveThreshold(image, binaryImage, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, blockSize, C);

    // Display the original and binary images
    imshow("Original Image", image);
    imshow("Adaptive gaussian Thresholding", binaryImage);

    waitKey(0);
    return 0;
}
