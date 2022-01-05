#include "Matrix.hpp"		/* Matrix */
#include "Algorithm.hpp"	/* projection */
#include <iostream>

int	main()
{
	Matrix<double>	proj;

	/* ratio is 1, because this clearly wasn't made by a competent person */
	proj = projection(FT_PI / 4, 1.0, 1.0, 10.0);
	std::cout << proj;
	return (0);
}