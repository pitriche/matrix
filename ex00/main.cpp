#include "Vector.hpp"
#include "Matrix.hpp"
#include <iostream>

int	main()
{
	Matrix<float>		mat({{1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}});
	Matrix<float>		mat2;
	Matrix<>			mat_default;
	Vector<short>		vec;
	Vector<short>		vec2;
	Vector<short>		vec3;
	Vector<>			vec_default;

	vec =	{1, 2, 3, 4};
	vec2 =	{4, 3, 2, 1};
	vec3 =	{4, 3, 2};
	std::cout << vec.size() << " vector length\n" << vec << std::endl;
	std::cout << vec3.size() << " vector 3 length\n" << vec << std::endl << std::endl;
	std::cout << vec << " + " << vec2 << " = " << vec + vec2 << std::endl;
	std::cout << vec << " - " << vec2 << " = " << vec - vec2 << std::endl;
	std::cout << vec << " * 48 = " << vec * 42 << std::endl << std::endl;
	// vec = vec + vec3; // Throws an exception

	mat2 = {
		{3, 4, 5, 4},
		{4, 5, 4, 3},
		{5, 4, 3, 2}};
	std::cout << mat.width() << " matrix width\n" << mat << std::endl;
	std::cout << mat << "+\n" << mat2 << "=\n" << mat + mat2 << std::endl;
	std::cout << mat << "-\n" << mat2 << "=\n" << mat - mat2 << std::endl;
	std::cout << mat2 << " * 42 =\n" << mat2 * 42 << std::endl;
	// mat_default = {{0, 1}, {1}};					// Throws an exception (corrupted)
	// mat = mat + Matrix<float>({{0, 1}, {1, 0}});	// Throws an exception (different sizes)
	return (0);
}