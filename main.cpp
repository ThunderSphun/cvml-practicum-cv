#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

int main() {
	cv::namedWindow("base", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("resize", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("crop", cv::WINDOW_AUTOSIZE);

	cv::Mat base = cv::imread("Images/bert en ernie.jpg", cv::IMREAD_COLOR);
	cv::Mat resize = base.clone();
	cv::Mat crop = base.clone();

	resize.resize(200);

	imshow("base", base);
	imshow("resize", resize);
	imshow("crop", crop);

	cv::waitKey(0);
	return 0;
}