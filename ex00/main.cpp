#include "Vector.hpp"
#include "Matrix.hpp"
#include <iostream>

int	main()
{
	Matrix<float, 3, 4>		mat;
	Matrix<float, 3, 4>		mat2;
	Matrix<>				mat_default;
	Vector<short, 4>		vec;
	Vector<short, 4>		vec2;
	Vector<>				vec_default;

	std::cout << mat.width() << " matrix width\n" << mat << std::endl;
	std::cout << vec.length() << "vector length\n" << vec << std::endl;
	vec =	{1, 2, 3, 4};
	vec2 =	{4, 3, 2, 1};
	std::cout << vec << " + " << vec2 << " = " << vec + vec2 << std::endl;
	std::cout << vec << " - " << vec2 << " = " << vec - vec2 << std::endl;
	std::cout << vec << " * 48 = " << vec * 42 << std::endl << std::endl;

	mat[0] = {1, 0, 0, 0};
	mat[1] = {0, 1, 0, 0};
	mat[2] = {0, 0, 1, 0};
	mat2[0] = {3, 4, 5, 4};
	mat2[1] = {4, 5, 4, 3};
	mat2[2] = {5, 4, 3, 2};

	std::cout << mat << "+\n" << mat2 << "=\n" << mat + mat2 << std::endl;
	std::cout << mat << "-\n" << mat2 << "=\n" << mat - mat2 << std::endl;
	std::cout << mat2 << " * 48 =\n" << mat2 * 48 << std::endl;
	return (0);
}