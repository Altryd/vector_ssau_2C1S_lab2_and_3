#pragma once
#include <iostream>
#include <complex>
template <class T>
class Vector
{
private:
	T* data;
	size_t size;
	size_t capacity;
	size_t grow_size;
	void ExpandCapacityByN(const size_t n, const size_t index = 0, const bool end_insertion = true);
public:
	Vector() : data(NULL), size(0), capacity(0), grow_size(10) {} 
	Vector(const size_t size) 
	{
		grow_size = 10;
		this->size = size;
		capacity = size + grow_size;
		data = new T[capacity];
		for (size_t i = 0; i < capacity; i++)
		{
			data[i] = 0;
		}
	}
	~Vector() { delete[] data; }
	Vector(const Vector<T>& rhs); 
	void Clear(); 
	size_t GetSize() const; 
	const T* GetData() const;
	void Print() const; 
	void PushBack(const T& value); 
	void Insert(const T& value, const size_t index);  
	void Erase(const size_t index); 
	Vector<T>& operator=(const Vector<T>& rhs); 
	T& operator[] (const size_t index); 
	T operator[](const size_t index) const; 
	Vector<T>& operator+= (const Vector<T>& rhs); 
	Vector<T> operator+(const Vector<T>& rhs) const; 
	Vector<T>& operator-= (const Vector<T>& rhs); 
	Vector<T> operator-(const Vector<T>& rhs) const; 
	T DotProduct(const Vector<T>& rhs) const 
	{
		if (size != rhs.size) throw "Bad dimensions";
		T scalar_product = 0;
		for (size_t i = 0; i < size; i++)
		{
			scalar_product += data[i] * rhs.data[i];
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
	if (size != rhs.size) throw "Bad dimensions";
	std::complex<float> scalar_product = 0;
	for (size_t i = 0; i < size; i++)
	{
		scalar_product += std::complex<float>(data[i].real() * rhs.data[i].real(), (-1) * data[i].imag() * rhs.data[i].imag());
	}
	return scalar_product;
}
template<>
std::complex<double> Vector<std::complex<double>>::DotProduct(const Vector<std::complex<double>>& rhs) const 
{
	if (size != rhs.size) throw "Bad dimensions";
	std::complex<double> scalar_product = 0;
	for (size_t i = 0; i < size; i++)
	{
		scalar_product += std::complex<double>(data[i].real() * rhs.data[i].real(), (-1) * data[i].imag() * rhs.data[i].imag());
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