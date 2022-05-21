#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

int main() {
	cv::namedWindow("base", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("resize", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("crop", cv::WINDOW_AUTOSIZE);

	cv::Mat resize;
	
	cv::Mat base = cv::imread("Images/bert en ernie.jpg", cv::IMREAD_COLOR);
	cv::Mat crop= base(cv::Rect(25, 25, 200, base.rows - 50));
	cv::resize(base, resize, cv::Size(400, 100));

	imshow("base", base);
	imshow("resize", resize);
	imshow("crop", crop);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}