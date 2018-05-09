#include "IllegalCoordinateException.h"

IllegalCoordinateException::IllegalCoordinateException(size_t i, size_t j) : i(i), j(j)
{

}

string IllegalCoordinateException::theCoordinate() const
{
	return to_string(this->i) + "," + to_string(this->j);
}
