#include"Error.h"
#include<string>
using namespace std;

Error::Error(ErrorCode code)
{
	this->code = code;
}

string Error::ToString()
{
	switch (code)
	{
	case NegativePrise:
		return "ֳ�� ������� �� ���� ���� ����� �� 0!";
	case NegativeTime:
		return "��� ������� �� ���� ���� ������ �� ���������� ����!";
	case IdxOutsideLimit:
		return "������������ ������!";
	case MaxSizeReached:
		return "�������� ���������!";
	default:
		return "---------";
	}
}