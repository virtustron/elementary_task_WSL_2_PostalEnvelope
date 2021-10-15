// 2_PostalEnvelope.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "EnvelopeConsoleUI.hpp"
#include "EnvelopesAnalysis.hpp"

int main(int argc, char* argv[])
{
	void* container = NULL;
	
	// 10.0, 10.0, 15.0, 5.0
	if (InitializeEnvelopesContainer(&container) == INIT_SUCCEDED)
	{
		bool can_contain;
		
		if (CanOneEnvelopeContainAnother(container, &can_contain));
	
		if (can_contain)
		{
			std::cout << "Can contain" << "\n";
		}
		else
		{
			std::cout << "Can not contain" << "\n";
		}

	}
	
	
	/*
	EnvelopeConsoleUI envelopes_console_ui;
	
	try
	{
		envelopes_console_ui.StartEnvelopeCompairingDialog(argc, argv);
	}
	catch(const InvalidEnvelopeSizeException& e)
	{
		std::cout << e.get_error_message() << '\n';
	}
	*/

	return 0;
}

