#include "Envelope.hpp"

Envelope::Envelope()
{
	m_long_side_size = 1;
	m_short_side_size = 1;
}

Envelope::Envelope(int size_1, int size_2)
{
	set_side_sizes(size_1, size_2);
}

int Envelope::get_long_side_size()
{
	return m_long_side_size;
}

int Envelope::get_short_side_size()
{
	return m_short_side_size;
}

void Envelope::set_side_sizes(int size_1, int size_2)
{
	if (!IsSizeValid(size_1))
		throw InvalidEnvelopeSizeException("Invalid envelope size value", size_1);

	if (!IsSizeValid(size_2))
		throw InvalidEnvelopeSizeException("Invalid envelope size value", size_2);

	if (size_1 > size_2)
	{
		m_long_side_size = size_1;
		m_short_side_size = size_2;
	}
	else
	{
		m_long_side_size = size_2;
		m_short_side_size = size_1;
	}
}

bool Envelope::IsSizeValid(int envelope_size)
{
	if (envelope_size <= 0)
		return false;

	return true;
}