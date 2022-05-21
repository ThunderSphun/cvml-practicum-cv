#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main() {
	namedWindow("original", WINDOW_AUTOSIZE);
	namedWindow("output", WINDOW_AUTOSIZE);

	Mat output;

	Mat tony = imread("Images/tony's.jpeg");
	resize(tony, tony, Size(tony.cols / 5, tony.rows / 5));

	auto w = (float) tony.cols;
	auto h = (float) tony.rows;

	Point2f src[4] = {{70, 43},{48, 158},{366, 140},{325, 36}};
	Point2f dst[4] = {{0, 0}, {0, h}, {w, h}, {w, 0}};

	Mat transform = getPerspectiveTransform(src, dst);
	warpPerspective(tony, output, transform, Point((int) w, (int) h));

	for (auto &s : src) {
		circle(tony, s, 10, Scalar(0, 0, 255), FILLED);
	}

///		Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
///		Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

///		matrix = getPerspectiveTransform(src, dst);
///		warpPerspective(img, imgWarp, matrix, Point(w, h));

	imshow("original", tony);
	imshow("output", output);

	waitKey(0);
	destroyAllWindows();
	return 0;
}