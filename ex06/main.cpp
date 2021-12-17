#include "Vector.hpp"
#include "Matrix.hpp"
#include "Algorithm.hpp"
#include <iostream>

int	main()
{
	Vector<double>	vec1({1, 0, 0});
	Vector<double>	vec2({1, 3, 0.3});

	std::cout << "Cross product of " << vec1 << " and " << vec2 << " is: " <<
	vec1.cross(vec2) << std::endl;

	std::cout << "Cross product of [1, 2, 3] and [4, 5, 6] is: " <<
	Vector<double>({1, 2, 3}).cross(Vector<double>({4, 5, 6})) << std::endl;
	return (0);
}