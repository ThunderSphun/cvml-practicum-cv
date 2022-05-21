#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main() {
	namedWindow("output", WINDOW_AUTOSIZE);

	Mat output = Mat::zeros(Size(250, 150), CV_8UC3);

	putText(output,"Lorem Ipsem",Point(30,50),
			FONT_HERSHEY_SCRIPT_COMPLEX,1,Scalar(0,255,255));
	circle(output, Point(100, 75), 50, Scalar(0, 0, 128), 2);
	rectangle(output, Rect(100, 75, 100, 50), Scalar(0, 0, 255), 2);
	line(output, Point(0, 75), Point(250, 150), Scalar(50, 50, 255), 3);

	imshow("output", output);

	waitKey(0);
	destroyAllWindows();
	return 0;
}