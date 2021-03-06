#include "Mat4.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>

Mat4::Mat4()
{
}


Mat4::~Mat4()
{
}

Mat4::Mat4(const Vec4<float>& row0, const Vec4<float>& row1, const Vec4<float>& row2, const Vec4<float>& row3)
{
	m[0][0] = row0.x; m[0][1] = row0.y; m[0][2] = row0.z; m[0][3] = row0.a;
	m[1][0] = row1.x; m[1][1] = row1.y; m[1][2] = row1.z; m[1][3] = row1.a;
	m[2][0] = row2.x; m[2][1] = row2.y; m[2][2] = row2.z; m[2][3] = row2.a;
	m[3][0] = row3.x; m[3][1] = row3.y; m[3][2] = row3.z; m[3][3] = row3.a;
}

Mat4::Mat4(float a)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m[i][j] = a;
		}
		
	}
}

Mat4& Mat4::mul(const Mat4& other)
{
	Mat4 result(0);
	result.m[0][0] = (m[0][0] * other.m[0][0]) + (m[0][1] * other.m[1][0]) + (m[0][2] * other.m[2][0]) + (m[0][3] * other.m[3][0]);
	result.m[0][1] = (m[0][0] * other.m[0][1]) + (m[0][1] * other.m[1][1]) + (m[0][2] * other.m[2][1]) + (m[0][3] * other.m[3][1]);
	result.m[0][2] = (m[0][0] * other.m[0][2]) + (m[0][1] * other.m[1][2]) + (m[0][2] * other.m[2][2]) + (m[0][3] * other.m[3][2]);
	result.m[0][3] = (m[0][0] * other.m[0][3]) + (m[0][1] * other.m[1][3]) + (m[0][2] * other.m[2][3]) + (m[0][3] * other.m[3][3]);
	
	result.m[1][0] = (m[1][0] * other.m[0][0]) + (m[1][1] * other.m[1][0]) + (m[1][2] * other.m[2][0]) + (m[1][3] * other.m[3][0]);
	result.m[1][1] = (m[1][0] * other.m[0][1]) + (m[1][1] * other.m[1][1]) + (m[1][2] * other.m[2][1]) + (m[1][3] * other.m[3][1]);
	result.m[1][2] = (m[1][0] * other.m[0][2]) + (m[1][1] * other.m[1][2]) + (m[1][2] * other.m[2][2]) + (m[1][3] * other.m[3][2]);
	result.m[1][3] = (m[1][0] * other.m[0][3]) + (m[1][1] * other.m[1][3]) + (m[1][2] * other.m[2][3]) + (m[1][3] * other.m[3][3]);
	
	result.m[2][0] = (m[2][0] * other.m[0][0]) + (m[2][1] * other.m[1][0]) + (m[2][2] * other.m[2][0]) + (m[2][3] * other.m[3][0]);
	result.m[2][1] = (m[2][0] * other.m[0][1]) + (m[2][1] * other.m[1][1]) + (m[2][2] * other.m[2][1]) + (m[2][3] * other.m[3][1]);
	result.m[2][2] = (m[2][0] * other.m[0][2]) + (m[2][1] * other.m[1][2]) + (m[2][2] * other.m[2][2]) + (m[2][3] * other.m[3][2]);
	result.m[2][3] = (m[2][0] * other.m[0][3]) + (m[2][1] * other.m[1][3]) + (m[2][2] * other.m[2][3]) + (m[2][3] * other.m[3][3]);

	result.m[3][0] = (m[3][0] * other.m[0][0]) + (m[3][1] * other.m[1][0]) + (m[3][2] * other.m[2][0]) + (m[3][3] * other.m[3][0]);
	result.m[3][1] = (m[3][0] * other.m[0][1]) + (m[3][1] * other.m[1][1]) + (m[3][2] * other.m[2][1]) + (m[3][3] * other.m[3][1]);
	result.m[3][2] = (m[3][0] * other.m[0][2]) + (m[3][1] * other.m[1][2]) + (m[3][2] * other.m[2][2]) + (m[3][3] * other.m[3][2]);
	result.m[3][3] = (m[3][0] * other.m[0][3]) + (m[3][1] * other.m[1][3]) + (m[3][2] * other.m[2][3]) + (m[3][3] * other.m[3][3]);
	*this = result;
	return *this;
}

Mat4 operator*(Mat4 left, const Mat4& right)
{
	return left.mul(right);
}

Mat4& Mat4::operator*=(const Mat4& other)
{
	return this->mul(other);
}

void Mat4::print()
{
	for (int i = 0; i < 4;i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (m[i][j] > 0.000001 || m[i][j] < -0.000001)
			{
				std::cout << " " << m[i][j] << " ";
			}
			else std::cout << " " << 0 << " ";
			
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}



float Mat4::det()
{
	return /*m[0][0] * (
			- m[3][1] * m[2][2] * m[1][3]
			- m[3][2] * m[2][3] * m[1][1]
			- m[3][3] * m[2][1] * m[1][2]
			+ m[1][1] * m[2][2] * m[3][3]
			+ m[1][2] * m[2][3] * m[3][1]
			+ m[1][3] * m[2][1] * m[3][2]) -

		m[0][1] * (
			- m[3][0] * m[2][2] * m[1][3]
			- m[3][2] * m[2][3] * m[1][0]
			- m[3][3] * m[2][0] * m[1][2]
			+ m[1][0] * m[2][2] * m[3][3]
			+ m[1][2] * m[2][3] * m[3][0]
			+ m[1][3] * m[2][0] * m[3][2]) +

		m[0][2] * (
			- m[3][0] * m[2][1] * m[1][3]
			- m[3][1] * m[2][3] * m[1][0]
			- m[3][3] * m[2][0] * m[1][1]
			+ m[1][0] * m[2][1] * m[3][3]
			+ m[1][1] * m[2][3] * m[3][0]
			+ m[1][3] * m[2][0] * m[3][1]) -

		m[0][3] * (
			- m[3][0] * m[2][1] * m[1][2]
			- m[3][1] * m[2][2] * m[1][0]
			- m[3][2] * m[2][0] * m[1][1]
			+ m[1][0] * m[2][1] * m[3][2]
			+ m[1][1] * m[2][2] * m[3][0]
			+ m[1][2] * m[2][0] * m[3][1]);	*/

		/////////////////

		/*- m[1][0] * (
			- m[3][1] * m[2][2] * m[0][3]
			- m[3][2] * m[2][3] * m[0][1]
			- m[3][3] * m[2][1] * m[0][2]
			+ m[0][1] * m[2][2] * m[3][3]
			+ m[0][2] * m[2][3] * m[3][1]
			+ m[0][3] * m[2][1] * m[3][2]) +

		m[1][1] * (
			- m[3][0] * m[2][2] * m[0][3]
			- m[3][2] * m[2][3] * m[0][0]
			- m[3][3] * m[2][0] * m[0][2]
			+ m[0][0] * m[2][2] * m[3][3]
			+ m[0][2] * m[2][3] * m[3][0]
			+ m[0][3] * m[2][0] * m[3][2]) -

		m[1][2] * (
			- m[3][0] * m[2][1] * m[0][3]
			- m[3][1] * m[2][3] * m[0][0]
			- m[3][3] * m[2][0] * m[0][1]
			+ m[0][0] * m[2][1] * m[3][3]
			+ m[0][1] * m[2][3] * m[3][0]
			+ m[0][3] * m[2][0] * m[3][1]) +

		m[1][3] * (
			- m[3][0] * m[2][1] * m[0][2]
			- m[3][1] * m[2][2] * m[0][0]
			- m[3][2] * m[2][0] * m[0][1]
			+ m[0][0] * m[2][1] * m[3][2]
			+ m[0][1] * m[2][2] * m[3][0]
			+ m[0][2] * m[2][0] * m[3][1]);*/

		/////////

		/*m[2][0] * (
			- m[3][1] * m[1][2] * m[0][3]
			- m[3][2] * m[1][3] * m[0][1]
			- m[3][3] * m[1][1] * m[0][2]
			+ m[0][1] * m[1][2] * m[3][3]
			+ m[0][2] * m[1][3] * m[3][1]
			+ m[0][3] * m[1][1] * m[3][2]) -

		m[2][1] * (
			- m[3][0] * m[1][2] * m[0][3]
			- m[3][2] * m[1][3] * m[0][0]
			- m[3][3] * m[1][0] * m[0][2]
			+ m[0][0] * m[1][2] * m[3][3]
			+ m[0][2] * m[1][3] * m[3][0]
			+ m[0][3] * m[1][0] * m[3][2]) +

		m[2][2] * (
			- m[3][0] * m[1][1] * m[0][3]
			- m[3][1] * m[1][3] * m[0][0]
			- m[3][3] * m[1][0] * m[0][1]
			+ m[0][0] * m[1][1] * m[3][3]
			+ m[0][1] * m[1][3] * m[3][0]
			+ m[0][3] * m[1][0] * m[3][1]) -

		m[2][3] * (
			- m[3][0] * m[1][1] * m[0][2]
			- m[3][1] * m[1][2] * m[0][0]
			- m[3][2] * m[1][0] * m[0][1]
			+ m[0][0] * m[1][1] * m[3][2]
			+ m[0][1] * m[1][2] * m[3][0]
			+ m[0][2] * m[1][0] * m[3][1]);
			*/

			////////
		 - m[3][0] * (
			- m[2][1] * m[1][2] * m[0][3]
			- m[2][2] * m[1][3] * m[0][1]
			- m[2][3] * m[1][1] * m[0][2]
			+ m[0][1] * m[1][2] * m[2][3]
			+ m[0][2] * m[1][3] * m[2][1]
			+ m[0][3] * m[1][1] * m[2][2]) +

			m[3][1] * (
				- m[2][0] * m[1][2] * m[0][3]
				- m[2][2] * m[1][3] * m[0][0]
				- m[2][3] * m[1][0] * m[0][2]
				+ m[0][0] * m[1][2] * m[2][3]
				+ m[0][2] * m[1][3] * m[2][0]
				+ m[0][3] * m[1][0] * m[2][2]) -

			m[3][2] * (
				- m[2][0] * m[1][1] * m[0][3]
				- m[2][1] * m[1][3] * m[0][0]
				- m[2][3] * m[1][0] * m[0][1]
				+ m[0][0] * m[1][1] * m[2][3]
				+ m[0][1] * m[1][3] * m[2][0]
				+ m[0][3] * m[1][0] * m[2][1]) +

			m[3][3] * (
				- m[2][0] * m[1][1] * m[0][2]
				- m[2][1] * m[1][2] * m[0][0]
				- m[2][2] * m[1][0] * m[0][1]
				+ m[0][0] * m[1][1] * m[2][2]
				+ m[0][1] * m[1][2] * m[2][0]
				+ m[0][2] * m[1][0] * m[2][1]);
		

}

Mat4& Mat4::minor()
{
	Mat4 result(0);
	result.m[0][0] = (
		- m[3][1] * m[2][2] * m[1][3]
		- m[3][2] * m[2][3] * m[1][1]
		- m[3][3] * m[2][1] * m[1][2]
		+ m[1][1] * m[2][2] * m[3][3]
		+ m[1][2] * m[2][3] * m[3][1]
		+ m[1][3] * m[2][1] * m[3][2]);

	result.m[0][1] =   (
		- m[3][0] * m[2][2] * m[1][3]
		- m[3][2] * m[2][3] * m[1][0]
		- m[3][3] * m[2][0] * m[1][2]
		+ m[1][0] * m[2][2] * m[3][3]
		+ m[1][2] * m[2][3] * m[3][0]
		+ m[1][3] * m[2][0] * m[3][2]);

	result.m[0][2] =  (
		- m[3][0] * m[2][1] * m[1][3]
		- m[3][1] * m[2][3] * m[1][0]
		- m[3][3] * m[2][0] * m[1][1]
		+ m[1][0] * m[2][1] * m[3][3]
		+ m[1][1] * m[2][3] * m[3][0]
		+ m[1][3] * m[2][0] * m[3][1]);

	result.m[0][3] =  (
		- m[3][0] * m[2][1] * m[1][2]
		- m[3][1] * m[2][2] * m[1][0]
		- m[3][2] * m[2][0] * m[1][1]
		+ m[1][0] * m[2][1] * m[3][2]
		+ m[1][1] * m[2][2] * m[3][0]
		+ m[1][2] * m[2][0] * m[3][1]);	

	/////////////////

	result.m[1][0] =  (
		- m[3][1] * m[2][2] * m[0][3]
		- m[3][2] * m[2][3] * m[0][1]
		- m[3][3] * m[2][1] * m[0][2]
		+ m[0][1] * m[2][2] * m[3][3]
		+ m[0][2] * m[2][3] * m[3][1]
		+ m[0][3] * m[2][1] * m[3][2]);


	result.m[1][1] =  (
		- m[3][0] * m[2][2] * m[0][3]
		- m[3][2] * m[2][3] * m[0][0]
		- m[3][3] * m[2][0] * m[0][2]
		+ m[0][0] * m[2][2] * m[3][3]
		+ m[0][2] * m[2][3] * m[3][0]
		+ m[0][3] * m[2][0] * m[3][2]);

	result.m[1][2] =  (
		- m[3][0] * m[2][1] * m[0][3]
		- m[3][1] * m[2][3] * m[0][0]
		- m[3][3] * m[2][0] * m[0][1]
		+ m[0][0] * m[2][1] * m[3][3]
		+ m[0][1] * m[2][3] * m[3][0]
		+ m[0][3] * m[2][0] * m[3][1]);


	result.m[1][3] =  (
	- m[3][0] * m[2][1] * m[0][2]
	- m[3][1] * m[2][2] * m[0][0]
	- m[3][2] * m[2][0] * m[0][1]
	+ m[0][0] * m[2][1] * m[3][2]
	+ m[0][1] * m[2][2] * m[3][0]
	+ m[0][2] * m[2][0] * m[3][1]);

	/////////

	result.m[2][0] =  (
		- m[3][1] * m[1][2] * m[0][3]
		- m[3][2] * m[1][3] * m[0][1]
		- m[3][3] * m[1][1] * m[0][2]
		+ m[0][1] * m[1][2] * m[3][3]
		+ m[0][2] * m[1][3] * m[3][1]
		+ m[0][3] * m[1][1] * m[3][2]);

	result.m[2][1] =  (
		- m[3][0] * m[1][2] * m[0][3]
		- m[3][2] * m[1][3] * m[0][0]
		- m[3][3] * m[1][0] * m[0][2]
		+ m[0][0] * m[1][2] * m[3][3]
		+ m[0][2] * m[1][3] * m[3][0]
		+ m[0][3] * m[1][0] * m[3][2]);

	result.m[2][2] =  (
		- m[3][0] * m[1][1] * m[0][3]
		- m[3][1] * m[1][3] * m[0][0]
		- m[3][3] * m[1][0] * m[0][1]
		+ m[0][0] * m[1][1] * m[3][3]
		+ m[0][1] * m[1][3] * m[3][0]
		+ m[0][3] * m[1][0] * m[3][1]);

	result.m[2][3] =  (
	- m[3][0] * m[1][1] * m[0][2]
	- m[3][1] * m[1][2] * m[0][0]
	- m[3][2] * m[1][0] * m[0][1]
	+ m[0][0] * m[1][1] * m[3][2]
	+ m[0][1] * m[1][2] * m[3][0]
	+ m[0][2] * m[1][0] * m[3][1]);
	

	////////
	result.m[3][0] =  (
		-m[2][1] * m[1][2] * m[0][3]
		- m[2][2] * m[1][3] * m[0][1]
		- m[2][3] * m[1][1] * m[0][2]
		+ m[0][1] * m[1][2] * m[2][3]
		+ m[0][2] * m[1][3] * m[2][1]
		+ m[0][3] * m[1][1] * m[2][2]);

	result.m[3][1] =  (
		- m[2][0] * m[1][2] * m[0][3]
		- m[2][2] * m[1][3] * m[0][0]
		- m[2][3] * m[1][0] * m[0][2]
		+ m[0][0] * m[1][2] * m[2][3]
		+ m[0][2] * m[1][3] * m[2][0]
		+ m[0][3] * m[1][0] * m[2][2]);


	result.m[3][2] =  (
		- m[2][0] * m[1][1] * m[0][3]
		- m[2][1] * m[1][3] * m[0][0]
		- m[2][3] * m[1][0] * m[0][1]
		+ m[0][0] * m[1][1] * m[2][3]
		+ m[0][1] * m[1][3] * m[2][0]
		+ m[0][3] * m[1][0] * m[2][1]);

	result.m[3][3] =  (
			- m[2][0] * m[1][1] * m[0][2]
			- m[2][1] * m[1][2] * m[0][0]
			- m[2][2] * m[1][0] * m[0][1]
			+ m[0][0] * m[1][1] * m[2][2]
			+ m[0][1] * m[1][2] * m[2][0]
			+ m[0][2] * m[1][0] * m[2][1]);

	*this = result;
	return *this;
}

Mat4& Mat4::cofactor()
{
	Mat4 result(0);
	result = this->minor();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((i + j) % 2 != 0)
			{
				result.m[i][j] = -1 * result.m[i][j];
			}
		}		
	}
	*this = result;
	return *this;
}

Mat4& Mat4::transpose()
{
	Mat4 result(0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.m[i][j] = m[j][i];
			
		}
	}
	
	*this = result;
	return *this;
}

Mat4& Mat4::scl(float sclvalue)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m[i][j] = m[i][j] * sclvalue;
		}
	}
	return *this;
}

Mat4& Mat4::inverse()
{
	Mat4 result(0);
	float deter = this->det();
	result = *this;
	result.cofactor();
	result.transpose();
	result.scl(1 / deter);

	*this = result;
	return *this;
}