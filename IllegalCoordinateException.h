#pragma once

#include <string>
#include <exception>

using namespace std;

class IllegalCoordinateException : public exception
{
public:
	IllegalCoordinateException(size_t i, size_t j);
	string theCoordinate() const;

private:
	size_t i, j;
};
