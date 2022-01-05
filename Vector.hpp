template <typename T>
struct	Vector;

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <vector>
# include "Algorithm.hpp"	/* sqrt, square */
# include <iostream>		/* ostream */

/* ########################################################################## */

template <typename T = float>
struct	Vector : public std::vector<T>
{
	Vector(void) { }
	Vector(unsigned size)
	{
		this->resize(size);
		for (unsigned i = 0; i < size; ++i)
			(*this)[i] = (T)0;
	}

	Vector(const Vector &src) { *this = src; }
	Vector(const std::vector<T> &src) { *this = src; }
	virtual	~Vector(void) { }

	Vector	&operator=(const Vector &rhs)
	{
		this->resize(rhs.size());
		for (unsigned i = 0; i < this->size(); ++i)
			(*this)[i] = rhs[i];
		return (*this);
	}

	Vector	&operator=(const std::vector<T> &rhs)
	{
		this->resize(rhs.size());
		for (unsigned i = 0; i < this->size(); ++i)
			(*this)[i] = rhs[i];
		return (*this);
	}

	/* -^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^ */

	Vector	operator+(const Vector &rhs) const
	{
		Vector	res(*this);

		if (rhs.size() != this->size())
			throw std::logic_error("Operation on different size Vectors");
		for (unsigned i = 0; i < this->size(); ++i)
			res[i] += (T)rhs[i];
		return (res);
	}

	Vector	operator-(const Vector &rhs) const
	{
		Vector	res(*this);

		if (rhs.size() != this->size())
			throw std::logic_error("Operation on different size Vectors");
		for (unsigned i = 0; i < this->size(); ++i)
			res[i] -= (T)rhs[i];
		return (res);
	}

	/* scaling */
	Vector	operator*(float rhs) const
	{
		Vector	res(*this);

		for (unsigned i = 0; i < this->size(); ++i)
			res[i] *= rhs;
		return (res);
	}

	/* scaling */
	Vector	operator/(float rhs) const
	{
		Vector	res(*this);

		for (unsigned i = 0; i < this->size(); ++i)
			res[i] /= rhs;
		return (res);
	}

	/* dot product */
	T		operator*(const Vector &rhs) const
	{
		T	res;

		if (rhs.size() != this->size())
			throw std::logic_error("Operation on different size Vectors");
		res = (T)0;
		for (unsigned i = 0; i < this->size(); ++i)
			res += (*this)[i] * rhs[i];
		return (res);
	}

	/* cross product */
	Vector	cross(const Vector &rhs) const
	{
		Vector	res(3);

		if (rhs.size() != 3 || this->size() != 3)
			throw std::logic_error("Cross product on non 3 dimentional Vectors");
		res[0] = (*this)[1] * rhs[2] - (*this)[2] * rhs[1];
		res[1] = (*this)[2] * rhs[0] - (*this)[0] * rhs[2];
		res[2] = (*this)[0] * rhs[1] - (*this)[1] * rhs[0];
		return (res);
	}

	Vector	&operator+=(const Vector &rhs) { return (*this = *this + rhs); }
	Vector	&operator-=(const Vector &rhs) { return (*this = *this - rhs); }
	Vector	&operator*=(float rhs) { return (*this = *this * rhs); }
	Vector	&operator/=(float rhs) { return (*this = *this / rhs); }
	Vector	&operator*=(const Vector &rhs) { return (*this = *this * rhs); }

	/* fill with 0 */
	void		null(void)
	{
		for (T &scalar : *this)
			scalar = (T)0;
	}

	/* -^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^ */

	T	norm(void) const
	{
		T	res;

		if (this->size() > 0)
			res = square((*this)[0]);
		for (unsigned i = 1; i < this->size(); ++i)
			res += square((*this)[i]);
		return (sqrt(res));
	}

	T	norm_1(void) const
	{
		T	res;

		if (this->size() > 0)
			res = abs((*this)[0]);
		for (unsigned i = 1; i < this->size(); ++i)
			res += abs((*this)[i]);
		return (res);
	}
	T	norm_inf(void) const
	{
		T	res;

		if (this->size() > 0)
			res = abs((*this)[0]);
		for (unsigned i = 1; i < this->size(); ++i)
			if (res < abs((*this)[i]))
				res = abs((*this)[i]);
		return (res);
	}

	T	summation(void) const
	{
		T	res;

		if (this->size() > 0)
			res = (*this)[0];
		for (unsigned i = 1; i < this->size(); ++i)
			res += (*this)[i];
		return (res);
	}

	/* -^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^-.-^ */

	T	cosine(const Vector &rhs) const
	{
		T	res;

		res = *this * rhs;
		return (res / (this->norm() * rhs.norm()));
	}
};

/* ########################################################################## */

template <typename T>
std::ostream	&operator<<(std::ostream &lhs, const Vector<T> &rhs)
{
	lhs << "[";
	for (unsigned i = 0; i < rhs.size(); ++i)
	{
		lhs << rhs[i];
		if (i + 1 < rhs.size())
			lhs << ", ";
	}
	lhs << "]";
	return (lhs);
}

template <typename T>
Vector<T>	linear_combination(const Vector<Vector<T>> &vectors,
	const Vector<T> &coefficients)
{
	Vector<T>	res;
	unsigned	size;
	unsigned	id;

	if (vectors.size() != coefficients.size())
		throw std::logic_error("Coefficients not matching vectors");
	size = vectors[0].size();
	res = Vector<T>(size);
	id = 0;
	for (const Vector<T> &vec : vectors)
	{
		if (vec.size() != size)
			throw std::logic_error("Corrupted data");
		res += vec * coefficients[id++];
	}
	return (res);
}

#endif