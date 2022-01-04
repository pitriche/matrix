#include "Matrix.hpp"
#include <iostream>

int	main()
{
	Matrix<double>	mat1({{1, 3, 0.3, 4}, {5, 4, 3, 3}});
	Matrix<double>	mat2({{1, 3, 0.3}, {5, 3, 3}, {1, 3, 0.3}, {5, 3, 3}});

	std::cout << mat1 << "Transpose = " << mat1.transpose() << std::endl << std::endl;
	std::cout << mat2 << "Transpose = " << mat2.transpose();
	return (0);
}