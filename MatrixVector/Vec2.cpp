#include "Vec2.h"
#include "math.h"

#define PI 3.14159265
/*Vec2i::Vec2i(float x_, float y_)
	:x(x_), y(y_)
{
	angleX = atan(y / x) * 180 / PI;
	magnitude = calMagnitude();
	magnitudeSq = calMagnitudeSq();
	normalize();
}


Vec2i::~Vec2i()
{
}

Vec2i &Vec2i::add(Vec2i other)
{
	x = x + other.x;
	y = y + other.y;

	setnewProperty();
	return *this;
}

Vec2i &Vec2i::subtract(Vec2i other)
{
	x = x - other.x;
	y = y - other.y;

	setnewProperty();
	return *this;
}

Vec2i &Vec2i::scale(float scl)
{
	x = x * scl;
	y = y * scl;

	setnewProperty();
	return *this;
}

Vec2i operator+(Vec2i left, Vec2i right)
{
	return left.add(right);
}

Vec2i& Vec2i::operator+=(Vec2i const& other)
{
	return this->add(other);
}

Vec2i operator-(Vec2i left, Vec2i right)
{
	return left.subtract(right);
}

Vec2i& Vec2i::operator*(float const& other)
{
	return this->scale(other);
}

Vec2i& Vec2i::operator*=(float const& other)
{
	return this->scale(other);
}

Vec2i& Vec2i::operator/(float const& other)
{
	return this->scale(1/other);
}

Vec2i& Vec2i::operator/=(float const& other)
{
	return this->scale(1 / other);
}

Vec2i& Vec2i::operator-=(Vec2i const& other)
{
	return this->subtract(other);
}
bool Vec2i::operator==(const Vec2i & other) const
{
	return(x == other.x) && (y == other.y);
}

float Vec2i::angle(Vec2i other)
{
	if(((this->x == other.x) && (this->y == other.y)) || (this->x==0 && this->y ==0) || (other.x==0 && other.y ==0) )
	{
		return 0;
	}
	else return acos((this->dot(other))/(magnitude*other.magnitude)) * 180 / PI;
}



int Vec2i::dot(Vec2i other)
{
	return x * other.x + y * other.y;
}

int Vec2i::cross(Vec2i other)
{
	return x * other.y - y * other.x;
}

float Vec2i::calMagnitude()
{
	return sqrt(x*x + y*y);
}

float Vec2i::calMagnitudeSq()
{
	return x*x + y*y;
}

void Vec2i::normalize()
{
	xNor = x / calMagnitude();
	yNor = y / calMagnitude();
}

float Vec2i::distance(Vec2i other)
{
	return this->subtract(other).magnitude;
}

void Vec2i::setnewProperty()
{
	angleX = atan(y / x) * 180 / PI;
	magnitude = calMagnitude();
	magnitudeSq = calMagnitudeSq();
	normalize();
}*/