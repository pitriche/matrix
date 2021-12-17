#include "Vector.hpp"
#include "Matrix.hpp"
#include "Algorithm.hpp"
#include <iostream>

int	main()
{
	Vector<double>	vec1({1, 0, 0});
	Vector<double>	vec2({1, 3, 0.3});

	std::cout << "Cosine of " << vec1 << " and " << vec2 << " is: " <<
	vec1.cosine(vec2) << std::endl;
	return (0);
}