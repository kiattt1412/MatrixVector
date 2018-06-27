#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <crtdbg.h>
#include <memory>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#define _CRTDBG_MAP_ALLOC

#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Mat4.h"

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cout << " - Vector 2D - " << endl;
	Vec2<float> v1(1, 1);
	Vec2<float> v2(2, 2);
	Vec2<float> v3(3, 5);

	cout << endl;
	cout << " (1,1) Magnitude : " << v1.calMagnitude() << endl;
	cout << " (1,1) MagnitudeSq : " << v1.calMagnitudeSq() << endl;
	Vec2<float> v1add57 = v1.add(Vec2<float>(5, 7));
	Vec2<float> v1sub57 = v1.subtract(Vec2<float>(5, 7));
	cout << " v1 Add (5,7) : " << "(" << v1add57.x << "," << v1add57.y <<")" << endl;
	Vec2<float> v1plus = Vec2<float>(1, 2) + Vec2<float>(2, 3);
	cout << " (1,2) + (2,3) : " << "(" << v1plus.x << "," << v1plus.y << ")" <<endl;
	v1plus += Vec2<float>(2,3);
	cout << " (3,5) += (2,3) : " << "(" << v1plus.x << "," << v1plus.y << ")" << endl;
	v1plus -= Vec2<float>(2,3);
	cout << " (5,8) -= (2,3) : " << "(" << v1plus.x << "," << v1plus.y << ")" << endl;
	Vec2<float> v25(2, 5);
	Vec2<float> vrsMul = v25 * 3;
	cout << " (2,5) * 3 : " << "(" << vrsMul.x << "," << vrsMul.y << ")" << endl;
	vrsMul *= 2;
	cout << " (6,15) *= 2 : " << "(" << vrsMul.x << "," << vrsMul.y << ")" << endl;
	Vec2<float> v26(2, 6);
	Vec2<float> vrsDiv = v26 / 3;
	cout << " (2,6) / 3 : " << "(" << vrsDiv.x << "," << vrsDiv.y << ")" << endl;
	vrsDiv /= 2;
	cout << " (0.67,2) /= 2 : " << "(" << vrsDiv.x << "," << vrsDiv.y << ")" << endl;
	cout << " v1 Sub (5,7) : " << "(" << v1sub57.x << "," << v1sub57.y << ")" << endl;
	cout << " (2,2) dot (3,5) : " << v2.dot(v3) << endl;
	cout << " (2,2) cross (3,5) : " << v2.cross(v3) << endl;
	cout << " v1 add (3,4) Magnitude : " << Vec2<float>(1,1).add(Vec2<float>(2, 3)).calMagnitude() << endl;
	cout << " v1 Angle : " << v1.angle(Vec2<float>(1,0)) << endl;
	cout << " Distance (0,0) and (3,4) : " << Vec2<float>(0, 0).distance(Vec2<float>(3, 4)) << endl;
	cout << " (3,5) scaled by 5 :" << Vec2<float>(3, 5).scale(5).x << "," << Vec2<float>(3, 5).scale(5).y << endl << endl;
	cout << " (4,4) angle (5,5) :" << Vec2<float>(4, 4).angle(Vec2<float>(5, 5)) << endl;
	cout << " (0,5) angle (5,0) :" << Vec2<float>(0, 5).angle(Vec2<float>(5, 0)) << endl;
	cout << " (5,0) angle (2,5) :" << Vec2<float>(5, 0).angle(Vec2<float>(2, 5)) << endl;
	cout << " (2,5) angle (5,0) :" << Vec2<float>(2, 5).angle(Vec2<float>(5, 0)) << endl;
	cout << " ------------------------------------------------------------------------- " << endl << endl; 
	cout << " - Vector 3D - " << endl << endl;
	Vec3<float> v4(1, 1, 1);
	cout << " v4(1,1,1) - X : " << v4.x << " ,Y : " << v4.y << " ,Z : " << v4.z << endl;
	cout << " v4 Magnitude : " << v4.magnitude << endl;
	cout << " v4 MagnitudeSq : " << v4.magnitudeSq << endl;
	cout << " (2,3,5) + (6,1,1) : (" << Vec3<float>(2, 3, 5).add(Vec3<float>(6,1,1)).x << "," << Vec3<float>(2, 3, 5).add(Vec3<float>(6, 1, 1)).y << "," << Vec3<float>(2, 3, 5).add(Vec3<float>(6, 1, 1)).z << ")" << endl;
	cout << " (2,3,5) - (6,1,1) : (" << Vec3<float>(2, 3, 5).subtract(Vec3<float>(6, 1, 1)).x << "," << Vec3<float>(2, 3, 5).subtract(Vec3<float>(6, 1, 1)).y << "," << Vec3<float>(2, 3, 5).subtract(Vec3<float>(6, 1, 1)).z << ")" << endl;
	Vec3<float> v0(0, 0, 0);
	v0 += Vec3<float>(1, 1, 1);
	cout << " (0,0,0) += (1,1,1) : " << "(" << v0.x << "," << v0.y << "," << v0.z << ")" << endl;
	v0 *= 5;
	cout << " (1,1,1) *= 5 : " << "(" << v0.x << "," << v0.y << "," << v0.z << ")" << endl;
	v0 /= 2;
	cout << " (5,5,5) /= 2 : " << "(" << v0.x << "," << v0.y << "," << v0.z << ")" << endl;
	v0 -= Vec3<float>(0.5,0.5,0.5);
	cout << " (2.5,2.5,2.5) -= (0.5,0.5,0.5) : " << "(" << v0.x << "," << v0.y << "," << v0.z << ")" << endl;
	cout << " (2,3,5) dot (6,1,1) : " << Vec3<float>(2, 3, 5).dot(Vec3<float>(6, 1, 1)) << endl;
	cout << " (1,2,3) cross (1,5,7) : " << Vec3<float>(1, 2, 3).cross(Vec3<float>(1, 5, 7)).x << "," << Vec3<float>(1, 2, 3).cross(Vec3<float>(1, 5, 7)).y << "," << Vec3<float>(1, 2, 3).cross(Vec3<float>(1, 5, 7)).z << endl;
	cout << " Angle between (1,2,3) and (1,5,7) : " << Vec3<float>(1, 2, 3).angle(Vec3<float>(1, 5, 7)) << endl;
	cout << " Distance (7,4,3) and (17,6,2) : " << Vec3<float>(7, 4, 3).distance(Vec3<float>(17, 6, 2)) << endl;
	Vec4<float> v4d(1, 1, 1, 1);
	v4d += Vec4<float>(1, 1, 1, 1);
	v4d.print();
	cout << " ------------------------------------------------------------------------- " << endl << endl;
	cout << " - Mat4 - " << endl << endl;

	Mat4 mat1(Vec4<float>(1,3,5,4), Vec4<float>(1, 3, 5, 1), Vec4<float>(2, 3, 4, 9), Vec4<float>(1, 3, 2, 1));
	Mat4 mat11(Vec4<float>(1, 3, 5, 4), Vec4<float>(1, 3, 5, 1), Vec4<float>(2, 3, 4, 9), Vec4<float>(1, 3, 2, 1));
	Mat4 mat2(Vec4<float>(2, 2, 3, 4), Vec4<float>(5, 6, 7, 8), Vec4<float>(3, 4, 5, 6), Vec4<float>(-1, 3, 5, 2));
	Mat4 mat22(Vec4<float>(2, 2, 3, 4), Vec4<float>(5, 6, 7, 8), Vec4<float>(3, 4, 5, 6), Vec4<float>(-1, 3, 5, 2));
	Mat4 mat3(Vec4<float>(1, 9, -3, -41), Vec4<float>(52, -6, 17, -8), Vec4<float>(-300, 4, 15, -25), Vec4<float>(-1, 3, 5, 2));
	Mat4 mat33(Vec4<float>(1, 9, -3, -41), Vec4<float>(52, -6, 17, -8), Vec4<float>(-300, 4, 15, -25), Vec4<float>(-1, 3, 5, 2));
	Mat4 mat0(0);
	Mat4 mat4(4);
	Mat4 mat5(5);
	Mat4 matone(Vec4<float>(3, 1, 2, 3), Vec4<float>(1, 7, 2, 3), Vec4<float>(1, 2, 1, 1), Vec4<float>(2, 0,1, 2));
	
	cout << " Mat 3 " << endl;
	mat3.print();
	cout << " Mat 3 Inverse " << endl;
	mat33.inverse().print();
	cout << " Mat3 * Mat 33 Inverse " << endl;
	Mat4 mati = mat3 * mat33;
	mati.print();
	cout << " Mat 1 " << endl;
	mat1.print();
	mat1.transpose();
	cout << " Mat 1 Transpose " << endl;
	mat1.print();
	

	getchar();
	return 0;

}
