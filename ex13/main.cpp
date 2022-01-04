#include "Matrix.hpp"
#include <iostream>

int	main()
{
	Matrix<double>	mat1({{8, 5, -2, 4, 28}, {4, 2.5, 20, 4, -4}, {8, 5, 1, 4, 17}});
	Matrix<double>	mat2({{0, 3, 0.3}, {5, 15, 3}, {1, 4, 0.3}, {5, 3, 3}});
	Matrix<double>	mat3({{3, -1, 7}, {2, 1, 8}});
	Matrix<double>	mat4({{0, 0, 0}, {0, 0, 0}});
	Matrix<double>	mat5({{1, 1, 1}, {2, 3, 4}});
	Matrix<double>	mat6({{3, -1, 14, 7}, {2, 2, 3, 0}, {1, -12, -18, 33}});
	Matrix<double>	mat7({{3, -1, 14, 7}, {6, -2, 28, 14}, {1.5, -0.5, 7, 3.5}});

	std::cout << mat1 << "rank > " << mat1.rank() << std::endl << std::endl;
	std::cout << mat2 << "rank > " << mat2.rank() << std::endl << std::endl;
	std::cout << mat3 << "rank > " << mat3.rank() << std::endl << std::endl;
	std::cout << mat4 << "rank > " << mat4.rank() << std::endl << std::endl;
	std::cout << mat5 << "rank > " << mat5.rank() << std::endl << std::endl;
	std::cout << mat6 << "rank > " << mat6.rank() << std::endl << std::endl;
	std::cout << mat7 << "rank > " << mat7.rank() << std::endl;
	return (0);
}