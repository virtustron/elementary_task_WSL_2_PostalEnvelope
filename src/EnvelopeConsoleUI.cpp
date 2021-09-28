#include "EnvelopeConsoleUI.hpp"

EnvelopeConsoleUI::EnvelopeConsoleUI()
{

}

EnvelopeConsoleUI::~EnvelopeConsoleUI()
{
	if (m_envelope_1 != NULL)
		delete m_envelope_1;

	if (m_envelope_2 != NULL)
		delete m_envelope_2;
}

void EnvelopeConsoleUI::StartEnvelopeCompairingDialog()
{
	char user_answer[3];

	m_envelope_1 = new Envelope();
	m_envelope_2 = new Envelope();

	do
	{
		StartReadEnvelopeDialog(m_envelope_1);
		StartReadEnvelopeDialog(m_envelope_2);
		
		if (EnvelopeComparator::CanOneContainAnother(m_envelope_1, m_envelope_2))
			std::cout << "One of these envelopes can contain another one\n";
		else
			std::cout << "No one of these envelopes can contain another one\n\n";
		
		std::cout << "If you want to compare the next envelopes, enter (y/yes):\n";
		std::cin >> user_answer;
	} while (strcmp(user_answer, "y") == 0 || strcmp(user_answer, "yes") == 0);
}

void EnvelopeConsoleUI::StartReadEnvelopeDialog(Envelope* envelope) 
{
	int side_size_1, side_size_2;

	std::cout << "Enter first side of the envelope:\n";
	std::cin >> side_size_1;

	/*
	if (!std::cin)				// or if(cin.fail())
	{
		// user didn't input a number
		std::cin.clear();		// reset failbit
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input

		// TODO: replace with throw-operator (and create responsible exception class)
		std::cout << "Please enter a numeric value\n";
		side_size_1 = 1;
	}
	*/

	std::cout << "Enter second side of the envelope:\n";
	std::cin >> side_size_2;

	/*
	if (!std::cin)				// or if(cin.fail())
	{
		// user didn't input a number
		std::cin.clear();		// reset failbit
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input

		// TODO: replace with throw-operator (and create responsible exception class)
		std::cout << "Please enter a numeric value\n";
		side_size_2 = 1;
	}
	*/

	try
	{
		envelope->set_side_sizes(side_size_1, side_size_2);
	}
	catch (InvalidEnvelopeSizeException size_exception)
	{
		std::cout << size_exception.get_error_message() << " " << size_exception.get_size_value() << "\n";
	}
}
