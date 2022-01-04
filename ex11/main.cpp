#include "Matrix.hpp"
#include <iostream>

int	main()
{
	Matrix<double>	mat1({{8, 5, -2, 4, 28}, {4, 2.5, 20, 4, -4}, {8, 5, 1, 4, 17}, {8, 50, -2, 4, 8}, {8, 5, 8, 4, 2}});
	Matrix<double>	mat2({{0, 3, 0.3}, {5, 15, 3}, {1, 4, 0.3}});
	Matrix<double>	mat3({{3}});
	Matrix<double>	mat4({{0, 0}, {0, 0}});
	Matrix<double>	mat5({{1, 1}, {2, 3}});
	Matrix<double>	mat6({{3, -1, 14, 7}, {2, 2, 3, 0}, {1, -12, -18, 33}, {30, -61, 4, 3}});
	Matrix<double>	mat7({{3, -1, 14}, {6, -2, 28}, {1.5, -0.5, 7}});

	std::cout << mat1 << "determinant > " << mat1.determinant() << std::endl << std::endl;
	std::cout << mat2 << "determinant > " << mat2.determinant() << std::endl << std::endl;
	std::cout << mat3 << "determinant > " << mat3.determinant() << std::endl << std::endl;
	std::cout << mat4 << "determinant > " << mat4.determinant() << std::endl << std::endl;
	std::cout << mat5 << "determinant > " << mat5.determinant() << std::endl << std::endl;
	std::cout << mat6 << "determinant > " << mat6.determinant() << std::endl << std::endl;
	std::cout << mat7 << "determinant > " << mat7.determinant() << std::endl;
	return (0);
}