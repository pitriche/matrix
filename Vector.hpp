#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <array>
# include <iostream>

/* ########################################################################## */

template <typename T = float, unsigned LENGTH = 3>
struct	Vector : std::array<T, LENGTH>
{
	Vector()
	{
		for (T &scalar : *this)
			scalar = static_cast<T>(0);
	}

	Vector(Vector &src) { *this = src; }
	virtual	~Vector() { }

	Vector	&operator=(Vector &rhs)
	{ (std::array<T, LENGTH>)*this = (std::array<T, LENGTH>)rhs; }

	/* -^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^ */

	unsigned	length(void)	{ return (LENGTH); }
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
	lhs << "]" << std::endl;
	return (lhs);
}

#endif