#include "EnvelopeConsoleUI.hpp"

const int COMPLETE_ENVELOPES_PARAMETERS_COUNT = 4;

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

	}
	else
	{
		ShowProgramInstructions();
	}
	
	
	char user_answer[3];
	
	do
	{
		try
		{
			m_envelope_1 = ReadEnvelopeParemeters();
			m_envelope_2 = ReadEnvelopeParemeters();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		
		
		if (EnvelopeComparator::CanOneContainAnother(m_envelope_1, m_envelope_2))
			std::cout << "One of these envelopes can contain another one\n";
		else
			std::cout << "No one of these envelopes can contain another one\n\n";
		
		std::cout << "If you want to compare the next envelopes, enter (y/yes):\n";
		std::cin >> user_answer;
	} while (strcmp(user_answer, "y") == 0 || strcmp(user_answer, "yes") == 0);



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
	std::cout << "=== Envelope Analysis console application user manual ===\n";
	std::cout << "1. Enter four numbers - sizes of two envelopes - one by one.\n";
	std::cout << "2. After analysis result - enter \"y\" or \"yes\" to continue\n";
}
