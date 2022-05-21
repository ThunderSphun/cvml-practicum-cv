#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main() {
	namedWindow("base", WINDOW_AUTOSIZE);
	namedWindow("resize", WINDOW_AUTOSIZE);
	namedWindow("crop", WINDOW_AUTOSIZE);

	Mat resize;
	
	Mat base = imread("Images/bert en ernie.jpg", IMREAD_COLOR);
	Mat crop= base(Rect(25, 25, 200, base.rows - 50));
	cv::resize(base, resize, Size(400, 100));

	imshow("base", base);
	imshow("resize", resize);
	imshow("crop", crop);

	waitKey(0);

	destroyAllWindows();

	return 0;
}