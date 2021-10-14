#pragma once

#include "InvalidEnvelopeSizeException.hpp"

class Envelope
{
public:
	Envelope();
	Envelope(double side_1, double side_2);
	double get_long_side_size() const;
	double get_short_side_size() const;
	void set_side_sizes(double size_1, double size_2);

private:
	double m_long_side_size;
	double m_short_side_size;
	bool IsSizeValid(double envelope_size);
};

