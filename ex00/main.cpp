#include "Vector.hpp"
#include "Matrix.hpp"
#include <iostream>

int	main()
{
	Matrix<float, 20, 10>	mat;
	Matrix<>				mat_default;
	Vector<char, 15>		vec;
	Vector<>				vec_default;

	std::cout << mat.width() << "dada\n" << mat << std::endl;
	std::cout << vec.length() << "dodo\n" << vec << std::endl;
	return (0);
}