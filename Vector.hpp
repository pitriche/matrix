#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <array>
# include <iostream>

/* ########################################################################## */

template <typename T = float, unsigned LENGTH = 3>
struct	Vector : public std::array<T, LENGTH>
{
	Vector(void)
	{
		for (T &scalar : *this)
			scalar = static_cast<T>(0);
	}

	Vector(const Vector &src) { *this = src; }
	virtual	~Vector(void) { }

	Vector	&operator=(const Vector &rhs)
	{
		for (unsigned i = 0; i < LENGTH; ++i)
			(*this)[i] = rhs[i];
		return (*this);
	}

	Vector	&operator=(const std::array<T, LENGTH> &rhs)
	{
		for (unsigned i = 0; i < LENGTH; ++i)
			(*this)[i] = rhs[i];
		return (*this);
	}

	unsigned	length(void) const	{ return (LENGTH); }

	/* -^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^ */

	Vector	operator+(const Vector &rhs) const
	{
		Vector	res(*this);

		for (unsigned i = 0; i < LENGTH; ++i)
			res[i] += (T)rhs[i];
		return (res);
	}

	Vector	operator-(const Vector &rhs) const
	{
		Vector	res(*this);

		for (unsigned i = 0; i < LENGTH; ++i)
			res[i] -= (T)rhs[i];
		return (res);
	}

	Vector	operator*(T rhs) const
	{
		Vector	res(*this);

		for (unsigned i = 0; i < LENGTH; ++i)
			res[i] *= rhs;
		return (res);
	}

};

/* ########################################################################## */

template <typename T, unsigned L>
std::ostream	&operator<<(std::ostream &lhs, const Vector<T, L> &rhs)
{
	lhs << "[";
	for (unsigned i = 0; i < L; ++i)
	{
		lhs << ((std::array<T, L>)rhs)[i];
		if (i + 1 < L)
			lhs << ", ";
	}
	lhs << "]";
	return (lhs);
}

template <typename T, unsigned L>
std::array<Vector<T, L>>	&linear_combination(std::array<Vector<T, L>> &arr, const std::array<T> &rhs)
{
	lhs << "[";
	for (unsigned i = 0; i < L; ++i)
	{
		lhs << ((std::array<T, L>)rhs)[i];
		if (i + 1 < L)
			lhs << ", ";
	}
	lhs << "]";
	return (lhs);
}

#endif