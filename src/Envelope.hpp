#pragma once

#include "InvalidEnvelopeSizeException.h"

class Envelope
{
public:
	Envelope();
	Envelope(int side_1, int side_2);
	int get_long_side_size();
	int get_short_side_size();
	void set_side_sizes(int size_1, int size_2);

private:
	int m_long_side_size;
	int m_short_side_size;
	bool IsSizeValid(int envelope_size);
};

