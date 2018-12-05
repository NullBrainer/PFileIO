#ifndef IMAGEDECODER_H
#define IMAGEDECODER_H
#include <vector>
#include "EasyBMP.h"
#include "Key.h"
#include <vector>
class ImageDecoder {
public:
	std::vector<double> decode(BMP&, Key&);
private:
};
#endif IMAGEDECODER_H