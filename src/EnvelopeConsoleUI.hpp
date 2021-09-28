#pragma once

#include <iostream>
#include "Envelope.hpp"
#include "EnvelopeComparator.hpp"

class EnvelopeConsoleUI
{
public:
	EnvelopeConsoleUI();
	~EnvelopeConsoleUI();
	void StartEnvelopeCompairingDialog();

private:
	Envelope *m_envelope_1;
	Envelope *m_envelope_2;
	void StartReadEnvelopeDialog(Envelope* envelope);
};

