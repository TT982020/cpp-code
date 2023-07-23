#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __STRING_H__
#define __STRING_H__
#include <string>
#include <iostream>
class String
{
public:
	String(const char* ch = 0);
	String(const String& str);
	String& operator = (const String& str);
	char* get_c_str() const { return m_data; };
	~String();
private:
	char* m_data;
};

inline String::String(const char* ch)
{
	if (ch)
	{
		m_data = new char[strlen(ch) + 1];
		strcpy(m_data, ch);
	}
	else {
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline String::~String()
{
	delete[] m_data;
}

inline String::String(const String& str) {
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}

inline String& String::operator=(const String& str) {
	if (this== &str)
	{
		return *this;
	}
	delete[] m_data;
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
	return *this;
}

#endif // !__STRING_H__
