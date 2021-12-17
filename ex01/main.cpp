#include "Vector.hpp"
#include <iostream>

int	main()
{
	Vector<double>			coefficients;
	Vector<Vector<double>>	vectors;

	coefficients = {0.5, 1, 2};
	vectors.resize(3);
	vectors[0] = {10, 11, 12, 13, 14};
	vectors[1] = {0, 1, 2, 3, 4};
	vectors[2] = {10, 10, 10, 10, 10};
	std::cout << "Linear combination of :" << std::endl <<
	vectors[0] << std::endl <<
	vectors[1] << std::endl <<
	vectors[2] << std::endl <<
	"with coefficients " << coefficients << " yields:" << std::endl;
	std::cout << linear_combination(vectors, coefficients) << std::endl;
	return (0);
}