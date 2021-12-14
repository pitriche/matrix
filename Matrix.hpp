#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <array>
# include <iostream>

/* ########################################################################## */

template <typename T = float, unsigned WIDTH = 4, unsigned HEIGHT = 4>
struct	Matrix : std::array<std::array<T, WIDTH>, HEIGHT>
{
	Matrix()
	{
		for (std::array<T, WIDTH> &line : *this)
			for (T &scalar : line)
				scalar = static_cast<T>(0);
	}

	Matrix(Matrix &src) { *this = src; }
	virtual	~Matrix() { }

	Matrix	&operator=(Matrix &rhs)
	{
		(std::array<std::array<T, WIDTH>, HEIGHT>)*this =
		(std::array<std::array<T, WIDTH>, HEIGHT>)rhs;
	}

	/* -^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^ */

	unsigned	width(void)		{ return (WIDTH); }
	unsigned	height(void)	{ return (HEIGHT); }


};

/* ########################################################################## */

template <typename T, unsigned W, unsigned H>
std::ostream	&operator<<(std::ostream &lhs, const Matrix<T, W, H> &rhs)
{
	for (const std::array<T, W> &line : rhs)
	{
		lhs << "[";
		for (unsigned i = 0; i < W; ++i)
		{
			lhs << line[i];
			if (i + 1 < W)
				lhs << ", ";
		}
		lhs << "]" << std::endl;
	}
	return (lhs);
}

#endif