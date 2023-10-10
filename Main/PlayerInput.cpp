#include "PlayerInput.h"

#include <iostream>
#include <string>

void valideInput()
{
	bool isValidInput = true;

	std::string inputString;

	do
	{
		for(char inputChar : inputString)
		{
			if(isdigit(inputChar))
			{
				std::cout << "[" << inputChar <<"] isn't accepted" << std::endl;
				isValidInput = false;
				break;
			}
		}
	}

	while (!isValidInput);
}