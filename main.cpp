#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main() {
	CascadeClassifier plateCascade("haarcascade_russian_plate_number.xml");

	if (plateCascade.empty()) {
		cout << "XML file not loaded" << endl;
		return -1;
	}

	Mat glyph;
	double area;
	Mat img;
	vector<Rect> plates;
	vector<Rect> pTest;
	Mat licencePlate;
	Mat thresholdPlate;
	vector<vector<Point>> contours;
	char filePath[30];

	VideoCapture cap(2, CAP_DSHOW);

	namedWindow("capture", WINDOW_FREERATIO);

	while (waitKey(1) != 27) {
		cap.read(img);

		plateCascade.detectMultiScale(img, plates, 1.1, 10);

		for (int i = 0; i < plates.size(); i++) {
			licencePlate = img(plates[i]);
			resize(licencePlate, licencePlate, Size(licencePlate.cols * 5, licencePlate.rows * 5));

			sprintf(filePath, "Images/out/plates/%i.png", i);
			imwrite(filePath, licencePlate);

			cvtColor(licencePlate, thresholdPlate, COLOR_BGR2GRAY);

			plateCascade.detectMultiScale(thresholdPlate, pTest, 1.1, 10);
			if (pTest.size() != 1) continue;

			threshold(thresholdPlate, thresholdPlate, 130, 1000, THRESH_BINARY_INV);

			dilate(thresholdPlate, thresholdPlate, getStructuringElement(MORPH_RECT, Size(3, 3)));
			erode(thresholdPlate, thresholdPlate, getStructuringElement(MORPH_RECT, Size(5, 5)));
			dilate(thresholdPlate, thresholdPlate, getStructuringElement(MORPH_RECT, Size(3, 3)));

			findContours(thresholdPlate, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

			for (int j = 0; j < contours.size(); j++) {
				area = contourArea(contours[j]);

				if (area < 3000 && area > 100) {
					glyph = licencePlate(boundingRect(contours[j]));
					sprintf(filePath, "Images/out/plates/%i_%i.png", i, j);
					imwrite(filePath, glyph);
				}
			}
		}

		imshow("capture", img);
	}

	destroyAllWindows();

	return 0;
}