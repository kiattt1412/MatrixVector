#include "Vec3.h"
#include "math.h"

#define PI 3.14159265

/*Vec3i::Vec3i(float x_, float y_,float z_)
	:x(x_), y(y_), z(z_)
{
	magnitude = calMagnitude();
	magnitudeSq = calMagnitudeSq();
	normalize();
}

Vec3i::~Vec3i()
{
}


Vec3i& Vec3i::add(Vec3i other)
{
	x = x + other.x;
	y = y + other.y;
	z = z + other.z;
	setnewProperty();
	return *this;
}
Vec3i& Vec3i::subtract(Vec3i other)
{
	x = x - other.x;
	y = y - other.y;
	z = z - other.z;
	setnewProperty();
	return *this;
}

Vec3i& Vec3i::scale(float scl)
{
	x = x*scl;
	y = y*scl;
	z = z*scl;
	setnewProperty();
	return *this;
}

Vec3i operator+(Vec3i left, Vec3i right)
{
	return left.add(right);
}

Vec3i operator-(Vec3i left, Vec3i right)
{
	return left.subtract(right);
}
bool Vec3i::operator==(const Vec3i & other) const
{
	return(x == other.x) && (y == other.y) && (z==other.z);
}

int Vec3i::dot(Vec3i other)
{
	return x*other.x + y*other.y + z*other.z;
}

Vec3i& Vec3i::cross(Vec3i other)
{
	//return x * other.y - y * other.x;
	Vec3i crossResult(0,0,0);
	crossResult.x = y*other.z - z*other.y;
	crossResult.y = z*other.x - x*other.z;
	crossResult.z = x*other.y - y*other.x;
	return crossResult;
}

float Vec3i::calMagnitude()
{
	return sqrt(x*x + y*y +z*z);
}

float Vec3i::calMagnitudeSq()
{
	return x*x + y*y +z*z;
}

void Vec3i::normalize()
{
	xNor = x / calMagnitude();
	yNor = y / calMagnitude();
	zNor = z / calMagnitude();
}

void Vec3i::setnewProperty()
{
	magnitude = calMagnitude();
	magnitudeSq = calMagnitudeSq();
	normalize();
}

float Vec3i::angle(Vec3i other)
{
	if (((this->x == other.x) && (this->y == other.y) && (this->z == other.z)))
	{
		return 0;
	}
	else return acos((this->dot(other)) / (magnitude*other.magnitude)) * 180 / PI;
}

float Vec3i::distance(Vec3i other)
{
	return this->subtract(other).magnitude;
}

Vec3i& Vec3i::operator+=(Vec3i const& other)
{
	return this->add(other);
}

Vec3i& Vec3i::operator-=(Vec3i const& other)
{
	return this->subtract(other);
}

Vec3i& Vec3i::operator*(float const& other)
{
	return this->scale(other);
}

Vec3i& Vec3i::operator*=(float const& other)
{
	return this->scale(other);
}

Vec3i& Vec3i::operator/(float const& other)
{
	return this->scale(1 / other);
}

Vec3i& Vec3i::operator/=(float const& other)
{
	return this->scale(1 / other);
}*/

