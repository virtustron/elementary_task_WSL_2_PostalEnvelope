#pragma once

#include <cstring>

const int UNDEFINED_ENVELOPE_SIZE = -1;

class InvalidEnvelopeSizeException
{
public:
	InvalidEnvelopeSizeException();
	InvalidEnvelopeSizeException(const char* error_message);
	InvalidEnvelopeSizeException(const char* error_message, int size_value);

	char* get_error_message() const;
	int get_size_value();

private:
	char m_error_message[50];
	int m_size_value;

};

