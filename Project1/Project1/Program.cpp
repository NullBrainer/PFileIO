#include "Program.h"

Program::Program():mbuilder(new ThreeByThreeMatrixBuilder())
{
}

Program::~Program()
{
}

void Program::Run()
{	
	EncryptionHandler::getInstance().encrypt("Encrypted message", "picture.bmp");
	std::string message = EncryptionHandler::getInstance().decrypt("newpicture.bmp", "KEY.KEY");
	
	/*
	ImageEncoder IE;
	MessageEncoder ME;
	ImageDecoder ID;
	MessageDecoder MD;
	std::string fileName = "picture.bmp";
	std::string message = "Deep in thought.";
	BMP image;
	image.ReadFromFile(fileName.c_str());
	Key key_nought;
	std::vector<double> encodedVals = ME.encode(message, key_nought);
	IE.encode(encodedVals, image, key_nought);
	image.WriteToFile("newPicture.bmp");
	KeyWriter KW;
	KW.WriteKeyToFile("KEY", key_nought);

	BMP newImage;
	newImage.ReadFromFile("newPicture.bmp");
	KeyReader KR;
	Key key_prime = KR.ReadFromFile("KEY.KEY");
	std::vector<double> decodedVals = ID.decode(newImage, key_prime);
	std::string decodedMessage = MD.decode(decodedVals, key_prime);
	std::cout << decodedMessage << std::endl;
	*/
	/*
	make keyfile
	read imgfile
	get bytes

	*/
	/*
	std::string filename = "keyfile.KEY";
	std::string imgfile = "image.png";
	std::string message = "Some hidden message";
	std::unique_ptr<FileController>fc(new FileController(imgfile));
	imgbytes = fc->Read();
	Encode(message);
	*/

	/*
	create matrix
	read image bytes
	encrypt message
	
	std::cout << "Write stuff into the file: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string content;
	std::getline(std::cin, content);
	fc->Write(content);
	*/
	/*
	std::cout << "The File says: ";
	std::vector<char> fileinfo = fc->Read();
	std::vector<int> filenumbers = fc->GetBinary();
	
	for (int i = 0; i < 50; i++)
	{
		std::cout << fileinfo[i];
	}
	*/
	/*
	std::cout << "\nFile in numbers: ";
	for (int i = 0; i < 50; i++)
	{
		std::cout << filenumbers[i];
	}
	*/
	/*
	char c;
	std::cin >> c;
	*/
	
}

void Program::Encode( std::string message)
{

	/*
	Create Matrix
	Encoder encode = req key obj and message , returns a vector of dubbles and sets inverse for the key
	write doubles to the file with some key Symbols
	*/
	MatrixObj = mbuilder->createMatrix();
	codeinfo = encodur.encode(message, KeyObj);
	std::string encryptedmessage;;
	for (int i = 0; i < codeinfo.size(); i++)
	{
		encryptedmessage.append(std::to_string(codeinfo[i]));
	}
	/*
	place each float value in a random spot in the message
	for every placement, add to the key object the location added

	*/

}

std::string Program::Decode(std::string modifiedfile, std::string keyfilename)
{
/*	
read and parse
access decoded vector from encoder and pass in key
key must be initialized from reading key file
*/	
	std::string decodedmessage = "Decoding Failed";

	decodur.decode(codeinfo, KeyObj);
	return decodedmessage;
}
void Program::EmbedEncryptedMessage(std::string encryptedmessage)
{

	for (int i = 0; i < imgbytes.size(); i++)
	{

	}
}
/*
read image
*/

