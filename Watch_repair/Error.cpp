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
		return "Ціна ремонту не може бути менша за 0!";
	case NegativeTime:
		return "Час ремонту не може бути меншим чи дорівнювати нулю!";
	case IdxOutsideLimit:
		return "Неправильний індекс!";
	case MaxSizeReached:
		return "Забагато замовлень!";
	default:
		return "---------";
	}
}