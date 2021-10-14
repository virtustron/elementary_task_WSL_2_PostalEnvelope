// 2_PostalEnvelope.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "EnvelopeConsoleUI.hpp"

int main(int argc, char* argv[])
{
	EnvelopeConsoleUI envelopes_console_ui;
	
	try
	{
		envelopes_console_ui.StartEnvelopeCompairingDialog(argc, argv);
	}
	catch(const InvalidEnvelopeSizeException& e)
	{
		std::cout << e.get_error_message() << '\n';
	}

	return 0;
}

