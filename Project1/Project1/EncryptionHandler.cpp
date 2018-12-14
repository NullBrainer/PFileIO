#include "Encryption.h"

void EncryptionHandler::encrypt(std::string message, std::string filename) {
	ImageEncoder IE;
	MessageEncoder ME;
	image.ReadFromFile(filename.c_str());
	Key key;
	std::vector<double> encodedVals = ME.encode(message, key);
	IE.encode(encodedVals, image, key);
	std::string newFile = "new";
	newFile.append(filename);
	image.WriteToFile(newFile.c_str());
	KeyWriter KW;
	KW.WriteKeyToFile("KEY", key);
}

std::string EncryptionHandler::decrypt(std::string pictureFile, std::string keyFile) {
	image.ReadFromFile(pictureFile.c_str());
	KeyReader KR;
	ImageDecoder ID;
	MessageDecoder MD;
	Key key = KR.ReadFromFile(keyFile);
	std::vector<double> decodedVals = ID.decode(image, key);
	std::string decodedMessage = MD.decode(decodedVals, key);
	return decodedMessage;
}