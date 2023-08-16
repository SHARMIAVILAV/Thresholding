#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // Path to input image is specified and image is loaded with imread command
    Mat image = imread("/home/sharmi/Downloads/Thresholding/images/globalTypes.png");

    // cvtColor is applied over the image input with applied parameters to convert the image to grayscale
    Mat img;
    cvtColor(image, img, COLOR_BGR2GRAY);

    // Applying different thresholding techniques on the input image
    // All pixel values above 120 will be set to 255
    Mat thresh1, thresh2, thresh3, thresh4, thresh5;
    threshold(img, thresh1, 120, 255, THRESH_BINARY);
    threshold(img, thresh2, 120, 255, THRESH_BINARY_INV);
    threshold(img, thresh3, 120, 255, THRESH_TRUNC);
    threshold(img, thresh4, 120, 255, THRESH_TOZERO);
    threshold(img, thresh5, 120, 255, THRESH_TOZERO_INV);

    // The window showing output images with the corresponding thresholding
    // techniques applied to the input images
    imshow("Binary Threshold", thresh1);
    imshow("Binary Threshold Inverted", thresh2);
    imshow("Truncated Threshold", thresh3);
    imshow("Set to 0", thresh4);
    imshow("Set to 0 Inverted", thresh5);

    // Wait for a key press and then close the windows
    if (waitKey(0) & 0xff == 27)
        destroyAllWindows();

    return 0;
}