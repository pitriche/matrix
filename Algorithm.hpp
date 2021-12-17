#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

template <typename T>
T	linear_interpolation(const T &elem1, const T &elem2, float coefficient)
{
	// if (coefficient < 0.0f || coefficient > 1.0f)	// out of bound
	// 	throw std::logic_error("Coefficient out of bounds");
	return (elem1 * (1 - coefficient) + elem2 * coefficient);
}

/* Babylonian Method */
template <typename T>
T	sqrt(T scalar)
{
	const static float	steps =	150;
	T					res;

	res = scalar;
	for (unsigned i = 0; i < steps; ++i)
		res = (res + (scalar / res)) / 2;
	return (res);
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

#endif