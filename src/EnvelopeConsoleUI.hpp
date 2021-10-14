#pragma once

#include <iostream>
#include <limits>
#include "Envelope.hpp"
#include "EnvelopeComparator.hpp"
#include "InvalidEnvelopeSizeException.hpp"

const std::string UI_ENVELOPE_CAN_CONTAIN = "One of these envelopes can contain another one";
const std::string UI_ENVELOPE_CAN_NOT_CONTAIN = "No one of these envelopes can contain another one";
const std::string UI_DO_YOU_WANT_TO_CONTINUE = "If you want to compare the next envelopes, enter (y/yes):"; 

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

