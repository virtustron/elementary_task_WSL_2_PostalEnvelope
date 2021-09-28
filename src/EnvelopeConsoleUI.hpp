#pragma once

#include <iostream>
#include "Envelope.h"
#include "EnvelopeComparator.h"

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

