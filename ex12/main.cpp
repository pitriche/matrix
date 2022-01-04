#include "Matrix.hpp"
#include <iostream>

int	main()
{
	Matrix<double>	mat1({{8, 5, -2, 4, 28}, {4, 2.5, 20, 4, -4}, {8, 5, 1, 4, 17}, {8, 50, -2, 4, 8}, {8, 5, 8, 4, 2}});
	Matrix<double>	mat2({{0, 3, 0.3}, {5, 15, 3}, {1, 4, 0.3}});
	Matrix<double>	mat3({{3}});
	Matrix<double>	mat4({{1, 1}, {2, 3}});
	Matrix<double>	mat5({{3, -1, 14, 7}, {2, 2, 3, 0}, {1, -12, -18, 33}, {30, -61, 4, 3}});
	Matrix<double>	mat6({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}});

	std::cout << mat1 << "inverse>\n" << mat1.inverse() << std::endl;
	std::cout << mat2 << "inverse>\n" << mat2.inverse() << std::endl;
	std::cout << mat3 << "inverse>\n" << mat3.inverse() << std::endl;
	std::cout << mat4 << "inverse>\n" << mat4.inverse() << std::endl;
	std::cout << mat5 << "inverse>\n" << mat5.inverse() << std::endl;
	std::cout << mat6 << "inverse>\n" << mat6.inverse();
	return (0);
}