#include "Vector.hpp"
#include "Matrix.hpp"
#include "Algorithm.hpp"
#include <iostream>

int	main()
{
	Vector<double>	vec1({1, 2, 3, 4});
	Vector<double>	vec2({5, 5, 5, 5});

	Matrix<int>	mat1({{12, 15, 17, 19}, {15, 17, 19, 21}});
	Matrix<int>	mat2({{510, 500, 490, 480}, {120, 130, 120, 110}});

	std::cout << "Linear interpolation of :" << std::endl <<
	vec1 << std::endl <<
	vec2 << std::endl <<
	"with 0.5 coefficient yields: " << linear_interpolation(vec1, vec2, 0.5f) << std::endl << std::endl;


	std::cout << "Linear interpolation of :" << std::endl <<
	mat1 << std::endl <<
	mat2 << std::endl <<
	"with 0.2 coefficient yields :" << std::endl <<
	linear_interpolation(mat1, mat2, 0.2f) << std::endl;


	for (unsigned i = 0; i < 26; ++i)
		std::cout << "LERP of 'a' and 'z' with coefficient " << i <<
		"/25 yields :" << linear_interpolation('a', 'z', i / 25.0f) << std::endl;
	return (0);
}