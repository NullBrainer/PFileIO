#ifndef MESSAGEENCODER_H
#define MESSAGEENCODER_H
#include <vector>
#include <string>
#include "Key.h"
class MessageEncoder {
public:
	MessageEncoder() = default;
	std::vector<double> encode(std::string, Key&);
private:
};
#endif MESSAGEENCODER_H
