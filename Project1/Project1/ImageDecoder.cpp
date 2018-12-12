#include "ImageDecoder.h"

std::vector<double> ImageDecoder::decode(BMP& image, Key& key) {
	std::list<std::tuple<int, int, int>> posQuos = key.getPositionsQuotients();
	std::vector<double> encodedValues;

	auto iter = posQuos.begin();
	int x, y, quotient;
	while (iter != posQuos.end()) {
		std::tuple<int, int, int> positionQuotient = *iter;
		x = std::get<0>(positionQuotient);
		y = std::get<1>(positionQuotient);
		quotient = std::get<2>(positionQuotient);

		RGBApixel pixel = image.GetPixel(x, y);
		double encodedColor = pixel.Blue;
		double reverse = quotient + (encodedColor / 256);
		double encodedNumber = std::round(reverse * 256);
		encodedValues.push_back(encodedNumber);
		iter++;
	}
	return encodedValues;
}