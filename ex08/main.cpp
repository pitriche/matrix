#include "Matrix.hpp"
#include <iostream>

int	main()
{
	Matrix<double>	mat1({{1, 3}, {5, 4}});
	Matrix<double>	mat2({{1, 3, 0.3, 2}, {5, 3, 3, 5}, {1, 3, 0.3, 10}, {5, 3, 3, -2}});

	std::cout << mat1 << "Trace = " << mat1.trace() << std::endl << std::endl;
	std::cout << mat2 << "Trace = " << mat2.trace() << std::endl;
	return (0);
}