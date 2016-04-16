#ifndef MATRIX_H
#define MATRIX_H

#include <math/Vector.hpp>

namespace GE
{
namespace Math
{
	
class Matrix2;
class Matrix3;
class Matrix4;

//Matrix2

/*
| 0 2 |
| 1 3 |
*/

class Matrix2
{
public:
	union //Matrix data
	{
		struct { //Individual access
			float v00, v10;
			float v01, v11;
		};
		float d1[4]; //1D access
		float d2[2][2]; //2D access
	};
	//Operators - on same object type
	Matrix2& operator+=(const Matrix2 &rhs);
	Matrix2 operator+(const Matrix2 &rhs);
	Matrix2& operator*=(const Matrix2 &rhs);
	Matrix2 operator*(const Matrix2 &rhs);
	bool operator==(const Matrix2 &rhs);
	bool operator!=(const Matrix2 &rhs);
	//Operators - on Vector2
	Vector2 operator*(const Vector2& rhs);
	//Operators - on floats
	Matrix2& operator*=(const float& rhs);
	Matrix2 operator*(const float& rhs);
	//Functions
	float Det();
	static Matrix2 Identity();
	Matrix2 Transpose();
	Matrix2 Inverse();
	Vector2 Row(unsigned row);
	Vector2 Col(unsigned col);
	void SetRow(Vector2 &row, unsigned row_num);
	void SetCol(Vector2 &col, unsigned col_num);
};

Matrix2 operator*(const float& lhs, const Matrix2 &rhs);

//Matrix3

/*
| 0 3 6 |
| 1 4 7 |
| 2 5 8 |
*/

class Matrix3
{
public:
	union //Matrix data
	{
		struct { //Individual access
			float v00, v10, v20;
			float v01, v11, v21;
			float v02, v12, v22;
		};
		float d1[9]; //1D access
		float d2[3][3]; //2D access
	};
	//Operators - on same object type
	Matrix3& operator+=(const Matrix3 &rhs);
	Matrix3 operator+(const Matrix3 &rhs);
	Matrix3& operator*=(const Matrix3 &rhs);
	Matrix3 operator*(const Matrix3 &rhs);
	//Operators - on Vector3
	Vector3 operator*(const Vector3 &rhs);
	//Operators - on floats
	Matrix3& operator*=(const float &rhs);
	Matrix3 operator*(const float &rhs);
	//Functions
	float Det();
	static Matrix3 Identity();
	Matrix3 Transpose();
	Matrix3 Inverse();
	Vector3 Row(unsigned row);
	Vector3 Col(unsigned col);
	void SetRow(Vector3 &row, unsigned row_num);
	void SetCol(Vector3 &col, unsigned col_num);
	Matrix4 ToMatrix4();
};

//Matrix4

/*
| 0   4   8  12 |
| 1   5   9  13 |
| 2   6  10  14 |
| 3   7  11  15 |
*/

class Matrix4
{
public:
	union //Matrix data
	{
		struct { //Individual access
			float v00, v10, v20, v30;
			float v01, v11, v21, v31;
			float v02, v12, v22, v32;
			float v03, v13, v23, v33;
		};
		float d1[16]; //1D access
		float d2[4][4]; //2D access
	};
	//Operators - on same object type
	Matrix4& operator+=(const Matrix4 &rhs);
	Matrix4 operator+(const Matrix4 &rhs);
	Matrix4& operator*=(const Matrix4 &rhs);
	Matrix4 operator*(const Matrix4 &rhs);
	//Operators - on Vector4
	Vector4 operator*(const Vector4& rhs);
	//Operators - on floats
	Matrix4& operator*=(const float& rhs);
	Matrix4 operator*(const float& rhs);
	//Functions
	float Det();
	static Matrix4 Identity();
	Matrix4 Transpose();
	Matrix4 Inverse();
	Vector4 Row(unsigned row);
	Vector4 Col(unsigned col);
	void SetRow(Vector4 row, unsigned row_num);
	void SetCol(Vector4 col, unsigned col_num);
};

} //End of namespace "Math"
} //End of namespace "GE"

#endif // MATRIX_H
