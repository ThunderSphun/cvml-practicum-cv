#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main() {
	Mat img = imread("Images/heinz.jpg");
	Mat gray;
	Mat canny;

	cvtColor(img, gray, COLOR_BGR2GRAY);

	int minThreshold = 0;
	int maxThreshold = 255;

	namedWindow("Trackbars", WINDOW_AUTOSIZE);
	namedWindow("original", WINDOW_AUTOSIZE);
	namedWindow("gray", WINDOW_AUTOSIZE);
	namedWindow("with canny", WINDOW_AUTOSIZE);

	createTrackbar("minimum threshold", "Trackbars", &minThreshold, 512);
	createTrackbar("maximum threshold", "Trackbars", &maxThreshold, 512);

	while (true) {
		Canny(gray, canny, minThreshold, maxThreshold);

		imshow("original", img);
		imshow("gray", gray);
		imshow("with canny", canny);

		if (waitKey(1) == 27) {
			destroyAllWindows();
			return 0;
		}
	}
}