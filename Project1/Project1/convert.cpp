#include "Convert.h"

unsigned long hexToDecimal(string hex)
{
	unsigned long result = 0;
    for (int i = 0; i < hex.length(); i++) 
	{
        if (hex[i] >= 48 && hex[i] <= 57) result += (hex[i] - 48) * pow(16, hex.length() - i - 1);
        else if (hex[i] >= 65 && hex[i] <= 70) result += (hex[i] - 55) * pow(16, hex.length( ) - i - 1);
        else if (hex[i] >= 97 && hex[i] <= 102) result += (hex[i] - 87) * pow(16, hex.length() - i - 1);
    }
    return result;
}