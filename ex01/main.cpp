#include "Vector.hpp"
#include <iostream>

int	main()
{
	Vector<short, 4>		vec;
	Vector<short, 4>		vec2;

	vec =	{1, 2, 3, 4};
	vec2 =	{4, 3, 2, 1};
	std::cout << vec << " + " << vec2 << " = " << vec + vec2 << std::endl;
	std::cout << vec << " - " << vec2 << " = " << vec - vec2 << std::endl;
	std::cout << vec << " * 48 = " << vec * 42 << std::endl << std::endl;

	return (0);
}