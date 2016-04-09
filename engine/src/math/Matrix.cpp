#include <cmath>

#include <math/Vector.hpp>
#include <math/Matrix.hpp>

namespace GE
{
namespace Math
{
	
//
// Matrix2
//
	
Matrix2& Matrix2::operator+=(const Matrix2 &rhs)
{
    d1[0] += rhs.d1[0];
    d1[1] += rhs.d1[1];
    d1[2] += rhs.d1[2];
    d1[3] += rhs.d1[3];
    return *this;
}

Matrix2 Matrix2::operator+(const Matrix2 &rhs)
{
    Matrix2 result;
    result.d1[0] = d1[0] + rhs.d1[0];
    result.d1[1] = d1[1] + rhs.d1[1];
    result.d1[2] = d1[2] + rhs.d1[2];
    result.d1[3] = d1[3] + rhs.d1[3];
    return result;
}

Matrix2& Matrix2::operator*=(const Matrix2 &rhs)
{
    Matrix2 result;
    result.v00 = v00 * rhs.v00 + v01 * rhs.v10;
    result.v10 = v10 * rhs.v00 + v11 * rhs.v10;
    result.v01 = v00 * rhs.v01 + v01 * rhs.v11;
    result.v11 = v10 * rhs.v01 + v11 * rhs.v11;
    *this = result;
    return *this;
}

Matrix2 Matrix2::operator*(const Matrix2 &rhs)
{
    Matrix2 result;
    result.v00 = v00 * rhs.v00 + v01 * rhs.v10;
    result.v10 = v10 * rhs.v00 + v11 * rhs.v10;
    result.v01 = v00 * rhs.v01 + v01 * rhs.v11;
    result.v11 = v10 * rhs.v01 + v11 * rhs.v11;
    return result;
}

Vector2 Matrix2::operator*(const Vector2& rhs)
{
    Vector2 result;
    result.x = v00 * rhs.x * v01 * rhs.y;
    result.y = v10 * rhs.x * v11 * rhs.y;
    return result;
}

Matrix2& Matrix2::operator*=(const float& rhs)
{
    d1[0] *= rhs;
    d1[1] *= rhs;
    d1[2] *= rhs;
    d1[3] *= rhs;
    return *this;
}

Matrix2 Matrix2::operator*(const float& rhs)
{
    Matrix2 result;
    result.d1[0] = d1[0] * rhs;
    result.d1[1] = d1[1] * rhs;
    result.d1[2] = d1[2] * rhs;
    result.d1[3] = d1[3] * rhs;
    return result;
}

Matrix2 operator*(const float &lhs, const Matrix2 &rhs)
{
    Matrix2 result;
    result.d1[0] = lhs * rhs.d1[0];
    result.d1[1] = lhs * rhs.d1[1];
    result.d1[2] = lhs * rhs.d1[2];
    result.d1[3] = lhs * rhs.d1[3];
    return result;
}

float Matrix2::Det()
{
    return v00 * v11 - v10 * v01;
}

Matrix2 Matrix2::Identity()
{
    Matrix2 identity;
    identity.v00 = 1.0f;
    identity.v10 = 0.0f;
    identity.v01 = 0.0f;
    identity.v11 = 1.0f;
    return identity;
}

Matrix2 Matrix2::Inverse()
{
    float inv_det = 1.0f / Det();
    Matrix2 result;
    result.v00 = v11 * inv_det;
    result.v10 = -v01 * inv_det;
    result.v01 = -v10 * inv_det;
    result.v11 = v00 * inv_det;
    return result;
}

Matrix2 Matrix2::Transpose()
{
    Matrix2 result;
    result.v00 = v00;
    result.v10 = v01;
    result.v01 = v10;
    result.v11 = v11;
    return result;
}

Vector2 Matrix2::Row(unsigned row)
{
    return Vector2(d2[row][0],d2[row][1]);
}

Vector2 Matrix2::Col(unsigned col)
{
    return Vector2(d2[0][col],d2[1][col]);
}

void Matrix2::SetRow(Vector2 &row, unsigned row_num)
{
    d2[row_num][0] = row.x;
    d2[row_num][1] = row.y;
}

void Matrix2::SetCol(Vector2 &col, unsigned col_num)
{
    d2[0][col_num] = col.x;
    d2[1][col_num] = col.y;
}

//
// Matrix3
//

Matrix3 Matrix3::operator+(const Matrix3 &rhs)
{
    Matrix3 result;
    result.d1[0] = d1[0] + rhs.d1[0];
    result.d1[1] = d1[1] + rhs.d1[1];
    result.d1[2] = d1[2] + rhs.d1[2];
    result.d1[3] = d1[3] + rhs.d1[3];
    result.d1[4] = d1[4] + rhs.d1[4];
    result.d1[5] = d1[5] + rhs.d1[5];
    result.d1[6] = d1[6] + rhs.d1[6];
    result.d1[7] = d1[7] + rhs.d1[7];
    result.d1[8] = d1[8] + rhs.d1[8];
    return result;
}

Matrix3& Matrix3::operator+=(const Matrix3 &rhs)
{
    d1[0] += rhs.d1[0];
    d1[1] += rhs.d1[1];
    d1[2] += rhs.d1[2];
    d1[3] += rhs.d1[3];
    d1[4] += rhs.d1[4];
    d1[5] += rhs.d1[5];
    d1[6] += rhs.d1[6];
    d1[7] += rhs.d1[7];
    d1[8] += rhs.d1[8];
    return *this;
}

Matrix3 Matrix3::operator*(const Matrix3 &rhs)
{
    Matrix3 result;

    result.v00 = v00 * rhs.v00 + v01 * rhs.v10 + v02 * rhs. v20;
    result.v10 = v10 * rhs.v00 + v11 * rhs.v10 + v12 * rhs. v20;
    result.v20 = v20 * rhs.v00 + v21 * rhs.v10 + v22 * rhs. v20;
    result.v01 = v00 * rhs.v01 + v01 * rhs.v11 + v02 * rhs. v21;
    result.v11 = v10 * rhs.v01 + v11 * rhs.v11 + v12 * rhs. v21;
    result.v21 = v20 * rhs.v01 + v21 * rhs.v11 + v22 * rhs. v21;
    result.v02 = v00 * rhs.v02 + v01 * rhs.v12 + v02 * rhs. v22;
    result.v12 = v10 * rhs.v02 + v11 * rhs.v12 + v12 * rhs. v22;
    result.v22 = v20 * rhs.v02 + v21 * rhs.v12 + v22 * rhs. v22;

    return result;
}

Matrix3& Matrix3::operator*=(const Matrix3 &rhs)
{
    *this = *this * rhs;
    return *this;
}

Vector3 Matrix3::operator*(const Vector3& rhs)
{
    Vector3 result;
    result.x = v00 * rhs.x + v01 * rhs.y + v02 * rhs.z;
    result.y = v10 * rhs.x + v11 * rhs.y + v12 * rhs.z;
    result.z = v20 * rhs.x + v21 * rhs.y + v22 * rhs.z;
    return result;
}

Matrix3& Matrix3::operator*=(const float& rhs)
{
    d1[0] *= rhs;
    d1[1] *= rhs;
    d1[2] *= rhs;
    d1[3] *= rhs;
    d1[4] *= rhs;
    d1[5] *= rhs;
    d1[6] *= rhs;
    d1[7] *= rhs;
    d1[8] *= rhs;
    return *this;
}

Matrix3 Matrix3::operator*(const float& rhs)
{
    Matrix3 result;
    result.d1[0] = d1[0] * rhs;
    result.d1[1] = d1[1] * rhs;
    result.d1[2] = d1[2] * rhs;
    result.d1[3] = d1[3] * rhs;
    result.d1[4] = d1[4] * rhs;
    result.d1[5] = d1[5] * rhs;
    result.d1[6] = d1[6] * rhs;
    result.d1[7] = d1[7] * rhs;
    result.d1[8] = d1[8] * rhs;
    return result;
}

Matrix3 operator*(const float &lhs, const Matrix3 &rhs)
{
    Matrix3 result;
    result.d1[0] = lhs * rhs.d1[0];
    result.d1[1] = lhs * rhs.d1[1];
    result.d1[2] = lhs * rhs.d1[2];
    result.d1[3] = lhs * rhs.d1[3];
    result.d1[4] = lhs * rhs.d1[4];
    result.d1[5] = lhs * rhs.d1[5];
    result.d1[6] = lhs * rhs.d1[6];
    result.d1[7] = lhs * rhs.d1[7];
    result.d1[8] = lhs * rhs.d1[8];
    return result;
}

float Matrix3::Det()
{
    return (v00 * (v11 * v22 - v12 * v21) -
            v01 * (v10 * v22 - v20 * v12) +
            v02 * (v10 * v21 - v20 * v11));
}

Matrix3 Matrix3::Identity()
{
    Matrix3 identity;
	identity.v00 = 1.0f;
	identity.v10 = 0.0f;
	identity.v20 = 0.0f;
    identity.v01 = 0.0f;
	identity.v11 = 1.0f;
    identity.v21 = 0.0f;
    identity.v02 = 0.0f;
    identity.v12 = 0.0f;
    identity.v22 = 1.0f;
    return identity;
}

Matrix3 Matrix3::Inverse()
{
    float inv_det = 1.0f / Det();
    Matrix3 result;
    result.v00 = (v11 * v22 - v21 * v12) * inv_det;
    result.v10 = (v12 * v20 - v22 * v10) * inv_det;
    result.v20 = (v10 * v21 - v20 * v11) * inv_det;
    result.v01 = (v02 * v21 - v22 * v01) * inv_det;
    result.v11 = (v00 * v22 - v20 * v02) * inv_det;
    result.v21 = (v01 * v20 - v21 * v00) * inv_det;
    result.v02 = (v01 * v12 - v11 * v02) * inv_det;
    result.v12 = (v02 * v10 - v12 * v00) * inv_det;
    result.v22 = (v00 * v11 - v10 * v01) * inv_det;
    return result;
}

Matrix3 Matrix3::Transpose()
{
    Matrix3 result;
    result.v00 = v00;
    result.v10 = v01;
    result.v20 = v02;
    result.v01 = v10;
    result.v11 = v11;
    result.v21 = v12;
    result.v02 = v20;
    result.v12 = v21;
    result.v22 = v22;
    return result;
}

Vector3 Matrix3::Row(unsigned row)
{
    return Vector3(d2[row][0],d2[row][1],d2[row][2]);
}

Vector3 Matrix3::Col(unsigned col)
{
    return Vector3(d2[0][col],d2[1][col],d2[2][col]);
}

void Matrix3::SetRow(Vector3 &row, unsigned row_num)
{
    d2[row_num][0] = row.x;
    d2[row_num][1] = row.y;
    d2[row_num][2] = row.z;
}

void Matrix3::SetCol(Vector3 &col, unsigned col_num)
{
    d2[0][col_num] = col.x;
    d2[1][col_num] = col.y;
    d2[2][col_num] = col.z;
}

Matrix4 Matrix3::ToMatrix4()
{
    Matrix4 result;
    result.v00 = v00;
    result.v10 = v10;
    result.v20 = v20;
    result.v30 = 0.0f;
    result.v01 = v01;
    result.v11 = v11;
    result.v21 = v21;
    result.v31 = 0.0f;
    result.v02 = v02;
    result.v12 = v12;
    result.v22 = v22;
    result.v32 = 0.0f;
    result.v03 = 0.0f;
    result.v13 = 0.0f;
    result.v23 = 0.0f;
    result.v33 = 0.0f;
    return result;
}

//
//Matrix4
//

Matrix4 Matrix4::operator+(const Matrix4 &rhs)
{
    Matrix4 result;
    result.d1[0] = d1[0] + rhs.d1[0];
    result.d1[1] = d1[1] + rhs.d1[1];
    result.d1[2] = d1[2] + rhs.d1[2];
    result.d1[3] = d1[3] + rhs.d1[3];
    result.d1[4] = d1[4] + rhs.d1[4];
    result.d1[5] = d1[5] + rhs.d1[5];
    result.d1[6] = d1[6] + rhs.d1[6];
    result.d1[7] = d1[7] + rhs.d1[7];
    result.d1[8] = d1[8] + rhs.d1[8];
    result.d1[9] = d1[9] + rhs.d1[9];
    result.d1[10] = d1[10] + rhs.d1[10];
    result.d1[11] = d1[11] + rhs.d1[11];
    result.d1[12] = d1[12] + rhs.d1[12];
    result.d1[13] = d1[13] + rhs.d1[13];
    result.d1[14] = d1[14] + rhs.d1[14];
    result.d1[15] = d1[15] + rhs.d1[15];
    return result;
}

Matrix4& Matrix4::operator+=(const Matrix4 &rhs)
{
    d1[0] += rhs.d1[0];
    d1[1] += rhs.d1[1];
    d1[2] += rhs.d1[2];
    d1[3] += rhs.d1[3];
    d1[4] += rhs.d1[4];
    d1[5] += rhs.d1[5];
    d1[6] += rhs.d1[6];
    d1[7] += rhs.d1[7];
    d1[8] += rhs.d1[8];
    d1[9] += rhs.d1[9];
    d1[10] += rhs.d1[10];
    d1[11] += rhs.d1[11];
    d1[12] += rhs.d1[12];
    d1[13] += rhs.d1[13];
    d1[14] += rhs.d1[14];
    d1[15] += rhs.d1[15];
    return *this;
}

//
Matrix4 Matrix4::operator*(const Matrix4 &rhs)
{
    Matrix4 result;

    result.v00 = v00 * rhs.v00 + v01 * rhs.v10 + v02 * rhs. v20 + v03 * rhs. v30;
    result.v10 = v10 * rhs.v00 + v11 * rhs.v10 + v12 * rhs. v20 + v13 * rhs. v30;
    result.v20 = v20 * rhs.v00 + v21 * rhs.v10 + v22 * rhs. v20 + v23 * rhs. v30;
    result.v30 = v30 * rhs.v00 + v31 * rhs.v10 + v32 * rhs. v20 + v33 * rhs. v30;

    result.v01 = v00 * rhs.v01 + v01 * rhs.v11 + v02 * rhs. v21 + v03 * rhs. v31;
    result.v11 = v10 * rhs.v01 + v11 * rhs.v11 + v12 * rhs. v21 + v13 * rhs. v31;
    result.v21 = v20 * rhs.v01 + v21 * rhs.v11 + v22 * rhs. v21 + v23 * rhs. v31;
    result.v31 = v30 * rhs.v01 + v31 * rhs.v11 + v32 * rhs. v21 + v33 * rhs. v31;

    result.v02 = v00 * rhs.v02 + v01 * rhs.v12 + v02 * rhs. v22 + v03 * rhs. v32;
    result.v12 = v10 * rhs.v02 + v11 * rhs.v12 + v12 * rhs. v22 + v13 * rhs. v32;
    result.v22 = v20 * rhs.v02 + v21 * rhs.v12 + v22 * rhs. v22 + v23 * rhs. v32;
    result.v32 = v30 * rhs.v02 + v31 * rhs.v12 + v32 * rhs. v22 + v33 * rhs. v32;

    result.v03 = v00 * rhs.v03 + v01 * rhs.v13 + v02 * rhs. v23 + v03 * rhs. v33;
    result.v13 = v10 * rhs.v03 + v11 * rhs.v13 + v12 * rhs. v23 + v13 * rhs. v33;
    result.v23 = v20 * rhs.v03 + v21 * rhs.v13 + v22 * rhs. v23 + v23 * rhs. v33;
    result.v33 = v30 * rhs.v03 + v31 * rhs.v13 + v32 * rhs. v23 + v33 * rhs. v33;

    return result;
}

Matrix4& Matrix4::operator*=(const Matrix4 &rhs)
{
    *this = *this * rhs;
    return *this;
}

Vector4 Matrix4::operator*(const Vector4& rhs)
{
    Vector4 result;
    result.x = v00 * rhs.x + v01 * rhs.y + v02 * rhs.z + v03 * rhs.w;
    result.y = v10 * rhs.x + v11 * rhs.y + v12 * rhs.z + v13 * rhs.w;
    result.z = v20 * rhs.x + v21 * rhs.y + v22 * rhs.z + v23 * rhs.w;
    result.w = v30 * rhs.x + v31 * rhs.y + v32 * rhs.z + v33 * rhs.w;
    return result;
}

Matrix4& Matrix4::operator*=(const float& rhs)
{
    d1[0] *= rhs;
    d1[1] *= rhs;
    d1[2] *= rhs;
    d1[3] *= rhs;
    d1[4] *= rhs;
    d1[5] *= rhs;
    d1[6] *= rhs;
    d1[7] *= rhs;
    d1[8] *= rhs;
    d1[9] *= rhs;
    d1[10] *= rhs;
    d1[11] *= rhs;
    d1[12] *= rhs;
    d1[13] *= rhs;
    d1[14] *= rhs;
    d1[15] *= rhs;
    return *this;
}

Matrix4 Matrix4::operator*(const float& rhs)
{
    Matrix4 result;
    result.d1[0] = d1[0] * rhs;
    result.d1[1] = d1[1] * rhs;
    result.d1[2] = d1[2] * rhs;
    result.d1[3] = d1[3] * rhs;
    result.d1[4] = d1[4] * rhs;
    result.d1[5] = d1[5] * rhs;
    result.d1[6] = d1[6] * rhs;
    result.d1[7] = d1[7] * rhs;
    result.d1[8] = d1[8] * rhs;
    result.d1[9] = d1[9] * rhs;
    result.d1[10] = d1[10] * rhs;
    result.d1[11] = d1[11] * rhs;
    result.d1[12] = d1[12] * rhs;
    result.d1[13] = d1[13] * rhs;
    result.d1[14] = d1[14] * rhs;
    result.d1[15] = d1[15] * rhs;
    return result;
}

Matrix4 operator*(const float &lhs, const Matrix4 &rhs)
{
    Matrix4 result;
    result.d1[0] = lhs * rhs.d1[0];
    result.d1[1] = lhs * rhs.d1[1];
    result.d1[2] = lhs * rhs.d1[2];
    result.d1[3] = lhs * rhs.d1[3];
    result.d1[4] = lhs * rhs.d1[4];
    result.d1[5] = lhs * rhs.d1[5];
    result.d1[6] = lhs * rhs.d1[6];
    result.d1[7] = lhs * rhs.d1[7];
    result.d1[8] = lhs * rhs.d1[8];
    return result;
}

float Matrix4::Det()
{
    float b00 = v00*v11 - v01*v10;
    float b01 = v00*v12 - v02*v10;
    float b02 = v00*v13 - v03*v10;
    float b03 = v01*v12 - v02*v11;
    float b04 = v01*v13 - v03*v11;
    float b05 = v02*v13 - v03*v12;
    float b06 = v20*v31 - v21*v30;
    float b07 = v20*v32 - v22*v30;
    float b08 = v20*v33 - v23*v30;
    float b09 = v21*v32 - v22*v31;
    float b10 = v21*v33 - v23*v31;
    float b11 = v22*v33 - v23*v32;
    return b00*b11 - b01*b10 + b02*b09 + b03*b08 - b04*b07 + b05*b06;
}

Matrix4 Matrix4::Identity()
{
    Matrix4 identity;
    identity.v00 = 1.0f;
    identity.v10 = 0.0f;
    identity.v20 = 0.0f;
    identity.v30 = 0.0f;
    identity.v01 = 0.0f;
    identity.v11 = 1.0f;
    identity.v21 = 0.0f;
    identity.v31 = 0.0f;
    identity.v02 = 0.0f;
    identity.v12 = 0.0f;
    identity.v22 = 1.0f;
    identity.v32 = 0.0f;
    identity.v03 = 0.0f;
    identity.v13 = 0.0f;
    identity.v23 = 0.0f;
    identity.v33 = 1.0f;
    return identity;
}

Matrix4 Matrix4::Inverse()
{
    float b00 = v00*v11 - v01*v10;
    float b01 = v00*v12 - v02*v10;
    float b02 = v00*v13 - v03*v10;
    float b03 = v01*v12 - v02*v11;
    float b04 = v01*v13 - v03*v11;
    float b05 = v02*v13 - v03*v12;
    float b06 = v20*v31 - v21*v30;
    float b07 = v20*v32 - v22*v30;
    float b08 = v20*v33 - v23*v30;
    float b09 = v21*v32 - v22*v31;
    float b10 = v21*v33 - v23*v31;
    float b11 = v22*v33 - v23*v32;
    float inv_det = 1.0f / (b00*b11 - b01*b10 + b02*b09 + b03*b08 - b04*b07 + b05*b06);
    Matrix4 result;
    result.v00 = (v11*b11 - v12*b10 + v13*b09)*inv_det;
    result.v10 = (-v01*b11 + v02*b10 - v03*b09)*inv_det;
    result.v20 = (v31*b05 - v32*b04 + v33*b03)*inv_det;
    result.v30 = (-v21*b05 + v22*b04 - v23*b03)*inv_det;
    result.v01 = (-v10*b11 + v12*b08 - v13*b07)*inv_det;
    result.v11 = (v00*b11 - v02*b08 + v03*b07)*inv_det;
    result.v21 = (-v30*b05 + v32*b02 - v33*b01)*inv_det;
    result.v31 = (v20*b05 - v22*b02 + v23*b01)*inv_det;
    result.v02 = (v10*b10 - v11*b08 + v13*b06)*inv_det;
    result.v12 = (-v00*b10 + v01*b08 - v03*b06)*inv_det;
    result.v22 = (v30*b04 - v31*b02 + v33*b00)*inv_det;
    result.v32 = (-v20*b04 + v21*b02 - v23*b00)*inv_det;
    result.v03 = (-v10*b09 + v11*b07 - v12*b06)*inv_det;
    result.v13 = (v00*b09 - v01*b07 + v02*b06)*inv_det;
    result.v23 = (-v30*b03 + v31*b01 - v32*b00)*inv_det;
    result.v33 = (v20*b03 - v21*b01 + v22*b00)*inv_det;
    return result;
}

Matrix4 Matrix4::Transpose()
{
    Matrix4 result;
    result.v00 = v00;
    result.v10 = v01;
    result.v20 = v02;
    result.v30 = v03;
    result.v01 = v10;
    result.v11 = v11;
    result.v21 = v12;
    result.v31 = v13;
    result.v02 = v20;
    result.v12 = v21;
    result.v22 = v22;
    result.v32 = v23;
    result.v03 = v30;
    result.v13 = v31;
    result.v23 = v32;
    result.v33 = v33;
    return result;
}

Vector4 Matrix4::Row(unsigned row)
{
    return Vector4(d2[row][0],d2[row][1],d2[row][2],d2[row][3]);
}

Vector4 Matrix4::Col(unsigned col)
{
    return Vector4(d2[0][col],d2[1][col],d2[2][col],d2[3][col]);
}

void Matrix4::SetRow(Vector4 row, unsigned row_num)
{
    d2[row_num][0] = row.x;
    d2[row_num][1] = row.y;
    d2[row_num][2] = row.z;
    d2[row_num][3] = row.w;
}

void Matrix4::SetCol(Vector4 col, unsigned col_num)
{
    d2[0][col_num] = col.x;
    d2[1][col_num] = col.y;
    d2[2][col_num] = col.z;
    d2[3][col_num] = col.w;
}

} //End of namespace "Math"
} //End of namespace "GE"