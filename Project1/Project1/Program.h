#ifndef PROGRAM_HEADER
#define PROGRAM_HEADER
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
#include "Encryption.h"
class Program
{
public:
	Program();
	~Program();
	void Run();
	void Encode(std::string);
	std::string Decode(std::string, std::string);
	void EmbedEncryptedMessage(std::string);
	
private:
	std::unique_ptr<MatrixBuilder>mbuilder;
	Matrix MatrixObj;
	Key KeyObj;
	MessageEncoder encodur;
	MessageDecoder decodur;
	std::vector<double>codeinfo;
	std::vector<char>imgbytes;

};


#endif // !PROGRAM_HEADER

/*
Bring it all together and test the classes
FILEio for KEy file
*/

