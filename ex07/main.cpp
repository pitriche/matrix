#include "Vector.hpp"
#include "Matrix.hpp"
#include "Algorithm.hpp"
#include <iostream>

int	main()
{
	Vector<double>	vec({1, 0, 1, 0});
	Matrix<double>	mat1({{1, 3, 0.3, 4}, {5, 4, 3, 3}});
	Matrix<double>	mat2({{1, 3, 0.3}, {5, 3, 3}, {1, 3, 0.3}, {5, 3, 3}});

	std::cout << mat1 << "x" << std::endl << vec << "=" <<
	mat1 * vec << std::endl << std::endl;

	std::cout << mat1 << "x" << std::endl << mat2 << "=" << std::endl <<
	mat1 * mat2 << std::endl;
	std::cout << "[[0, 1][1, 0]] x" << std::endl <<
	"[[2, 3][4, 5]]=" << std::endl << Matrix<float>({{0, 1}, {1, 0}})
	* Matrix<float>({{2, 3}, {4, 5}});
	return (0);
}