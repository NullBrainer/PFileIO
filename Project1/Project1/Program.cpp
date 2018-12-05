#include "Program.h"
#include <vector>
#include <stdio.h>
#include "Key.h"
#include "MessageEncoder.h"
#include "ImageEncoder.h"
#include "EasyBMP.h"
#include "ImageDecoder.h"
#include "MessageDecoder.h"
#include <iostream>

Program::Program()
{
}

Program::~Program()
{
}

void Program::Run()
{
	std::string filename = "picture.bmp";
	BMP image;
	image.ReadFromFile(filename.c_str());
	std::string message = "Hello my name is RJ. I have been working on this for too long and I'm getting really tired. So it would mean a lot to me if this worked out.";
	std::cout << "Message to encrypt: " << message << std::endl;

	Key key;
	MessageEncoder me;
	ImageEncoder ie;
	std::vector<double> encodedVals;
	encodedVals = me.encode(message, key);
	ie.encode(encodedVals, image, key); 
	image.WriteToFile("PLEASELETTHISWORK.bmp");

	BMP image2;
	image2.ReadFromFile("PLEASELETTHISWORK.bmp");
	ImageDecoder id;
	std::vector<double> scrambledValues = id.decode(image2, key);
	MessageDecoder md;
	std::string decodedMessage = md.decode(scrambledValues, key);
	std::cout << "Decoded message: " << decodedMessage << std::endl;
}