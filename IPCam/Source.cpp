#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	VideoCapture vcap;
	Mat image;

	// This works on a D-Link CDS-932L

	const string videoStreamAddress = "http://admin:ipvrnt2k@140.115.155.22:80/video2.mjpg";
	//open the video stream and make sure it's opened
	if (!vcap.open(videoStreamAddress)) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	for (;;) {
		if (!vcap.read(image)) {
			cout << "No frame" << endl;
			waitKey();
		}
		imshow("Output Window", image);

		if (waitKey(1) >= 0) break;
	}

}