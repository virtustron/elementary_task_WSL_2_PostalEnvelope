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

// cmd arguments - 2 pairs of sizes: a b c d
void EnvelopeConsoleUI::StartEnvelopeCompairingDialog(int argc, char* argv[])
{
	if (COMPLETE_ENVELOPES_PARAMETERS_COUNT == argc)
	{
		m_envelope_1->set_side_sizes(argv[1], argv[2]);
		m_envelope_2->set_side_sizes(argv[3], argv[4]);

		if (EnvelopeComparator::CanOneContainAnother(m_envelope_1, m_envelope_2))
			std::cout << UI_ENVELOPE_CAN_CONTAIN << "\n";
		else
			std::cout << UI_ENVELOPE_CAN_NOT_CONTAIN << "\n";
	}
	else
	{
		ShowProgramInstructions();
		
		std::string user_answer;
	
		do
		{
			m_envelope_1 = ReadEnvelopeParemeters();
			m_envelope_2 = ReadEnvelopeParemeters();
		
			if (EnvelopeComparator::CanOneContainAnother(m_envelope_1, m_envelope_2))
				std::cout << UI_ENVELOPE_CAN_CONTAIN << "\n";
			else
				std::cout << UI_ENVELOPE_CAN_NOT_CONTAIN << "\n";
		
			std::cout << UI_DO_YOU_WANT_TO_CONTINUE << "\n";
			std::cin >> user_answer;
		} while ((user_answer.compare("y") == 0) || (user_answer.compare("yes") == 0));
	}
}

Envelope* EnvelopeConsoleUI::ReadEnvelopeParemeters() 
{
	Envelope* envelope = new Envelope();
	double side_size_1, side_size_2;

	std::cout << "Enter first side of the envelope:\n";
	std::cin >> side_size_1;
	
	if (!std::cin)				
	{
		std::cin.clear();		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

		throw InvalidEnvelopeSizeException("Non numerical envelope size");
	}

	std::cout << "Enter second side of the envelope:\n";
	std::cin >> side_size_2;

	if (!std::cin)			
	{
		std::cin.clear();		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

		throw InvalidEnvelopeSizeException("Non numerical envelope size");
	}
	
	try
	{
		envelope->set_side_sizes(side_size_1, side_size_2);
	}
	catch (InvalidEnvelopeSizeException size_exception)
	{
		std::cout << size_exception.get_error_message() << " " << size_exception.get_size_value() << "\n";
	}

	return envelope;
}

void EnvelopeConsoleUI::ShowProgramInstructions()
{
	std::cout << "\n";
	std::cout << "=== Envelope Analysis console application user manual ===\n";
	std::cout << "1. Enter four numbers - sizes of two envelopes - one by one.\n";
	std::cout << "2. After analysis result - enter \"y\" or \"yes\" to continue\n";
	std::cout << "\n";
}
