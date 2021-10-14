#pragma once

#include <iostream>
#include <limits>
#include "Envelope.hpp"
#include "EnvelopeComparator.hpp"
#include "InvalidEnvelopeSizeException.hpp"

class EnvelopeConsoleUI
{
public:
	EnvelopeConsoleUI();
	~EnvelopeConsoleUI();
	void StartEnvelopeCompairingDialog(int argc, char* argv[]);

private:
	Envelope *m_envelope_1;
	Envelope *m_envelope_2;
	Envelope* ReadEnvelopeParemeters();
	void ShowProgramInstructions();
};

