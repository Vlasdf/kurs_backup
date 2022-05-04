#include "Cluster.h"

Cluster::Cluster(const string& imageWay) {
	image = imread(imageWay, IMREAD_GRAYSCALE);
}

Mat Cluster::highlightBorders() {
	Mat newImage = Mat::zeros(image.rows, image.cols, CV_8UC1);

	for (int x = 1; x < image.rows - 1; x++) {
		for (int y = 1; y < image.cols - 1; y++) {
			uint newPixel = abs(image.at<uchar>(x - 1, y - 1) + image.at<uchar>(x - 1, y) + image.at<uchar>(x - 1, y + 1) -
				image.at<uchar>(x + 1, y - 1) - image.at<uchar>(x + 1, y) - image.at<uchar>(x + 1, y + 1));
			newPixel += abs(image.at<uchar>(x - 1, y - 1) + image.at<uchar>(x, y - 1) + image.at<uchar>(x + 1, y - 1) -
				image.at<uchar>(x - 1, y + 1) - image.at<uchar>(x, y + 1) - image.at<uchar>(x + 1, y + 1));

			newImage.at<uchar>(x, y) = newPixel;
		}
	}

	return newImage;
}

Mat Cluster::inversion() {
	Mat newImage = Mat::zeros(image.rows, image.cols, CV_8UC1);

	for (int x = 0; x < image.rows; x++)
		for (int y = 0; y < image.cols; y++)
			newImage.at<uchar>(x, y) = 255 - image.at<uchar>(x, y);


	return newImage;
}