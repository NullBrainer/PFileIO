#include "ImageEncoder.h"

void ImageEncoder::encode(std::vector<double>& encodedValues, BMP& image, Key& key) {
	srand(time(0));
	int width = image.TellWidth();
	int height = image.TellHeight();

	std::list<std::tuple<int, int, int>> posQuos;
	std::unordered_set<int> xpositions;
	std::unordered_set<int> ypositions;
	
	int xPos;
	int yPos;
	for (int i = 0; i < encodedValues.size(); i++) {
		xPos = rand() % width;
		yPos = rand() % height;
		
		while (xpositions.find(xPos) != xpositions.end()) {
			xPos = rand() % width;
		}
		while (ypositions.find(yPos) != ypositions.end()) {
			yPos = rand() % height;
		}

		xpositions.emplace(xPos);
		ypositions.emplace(yPos);

		int encodedNum = encodedValues[i];
		int quotient = encodedNum / 256;
		int encodedColor = encodedNum % 256;

		std::tuple<int, int, int> pq(xPos, yPos, quotient); 
		posQuos.push_back(pq);

		RGBApixel pixel;
		pixel.Red = encodedColor;
		pixel.Blue = encodedColor;
		pixel.Green = encodedColor;
		image.SetPixel(xPos, yPos, pixel);
	}
	key.setPosQuotient(posQuos);
}