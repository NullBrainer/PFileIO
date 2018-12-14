#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <stdio.h>
#include <memory>
#include <iostream>
#include "FileController.h"
#include "Key.h"
#include "MessageEncoder.h"
#include "MessageDecoder.h"
#include "ImageDecoder.h"
#include "ImageEncoder.h"
#include "ThreeByThreeMatrixBuilder.h"
#include "KeyReader.h"
#include "KeyWriter.h"
#include <vector>
#include <stdio.h>
#include <random>
#include "EasyBMP.h"
class EncryptionHandler {
public:
	static EncryptionHandler& getInstance() {
		static EncryptionHandler encryption;
		return encryption;
	}
	~EncryptionHandler() {};
	EncryptionHandler(EncryptionHandler&) = delete;
	void operator=(EncryptionHandler const&) = delete;

	void encrypt(std::string message, std::string filename);
	std::string decrypt(std::string pictureFile, std::string keyFile);
private:
	EncryptionHandler() {}
	BMP image;
};
#endif ENCRYPTION_H