#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main() {
	namedWindow("template", WINDOW_AUTOSIZE);

	waitKey(0);
	destroyAllWindows();
	return 0;
}