#include <math/Vector.hpp>
#include <math/Matrix.hpp>
#include <math/Quaternion.hpp>

#include <gtest/gtest.h>

//Vector2 Tests

class Vector2Test : public ::testing::Test
{
protected:
	GE::Math::Vector2 vec2_increment;
	GE::Math::Vector2 vec2_increment2;
	virtual void SetUp()
	{
		// vec2_increment:
		// 1
		// 2
		vec2_increment = GE::Math::Vector2(1, 2);

		// vec2_increment2:
		// 3
		// 4
		vec2_increment2 = GE::Math::Vector2(3, 4);
	}
};

TEST_F(Vector2Test, ValueAccess)
{
	EXPECT_FLOAT_EQ(1, vec2_increment.x);
	EXPECT_FLOAT_EQ(2, vec2_increment.y);
	EXPECT_FLOAT_EQ(3, vec2_increment2.x);
	EXPECT_FLOAT_EQ(4, vec2_increment2.y);
}

TEST_F(Vector2Test, EmptyVector)
{
	//Create an empty vector and test to see if it's initialized to 0.
	GE::Math::Vector2 vec2_empty;
	EXPECT_FLOAT_EQ(0, vec2_empty.x);
	EXPECT_FLOAT_EQ(0, vec2_empty.y);
}

TEST_F(Vector2Test,ArithmeticEquals)
{
	//Create an empty vector and test to see if it's initialized to 0.
	EXPECT_EQ(true, vec2_increment == vec2_increment);
	//Test to make sure the function fails correctly
	EXPECT_EQ(false, vec2_increment == vec2_increment2);
	EXPECT_EQ(false, vec2_increment2 == vec2_increment); //Reverse order
}

TEST_F(Vector2Test, ArithmeticNotEquals)
{
	//Create an empty vector and test to see if it's initialized to 0.
	EXPECT_EQ(false, vec2_increment != vec2_increment);
	//Test to make sure the function fails correctly
	EXPECT_EQ(true, vec2_increment != vec2_increment2);
	EXPECT_EQ(true, vec2_increment2 != vec2_increment); //Reverse order
}

TEST_F(Vector2Test, ArithmeticAdd)
{
	GE::Math::Vector2 vec2_result = vec2_increment + vec2_increment2;
	EXPECT_FLOAT_EQ(4, vec2_result.x);
	EXPECT_FLOAT_EQ(6, vec2_result.y);
}

TEST_F(Vector2Test, ArithmeticAddEquals)
{
	GE::Math::Vector2 vec2_result = vec2_increment;
	vec2_result += vec2_increment2;
	EXPECT_FLOAT_EQ(4, vec2_result.x);
	EXPECT_FLOAT_EQ(6, vec2_result.y);
}

TEST_F(Vector2Test, Dot)
{
	float dot_result = GE::Math::Vector2::Dot(vec2_increment,vec2_increment2);
	EXPECT_FLOAT_EQ(11, dot_result); // (1 * 3) + (2 * 4)
}

TEST_F(Vector2Test, ArithmeticTimesVec2)
{
	GE::Math::Vector2 vec2_result = vec2_increment * vec2_increment2;
	EXPECT_FLOAT_EQ(3, vec2_result.x); // (1 * 3)
	EXPECT_FLOAT_EQ(8, vec2_result.y); // (2 * 4)
}

TEST_F(Vector2Test, ArithmeticTimesConst)
{
	GE::Math::Vector2 vec2_result = vec2_increment * 5;
	EXPECT_FLOAT_EQ(5, vec2_result.x); // (1 * 5)
	EXPECT_FLOAT_EQ(10, vec2_result.y); // (2 * 5)

	vec2_result = 5 * vec2_increment2;
	EXPECT_FLOAT_EQ(15, vec2_result.x); // (5 * 3)
	EXPECT_FLOAT_EQ(20, vec2_result.y); // (5 * 4)
}

TEST_F(Vector2Test, Normalize)
{
	GE::Math::Vector2 vec2_result = vec2_increment2.Normalize();
	EXPECT_FLOAT_EQ(3.0f / 5.0f, vec2_result.x); // Magnitude = sqrt(3^2 + 4^2) = sqrt(9+16)
	EXPECT_FLOAT_EQ(4.0f / 5.0f, vec2_result.y); //           = sqrt(25) = 5
}

//Matrix2 Tests

class Matrix2Test : public ::testing::Test
{
protected:
	GE::Math::Matrix2 mat2_identity;
	GE::Math::Matrix2 mat2_increment;
	GE::Math::Matrix2 mat2_pow2;
	GE::Math::Vector2 vec2_increment;
	virtual void SetUp()
	{
		// mat2_identity: A 2X2 identity matrix
		// 1 0
		// 0 1
		mat2_identity.v00 = 1;
		mat2_identity.v10 = 0;
		mat2_identity.v01 = 0;
		mat2_identity.v11 = 1;

		// mat2_increment: Values increase by 1
		// 1 3
		// 2 4
		mat2_increment.v00 = 1;
		mat2_increment.v10 = 2;
		mat2_increment.v01 = 3;
		mat2_increment.v11 = 4;

		// mat2_pow2: Values are powers of 2 in order
		// 1 4
		// 2 8
		mat2_pow2.v00 = 1;
		mat2_pow2.v10 = 2;
		mat2_pow2.v01 = 4;
		mat2_pow2.v11 = 8;

		// vec2_increment: Vector values increase by 1 in coordinate order
		// 1
		// 2
		vec2_increment.x = 1;
		vec2_increment.y = 2;
	}
};

TEST_F(Matrix2Test, DirectValueAccess)
{
	//Test direct access (first number is the row, second number is the column)
	EXPECT_FLOAT_EQ(1, mat2_increment.v00);
	EXPECT_FLOAT_EQ(2, mat2_increment.v10);
	EXPECT_FLOAT_EQ(3, mat2_increment.v01);
	EXPECT_FLOAT_EQ(4, mat2_increment.v11);
}

TEST_F(Matrix2Test, OneDimensionalValueAccess)
{
	//Test one-dimensional access (d1[value], iterate by column)
	EXPECT_FLOAT_EQ(1, mat2_increment.d1[0]);
	EXPECT_FLOAT_EQ(2, mat2_increment.d1[1]);
	EXPECT_FLOAT_EQ(3, mat2_increment.d1[2]);
	EXPECT_FLOAT_EQ(4, mat2_increment.d1[3]);
}

TEST_F(Matrix2Test, TwoDimensionalValueAccess)
{
	//Test one-dimensional access (d2[col][row])
	EXPECT_FLOAT_EQ(1, mat2_increment.d2[0][0]);
	EXPECT_FLOAT_EQ(2, mat2_increment.d2[0][1]);
	EXPECT_FLOAT_EQ(3, mat2_increment.d2[1][0]);
	EXPECT_FLOAT_EQ(4, mat2_increment.d2[1][1]);
}

TEST_F(Matrix2Test, ArithmeticAddMat2)
{
	//Add two Matrix2 together, store the result
	GE::Math::Matrix2 mat_sum = mat2_increment + mat2_pow2;
	EXPECT_FLOAT_EQ(2,  mat_sum.v00); // 1 + 1
	EXPECT_FLOAT_EQ(4,  mat_sum.v10); // 2 + 2
	EXPECT_FLOAT_EQ(7,  mat_sum.v01); // 3 + 4
	EXPECT_FLOAT_EQ(12, mat_sum.v11); // 4 + 8
}

TEST_F(Matrix2Test, ArithmeticAddEqualsMat2)
{
	//Add one Matrix2 to another
	GE::Math::Matrix2 mat_sum = mat2_increment;
	mat_sum += mat2_pow2;
	EXPECT_FLOAT_EQ(2, mat_sum.v00); // 1 + 1
	EXPECT_FLOAT_EQ(4, mat_sum.v10); // 2 + 2
	EXPECT_FLOAT_EQ(7, mat_sum.v01); // 3 + 4
	EXPECT_FLOAT_EQ(12, mat_sum.v11); // 4 + 8
}

TEST_F(Matrix2Test, ArithmeticTimesMat2)
{
	//Multiply two Matrix2 together
	GE::Math::Matrix2 mat_product = mat2_increment * mat2_pow2;
	EXPECT_FLOAT_EQ(7,  mat_product.v00); // 1 * 1 + 3 * 2
	EXPECT_FLOAT_EQ(10, mat_product.v10); // 2 * 1 + 4 * 2
	EXPECT_FLOAT_EQ(28, mat_product.v01); // 1 * 4 + 3 * 8
	EXPECT_FLOAT_EQ(40, mat_product.v11); // 2 * 4 + 4 * 8
}

TEST_F(Matrix2Test, ArithmeticTimesEqualsMat2)
{
	//Multiply two Matrix2 together
	GE::Math::Matrix2 mat_product = mat2_increment;
	mat_product *= mat2_pow2;
	EXPECT_FLOAT_EQ(7, mat_product.v00); // 1 * 1 + 3 * 2
	EXPECT_FLOAT_EQ(10, mat_product.v10); // 2 * 1 + 4 * 2
	EXPECT_FLOAT_EQ(28, mat_product.v01); // 1 * 4 + 3 * 8
	EXPECT_FLOAT_EQ(40, mat_product.v11); // 2 * 4 + 4 * 8
}

TEST_F(Matrix2Test, ArithmeticTimesVec2)
{
	//Multiply a Matrix2 and a Vector2 and store the result
	GE::Math::Vector2 vec_product = mat2_increment * vec2_increment;
	EXPECT_FLOAT_EQ(7, vec_product.x); // 1 * 1 + 3 * 2
	EXPECT_FLOAT_EQ(10, vec_product.y); // 2 * 1 + 4 * 2
}

TEST_F(Matrix2Test, ArithmeticTimesConst)
{
	//Multiply a Matrix2 and a Vector2 and store the result
	GE::Math::Matrix2 mat_product = mat2_increment * 5;
	EXPECT_FLOAT_EQ(5, mat_product.v00);  // 1 * 5
	EXPECT_FLOAT_EQ(10, mat_product.v10); // 2 * 5
	EXPECT_FLOAT_EQ(15, mat_product.v01); // 3 * 5
	EXPECT_FLOAT_EQ(20, mat_product.v11); // 4 * 5

	//Reverse the operands (this is a separate function)
	mat_product = 5 * mat2_increment;
	EXPECT_FLOAT_EQ(5, mat_product.v00);  // 1 * 5
	EXPECT_FLOAT_EQ(10, mat_product.v10); // 2 * 5
	EXPECT_FLOAT_EQ(15, mat_product.v01); // 3 * 5
	EXPECT_FLOAT_EQ(20, mat_product.v11); // 4 * 5
}

TEST_F(Matrix2Test, ArithmeticTimesEqualsConst)
{
	//Multiply a Matrix2 and a Vector2 and store the result
	GE::Math::Matrix2 mat_product = mat2_increment;
	mat_product *= 5;
	EXPECT_FLOAT_EQ(5, mat_product.v00); // 1 * 5
	EXPECT_FLOAT_EQ(10, mat_product.v10); // 2 * 5
	EXPECT_FLOAT_EQ(15, mat_product.v01); // 3 * 5
	EXPECT_FLOAT_EQ(20, mat_product.v11); // 4 * 5
}

TEST_F(Matrix2Test, ArithmeticEqualsMat2)
{
	//Test mat2_increment against itself
	EXPECT_EQ(true, mat2_increment == mat2_increment);
	//Test to see if some of the other ones are equal (they're not)
	EXPECT_EQ(false, mat2_identity == mat2_increment);
	EXPECT_EQ(false, mat2_increment == mat2_identity); //Reverse order
}

TEST_F(Matrix2Test, ArithmeticNotEqualsMat2)
{
	//Test mat2_increment against itself
	EXPECT_EQ(false, mat2_increment != mat2_increment);
	//Test to see if some of the other ones are equal (they're not)
	EXPECT_EQ(true, mat2_identity != mat2_increment);
	EXPECT_EQ(true, mat2_increment != mat2_identity); //Reverse order
}

TEST_F(Matrix2Test, Determinant)
{
	//Test the determinants of all the test matrices
	EXPECT_FLOAT_EQ(1, mat2_identity.Det()); // (1 * 1) - (0 * 0) = 1
	EXPECT_FLOAT_EQ(-2, mat2_increment.Det()); // (1 * 4) - (2 * 3) = -2
	EXPECT_FLOAT_EQ(0, mat2_pow2.Det()); // (1 * 8) - (2 * 4) = 0
}

TEST_F(Matrix2Test, Identity)
{
	//Test Identity() and compare it to the preconstructed identity matrix
	EXPECT_EQ(true, GE::Math::Matrix2::Identity() == mat2_identity); // diagonal of ones
}

TEST_F(Matrix2Test, Inverse)
{
	//Test the inverses of each matrix that has one (determinant != 0)
	GE::Math::Matrix2 identity_inverse = mat2_identity.Inverse();
	GE::Math::Matrix2 increment_inverse = mat2_increment.Inverse();

	EXPECT_EQ(true, identity_inverse == mat2_identity); //This is an easy check

	EXPECT_FLOAT_EQ(-2, increment_inverse.v00);
	EXPECT_FLOAT_EQ(1, increment_inverse.v10);
	EXPECT_FLOAT_EQ(1.5, increment_inverse.v01);
	EXPECT_FLOAT_EQ(-0.5, increment_inverse.v11);
}

TEST_F(Matrix2Test, Transpose)
{
	//Test the transpose of each matrix
	GE::Math::Matrix2 identity_transpose = mat2_identity.Transpose();
	GE::Math::Matrix2 increment_transpose = mat2_increment.Transpose();
	GE::Math::Matrix2 pow2_transpose = mat2_pow2.Transpose();

	EXPECT_EQ(true, identity_transpose == mat2_identity); //This is an easy check

	EXPECT_FLOAT_EQ(1, increment_transpose.v00);
	EXPECT_FLOAT_EQ(3, increment_transpose.v10);
	EXPECT_FLOAT_EQ(2, increment_transpose.v01);
	EXPECT_FLOAT_EQ(4, increment_transpose.v11);

	EXPECT_FLOAT_EQ(1, pow2_transpose.v00);
	EXPECT_FLOAT_EQ(4, pow2_transpose.v10);
	EXPECT_FLOAT_EQ(2, pow2_transpose.v01);
	EXPECT_FLOAT_EQ(8, pow2_transpose.v11);
}

TEST_F(Matrix2Test, RowFunction)
{
	//Test every row of mat2_increment
	EXPECT_EQ(true, GE::Math::Vector2(1, 3) == mat2_increment.Row(0));
	EXPECT_EQ(true, GE::Math::Vector2(2, 4) == mat2_increment.Row(1));
}

TEST_F(Matrix2Test, ColFunction)
{
	//Test every column of mat2_increment
	EXPECT_EQ(true, GE::Math::Vector2(1, 2) == mat2_increment.Col(0));
	EXPECT_EQ(true, GE::Math::Vector2(3, 4) == mat2_increment.Col(1));
}

TEST_F(Matrix2Test, SetRowFunction)
{
	//Test setting every row of a Matrix2.
	GE::Math::Matrix2 mat2_settest = mat2_identity;
	mat2_settest.SetRow(GE::Math::Vector2(1, 4), 0);
	mat2_settest.SetRow(GE::Math::Vector2(2, 8), 1);
	EXPECT_EQ(true, mat2_settest == mat2_pow2);
}

TEST_F(Matrix2Test, SetColFunction)
{
	//Test setting every column of a Matrix2.
	GE::Math::Matrix2 mat2_settest = mat2_identity;
	mat2_settest.SetCol(GE::Math::Vector2(1, 2), 0);
	mat2_settest.SetCol(GE::Math::Vector2(4, 8), 1);
	EXPECT_EQ(true, mat2_settest == mat2_pow2);
}

GTEST_API_ int main(int argc, char **argv) {
	printf("GE::Math Unit Tests\n");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}