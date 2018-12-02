#ifndef MESSAGEDECODER_H
#define MESSAGEDECODER_H
#include <string>
#include "Key.h"
#include <vector>
#include <iterator>
class MessageDecoder {
public:
	// Takes in a sequence of numbers (should be encrypted) and a key, then uses the key to decrypt
	std::string decode(std::vector<double>, Key&);
private:
};
#endif MESSAGEDECODER_H