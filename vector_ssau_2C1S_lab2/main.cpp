#include "Vector.h"
#include <complex>

template <typename T>
void GetValueFromUser(T& value)
{
	while (true)
	{
		std::cin >> value;
		if (std::cin.fail() || std::cin.bad())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "The input is incorrect, please try again" << std::endl;
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}
	}
}
template<typename T>
void GetValueFromUser(std::complex<T>& value)
{
	T real = 0;
	T imag = 0;
	std::cout << "Please enter the real part of complex number" << std::endl;
	GetValueFromUser(real);
	std::cout << "Please enter the imaginary part of complex number" << std::endl;
	GetValueFromUser(imag);
	value.real(real);
	value.imag(imag);
}
template <typename T>
bool IsValueInRange(const T& value, const T& left_border, const T& right_border)
{
	return (value >= left_border && value <= right_border);
}
template <typename T>
void GetValueFromUserInRange(T& value, const T& left_border, const T& right_border, const char* condition = "")
{
	std::cout << condition;
	while (true)
	{
		GetValueFromUser(value);
		if (IsValueInRange(value, left_border, right_border))
		{
			return;
		}
		else
		{
			std::cout << "The value is not in range, try again" << std::endl;
		}
	}
}
template <typename Type_Vectors>
void Menu(Type_Vectors)
{
	bool function_is_working = true;
	Vector<Type_Vectors> first_vector;
	Vector<Type_Vectors> second_vector;
	while (function_is_working)
	{
		std::cout << "First vector:" << first_vector << std::endl;
		std::cout << "\nSecond vector:" << second_vector << std::endl;
		std::cout << "Enter:\n0 - to work and edit with single vector" << std::endl;
		std::cout << "1 - to sum two vectors\n2 - to substract second vector from first" << std::endl;
		std::cout << "3 - to calculate the scalar product of two vectors\n4 - clear two vectors" << std::endl;
		std::cout << "5 - Print are two vectors equal or not\n6 - make first vector equal to second\n";
		std::cout << "7 - finish working with vectors" << std::endl;
		long int action = 0;
		GetValueFromUserInRange(action, (long int)0, (long int)7, "\nEnter a number in range [0;7]");
		switch (action)
		{
		case 0: //работа с векторами по отдельности
		{
			long int order_number = 0;
			GetValueFromUserInRange(order_number, (long int)1, (long int)2, "Enter the order number of vector you wanted to edit");
			//[] , * by scalar , / by scalar
			if (order_number == 1)
			{
				bool working_with_first_vector = true;
				while (working_with_first_vector)
				{
					system("cls");
					std::cout << first_vector << std::endl;
					std::cout << "You are now editing the first vector, Enter:" << std::endl;
					std::cout << "0 - to edit the element in the vector with index\n1 - to multiply the vector by a scalar" << std::endl;
					std::cout << "2 - to divide the vector by a scalar\n3 - add a new random element in the vector with index " << std::endl;
					std::cout << "4 - remove an element from the vector\n5 - finish working with the vector" << std::endl;
					long int editing_first_vector = 0;
					GetValueFromUserInRange(editing_first_vector, (long int)0, (long int)5, "Enter the number in range[0;5]");
					switch (editing_first_vector)
					{
					case 0: //edit
					{
						size_t index = 0;
						GetValueFromUser(index);
						try
						{
							std::cout << "Enter a new value for the element" << std::endl;
							Type_Vectors value = 0;
							GetValueFromUser(value);
							first_vector[index] = value;
						}
						catch (std::out_of_range& ex)
						{
							std::cout << ex.what() << " Try again" << std::endl;
							system("pause");
						}
						break;
					}
					case 1: //*=
					{
						std::cout << "Enter a scalar" << std::endl;
						Type_Vectors scalar = 0;
						GetValueFromUser(scalar);
						first_vector *= scalar;
						break;
					}
					case 2: // /=
					{
						std::cout << "Enter a scalar" << std::endl;
						Type_Vectors scalar = 0;
						GetValueFromUser(scalar);
						try
						{
							first_vector /= scalar;
						}
						catch (const char* ex)
						{
							std::cout << ex << " Try again" << std::endl;
							system("pause");
						}
						break;
					}
					case 3: //insert
					{
						if (first_vector.GetSize())
						{
							std::cout << "Enter the index of element to insert" << std::endl;
							size_t index = 0;
							GetValueFromUser(index);
							try
							{
								Type_Vectors value = (Type_Vectors)rand();
								first_vector.Insert(value, index);
							}
							catch (std::out_of_range& ex)
							{
								std::cout << ex.what() << " Try again" << std::endl;
								system("pause");
							}
						}
						else
						{
							first_vector.PushBack((Type_Vectors)rand());
						}
						break;
					}
					case 4: //erase
					{
						if (first_vector.GetSize())
						{
							std::cout << "Enter the index of element to delete" << std::endl;
							size_t index = 0;
							GetValueFromUser(index);
							try
							{
								first_vector.Erase(index);
							}
							catch (std::out_of_range& ex)
							{
								std::cout << ex.what() << " Try again" << std::endl;
								system("pause");
							}
						}
						else
						{
							std::cout << "There are no elements to delete" << std::endl;
						}
						break;
					}
					case 5: //finish working
					{
						working_with_first_vector = false;
						break;
					}
					}
				}
			}
			else
			{
				bool working_with_second_vector = true;
				while (working_with_second_vector)
				{
					system("cls");
					std::cout << second_vector << std::endl;
					std::cout << "You are now editing the second vector, Enter:" << std::endl;
					std::cout << "0 - to edit the element in the vector with index\n1 - to multiply the vector by a scalar" << std::endl;
					std::cout << "2 - to divide the vector by a scalar\n3 - add a new random element in the vector with index " << std::endl;
					std::cout << "4 - remove an element from the vector\n5 - finish working with the vector" << std::endl;
					long int editing_second_vector = 0;
					GetValueFromUserInRange(editing_second_vector, (long int)0, (long int)5, "Enter the number in range[0;5]");
					switch (editing_second_vector)
					{
					case 0: //edit
					{
						size_t index = 0;
						GetValueFromUser(index);
						try
						{
							std::cout << "Enter a new value for the element" << std::endl;
							Type_Vectors value = 0;
							GetValueFromUser(value);
							second_vector[index] = value;
						}
						catch (std::out_of_range& ex)
						{
							std::cout << ex.what() << " Try again" << std::endl;
							system("pause");
						}
						break;
					}
					case 1: //*=
					{
						std::cout << "Enter a scalar" << std::endl;
						Type_Vectors scalar = 0;
						GetValueFromUser(scalar);
						second_vector *= scalar;
						break;
					}
					case 2: // /=
					{
						std::cout << "Enter a scalar" << std::endl;
						Type_Vectors scalar = 0;
						GetValueFromUser(scalar);
						try
						{
							second_vector /= scalar;
						}
						catch (const char* ex)
						{
							std::cout << ex << " Try again" << std::endl;
							system("pause");
						}
						break;
					}
					case 3: //insert
					{
						if (second_vector.GetSize())
						{
							std::cout << "Enter the index of element to insert" << std::endl;
							size_t index = 0;
							GetValueFromUser(index);
							try
							{
								Type_Vectors value = (Type_Vectors)rand();
								second_vector.Insert(value, index);
							}
							catch (std::out_of_range& ex)
							{
								std::cout << ex.what() << " Try again" << std::endl;
								system("pause");
							}
						}
						else
						{
							second_vector.PushBack((Type_Vectors)rand());
						}
						break;
					}
					case 4: //erase
					{
						if (second_vector.GetSize())
						{
							std::cout << "Enter the index of element to erase" << std::endl;
							size_t index = 0;
							GetValueFromUser(index);
							try
							{
								second_vector.Erase(index);
							}
							catch (std::out_of_range& ex)
							{
								std::cout << ex.what() << " Try again" << std::endl;
								system("pause");
							}
						}
						else
						{
							std::cout << "There are no elements to delete" << std::endl;
						}
						break;
					}
					case 5: //finish working
					{
						working_with_second_vector = false;
						break;
					}
					}
				}
			}
			break;
		}
		case 1: //сложить два вектора
		{
			try
			{
				Vector<Type_Vectors> sum = first_vector + second_vector;
				std::cout << sum;
			}
			catch (const char* ex)
			{
				std::cout << ex << std::endl;
			}
			system("pause");
			break;
		}
		case 2: //вычесть из первого второй вектор
		{
			try
			{
				Vector<Type_Vectors> subtraction = first_vector - second_vector;
				std::cout << subtraction;
			}
			catch (const char* ex)
			{
				std::cout << ex << std::endl;
			}
			system("pause");
			break;
		}
		case 3: //скал¤рное произведение
		{
			try
			{
				Type_Vectors scalar_product = first_vector.DotProduct(second_vector);
				std::cout << scalar_product << std::endl;
			}
			catch (const char* ex)
			{
				std::cout << ex << std::endl;
			}
			system("pause");
			break;
		}
		case 4: //очистить векторы
		{
			first_vector.Clear();
			second_vector.Clear();
			break;
		}
		case 5: //оценить, равны ли вектора
		{
			first_vector == second_vector ? std::cout << "Vectors are equal" << std::endl :
				std::cout << "Vectors are different" << std::endl;
			system("pause");
			break;
		}
		case 6:
		{
			first_vector = second_vector;
			break;
		}
		case 7: //выйти из программы
		{
			function_is_working = false;
			break;
		}

		}
		system("cls");
	}
}
template <typename Type_Vectors>
void Menu(std::complex<Type_Vectors>)
{
	bool function_is_working = true;
	Vector<std::complex<Type_Vectors>> first_vector;
	Vector<std::complex<Type_Vectors>> second_vector;
	while (function_is_working)
	{
		std::cout << "First vector:" << first_vector << std::endl;
		std::cout << "\nSecond vector:" << second_vector << std::endl;
		std::cout << "Enter:\n0 - to work and edit with single vector" << std::endl;
		std::cout << "1 - to sum two vectors\n2 - to substract second vector from first" << std::endl;
		std::cout << "3 - to calculate the scalar product of two vectors\n4 - clear two vectors" << std::endl;
		std::cout << "5 - Print are two vectors equal or not\n6 - make first vector equal to second\n";
		std::cout << "7 - finish working with vectors" << std::endl;
		long int action = 0;
		GetValueFromUserInRange(action, (long int)0, (long int)7, "\nEnter a number in range [0;7]");
		switch (action)
		{
		case 0: //работа с векторами по отдельности
		{
			long int order_number = 0;
			GetValueFromUserInRange(order_number, (long int)1, (long int)2, "Enter the order number of vector you wanted to edit");
			//[] , * by scalar , / by scalar
			if (order_number == 1)
			{
				bool working_with_first_vector = true;
				while (working_with_first_vector)
				{
					system("cls");
					std::cout << first_vector << std::endl;
					std::cout << "You are now editing the first vector, Enter:" << std::endl;
					std::cout << "0 - to edit the element in the vector with index\n1 - to multiply the vector by a scalar" << std::endl;
					std::cout << "2 - to divide the vector by a scalar\n3 - add a new random element in the vector with index " << std::endl;
					std::cout << "4 - remove an element from the vector\n5 - finish working with the vector" << std::endl;
					long int editing_first_vector = 0;
					GetValueFromUserInRange(editing_first_vector, (long int)0, (long int)5, "Enter the number in range[0;5]");
					switch (editing_first_vector)
					{
					case 0: //edit
					{
						size_t index = 0;
						GetValueFromUser(index);
						try
						{
							std::cout << "Enter a new value for the element" << std::endl;
							std::complex<Type_Vectors> value((Type_Vectors)0, (Type_Vectors)0);
							GetValueFromUser(value);
							first_vector[index] = value;
						}
						catch (std::out_of_range& ex)
						{
							std::cout << ex.what() << " Try again" << std::endl;
							system("pause");
						}
						break;
					}
					case 1: //*=
					{
						std::cout << "Enter a scalar" << std::endl;
						std::complex<Type_Vectors> scalar((Type_Vectors)0, (Type_Vectors)0);
						GetValueFromUser(scalar);
						first_vector *= scalar;
						break;
					}
					case 2: // /=
					{
						std::cout << "Enter a scalar" << std::endl;
						std::complex<Type_Vectors> scalar((Type_Vectors)0, (Type_Vectors)0);
						GetValueFromUser(scalar);
						try
						{
							first_vector /= scalar;
						}
						catch (const char* ex)
						{
							std::cout << ex << " Try again" << std::endl;
							system("pause");
						}
						break;
					}
					case 3: //insert
					{
						if (first_vector.GetSize())
						{
							std::cout << "Enter the index of element to insert" << std::endl;
							size_t index = 0;
							GetValueFromUser(index);
							try
							{
								std::complex<Type_Vectors> value((Type_Vectors)rand(), (Type_Vectors)rand());
								first_vector.Insert(value, index);
							}
							catch (std::out_of_range& ex)
							{
								std::cout << ex.what() << " Try again" << std::endl;
								system("pause");
							}
						}
						else
						{
							first_vector.PushBack(std::complex<Type_Vectors>((Type_Vectors)rand(), (Type_Vectors)rand()));
						}
						break;
					}
					case 4: //erase
					{
						if (first_vector.GetSize())
						{
							std::cout << "Enter the index of element to delete" << std::endl;
							size_t index = 0;
							GetValueFromUser(index);
							try
							{
								first_vector.Erase(index);
							}
							catch (std::out_of_range& ex)
							{
								std::cout << ex.what() << " Try again" << std::endl;
								system("pause");
							}
						}
						else
						{
							std::cout << "There are no elements to delete" << std::endl;
						}
						break;
					}
					case 5: //finish working
					{
						working_with_first_vector = false;
						break;
					}
					}
				}
			}
			else
			{
				bool working_with_second_vector = true;
				while (working_with_second_vector)
				{
					system("cls");
					std::cout << second_vector << std::endl;
					std::cout << "You are now editing the second vector, Enter:" << std::endl;
					std::cout << "0 - to edit the element in the vector with index\n1 - to multiply the vector by a scalar" << std::endl;
					std::cout << "2 - to divide the vector by a scalar\n3 - add a new random element in the vector with index " << std::endl;
					std::cout << "4 - remove an element from the vector\n5 - finish working with the vector" << std::endl;
					long int editing_second_vector = 0;
					GetValueFromUserInRange(editing_second_vector, (long int)0, (long int)5, "Enter the number in range[0;5]");
					switch (editing_second_vector)
					{
					case 0: //edit
					{
						size_t index = 0;
						GetValueFromUser(index);
						try
						{
							std::cout << "Enter a new value for the element" << std::endl;
							std::complex<Type_Vectors> value((Type_Vectors)0, (Type_Vectors)0);
							GetValueFromUser(value);
							second_vector[index] = value;
						}
						catch (std::out_of_range& ex)
						{
							std::cout << ex.what() << " Try again" << std::endl;
							system("pause");
						}
						break;
					}
					case 1: //*=
					{
						std::cout << "Enter a scalar" << std::endl;
						std::complex<Type_Vectors> scalar((Type_Vectors)0, (Type_Vectors)0);
						GetValueFromUser(scalar);
						second_vector *= scalar;
						break;
					}
					case 2: // /=
					{
						std::cout << "Enter a scalar" << std::endl;
						std::complex<Type_Vectors> scalar((Type_Vectors)0, (Type_Vectors)0);
						GetValueFromUser(scalar);
						try
						{
							second_vector /= scalar;
						}
						catch (const char* ex)
						{
							std::cout << ex << " Try again" << std::endl;
							system("pause");
						}
						break;
					}
					case 3: //insert
					{
						if (second_vector.GetSize())
						{
							std::cout << "Enter the index of element to insert" << std::endl;
							size_t index = 0;
							GetValueFromUser(index);
							try
							{
								std::complex<Type_Vectors> value((Type_Vectors)rand(), (Type_Vectors)rand());
								second_vector.Insert(value, index);
							}
							catch (std::out_of_range& ex)
							{
								std::cout << ex.what() << " Try again" << std::endl;
								system("pause");
							}
						}
						else
						{
							second_vector.PushBack(std::complex<Type_Vectors>((Type_Vectors)rand(), (Type_Vectors)rand()));
						}
						break;
					}
					case 4: //erase
					{
						if (second_vector.GetSize())
						{
							std::cout << "Enter the index of element to erase" << std::endl;
							size_t index = 0;
							GetValueFromUser(index);
							try
							{
								second_vector.Erase(index);
							}
							catch (std::out_of_range& ex)
							{
								std::cout << ex.what() << " Try again" << std::endl;
								system("pause");
							}
						}
						else
						{
							std::cout << "There are no elements to delete" << std::endl;
						}
						break;
					}
					case 5: //finish working
					{
						working_with_second_vector = false;
						break;
					}
					}
				}
			}
			break;
		}
		case 1: //сложить два вектора
		{
			try
			{
				Vector<std::complex<Type_Vectors>> sum = first_vector + second_vector;
				std::cout << sum;
			}
			catch (const char* ex)
			{
				std::cout << ex << std::endl;
			}
			system("pause");
			break;
		}
		case 2: //вычесть из первого второй вектор
		{
			try
			{
				Vector<std::complex<Type_Vectors>> subtraction = first_vector - second_vector;
				std::cout << subtraction;
			}
			catch (const char* ex)
			{
				std::cout << ex << std::endl;
			}
			system("pause");
			break;
		}
		case 3: //скал¤рное произведение
		{
			try
			{
				std::complex<Type_Vectors> scalar_product = first_vector.DotProduct(second_vector);
				std::cout << scalar_product << std::endl;
			}
			catch (const char* ex)
			{
				std::cout << ex << std::endl;
			}
			system("pause");
			break;
		}
		case 4: //очистить векторы
		{
			first_vector.Clear();
			second_vector.Clear();
			break;
		}
		case 5: //оценить, равны ли вектора
		{
			first_vector == second_vector ? std::cout << "Vectors are equal" << std::endl :
				std::cout << "Vectors are different" << std::endl;
			system("pause");
			break;
		}
		case 6:
		{
			first_vector = second_vector;
			break;
		}
		case 7: //выйти из программы
		{
			function_is_working = false;
			break;
		}

		}
		system("cls");
	}
}
int main()
{
	//Vector<int> int_vector(11);
	//int_vector.Insert(0, 0);
	//int_vector.Insert(1, 0);
	//int_vector.Insert(2, 0);
	//std::cout << int_vector << std::endl;

	//Vector<std::complex<double>> complex_vector;
	//complex_vector.PushBack({ 1,1 });
	//complex_vector.PushBack({ 1,-1 });
	//Vector<std::complex<double>> complex_vector2;
	//complex_vector2.PushBack({ 2,2 });
	//complex_vector2.PushBack({ 3,-3 });

	//std::cout<< complex_vector.DotProduct(complex_vector2);
	//std::complex<double> x = 0;
	//GetValueFromUser(x);
	//std::cout << "\n" << x << std::endl;
	bool working_with_vectors = true;
	while (working_with_vectors)
	{
		std::cout << "Enter:\n0 - to work with two Vector<int>" << std::endl;
		std::cout << "1 - to work with two Vector<float>" << std::endl;
		std::cout << "2 - to work with two Vector<double>" << std::endl;
		std::cout << "3 - to work with two Vector<std::complex<float>>" << std::endl;
		std::cout << "4 - to work with two Vector<std::complex<double>>" << std::endl;
		std::cout << "5 - to finish working with program" << std::endl;
		int option = 0;
		GetValueFromUserInRange(option, 0, 5);
		switch (option)
		{
			case 0:
			{
				Menu(0);
				std::cout << "int" << std::endl;
				break;
			}
			case 1:
			{
				Menu((float)0.0);
				std::cout << "float" << std::endl;
				break;
			}
			case 2:
			{
				Menu(0.0);
				std::cout << "double" << std::endl;
				break;
			}
			case 3:
			{
				Menu(std::complex<float>(0, 0));
				std::cout << "std::complex<float>" << std::endl;
				break;
			}
			case 4:
			{
				Menu(std::complex<double>(0, 0));
				std::cout << "std::complex<double>" << std::endl;
				break;
			}
			case 5:
			{
				working_with_vectors = false;
				break;
			}
		}
	}
}

