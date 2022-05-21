#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main() {
	namedWindow("ball with stripes", WINDOW_AUTOSIZE);
	namedWindow("ball without stripes", WINDOW_AUTOSIZE);

	Mat stripes = imread("Images/ballstripes.bmp");
	Mat stripeless;

	dilate(stripes, stripeless, getStructuringElement(MORPH_RECT, Size(5, 5)));
	erode(stripeless, stripeless, getStructuringElement(MORPH_RECT, Size(5, 5)));

	imshow("ball with stripes", stripes);
	imshow("ball without stripes", stripeless);

	waitKey(0);
	destroyAllWindows();
	return 0;
}