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
	Vector() : data(NULL), size(0), capacity(0), grow_size(10) {} //check
	Vector(const size_t size) //check
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
	Vector(const Vector<T>& rhs); //check
	void Clear(); //check
	size_t GetSize() const; //check
	const T* GetData() const;
	void Print() const; 
	void PushBack(const T& value); //check
	void Insert(const T& value, const size_t index);  //check
	void Erase(const size_t index); //check
	Vector<T>& operator=(const Vector<T>& rhs); //check
	T& operator[] (const size_t index); //check
	T operator[](const size_t index) const; //check
	Vector<T>& operator+= (const Vector<T>& rhs); //check
	Vector<T> operator+(const Vector<T>& rhs) const; //check
	Vector<T>& operator-= (const Vector<T>& rhs); //check
	Vector<T> operator-(const Vector<T>& rhs) const; //check
	T DotProduct(const Vector<T>& rhs) const //check
	{
		if (size != rhs.size) throw "Bad dimensions";
		T scalar_product = 0;
		for (size_t i = 0; i < size; i++)
		{
			scalar_product += data[i] * rhs.data[i];
		}
		return scalar_product;
	}
	//OLD VERSION, Delete or Fix Later:
	//std::complex<T> DotProduct(const Vector<std::complex<T>>& rhs) const
	//{
	//	if (size != rhs.size) throw "Bad dimensions";
	//	std::complex<T> scalar_product = 0;
	//	for (size_t i = 0; i < size; i++)
	//	{
	//		scalar_product += std::complex<T>(data[i].real() * rhs.data[i].real(), (-1) * data[i].imag() * rhs.data[i].imag());
	//	}
	//	return scalar_product;
	//}
	Vector<T>& operator*=(const T& value); //check
	Vector<T> operator*(const T& value) const; //check
	Vector<T>& operator/=(const T& value); //check
	Vector<T> operator/(const T& value) const; //check
	bool operator==(const Vector<T>& rhs) const; //check
	bool operator!=(const Vector<T>& rhs) const; //check
};
template<>
std::complex<float> Vector<std::complex<float>>::DotProduct(const Vector<std::complex<float>>& rhs) const //check
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
std::complex<double> Vector<std::complex<double>>::DotProduct(const Vector<std::complex<double>>& rhs) const //check
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
Vector<T>& operator*=(const T& value, Vector<T>& rhs); //check
template <class T>
Vector<T> operator*(const T& value, const Vector<T>& rhs); //check
template <class T>
std::ostream& operator<< (std::ostream& out, const Vector<T>& vector);
#include "Vector.inl"