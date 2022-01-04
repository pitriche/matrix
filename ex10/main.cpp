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

	std::cout << mat1 << "reduced row >\n" << mat1.reduced_row_echelon() << std::endl;
	std::cout << mat2 << "reduced row >\n" << mat2.reduced_row_echelon() << std::endl;
	std::cout << mat3 << "reduced row >\n" << mat3.reduced_row_echelon() << std::endl;
	std::cout << mat4 << "reduced row >\n" << mat4.reduced_row_echelon() << std::endl;
	std::cout << mat5 << "reduced row >\n" << mat5.reduced_row_echelon() << std::endl;
	std::cout << mat6 << "reduced row >\n" << mat6.reduced_row_echelon() << std::endl;
	std::cout << mat7 << "reduced row >\n" << mat7.reduced_row_echelon() << std::endl;
	return (0);
}