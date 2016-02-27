#include <cmath>

#include "Vector.hpp"
#include "Matrix.hpp"

//
//Matrix2
//

//TODO: Unroll loops
Matrix2& Matrix2::operator=(const Matrix2 &rhs)
{
    for (unsigned i = 0; i < 4; ++i)
    {
        d1[i] = rhs.d1[i];
    }
    return *this;
}

Matrix2& Matrix2::operator+=(const Matrix2 &rhs)
{
    for (unsigned i = 0; i < 4; ++i)
    {
        d1[i] += rhs.d1[i];
    }
    return *this;
}

Matrix2 Matrix2::operator+(const Matrix2 &rhs)
{
    Matrix2 result;
    for (unsigned i = 0; i < 4; ++i)
    {
        result.d1[i] = d1[i] + rhs.d1[i];
    }
    return result;
}

Matrix2& Matrix2::operator*=(const Matrix2 &rhs)
{
    Matrix2 result;
    result.v11 = v11 * rhs.v11 + v12 * rhs.v21;
    result.v21 = v21 * rhs.v11 + v22 * rhs.v21;
    result.v12 = v11 * rhs.v12 + v12 * rhs.v22;
    result.v22 = v21 * rhs.v12 + v22 * rhs.v22;
    *this = result;
    return *this;
}

Matrix2 Matrix2::operator*(const Matrix2 &rhs)
{
    /*
    Matrix2 result;
    for (unsigned j = 0; j < 2; ++j)
    {
        for (unsigned i = 0; i < 2; ++i)
        {
            set(j, i, Row(j).Dot(rhs.Col(i)));
        }
    }
    return result;
    */

    Matrix2 result;
    result.v11 = v11 * rhs.v11 + v12 * rhs.v21;
    result.v21 = v21 * rhs.v11 + v22 * rhs.v21;
    result.v12 = v11 * rhs.v12 + v12 * rhs.v22;
    result.v22 = v21 * rhs.v12 + v22 * rhs.v22;
    return result;
}

Vector2 Matrix2::operator*(const Vector2& rhs)
{
    Vector2 result;
    result.x = v11 * rhs.x * v12 * rhs.y;
    result.y = v21 * rhs.x * v22 * rhs.y;
    return result;
}

Matrix2& Matrix2::operator*=(const float& rhs)
{
    for (unsigned i = 0; i < 4; ++i)
    {
        d1[i] = d1[i] * rhs;
    }
    return *this;
}

Matrix2 Matrix2::operator*(const float& rhs)
{
    Matrix2 result;
    for (unsigned i = 0; i < 4; ++i)
    {
        result.d1[i] = d1[i] * rhs;
    }
    return result;
}

Matrix2 operator*(const float &lhs, const Matrix2 &rhs)
{
    Matrix2 result;
    for (unsigned i = 0; i < 4; ++i)
    {
        result.d1[i] = lhs * rhs.d1[i];
    }
    return result;
}

float Matrix2::Det()
{
    return v11 * v22 - v21 * v12;
}

const Matrix2 Matrix2::Identity()
{
    return Matrix2{1.0f,0.0f,0.0f,1.0f};
}

void Matrix2::Reset()
{
    for (unsigned i = 0; i < 4; ++i)
    {
        d1[i] = 0;
    }
}

Matrix2 Matrix2::Inverse()
{
    float det = Det();
    if (det != 0)
    {
        float inv_det = 1.0f / det;
        Matrix2 result;
        result.v11 = v22 * inv_det;
        result.v21 = -v12 * inv_det;
        result.v12 = -v21 * inv_det;
        result.v22 = v11 * inv_det;
        return result;
    }
    else
        return Matrix2::Identity(); //Not sure what a good backup plan would be...
}

Matrix2 Matrix2::Transpose()
{
    Matrix2 result;
    result.v11 = v11;
    result.v21 = v12;
    result.v12 = v21;
    result.v22 = v22;
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

Matrix3& Matrix3::operator=(const Matrix3 &rhs)
{
    for (unsigned i = 0; i < 9; ++i)
    {
        d1[i] = rhs.d1[i];
    }
    return *this;
}

Matrix3 Matrix3::operator+(const Matrix3 &rhs)
{
    Matrix3 result;
    for (unsigned i = 0; i < 9; ++i)
    {
        result.d1[i] = d1[i] + rhs.d1[i];
    }
    return result;
}

Matrix3& Matrix3::operator+=(const Matrix3 &rhs)
{
    for (unsigned i = 0; i < 9; ++i)
    {
        d1[i] += rhs.d1[i];
    }
    return *this;
}

Matrix3 Matrix3::operator*(const Matrix3 &rhs)
{
    Matrix3 result;

    result.v11 = v11 * rhs.v11 + v12 * rhs.v21 + v13 * rhs. v31;
    result.v21 = v21 * rhs.v11 + v22 * rhs.v21 + v23 * rhs. v31;
    result.v31 = v31 * rhs.v11 + v32 * rhs.v21 + v33 * rhs. v31;
    result.v12 = v11 * rhs.v12 + v12 * rhs.v22 + v13 * rhs. v32;
    result.v22 = v21 * rhs.v12 + v22 * rhs.v22 + v23 * rhs. v32;
    result.v32 = v31 * rhs.v12 + v32 * rhs.v22 + v33 * rhs. v32;
    result.v13 = v11 * rhs.v13 + v12 * rhs.v23 + v13 * rhs. v33;
    result.v23 = v21 * rhs.v13 + v22 * rhs.v23 + v23 * rhs. v33;
    result.v33 = v31 * rhs.v13 + v32 * rhs.v23 + v33 * rhs. v33;

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
    result.x = v11 * rhs.x * v12 * rhs.y;
    result.y = v21 * rhs.x * v22 * rhs.y;
    return result;
}

Matrix3& Matrix3::operator*=(const float& rhs)
{
    for (unsigned i = 0; i < 9; ++i)
    {
        d1[i] = d1[i] * rhs;
    }
    return *this;
}

Matrix3 Matrix3::operator*(const float& rhs)
{
    Matrix3 result;
    for (unsigned i = 0; i < 9; ++i)
    {
        result.d1[i] = d1[i] * rhs;
    }
    return result;
}

Matrix3 operator*(const float &lhs, const Matrix3 &rhs)
{
    Matrix3 result;
    for (unsigned i = 0; i < 9; ++i)
    {
        result.d1[i] = lhs * rhs.d1[i];
    }
    return result;
}

float Matrix3::Det()
{
    return (v11 * (v22 * v33 - v23 * v32) -
            v12 * (v21 * v33 - v31 * v23) +
            v13 * (v21 * v32 - v31 * v22));
}

const Matrix3 Matrix3::Identity()
{
    return Matrix3{1.0f,0.0f,0.0f,
                   0.0f,1.0f,0.0f,
                   0.0f,0.0f,1.0f};
}

void Matrix3::Reset()
{
    for (unsigned i = 0; i < 9; ++i)
    {
        d1[i] = 0;
    }
}

Matrix3 Matrix3::Inverse()
{
    float det = Det();
    if (det != 0)
    {
        float inv_det = 1.0f / det;
        Matrix3 result;
        result.v11 = (v22 * v33 - v32 * v23) * inv_det;
        result.v21 = (v23 * v31 - v33 * v21) * inv_det;
        result.v31 = (v21 * v32 - v31 * v22) * inv_det;
        result.v12 = (v13 * v32 - v33 * v12) * inv_det;
        result.v22 = (v11 * v33 - v31 * v13) * inv_det;
        result.v32 = (v12 * v31 - v32 * v11) * inv_det;
        result.v13 = (v12 * v23 - v22 * v13) * inv_det;
        result.v23 = (v13 * v21 - v23 * v11) * inv_det;
        result.v33 = (v11 * v22 - v21 * v12) * inv_det;
        return result;
    }

    else
        return Matrix3::Identity(); //Not sure what a good backup plan would be...
}

Matrix3 Matrix3::Transpose()
{
    Matrix3 result;
    result.v11 = v11;
    result.v21 = v12;
    result.v31 = v13;
    result.v12 = v21;
    result.v22 = v22;
    result.v32 = v23;
    result.v13 = v31;
    result.v23 = v32;
    result.v33 = v33;
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
    result.v11 = v11;
    result.v21 = v21;
    result.v31 = v31;
    result.v41 = 0;
    result.v12 = v12;
    result.v22 = v22;
    result.v32 = v32;
    result.v42 = 0;
    result.v13 = v13;
    result.v23 = v23;
    result.v33 = v33;
    result.v43 = 0;
    result.v14 = 0;
    result.v24 = 0;
    result.v34 = 0;
    result.v44 = 0;
    return result;
}

//
//Matrix4
//

Matrix4& Matrix4::operator=(const Matrix4 &rhs)
{
    for (unsigned i = 0; i < 16; ++i)
    {
        d1[i] = rhs.d1[i];
    }
    return *this;
}

Matrix4 Matrix4::operator+(const Matrix4 &rhs)
{
    Matrix4 result;
    for (unsigned i = 0; i < 16; ++i)
    {
        result.d1[i] = d1[i] + rhs.d1[i];
    }
    return result;
}

Matrix4& Matrix4::operator+=(const Matrix4 &rhs)
{
    for (unsigned i = 0; i < 16; ++i)
    {
        d1[i] += rhs.d1[i];
    }
    return *this;
}

Matrix4 Matrix4::operator*(const Matrix4 &rhs)
{
    Matrix4 result;

    result.v11 = v11 * rhs.v11 + v12 * rhs.v21 + v13 * rhs. v31;
    result.v21 = v21 * rhs.v11 + v22 * rhs.v21 + v23 * rhs. v31;
    result.v31 = v31 * rhs.v11 + v32 * rhs.v21 + v33 * rhs. v31;
    result.v12 = v11 * rhs.v12 + v12 * rhs.v22 + v13 * rhs. v32;
    result.v22 = v21 * rhs.v12 + v22 * rhs.v22 + v23 * rhs. v32;
    result.v32 = v31 * rhs.v12 + v32 * rhs.v22 + v33 * rhs. v32;
    result.v13 = v11 * rhs.v13 + v12 * rhs.v23 + v13 * rhs. v33;
    result.v23 = v21 * rhs.v13 + v22 * rhs.v23 + v23 * rhs. v33;
    result.v33 = v31 * rhs.v13 + v32 * rhs.v23 + v33 * rhs. v33;

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
    result.x = v11 * rhs.x * v12 * rhs.y;
    result.y = v21 * rhs.x * v22 * rhs.y;
    return result;
}

Matrix4& Matrix4::operator*=(const float& rhs)
{
    for (unsigned i = 0; i < 16; ++i)
    {
        d1[i] *= rhs;
    }
    return *this;
}

Matrix4 Matrix4::operator*(const float& rhs)
{
    Matrix4 result;
    for (unsigned i = 0; i < 16; ++i)
    {
        result.d1[i] = d1[i] * rhs;
    }
    return result;
}

Matrix4 operator*(const float &lhs, const Matrix4 &rhs)
{
    Matrix4 result;
    for (unsigned i = 0; i < 16; ++i)
    {
        result.d1[i] = lhs * rhs.d1[i];
    }
    return result;
}

float* Matrix4::Values()
{
    return d1;
}

float Matrix4::Det()
{
    return (v11 * (v22 * v33 - v23 * v32) -
            v12 * (v21 * v33 - v31 * v23) +
            v13 * (v21 * v32 - v31 * v22));
}

const Matrix4 Matrix4::Identity()
{
    return Matrix4{1.0f,0.0f,0.0f,0.0f,
                   0.0f,1.0f,0.0f,0.0f,
                   0.0f,0.0f,1.0f,0.0f,
                   0.0f,0.0f,0.0f,1.0f};
}

void Matrix4::Reset()
{
    for (unsigned i = 0; i < 16; ++i)
    {
        d1[i] = 0;
    }
}

Matrix4 Matrix4::Inverse()
{
    float det = Det();
    float b00 = v11*v22 - v12*v21;
    float b01 = v11*v23 - v13*v21;
    float b02 = v11*v24 - v14*v21;
    float b03 = v12*v23 - v13*v22;
    float b04 = v12*v24 - v14*v22;
    float b05 = v13*v24 - v14*v23;
    float b06 = v31*v42 - v32*v41;
    float b07 = v31*v43 - v33*v41;
    float b08 = v31*v44 - v34*v41;
    float b09 = v32*v43 - v33*v42;
    float b10 = v32*v44 - v34*v42;
    float b11 = v33*v44 - v34*v43;
    if (det != 0)
    {
        float inv_det = 1.0f / (b00*b11 - b01*b10 + b02*b09 + b03*b08 - b04*b07 + b05*b06);
        Matrix4 result;
        result.v11 = (v22*b11 - v23*b10 + v24*b09)*inv_det;
        result.v21 = (-v12*b11 + v13*b10 - v14*b09)*inv_det;
        result.v31 = (v42*b05 - v43*b04 + v44*b03)*inv_det;
        result.v41 = (-v32*b05 + v33*b04 - v34*b03)*inv_det;
        result.v12 = (-v21*b11 + v23*b08 - v24*b07)*inv_det;
        result.v22 = (v11*b11 - v13*b08 + v14*b07)*inv_det;
        result.v32 = (-v41*b05 + v43*b02 - v44*b01)*inv_det;
        result.v42 = (v31*b05 - v33*b02 + v34*b01)*inv_det;
        result.v13 = (v21*b10 - v22*b08 + v24*b06)*inv_det;
        result.v23 = (-v11*b10 + v12*b08 - v14*b06)*inv_det;
        result.v33 = (v41*b04 - v42*b02 + v44*b00)*inv_det;
        result.v43 = (-v31*b04 + v32*b02 - v34*b00)*inv_det;
        result.v14 = (-v21*b09 + v22*b07 - v23*b06)*inv_det;
        result.v24 = (v11*b09 - v12*b07 + v13*b06)*inv_det;
        result.v34 = (-v41*b03 + v42*b01 - v43*b00)*inv_det;
        result.v44 = (v31*b03 - v32*b01 + v33*b00)*inv_det;
        return result;
    }

    else
        return Matrix4::Identity(); //Not sure what a good backup plan would be...
}

Matrix4 Matrix4::Transpose()
{
    Matrix4 result;
    result.v11 = v11;
    result.v21 = v12;
    result.v31 = v13;
    result.v41 = v14;
    result.v12 = v21;
    result.v22 = v22;
    result.v32 = v23;
    result.v42 = v24;
    result.v13 = v31;
    result.v23 = v32;
    result.v33 = v33;
    result.v43 = v34;
    result.v14 = v41;
    result.v24 = v42;
    result.v34 = v43;
    result.v44 = v44;
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

void Matrix4::SetRow(Vector4 &row, unsigned row_num)
{
    d2[row_num][0] = row.x;
    d2[row_num][1] = row.y;
    d2[row_num][2] = row.z;
    d2[row_num][3] = row.w;
}

void Matrix4::SetCol(Vector4 &col, unsigned col_num)
{
    d2[0][col_num] = col.x;
    d2[1][col_num] = col.y;
    d2[2][col_num] = col.z;
    d2[3][col_num] = col.w;
}
