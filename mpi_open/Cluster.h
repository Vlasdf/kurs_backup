#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;
using namespace cv;

class Cluster {
public:
	Cluster();
	Cluster(const string&);
	Mat highlightBorders();
	Mat inversion();
	~Cluster();
private:
	Mat image;
};