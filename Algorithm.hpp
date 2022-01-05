#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

# include "Matrix.hpp"	/* Matrix */
# include <iostream>	/* logic_error ? */

# define FT_PI	3.14159265358979323846264338327950288419716939937510582097494459

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

/* trigonometric tangent, because we can't just use cmath. Radian as input */
template <typename T>
T	tan(T angle)
{
	T					res;

	while (angle < 0)				/* periodicity */
		angle += (T)FT_PI;
	while (angle > (T)FT_PI)
		angle -= (T)FT_PI;
	if (angle > (T)(FT_PI / 2))		/* symetry */
		return (-tan((T)FT_PI - angle));
	if (angle > (T)(FT_PI / 4))		/* cofunction */
		return ((T)1 / tan((T)(FT_PI / 2) - angle));
	if (angle > (T)(FT_PI / 8))		/* trigonometric identity */
		return ((T)2 * tan(angle / (T)2) / ((T)1 - square(tan(angle / (T)2))));
	res = angle;					/* polynomial */
	res += power(angle, 3) / (T)3;
	res += (T)2 * power(angle, 5) / (T)15;
	res += (T)17 * power(angle, 7) / (T)315;
	return (res);
}

template <typename T>
Matrix<T>	projection(T fov, T ratio, T near, T far)
{
	Matrix<T>	proj(4, 4);
	T			e;

	e = 1 / (tan(fov / 2.0f));
	proj[0][0] = e / ratio;
	proj[1][1] = e;
	proj[2][2] = (near + far) / (near - far);
	proj[2][3] = (2 * near * far) / (near - far);
	proj[3][2] = -1;
	return (proj);
}

#endif
