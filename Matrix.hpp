#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <vector>
# include "Vector.hpp"	/* Vector */
# include <iostream>	/* ostream */

/* ########################################################################## */

template <typename T = float>
struct	Matrix : public std::vector<std::vector<T>>
{
	Matrix(void) { }
	Matrix(unsigned height, unsigned width)
	{
		this->resize(height);
		for (unsigned j = 0; j < this->size(); ++j)
		{
			(*this)[j].resize(width);
			for (unsigned i = 0; i < width; ++i)
				(*this)[j][i] = (T)0;
		}
	}

	Matrix(const Matrix &src) { *this = src; }
	Matrix(const std::vector<std::vector<T>> &src) { *this = src; }
	virtual	~Matrix(void) { }

	Matrix	&operator=(const Matrix &rhs)
	{ return (*this = (std::vector<std::vector<T>>)rhs); }

	Matrix	&operator=(const std::vector<std::vector<T>> &rhs)
	{
		unsigned	width;

		width = rhs[0].size();
		this->resize(rhs.size());
		for (unsigned j = 0; j < this->size(); ++j)
		{
			if (rhs[j].size() != width)
				throw std::logic_error("Corrupted Matrix");
			(*this)[j].resize(width);
			for (unsigned i = 0; i < this->width(); ++i)
				(*this)[j][i] = rhs[j][i];
		}
		return (*this);
	}

	unsigned	width(void) const	{ return ((*this)[0].size()); }
	unsigned	height(void) const	{ return (this->size()); }

	/* throw exception if the matrix is corrupted */
	void		corrupted(void) const
	{
		unsigned	width;
		
		width = (*this)[0].size();
		for (const std::vector<T> &line : *this)
			if (line.size() != width)
				throw std::logic_error("Corrupted Matrix");
	}

	void		size_check(const Matrix &rhs) const
	{
		if (this->height() != rhs.height() || this->width() != rhs.width())
			throw std::logic_error("Operation on different size Matrices");
	}

	/* fill with 0 */
	void		null(void)
	{
		for (std::vector<T> &row : *this)
			for (T &scalar : row)
				scalar = (T)0;
	}

	/* -^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^ */

	Matrix	operator+(const Matrix &rhs) const
	{
		Matrix	res(*this);

		this->corrupted();
		rhs.corrupted();
		this->size_check(rhs);
		for (unsigned j = 0; j < this->height(); ++j)
			for (unsigned i = 0; i < this->width(); ++i)
				res[j][i] += (T)rhs[j][i];
		return (res);
	}


	Matrix	operator-(const Matrix &rhs) const
	{
		Matrix	res(*this);

		this->corrupted();
		rhs.corrupted();
		this->size_check(rhs);
		for (unsigned j = 0; j < this->height(); ++j)
			for (unsigned i = 0; i < this->width(); ++i)
				res[j][i] -= (T)rhs[j][i];
		return (res);
	}

	/* scaling */
	Matrix	operator*(float rhs) const
	{
		Matrix	res(*this);

		this->corrupted();
		for (unsigned j = 0; j < this->height(); ++j)
			for (unsigned i = 0; i < this->width(); ++i)
				res[j][i] *= rhs;
		return (res);
	}

	/* Matrix - Vector product */
	Vector<T>	operator*(const Vector<T> &rhs) const
	{
		Vector<T>	res;

		this->corrupted();
		if (this->width() != rhs.size())
			throw std::logic_error("Operation on different size Matrix and Vector");
		res.resize(this->height());
		res.null();

		for (unsigned j = 0; j < this->height(); ++j)
			for (unsigned i = 0; i < this->width(); ++i)
				res[j] += (*this)[j][i] * rhs[i];
		return (res);
	}

	/* Matrix - Matrix product */
	Matrix	operator*(const Matrix &rhs) const
	{
		Matrix	res;

		this->corrupted();
		rhs.corrupted();
		if (this->width() != rhs.height())
			throw std::logic_error("Operation on different size Matrices");
		res = Matrix(this->height(), rhs.width());
		// res.resize(this->height());
		// for (auto &row : res)
		// 	row.resize(rhs.width());

		for (unsigned j = 0; j < res.height(); ++j)
			for (unsigned i = 0; i < res.width(); ++i)
				for (unsigned p = 0; p < this->width(); ++p)
					res[j][i] += (*this)[j][p] * rhs[p][i];
		return (res);
	}

	Matrix	&operator+=(const Matrix &rhs) { return (*this = *this + rhs); }
	Matrix	&operator-=(const Matrix &rhs) { return (*this = *this - rhs); }
	Matrix	&operator*=(float rhs) { return (*this = *this * rhs); }
};

/* ########################################################################## */

template <typename T>
std::ostream	&operator<<(std::ostream &lhs, const Matrix<T> &rhs)
{
	for (const std::vector<T> &line : rhs)
	{
		lhs << "[";
		for (unsigned i = 0; i < rhs.width(); ++i)
		{
			lhs << line[i];
			if (i + 1 < rhs.width())
				lhs << ", ";
		}
		lhs << "]" << std::endl;
	}
	return (lhs);
}

#endif