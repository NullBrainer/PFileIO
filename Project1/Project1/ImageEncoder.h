#ifndef IMAGEENCODER_H
#define IMAGEENCODER_H

#include <vector>
#include "Key.h"
#include <string>
#include <random>
#include <ctime>
#include <unordered_set>
#include <map>
#include <list>
#include <tuple>
#include "EasyBMP.h"
class ImageEncoder {
public:
	//void encode(std::vector<double>, std::vector<char>&, Key&);
	void encode(std::vector<double>&, BMP&, Key&);
private:
};
#endif IMAGEENCODER_H