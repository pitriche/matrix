#include "Vector.hpp"
#include "Matrix.hpp"
#include "Algorithm.hpp"
#include <iostream>

int	main()
{
	Vector<double>	vec1({1, 2, 3, 4});
	Vector<double>	vec2({5, 5, 5, 5});

	std::cout << "Dot product of :" << std::endl <<
	vec1 << std::endl <<
	vec2 << std::endl <<
	"yields: " << vec1 * vec2 << std::endl;

	std::cout << "Dot product of : [0, 1] and [1, 0] yields: " <<
	Vector<float>({0, 1}) * Vector<float>({1, 0}) << std::endl;
	return (0);
}