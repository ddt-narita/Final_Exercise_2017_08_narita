#pragma once
#include <exception>

class JsonBadAcsessException :public std::exception
{
public:
	JsonBadAcsessException();
	~JsonBadAcsessException();
	JsonBadAcsessException(int row, int col);

private:
	int row;
	int col;
};

JsonBadAcsessException::JsonBadAcsessException()
{
}

JsonBadAcsessException::~JsonBadAcsessException()
{
}

inline JsonBadAcsessException::JsonBadAcsessException(int row, int col)
{
	this->row = row;
	this->col = col;
}

JsonBadAcsessException* e = new JsonBadAcsessException();