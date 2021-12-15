#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <array>
# include <iostream>

/* ########################################################################## */

template <typename T = float, unsigned HEIGHT = 4, unsigned WIDTH = 4>
struct	Matrix : std::array<std::array<T, WIDTH>, HEIGHT>
{
	Matrix(void)
	{
		for (std::array<T, WIDTH> &line : *this)
			for (T &scalar : line)
				scalar = static_cast<T>(0);
	}

	Matrix(const Matrix &src) { *this = src; }
	virtual	~Matrix(void) { }

	Matrix	&operator=(const Matrix &rhs)
	{
		for (unsigned j = 0; j < HEIGHT; ++j)
			for (unsigned i = 0; i < WIDTH; ++i)
				(*this)[j][i] = rhs[j][i];
		return (*this);
	}

	Matrix	&operator=(const std::array<std::array<T, WIDTH>, HEIGHT> &rhs)
	{
		for (unsigned j = 0; j < HEIGHT; ++j)
			for (unsigned i = 0; i < WIDTH; ++i)
				(*this)[j][i] = rhs[j][i];
		return (*this);
	}

	unsigned	width(void) const	{ return (WIDTH); }
	unsigned	height(void) const	{ return (HEIGHT); }

	/* -^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^ */


	Matrix	operator+(const Matrix &rhs) const
	{
		Matrix	res(*this);

		for (unsigned j = 0; j < HEIGHT; ++j)
			for (unsigned i = 0; i < WIDTH; ++i)
				res[j][i] += (T)rhs[j][i];
		return (res);
	}


	Matrix	operator-(const Matrix &rhs) const
	{
		Matrix	res(*this);

		for (unsigned j = 0; j < HEIGHT; ++j)
			for (unsigned i = 0; i < WIDTH; ++i)
				res[j][i] -= (T)rhs[j][i];
		return (res);
	}

	Matrix	operator*(T rhs) const
	{
		Matrix	res(*this);

		for (unsigned j = 0; j < HEIGHT; ++j)
			for (unsigned i = 0; i < WIDTH; ++i)
				res[j][i] *= rhs;
		return (res);
	}
};

/* ########################################################################## */

template <typename T, unsigned H, unsigned W>
std::ostream	&operator<<(std::ostream &lhs, const Matrix<T, H, W> &rhs)
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