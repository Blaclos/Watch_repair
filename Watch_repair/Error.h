#pragma once
#include<string>
using namespace std;

enum ErrorCode
{
	NegativePrise,
	NegativeTime,
	IdxOutsideLimit,
	MaxSizeReached,
	InvalidCharacter
};

class Error
{
private:
	ErrorCode code;
public:
	Error(ErrorCode code);
	string ToString();
};