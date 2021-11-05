#pragma once
#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
#include <iterator>
template <class T>
class Vector
{
private:
	std::vector<T> vector;
public:
	Vector(const size_t size=0) 
	{
		for (size_t i = 0; i < size; i++)
		{
			vector.push_back(0);
		}
	}
	Vector(const Vector<T>& rhs) = default; 
	~Vector() = default;
	auto Begin() const noexcept
	{
		return vector.begin();
	}
	auto End() const noexcept
	{
		return vector.end();
	}
	auto Begin() noexcept
	{
		return vector.begin();
	}
	auto End() noexcept
	{
		return vector.end();
	}
	void Clear(); 
	size_t GetSize() const; 
	const T* GetData() const;
	void Print() const; 
	void PushBack(const T& value); 
	void Insert(const T& value, const size_t index);
	void Insert(typename std::vector<T>::iterator it, const T& value)
	{
		vector.insert(it, value);
	}
	auto Erase(const size_t index); 
	auto Erase(typename std::vector<T>::const_iterator it)
	{
		return vector.erase(it);
	}
	Vector<T>& operator=(const Vector<T>& rhs) = default;
	T& operator[] (const size_t index); 
	T operator[](const size_t index) const; 
	Vector<T>& operator+= (const Vector<T>& rhs); 
	Vector<T> operator+(const Vector<T>& rhs) const; 
	Vector<T>& operator-= (const Vector<T>& rhs); 
	Vector<T> operator-(const Vector<T>& rhs) const; 
	T DotProduct(const Vector<T>& rhs) const 
	{
		if (vector.size() != rhs.vector.size()) throw "Bad dimensions";
		T scalar_product = 0;
		for (size_t i = 0; i < vector.size(); i++)
		{
			scalar_product += vector[i] * rhs.vector[i];
		}
		return scalar_product;
	}
	Vector<T>& operator*=(const T& value); 
	Vector<T> operator*(const T& value) const; 
	Vector<T>& operator/=(const T& value); 
	Vector<T> operator/(const T& value) const; 
	bool operator==(const Vector<T>& rhs) const; 
	bool operator!=(const Vector<T>& rhs) const; 
};
template<>
std::complex<float> Vector<std::complex<float>>::DotProduct(const Vector<std::complex<float>>& rhs) const 
{
	if (vector.size() != rhs.vector.size()) throw "Bad dimensions";
	std::complex<float> scalar_product = 0;
	for (size_t i = 0; i < vector.size(); i++)
	{
		scalar_product += std::complex<float>(vector[i].real() * rhs.vector[i].real(), (-1) * vector[i].imag() * rhs.vector[i].imag());
	}
	return scalar_product;
}
template<>
std::complex<double> Vector<std::complex<double>>::DotProduct(const Vector<std::complex<double>>& rhs) const 
{
	if (vector.size() != rhs.vector.size()) throw "Bad dimensions";
	std::complex<double> scalar_product = 0;
	for (size_t i = 0; i < vector.size(); i++)
	{
		scalar_product += std::complex<double>(vector[i].real() * rhs.vector[i].real(), (-1) * vector[i].imag() * rhs.vector[i].imag());
	}
	return scalar_product;
}

template <class T>
Vector<T>& operator*=(const T& value, Vector<T>& rhs); 
template <class T>
Vector<T> operator*(const T& value, const Vector<T>& rhs); 
template <class T>
std::ostream& operator<< (std::ostream& out, const Vector<T>& vector);
#include "Vector.inl"