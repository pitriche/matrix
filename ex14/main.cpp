#include "Matrix.hpp"		/* Matrix */
#include "Algorithm.hpp"	/* projection */
#include <iostream>

int	main()
{
	Matrix<double>	proj;

	proj = projection(FT_PI / 4, 16.0 / 9.0, 1.0, 10.0);
	std::cout << proj;
	return (0);
}