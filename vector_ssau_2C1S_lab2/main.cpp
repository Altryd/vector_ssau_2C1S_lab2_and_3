#include "Vector.h"
#include <complex>
int main()
{
	Vector<int> int_vector(11);
	int_vector.Insert(0, 0);
	int_vector.Insert(1, 0);
	int_vector.Insert(2, 0);
	std::cout << int_vector << std::endl;

	Vector<std::complex<double>> complex_vector;
	complex_vector.PushBack({ 1,1 });
	complex_vector.PushBack({ 1,-1 });
	Vector<std::complex<double>> complex_vector2;
	complex_vector2.PushBack({ 2,2 });
	complex_vector2.PushBack({ 3,-3 });

	std::cout<< complex_vector.DotProduct(complex_vector2);
}