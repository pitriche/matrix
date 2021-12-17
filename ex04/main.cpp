#include "Vector.hpp"
#include "Matrix.hpp"
#include "Algorithm.hpp"
#include <iostream>

int	main()
{
	Vector<double>	vec1({120000000, 220000000, 320000000, 420000000});
	Vector<double>	vec2({5, 5, 5, 5});

	std::cout << "Norm of " << vec1 << " is: " << vec1.norm() << std::endl;
	std::cout << "Norm of " << vec2 << " is: " << vec2.norm() << std::endl;

	std::cout << "Norm 1 of " << vec1 << " is: " << vec1.norm_1() << std::endl;
	std::cout << "Norm 1 of " << vec2 << " is: " << vec2.norm_1() << std::endl;

	std::cout << "Norm inf of " << vec1 << " is: " << vec1.norm_inf() << std::endl;
	std::cout << "Norm inf of " << vec2 << " is: " << vec2.norm_inf() << std::endl;
	return (0);
}