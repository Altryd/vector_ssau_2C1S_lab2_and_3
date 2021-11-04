#pragma once
#include <iostream>
#include <iterator>
#include "Vector.h"
template<class T>
void Vector<T>::Insert(const T& value, const size_t index)
{
	if (index > vector.size()) throw std::out_of_range("Index is out of range");
	auto ky = std::next(vector.begin(), index);
	vector.insert(ky, value);
}
template <class T>
void Vector<T>::Clear()
{
	vector.clear();
}
template <class T>
size_t Vector<T>::GetSize() const
{
	return vector.size();
}
template <class T>
const T* Vector<T>::GetData() const
{
	return vector.data();
}
template <class T>
void Vector<T>::Print() const
{
	size_t size = vector.size();
	if (vector.size())
	{
		std::cout << "Vector is empty" << std::endl;
		return;
	}
	std::cout << "[";
	for (size_t i = 0; i < size - 1; i++)
	{
		std::cout << vector[i] << " , ";
	}
	std::cout << vector[size - 1] << "] , the size of vector:" << size << std::endl;
}
template <class T>
void Vector<T>::PushBack(const T& value)
{
	vector.push_back(value);
}
template <class T>
auto Vector<T>::Erase(const size_t index)
{
	if (index >= vector.size()) throw std::out_of_range("Index is out of range");
	return vector.erase(std::next(vector.begin(),index));
}
template <class T>
T& Vector<T>::operator[] (const size_t index)
{
	if (index >= vector.size()) throw std::out_of_range("Index is out of range");
	return vector[index];
}
template <class T>
T Vector<T>::operator[](const size_t index) const
{
	if (index >= vector.size()) throw std::out_of_range("Index is out of range");
	return vector[index];
}
template <class T>
Vector<T>& Vector<T>::operator+= (const Vector<T>& rhs)
{
	if (vector.size() != rhs.vector.size()) throw "Bad dimensions";
	for (size_t i = 0; i < vector.size(); i++)
	{
		vector[i] += rhs.vector[i];
	}
	return *this;
}
template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& rhs) const
{
	if (vector.size() != rhs.vector.size()) throw "Bad dimensions";
	Vector result(*this);
	result += rhs;
	return result;
}
template <class T>
Vector<T>& Vector<T>::operator-= (const Vector<T>& rhs)
{
	if (vector.size() != rhs.vector.size()) throw "Bad dimensions";
	for (size_t i = 0; i < vector.size(); i++)
	{
		vector[i] -= rhs.vector[i];
	}
	return *this;
}
template <class T>
Vector<T> Vector<T>::operator-(const Vector<T>& rhs) const
{
	if (vector.size() != rhs.vector.size()) throw "Bad dimensions";
	Vector result(*this);
	result -= rhs;
	return result;
}
template <class T>
Vector<T>& Vector<T>::operator*=(const T& value)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		vector[i] *= value;
	}
	return *this;
}
template <class T>
Vector<T> Vector<T>::operator*(const T& value) const
{
	Vector<T> result(*this);
	result *= value;
	return result;
}
template <class T>
Vector<T>& Vector<T>::operator/=(const T& value)
{
	if (value == (T)0) throw "Dividing by zero is prohibited";
	for (size_t i = 0; i < vector.size(); i++)
	{
		vector[i] /= value;
	}
	return *this;
}
template <class T>
Vector<T> Vector<T>::operator/(const T& value) const
{
	Vector<T> result(*this);
	result /= value;
	return result;
}
template <class T>
bool Vector<T>::operator==(const Vector<T>& rhs) const
{
	return vector == rhs.vector;
}
template<>
bool Vector<double>::operator==(const Vector<double>& rhs) const
{
		if (vector.size() != rhs.vector.size()) return false;
		for (size_t i = 0; i < vector.size(); i++)
		{
			if (abs(vector[i] - rhs.vector[i]) >= 0.005) return false;
		}
		return true;
}
template<>
bool Vector<float>::operator==(const Vector<float>& rhs) const
{
	if (vector.size() != rhs.vector.size()) return false;
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (abs(vector[i] - rhs.vector[i]) >= 0.005) return false;
	}
	return true;
}
template <class T>
bool Vector<T>::operator!=(const Vector<T>& rhs) const
{
	return !(*this == rhs);
}
template <class T>
Vector<T>& operator*=(const T& value, Vector<T>& rhs)
{
	rhs *= value;
	return rhs;
}
template <class T>
Vector<T> operator*(const T& value, const Vector<T>& rhs)
{
	Vector<T> result(rhs);
	result *= value;
	return result;
}
template <class T>
std::ostream& operator<< (std::ostream& out, const Vector<T>& vector)
{
	size_t size = vector.GetSize();
	if (!size)
	{
		out << "Vector is empty" << std::endl;
		return out;
	}
	out << "[";
	for (size_t i = 0; i < size - 1; i++)
	{
		out << vector[i] << " , ";
	}
	out << vector[size - 1] << "] , the size of vector:" << size << std::endl;
	return out;
}