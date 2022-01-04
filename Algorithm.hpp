#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

template <typename T>
T	linear_interpolation(const T &elem1, const T &elem2, float coefficient)
{
	// if (coefficient < 0.0f || coefficient > 1.0f)	// out of bound
	// 	throw std::logic_error("Coefficient out of bounds");
	return (elem1 * (1 - coefficient) + elem2 * coefficient);
}

template <typename T>
T	square(T scalar) { return (scalar * scalar); }

template <typename T>
T	abs(T scalar)
{
	if (scalar >= (T)0)
		return (scalar);
	return (scalar * (T)(-1));
}

template <typename T>
T	power(T scalar, int pow)
{
	T	mult;

	if (pow == 0)
		return ((T)1);
	if (pow < 0)
		return ((T)1 / power(scalar, abs(pow)));
	mult = scalar;
	for (int i = 1; i < pow; ++i)
		scalar = scalar * mult;
	return (scalar);
}

# include <iostream>
/* Babylonian Method with fermi estimate */
template <typename T>
T	sqrt(T scalar)
{
	const static float	steps =	15;
	T					res;
	int					estimate;

	if (scalar < (T)0)
		throw std::logic_error("Square root on negative number isn't a real "
		"number");
	estimate = 0;
	if (scalar >= 1)
		while (power(1000.0, estimate) < scalar)
			++estimate;
	else
		while (power(1000.0, estimate) > scalar)
			--estimate;
	res = power(1000.0, estimate / 2);
	for (unsigned i = 0; i < steps; ++i)
		res = (res + (scalar / res)) / 2;
	return (res);
}

#endif
