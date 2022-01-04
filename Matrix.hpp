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

		// this->corrupted(); // included in copy constructor
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

		// this->corrupted(); // included in copy constructor
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

		// this->corrupted(); // included in copy constructor
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
		Matrix	res(this->height(), rhs.width());

		this->corrupted();
		rhs.corrupted();
		if (this->width() != rhs.height())
			throw std::logic_error("Operation on different size Matrices");

		for (unsigned j = 0; j < res.height(); ++j)
			for (unsigned i = 0; i < res.width(); ++i)
				for (unsigned p = 0; p < this->width(); ++p)
					res[j][i] += (*this)[j][p] * rhs[p][i];
		return (res);
	}

	Matrix	&operator+=(const Matrix &rhs) { return (*this = *this + rhs); }
	Matrix	&operator-=(const Matrix &rhs) { return (*this = *this - rhs); }
	Matrix	&operator*=(float rhs) { return (*this = *this * rhs); }

	/* -^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^ */

	private :

	/* unprotected */
	void	_swap_row(unsigned col1, unsigned col2)
	{
		T	tmp;

		for (unsigned i = 0; i < (*this)[col1].size(); ++i)
		{
			tmp = (*this)[col1][i];
			(*this)[col1][i] = (*this)[col2][i];
			(*this)[col2][i] = tmp;
		}
	}

	/* unprotected, divide a row by a scalar */
	void	_scalar_row(unsigned col, T scalar)
	{
		for (unsigned i = 0; i < (*this)[col].size(); ++i)
			if ((*this)[col][i] != 0)
				(*this)[col][i] /= scalar;
	}

	/* unprotected */
	void	_add_scalar_row(unsigned col1, unsigned col2, T scalar)
	{
		static const double	threshold = 1e-6;
		Vector<T>			tmp((*this)[col2]);

		tmp *= scalar;
		for (unsigned i = 0; i < (*this)[col1].size(); ++i)
		{
			(*this)[col1][i] += tmp[i];
			if (abs((*this)[col1][i]) < (T)threshold)
				(*this)[col1][i] = 0;
		}
	}

	/* -^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^ */

	public :

	/* Undefined behavior for 0x0 matrix */
	T		trace(void) const
	{
		T	res;

		this->corrupted();
		if (this->width() != this->height())
			throw std::logic_error("Trace on non square matrix");
		if (this->width() > 0)
			res = (*this)[0][0];
		for (unsigned i = 1; i < this->width(); ++i)
			res = res + (*this)[i][i];
		return (res);
	}

	Matrix	transpose(void) const
	{
		Matrix	res(this->width(), this->height());

		this->corrupted();
		for (unsigned i = 0; i < this->height(); ++i)
			for (unsigned j = 0; j < this->width(); ++j)
				res[j][i] = (*this)[i][j];
		return (res);
	}

	Matrix	reduced_row_echelon(void) const
	{
		Matrix		res(*this);
		unsigned	column;
		unsigned	pivot_new;

		column = 0;
		// this->corrupted(); // included in copy constructor
		for (unsigned pivot_row = 0; pivot_row < this->height(); ++pivot_row)
		{
			pivot_new = pivot_row;
			while (pivot_new < res.height() && res[pivot_new][column] == 0)
				++pivot_new;
			if (pivot_new >= res.height())
			{
				++column;
				--pivot_row;	/* repeat row on next column */
				continue ;
			}
			if (pivot_new != pivot_row)
				res._swap_row(pivot_row, pivot_new);
			for (unsigned i = 0; i < this->height(); ++i)
				if (res[i][column] != 0 && res[pivot_row][column] &&
					i != pivot_row)
					res._add_scalar_row(i, pivot_row,
						-res[i][column] / res[pivot_row][column]);
			if (column > res.width())
				break;
			if (res[pivot_row][column] != 0)
				res._scalar_row(pivot_row, res[pivot_row][column]);
			++column;
		}
		return (res);
	}

	T		determinant(void) const
	{
		Matrix		res(*this);
		unsigned	column;
		unsigned	pivot_new;
		T			determinant;

		determinant = (T)1;
		column = 0;
		// this->corrupted(); // included in copy constructor
		if (this->width() != this->height())
			throw std::logic_error("Determinant on non square matrix");
		for (unsigned pivot_row = 0; pivot_row < this->height(); ++pivot_row)
		{
			pivot_new = pivot_row;
			while (pivot_new < res.height() && res[pivot_new][column] == 0)
				++pivot_new;
			if (pivot_new >= res.height())
				return (0);	/* null coefficient in the diagonal */
			if (pivot_new != pivot_row)
			{
				res._swap_row(pivot_row, pivot_new);
				determinant *= -1;
			}
			for (unsigned i = 0; i < this->height(); ++i)
				if (res[i][column] != 0 && res[pivot_row][column] &&
					i != pivot_row)
					res._add_scalar_row(i, pivot_row,
						-res[i][column] / res[pivot_row][column]);
			if (column > res.width())
				break;
			++column;
		}
		for (unsigned i = 0; i < res.size(); ++i)
			determinant *= res[i][i];
		return (determinant);
	}

	Matrix	inverse(void) const
	{
		Matrix		res(this->height(), this->height() * 2);
		Matrix		inverse(this->height(), this->height());
		unsigned	column;
		unsigned	pivot_new;

		column = 0;
		// this->corrupted(); // included in copy constructor
		if (this->width() != this->height())
			throw std::logic_error("Determinant on non square matrix");
		for (unsigned i = 0; i < res.height(); ++i)
		{
			res[i][i + res.height()] = (T)1;
			for (unsigned j = 0; j < res.height(); ++j)
				res[i][j] = (*this)[i][j];
		}
		for (unsigned pivot_row = 0; pivot_row < this->height(); ++pivot_row)
		{
			pivot_new = pivot_row;
			while (pivot_new < res.height() && res[pivot_new][column] == 0)
				++pivot_new;
			if (pivot_new >= res.height())
				throw std::logic_error("Non invertible matrix");
			if (pivot_new != pivot_row)
				res._swap_row(pivot_row, pivot_new);
			for (unsigned i = 0; i < this->height(); ++i)
				if (res[i][column] != 0 && res[pivot_row][column] &&
					i != pivot_row)
					res._add_scalar_row(i, pivot_row,
						-res[i][column] / res[pivot_row][column]);
			if (column > res.width())
				break;
			if (res[pivot_row][column] != 0)
				res._scalar_row(pivot_row, res[pivot_row][column]);
			++column;
		}
		for (unsigned i = 0; i < inverse.height(); ++i)
			for (unsigned j = 0; j < inverse.width(); ++j)
				inverse[i][j] = res[i][j + res.height()];
		return (inverse);
	}








































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