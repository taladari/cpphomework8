#include "IllegalCoordinateException.h"

IllegalCoordinateException::IllegalCoordinateException(size_t i, size_t j) : i(i), j(j)
{

}

string IllegalCoordinateException::theCoordinate() const
{
	std::ostringstream ss;
	ss << this->i << "," << this->j;
	return ss.str();
}
