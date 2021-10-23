#include "../vector_ssau_2C1S_lab2/Vector.h"
#include "gmock/gmock.h"

TEST(VectorTests, DefaultCTOR)
{
	Vector<int> x;
	EXPECT_EQ(nullptr, x.GetData());
	EXPECT_EQ(0, x.GetSize());

	Vector<std::complex<double>> y;
	EXPECT_EQ(nullptr, y.GetData());
	EXPECT_EQ(0, y.GetSize());
}
TEST(VectorTests, ParametricCTOR_and_GetSize)
{
	Vector<int> x(3);
	EXPECT_EQ(3, x.GetSize());
	Vector<float> float_vec(5);
	EXPECT_EQ(5, float_vec.GetSize());
	Vector<double> double_vec(55);
	EXPECT_EQ(55, double_vec.GetSize());
	Vector<std::complex<float>> float_complex(50);
	EXPECT_EQ(50, float_complex.GetSize());
	Vector<std::complex<double>> double_complex(53);
	EXPECT_EQ(53, double_complex.GetSize());
}
TEST(VectorTests, ExpandCapacityByN) {
	EXPECT_EQ(1, 2);
}
TEST(VectorTests, OperatorSquareBrackets)
{
	Vector<int> vec(3);
	EXPECT_EQ(0, vec[0]);
	EXPECT_EQ(0, vec[1]);
	EXPECT_EQ(0, vec[2]);

	for (size_t i = 0; i < vec.GetSize(); i++)
	{
		vec[i] = (int)i + 1;
		EXPECT_EQ(i + 1, vec[i]);
	}

	Vector<double> vec_double(3);
	EXPECT_EQ(0, vec_double[0]);
	EXPECT_EQ(0, vec_double[1]);
	EXPECT_EQ(0, vec_double[2]);

	for (size_t i = 0; i < vec_double.GetSize(); i++)
	{
		vec_double[i] = (double)i + 1.3;
		EXPECT_EQ((double)i + 1.3, vec_double[i]);
	}

	Vector<float> vec_float(3);
	EXPECT_EQ(0, vec_float[0]);
	EXPECT_EQ(0, vec_float[1]);
	EXPECT_EQ(0, vec_float[2]);

	for (size_t i = 0; i < vec_float.GetSize(); i++)
	{
		vec_float[i] = (float)i + (float)1.5;
		EXPECT_EQ((float)i + 1.5, vec_float[i]);
	}

	Vector<std::complex<float>> float_complex(3);
	EXPECT_EQ(std::complex<float>(0, 0), float_complex[0]);
	EXPECT_EQ(std::complex<float>(0, 0), float_complex[1]);
	EXPECT_EQ(std::complex<float>(0, 0), float_complex[2]);


	for (size_t i = 0; i < float_complex.GetSize(); i++)
	{
		float_complex[i] =  std::complex<float>((float)1.5* (float)i,-(float)2.5* (float)i);
		EXPECT_EQ(std::complex<float>((float)1.5* (float)i,-(float)2.5* (float)i), float_complex[i]);
	}

	Vector<std::complex<double>> double_complex(3);
	EXPECT_EQ(std::complex<double>(0, 0), double_complex[0]);
	EXPECT_EQ(std::complex<double>(0, 0), double_complex[1]);
	EXPECT_EQ(std::complex<double>(0, 0), double_complex[2]);

	for (size_t i = 0; i < double_complex.GetSize(); i++)
	{
		double_complex[i] = std::complex<double>(-1.5 * (double)i, -2.5 * (double)i);
		EXPECT_EQ(std::complex<double>(-1.5 * (double)i, -2.5 * (double)i), double_complex[i]);
	}
	EXPECT_THROW(vec[-1], std::out_of_range);
	EXPECT_THROW(vec_double[5], std::out_of_range);
	EXPECT_THROW(vec_float[-1], std::out_of_range);
	EXPECT_THROW(float_complex[-1], std::out_of_range);
	EXPECT_THROW(double_complex[5], std::out_of_range);
}
TEST(VectorTests, CopyCTOR)
{
	//int
	{
		Vector<int> vec_int_first(3);
		for (size_t i = 0; i < vec_int_first.GetSize(); i++)
		{
			vec_int_first[i] = (int)i + 1;
		}
		Vector<int> vec_int_second(vec_int_first);
		EXPECT_EQ(3, vec_int_second.GetSize());
		for (size_t i = 0; i < vec_int_second.GetSize(); i++)
		{
			EXPECT_EQ(vec_int_second[i], i + 1);
		}
		Vector<int> vec_int_empty;
		Vector<int> vec_int_empty_copy(vec_int_empty);
		EXPECT_EQ(vec_int_empty_copy.GetSize(), 0);
		EXPECT_EQ(vec_int_empty_copy.GetData(), nullptr);
	}
	//float
	{
		Vector<float> vec_float_first(3);
		for (size_t i = 0; i < vec_float_first.GetSize(); i++)
		{
			vec_float_first[i] = (float)i + (float)1.5;
		}
		Vector<float> vec_float_second(vec_float_first);
		EXPECT_EQ(3, vec_float_second.GetSize());
		for (size_t i = 0; i < vec_float_second.GetSize(); i++)
		{
			EXPECT_EQ(vec_float_second[i], i + 1.5);
		}
		Vector<float> vec_float_empty;
		Vector<float> vec_float_empty_copy(vec_float_empty);
		EXPECT_EQ(vec_float_empty_copy.GetSize(), 0);
		EXPECT_EQ(vec_float_empty_copy.GetData(), nullptr);
	}
	//double
	{ 
		Vector<double> vec_double_first(3);
		for (size_t i = 0; i < vec_double_first.GetSize(); i++)
		{
			vec_double_first[i] = i + 1.5;
		}
		Vector<double> vec_double_second(vec_double_first);
		EXPECT_EQ(3, vec_double_second.GetSize());
		for (size_t i = 0; i < vec_double_second.GetSize(); i++)
		{
			EXPECT_EQ(vec_double_second[i], i + 1.5);
		}
		Vector<double> vec_double_empty;
		Vector<double> vec_double_empty_copy(vec_double_empty);
		EXPECT_EQ(vec_double_empty_copy.GetSize(), 0);
		EXPECT_EQ(vec_double_empty_copy.GetData(), nullptr);
	}
	//complex<float>
	{ 
		Vector<std::complex<float>> vec_comp_float_first(5);
		for (size_t i = 0; i < vec_comp_float_first.GetSize(); i++)
		{
			vec_comp_float_first[i] = std::complex<float>((float)i, -(float)i);
		}
		Vector<std::complex<float>> vec_comp_float_second(vec_comp_float_first);
		EXPECT_EQ(5, vec_comp_float_second.GetSize());
		for (size_t i = 0; i < vec_comp_float_second.GetSize(); i++)
		{
			EXPECT_EQ(vec_comp_float_second[i], std::complex<float>((float)i, -(float)i));
		}
		Vector<std::complex<float>> vec_comp_float_empty;
		Vector<std::complex<float>> vec_comp_float_empty_copy(vec_comp_float_empty);
		EXPECT_EQ(vec_comp_float_empty_copy.GetSize(), 0);
		EXPECT_EQ(vec_comp_float_empty_copy.GetData(), nullptr);
	}
	//complex<double>
	{ 
		Vector<std::complex<double>> vec_comp_double_first(5);
		for (size_t i = 0; i < vec_comp_double_first.GetSize(); i++)
		{
			vec_comp_double_first[i] = std::complex<double>(i + 0.3, 0.3 - i);
		}
		Vector<std::complex<double>> vec_comp_double_second(vec_comp_double_first);
		EXPECT_EQ(5, vec_comp_double_second.GetSize());
		for (size_t i = 0; i < vec_comp_double_second.GetSize(); i++)
		{
			EXPECT_EQ(vec_comp_double_second[i], std::complex<double>(i + 0.3, 0.3 - i));
		}
		Vector<std::complex<float>> vec_comp_double_empty;
		Vector<std::complex<float>> vec_comp_double_empty_copy(vec_comp_double_empty);
		EXPECT_EQ(vec_comp_double_empty_copy.GetSize(), 0);
		EXPECT_EQ(vec_comp_double_empty_copy.GetData(), nullptr);
	}


	Vector<int> vec(3);
	for (size_t i = 0; i < vec.GetSize(); i++)
	{
		vec[i] = (int)i + 1;
	}
	vec.Clear();
	Vector<int> copy_vec(vec);
	EXPECT_EQ(copy_vec.GetSize(), 0);
	EXPECT_EQ(copy_vec.GetData(), nullptr);
}
TEST(VectorTests, PushBack)
{
	//int
	{
		Vector<int> vec;
		vec.PushBack(5);
		EXPECT_EQ(vec[0], 5);

		Vector<int> vec_param(33);
		vec_param.PushBack(3);
		EXPECT_EQ(vec_param[33], 3);
		EXPECT_EQ(vec.GetSize(), 1);
		EXPECT_EQ(vec_param.GetSize(), 34);
	}
	//float
	{
		Vector<float> vec;
		vec.PushBack(5.5);
		EXPECT_EQ(vec[0], 5.5);

		Vector<float> vec_param(33);
		vec_param.PushBack(3);
		EXPECT_EQ(vec_param[33], 3);
		EXPECT_EQ(vec.GetSize(), 1);
		EXPECT_EQ(vec_param.GetSize(), 34);
	}
	//double
	{
		Vector<double> vec;
		vec.PushBack(5.5);
		EXPECT_EQ(vec[0], 5.5);

		Vector<double> vec_param(33);
		vec_param.PushBack(3.3);
		EXPECT_EQ(vec_param[33], 3.3);
		EXPECT_EQ(vec.GetSize(), 1);
		EXPECT_EQ(vec_param.GetSize(), 34);
	}
	//std::complex<float>
	{
		Vector<std::complex<float>> vec;
		vec.PushBack(std::complex<float>((float)3.2,-(float)5.5));
		EXPECT_EQ(vec[0], std::complex<float>((float)3.2, -(float)5.5));

		Vector<std::complex<float>> vec_param(33);
		vec_param.PushBack(std::complex<float>((float)5.2, -(float)55.5));
		EXPECT_EQ(vec_param[33], std::complex<float>((float)5.2, -(float)55.5));
		EXPECT_EQ(vec.GetSize(), 1);
		EXPECT_EQ(vec_param.GetSize(), 34);
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> vec;
		vec.PushBack(std::complex<double>(3.2, -5.5));
		EXPECT_EQ(vec[0], std::complex<double>(3.2, -5.5));

		Vector<std::complex<double>> vec_param(33);
		vec_param.PushBack(std::complex<double>(5.2, -55.5));
		EXPECT_EQ(vec_param[33], std::complex<double>(5.2, -55.5));
		EXPECT_EQ(vec.GetSize(), 1);
		EXPECT_EQ(vec_param.GetSize(), 34);
	}

	//multi-pushbacks
	Vector<std::complex<double>> vec(3);
	for (size_t i=0; i<10; i++)
	{
		vec.PushBack(std::complex<double>((double)i,(double)i));
	}
	EXPECT_EQ(13, vec.GetSize());
}
TEST(VectorTests, Clear)
{
	//int
	{
		Vector<int> vector(3);
		vector.Clear();
		EXPECT_EQ(0, vector.GetSize());
		EXPECT_EQ(nullptr, vector.GetData());

		Vector<int> vector2(100);
		for (size_t i = 0; i < vector2.GetSize(); i++)
		{
			vector2[i] = (int)i * 3 - 2;
		}
		vector2.Clear();
		EXPECT_EQ(0, vector2.GetSize());
		EXPECT_EQ(nullptr, vector2.GetData());
	}
	//double
	{
		Vector<double> vector(3);
		vector.Clear();
		EXPECT_EQ(0, vector.GetSize());
		EXPECT_EQ(nullptr, vector.GetData());

		Vector<double> vector2(100);
		for (size_t i = 0; i < vector2.GetSize(); i++)
		{
			vector2[i] = (double)i * 3 - 2;
		}
		vector2.Clear();
		EXPECT_EQ(0, vector2.GetSize());
		EXPECT_EQ(nullptr, vector2.GetData());
	}
	//float
	{
		Vector<float> vector(3);
		vector.Clear();
		EXPECT_EQ(0, vector.GetSize());
		EXPECT_EQ(nullptr, vector.GetData());

		Vector<float> vector2(100);
		for (size_t i = 0; i < vector2.GetSize(); i++)
		{
			vector2[i] = (float)i * 3 - (float)2.5;
		}
		vector2.Clear();
		EXPECT_EQ(0, vector2.GetSize());
		EXPECT_EQ(nullptr, vector2.GetData());
	}
	//complex<float>
	{
		Vector<std::complex<float>> vector(3);
		vector.Clear();
		EXPECT_EQ(0, vector.GetSize());
		EXPECT_EQ(nullptr, vector.GetData());

		Vector<std::complex<float>> vector2(100);
		for (size_t i = 0; i < vector2.GetSize(); i++)
		{
			vector2[i] = std::complex<float>((float)3.2*i*(-1),(float)0.5*i*(-2));
		}
		vector2.Clear();
		EXPECT_EQ(0, vector2.GetSize());
		EXPECT_EQ(nullptr, vector2.GetData());
	}
	//complex<double>
	{
		Vector<std::complex<double>> vector(3);
		vector.Clear();
		EXPECT_EQ(0, vector.GetSize());
		EXPECT_EQ(nullptr, vector.GetData());

		Vector<std::complex<double>> vector2(100);
		for (size_t i = 0; i < vector2.GetSize(); i++)
		{
			vector2[i] = std::complex<float>((float)3.2 * i * (-1), (float)0.5 * i * (-2));
		}
		vector2.Clear();
		EXPECT_EQ(0, vector2.GetSize());
		EXPECT_EQ(nullptr, vector2.GetData());
	}
	
	//adding after clearing
	Vector<int> vector_to_clear(5);
	for (size_t i = 0; i < vector_to_clear.GetSize(); i++)
	{
		vector_to_clear[i] = (int)i+1;
	}
	vector_to_clear.Clear();
	vector_to_clear.PushBack(5);
	vector_to_clear.Clear();
}
TEST(VectorTests, Insert)
{
	//int
	{
		Vector<int> vec;
		vec.Insert(5,0);
		EXPECT_EQ(vec[0], 5);
		EXPECT_THROW(vec.Insert(22,500), std::out_of_range);

		Vector<int> vec_param(33);
		vec_param.Insert(22,15);
		EXPECT_EQ(vec_param[15], 22);
		EXPECT_EQ(vec.GetSize(), 1);
		EXPECT_EQ(vec_param.GetSize(), 34);
	}
	//float
	{
		Vector<float> vec;
		vec.Insert(5, 0);
		EXPECT_EQ(vec[0], 5);
		EXPECT_THROW(vec.Insert(22, 500), std::out_of_range);

		Vector<float> vec_param(33);
		vec_param.Insert(22, 15);
		EXPECT_EQ(vec_param[15], 22);
		EXPECT_EQ(vec.GetSize(), 1);
		EXPECT_EQ(vec_param.GetSize(), 34);
	}
	//double
	{
		Vector<double> vec;
		vec.Insert(5, 0);
		EXPECT_EQ(vec[0], 5);
		EXPECT_THROW(vec.Insert(22, 500), std::out_of_range);

		Vector<double> vec_param(33);
		vec_param.Insert(22, 15);
		EXPECT_EQ(vec_param[15], 22);
		EXPECT_EQ(vec.GetSize(), 1);
		EXPECT_EQ(vec_param.GetSize(), 34);
	}
	//std::complex<float>
	{
		Vector<std::complex<float>> vec;
		vec.Insert(std::complex<float>((float)3.2, (float)2.2), 0);
		EXPECT_EQ(vec[0], std::complex<float>((float)3.2, (float)2.2));
		EXPECT_THROW(vec.Insert(std::complex<float>((float)3.3, (float)2.3), 500), std::out_of_range);

		Vector<std::complex<float>> vec_param(33);
		vec_param.Insert(std::complex<float>((float)3.4, (float)2.4), 15);
		EXPECT_EQ(vec_param[15], std::complex<float>((float)3.4, (float)2.4));
		EXPECT_EQ(vec.GetSize(), 1);
		EXPECT_EQ(vec_param.GetSize(), 34);
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> vec;
		vec.Insert(std::complex<double>(3.2, 2.2), 0);
		EXPECT_EQ(vec[0], std::complex<double>(3.2, 2.2));
		EXPECT_THROW(vec.Insert(std::complex<double>(3.3, 2.3), 500), std::out_of_range);

		Vector<std::complex<double>> vec_param(33);
		vec_param.Insert(std::complex<double>(3.4, 2.4), 15);
		EXPECT_EQ(vec_param[15], std::complex<double>(3.4, 2.4));
		EXPECT_EQ(vec.GetSize(), 1);
		EXPECT_EQ(vec_param.GetSize(), 34);
	}

	//multi-insert
	Vector<std::complex<double>> vec(3);
	for (size_t i = 0; i < 10; i++)
	{
		vec.Insert(std::complex<double>((double)i,2*(double)i), vec.GetSize());
		EXPECT_EQ(std::complex<double>((double)i, 2 * (double)i), vec[vec.GetSize() - 1]);
	}
	EXPECT_EQ(13, vec.GetSize());
}
TEST(VectorTests, Erase)
{
	//int
	{
		Vector<int> a;
		EXPECT_NO_THROW(a.Erase(5));
		a.PushBack(1);
		EXPECT_THROW(a.Erase(5), std::out_of_range);
		EXPECT_NO_THROW(a.Erase(0));
		EXPECT_EQ(0, a.GetSize());

		Vector<int> b(25);
		for (size_t i = 0; i < b.GetSize(); i++)
		{
			b[i] = ((int)i + 1) * (int)i;
		}
		b.Erase(1);
		EXPECT_EQ(b[1], 6);
		EXPECT_EQ(b[0], 0);
		EXPECT_EQ(b[9], 110);
		EXPECT_EQ(b.GetSize(), 24);
		b.Erase(22);
		EXPECT_EQ(b[1], 6);
		EXPECT_EQ(b[0], 0);
		EXPECT_EQ(b[9], 110);
		EXPECT_EQ(b[21], 506);
		EXPECT_EQ(b[22], 600);
		EXPECT_EQ(b.GetSize(), 23);
	}
	//float
	{
		Vector<float> a;
		EXPECT_NO_THROW(a.Erase(5));
		a.PushBack(1);
		EXPECT_THROW(a.Erase(5), std::out_of_range);
		EXPECT_NO_THROW(a.Erase(0));
		EXPECT_EQ(0, a.GetSize());

		Vector<float> b(25);
		for (size_t i = 0; i < b.GetSize(); i++)
		{
			b[i] = ((float)i + 1) * (float)i;
		}
		b.Erase(1);
		EXPECT_EQ(b[1], 6);
		EXPECT_EQ(b[0], 0);
		EXPECT_EQ(b[9], 110);
		EXPECT_EQ(b.GetSize(), 24);
		b.Erase(22);
		EXPECT_EQ(b[1], 6);
		EXPECT_EQ(b[0], 0);
		EXPECT_EQ(b[9], 110);
		EXPECT_EQ(b[21], 506);
		EXPECT_EQ(b[22], 600);
		EXPECT_EQ(b.GetSize(), 23);
	}
	//double
	{
		Vector<double> a;
		EXPECT_NO_THROW(a.Erase(5));
		a.PushBack(1);
		EXPECT_THROW(a.Erase(5), std::out_of_range);
		EXPECT_NO_THROW(a.Erase(0));
		EXPECT_EQ(0, a.GetSize());

		Vector<double> b(25);
		for (size_t i = 0; i < b.GetSize(); i++)
		{
			b[i] = ((double)i + 1) * i;
		}
		b.Erase(1);
		EXPECT_EQ(b[1], 6);
		EXPECT_EQ(b[0], 0);
		EXPECT_EQ(b[9], 110);
		EXPECT_EQ(b.GetSize(), 24);
		b.Erase(22);
		EXPECT_EQ(b[1], 6);
		EXPECT_EQ(b[0], 0);
		EXPECT_EQ(b[9], 110);
		EXPECT_EQ(b[21], 506);
		EXPECT_EQ(b[22], 600);
		EXPECT_EQ(b.GetSize(), 23);
	}
	//std::complex<float>
	{
		Vector<std::complex<float>> a;
		EXPECT_NO_THROW(a.Erase(5));
		a.PushBack(std::complex<float>(3, -2));
		EXPECT_THROW(a.Erase(5), std::out_of_range);
		EXPECT_NO_THROW(a.Erase(0));
		EXPECT_EQ(0, a.GetSize());

		Vector<std::complex<float>> b(25);
		for (size_t i = 0; i < b.GetSize(); i++)
		{
			b[i] = std::complex<float>(((float)i + 1) * i, ((float)i + 1) * i);
		}
		b.Erase(1);
		EXPECT_EQ(b[1], std::complex<float>(6, 6));
		EXPECT_EQ(b[0], std::complex < float>(0, 0));
		EXPECT_EQ(b[9], std::complex<float>(110, 110));
		EXPECT_EQ(b.GetSize(), 24);
		b.Erase(22);
		EXPECT_EQ(b[1], std::complex<float>(6, 6));
		EXPECT_EQ(b[0], std::complex < float>(0, 0));
		EXPECT_EQ(b[9], std::complex<float>(110, 110));
		EXPECT_EQ(b[21], std::complex<float>(506, 506));
		EXPECT_EQ(b[22], std::complex<float>(600, 600));
		EXPECT_EQ(b.GetSize(), 23);
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> a;
		EXPECT_NO_THROW(a.Erase(5));
		a.PushBack(std::complex<double>(3, -2));
		EXPECT_THROW(a.Erase(5), std::out_of_range);
		EXPECT_NO_THROW(a.Erase(0));
		EXPECT_EQ(0, a.GetSize());

		Vector<std::complex<double>> b(25);
		for (size_t i = 0; i < b.GetSize(); i++)
		{
			b[i] = std::complex<double>(((double)i + 1) * i, ((double)i + 1) * i);
		}
		b.Erase(1);
		EXPECT_EQ(b[1], std::complex<double>(6, 6));
		EXPECT_EQ(b[0], std::complex<double>(0, 0));
		EXPECT_EQ(b[9], std::complex<double>(110, 110));
		EXPECT_EQ(b.GetSize(), 24);
		b.Erase(22);
		EXPECT_EQ(b[1], std::complex<double>(6, 6));
		EXPECT_EQ(b[0], std::complex<double> (0, 0));
		EXPECT_EQ(b[9], std::complex<double>(110, 110));
		EXPECT_EQ(b[21], std::complex<double>(506, 506));
		EXPECT_EQ(b[22], std::complex<double>(600, 600));
		EXPECT_EQ(b.GetSize(), 23);
	}
}
TEST(VectorTests, OperatorPlusEqualForVectors)
{
	//int
	{
		Vector<int> a(3);
		Vector<int> b(5);
		EXPECT_THROW(a += b, const char*);

		Vector<int> first(5);
		Vector<int> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += (int)i;
			second[i] -= (int)i;
		}
		first += second;
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			EXPECT_EQ(0, first[i]);
		}
	}
	//float
	{
		Vector<float> a(3);
		Vector<float> b(5);
		EXPECT_THROW(a += b, const char*);

		Vector<float> first(5);
		Vector<float> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += i;
			second[i] -= i;
		}
		first += second;
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			EXPECT_EQ(0, first[i]);
		}
	}
	//double
	{
		Vector<double> a(3);
		Vector<double> b(5);
		EXPECT_THROW(a += b, const char*);

		Vector<double> first(5);
		Vector<double> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += i;
			second[i] -= i;
		}
		first += second;
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			EXPECT_EQ(0, first[i]);
		}
	}
	//std::complex<float>
	{
		Vector<std::complex<float>> a(3);
		Vector<std::complex<float>> b(5);
		EXPECT_THROW(a += b, const char*);

		Vector<std::complex<float>> first(5);
		Vector<std::complex<float>> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += std::complex<float>((float)i, (float)i);
			second[i] -= std::complex<float>((float)i, (float)i);
		}
		first += second;
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			EXPECT_EQ(std::complex<float>(0,0), first[i]);
		}
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> a(3);
		Vector<std::complex<double>> b(5);
		EXPECT_THROW(a += b, const char*);

		Vector<std::complex<double>> first(5);
		Vector<std::complex<double>> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += std::complex<double>((double)i, (double)i);
			second[i] -= std::complex<double>((double)i, (double)i);
		}
		first += second;
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			EXPECT_EQ(std::complex<double>((double)0,(double)0), first[i]);
		}
	}
}
TEST(VectorTests, OperatorPlusForVectors)
{
	//int
	{
		Vector<int> a(3);
		Vector<int> b(5);
		EXPECT_THROW(a + b, const char*);

		Vector<int> first(5);
		Vector<int> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += (int)i;
			second[i] -= (int)i;
		}
		Vector<int> third = first + second;
		for (size_t i = 0; i < third.GetSize(); i++)
		{
			EXPECT_EQ(0, third[i]);
		}
	}
	//float
	{
		Vector<float> a(3);
		Vector<float> b(5);
		EXPECT_THROW(a + b, const char*);

		Vector<float> first(5);
		Vector<float> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += (float)i;
			second[i] -= (float)i;
		}
		Vector<float> third = first + second;
		for (size_t i = 0; i < third.GetSize(); i++)
		{
			EXPECT_EQ(0, third[i]);
		}
	}
	//double
	{
		Vector<double> a(3);
		Vector<double> b(5);
		EXPECT_THROW(a + b, const char*);

		Vector<double> first(5);
		Vector<double> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += (double)i;
			second[i] -= (double)i;
		}
		Vector<double> third = first + second;
		for (size_t i = 0; i < third.GetSize(); i++)
		{
			EXPECT_EQ(0, third[i]);
		}
	}
	//std::complex<float>
	{
		Vector<std::complex<float>> a(3);
		Vector<std::complex<float>> b(5);
		EXPECT_THROW(a + b, const char*);

		Vector<std::complex<float>> first(5);
		Vector<std::complex<float>> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += std::complex<float>((float)i,(float)i);
			second[i] -= std::complex<float>((float)i, (float)i);
		}
		Vector<std::complex<float>> third = first + second;
		for (size_t i = 0; i < third.GetSize(); i++)
		{
			EXPECT_EQ(std::complex<float>((float)0, (float)0) , third[i]);
		}
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> a(3);
		Vector<std::complex<double>> b(5);
		EXPECT_THROW(a + b, const char*);

		Vector<std::complex<double>> first(5);
		Vector<std::complex<double>> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += std::complex<double>((double)i, (double)i);
			second[i] -= std::complex<double>((double)i, (double)i);
		}
		Vector<std::complex<double>> third = first + second;
		for (size_t i = 0; i < third.GetSize(); i++)
		{
			EXPECT_EQ(std::complex<double>((double)0, (double)0), third[i]);
		}
	}
}
TEST(VectorTests, OperatorMinusEqualForVectors)
{
	//int
	{
		Vector<int> a(3);
		Vector<int> b(5);
		EXPECT_THROW(a -= b, const char*);

		Vector<int> first(5);
		Vector<int> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += (int)i;
			second[i] += (int)i;
		}
		first -= second;
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			EXPECT_EQ(0, first[i]);
		}
	}
	//float
	{
		Vector<float> a(3);
		Vector<float> b(5);
		EXPECT_THROW(a -= b, const char*);

		Vector<float> first(5);
		Vector<float> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += (float)i;
			second[i] += (float)i;
		}
		first -= second;
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			EXPECT_EQ(0, first[i]);
		}
	}
	//double
	{
		Vector<double> a(3);
		Vector<double> b(5);
		EXPECT_THROW(a -= b, const char*);

		Vector<double> first(5);
		Vector<double> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += (double)i;
			second[i] += (double)i;
		}
		first -= second;
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			EXPECT_EQ(0, first[i]);
		}
	}
	//std::complex<float>
	{
		Vector<std::complex<float>> a(3);
		Vector<std::complex<float>> b(5);
		EXPECT_THROW(a -= b, const char*);

		Vector<std::complex<float>> first(5);
		Vector<std::complex<float>> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += std::complex<float>((float)i, (float)i);
			second[i] += std::complex<float>((float)i, (float)i);
		}
		first -= second;
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			EXPECT_EQ(std::complex<float>((float)0, (float)0), first[i]);
		}
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> a(3);
		Vector<std::complex<double>> b(5);
		EXPECT_THROW(a -= b, const char*);

		Vector<std::complex<double>> first(5);
		Vector<std::complex<double>> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += std::complex<double>((double)i, (double)i);
			second[i] += std::complex<double>((double)i, (double)i);
		}
		first -= second;
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			EXPECT_EQ(std::complex<double>(0, 0), first[i]);
		}
	}
}
TEST(VectorTests, OperatorMinusForVectors)
{
	//int
	{
		Vector<int> a(3);
		Vector<int> b(5);
		EXPECT_THROW(a - b, const char*);

		Vector<int> first(5);
		Vector<int> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += (int)i;
			second[i] += (int)i;
		}
		Vector<int> third = first - second;
		for (size_t i = 0; i < third.GetSize(); i++)
		{
			EXPECT_EQ(0, third[i]);
		}
	}
	//float
	{
		Vector<float> a(3);
		Vector<float> b(5);
		EXPECT_THROW(a - b, const char*);

		Vector<float> first(5);
		Vector<float> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += (float)i;
			second[i] += (float)i;
		}
		Vector<float> third = first - second;
		for (size_t i = 0; i < third.GetSize(); i++)
		{
			EXPECT_EQ(0, third[i]);
		}
	}
	//double
	{
		Vector<double> a(3);
		Vector<double> b(5);
		EXPECT_THROW(a - b, const char*);

		Vector<double> first(5);
		Vector<double> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += (double)i;
			second[i] += (double)i;
		}
		Vector<double> third = first - second;
		for (size_t i = 0; i < third.GetSize(); i++)
		{
			EXPECT_EQ(0, third[i]);
		}
	}
	//std::complex<float>
	{
		Vector<std::complex<float>> a(3);
		Vector<std::complex<float>> b(5);
		EXPECT_THROW(a - b, const char*);

		Vector<std::complex<float>> first(5);
		Vector<std::complex<float>> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += std::complex<float>((float)i, (float)i);
			second[i] += std::complex<float>((float)i, (float)i);
		}
		Vector<std::complex<float>> third = first - second;
		for (size_t i = 0; i < third.GetSize(); i++)
		{
			EXPECT_EQ(std::complex<float>((float)0, (float)0), third[i]);
		}
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> a(3);
		Vector<std::complex<double>> b(5);
		EXPECT_THROW(a - b, const char*);

		Vector<std::complex<double>> first(5);
		Vector<std::complex<double>> second(5);
		for (size_t i = 0; i < first.GetSize(); i++)
		{
			first[i] += std::complex<double>((double)i, (double)i);
			second[i] += std::complex<double>((double)i, (double)i);
		}
		Vector<std::complex<double>> third = first - second;
		for (size_t i = 0; i < third.GetSize(); i++)
		{
			EXPECT_EQ(std::complex<double>((double)0, (double)0), third[i]);
		}
	}
}
TEST(VectorTests, OperatorMultiplyEqual)
{
	//int
	{
		//*=
		{
			Vector<int> a(5);
			Vector<int> b(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a[i] += 2 + (int)i;
				b[i] += 5 * (int)i;
			}
			a *= 2;
			b *= (-1);
			Vector<int> a_test(5);
			Vector<int> b_test(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a_test[i] += 2 * (2 + (int)i);
				b_test[i] += (-1) * (5 * (int)i);
				EXPECT_EQ(a_test[i], a[i]);
				EXPECT_EQ(b_test[i], b[i]);
			}
		}
		//*= but commutativity
		{
			Vector<int> c(5);
			Vector<int> d(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c[i] += (int)2 + (int)i;
				d[i] += (int)5 * (int)i;
			}
			2 *= c;
			(-1) *= d;
			Vector<int> c_test(5);
			Vector<int> d_test(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c_test[i] += 2 * (2 + (int)i);
				d_test[i] += (-1) * (5 * (int)i);
				EXPECT_EQ(c_test[i], c[i]);
				EXPECT_EQ(d_test[i], d[i]);
			}
		}
	}
	//float
	{
		//*=
		{
			Vector<float> a(5);
			Vector<float> b(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a[i] += 2 + (float)i;
				b[i] += 5 * (float)i;
			}
			a *= 2;
			b *= (-1);
			Vector<float> a_test(5);
			Vector<float> b_test(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a_test[i] += 2 * (2 + (float)i);
				b_test[i] += (-1) * (5 * (float)i);
				EXPECT_EQ(a_test[i], a[i]);
				EXPECT_EQ(b_test[i], b[i]);
			}
		}
		//*= but commutativity
		{
			Vector<float> c(5);
			Vector<float> d(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c[i] += (float)2 + i;
				d[i] += (float)5 * i;
			}
			(float)2 *= c;
			(float)(-1) *= d;
			Vector<float> c_test(5);
			Vector<float> d_test(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c_test[i] += 2 * (2 + (float)i);
				d_test[i] += (-1) * (5 * (float)i);
				EXPECT_EQ(c_test[i], c[i]);
				EXPECT_EQ(d_test[i], d[i]);
			}
		}
	}
	//double
	{
		//*=
		{
			Vector<double> a(5);
			Vector<double> b(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a[i] += 2 + (double)i;
				b[i] += 5 * (double)i;
			}
			a *= 2;
			b *= (-1);
			Vector<double> a_test(5);
			Vector<double> b_test(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a_test[i] += 2 * (2 + (double)i);
				b_test[i] += (-1) * (5 * (double)i);
				EXPECT_EQ(a_test[i], a[i]);
				EXPECT_EQ(b_test[i], b[i]);
			}
		}
		//*= but commutativity
		{
			Vector<double> c(5);
			Vector<double> d(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c[i] += (double)2 + i;
				d[i] += (double)5 * i;
			}
			(double)2 *= c;
			(double)(-1) *= d;
			Vector<double> c_test(5);
			Vector<double> d_test(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c_test[i] += 2 * (2 + (double)i);
				d_test[i] += (-1) * (5 * (double)i);
				EXPECT_EQ(c_test[i], c[i]);
				EXPECT_EQ(d_test[i], d[i]);
			}
		}
	}
	//std::complex<float>
	{
		//*=
		{
			Vector<std::complex<float>> a(5);
			Vector<std::complex<float>> b(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a[i] += std::complex<float>((float)2, (float)2) + std::complex<float>((float)i, (float)i);
				b[i] += std::complex<float>((float)5, (float)5) * std::complex<float>((float)i, (float)i);
			}
			a *= std::complex<float>(2, 2);
			b *= std::complex<float>(-1, -1);
			Vector<std::complex<float>> a_test(5);
			Vector<std::complex<float>> b_test(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a_test[i] += std::complex<float>((float)2, (float)2) * (std::complex<float>((float)2, (float)2) + std::complex<float>((float)i, (float)i));
				b_test[i] += std::complex<float>((float)-1, (float)-1) * (std::complex<float>((float)5, (float)5) * std::complex<float>((float)i, (float)i));
				EXPECT_EQ(a_test[i], a[i]);
				EXPECT_EQ(b_test[i], b[i]);
			}
		}
		//*= but commutativity
		{
			Vector<std::complex<float>> c(5);
			Vector<std::complex<float>> d(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c[i] += std::complex<float>((float)2, (float)2) + std::complex<float>((float)i, (float)i);
				d[i] += std::complex<float>((float)5, (float)5) * std::complex<float>((float)i, (float)i);
			}
			std::complex<float>((float)2, (float)2) *= c;
			std::complex<float>((float)-1, (float)-1) *= d;
			Vector<std::complex<float>> c_test(5);
			Vector<std::complex<float>> d_test(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c_test[i] += std::complex<float>((float)2, (float)2) * (std::complex<float>((float)2, (float)2) + std::complex<float>((float)i, (float)i));
				d_test[i] += std::complex<float>((float)-1, (float)-1) * (std::complex<float>((float)5, (float)5) * std::complex<float>((float)i, (float)i));
				EXPECT_EQ(c_test[i], c[i]);
				EXPECT_EQ(d_test[i], d[i]);
			}
		}
	}
	//std::complex<double>
	{
		//*=
		{
			Vector<std::complex<double>> a(5);
			Vector<std::complex<double>> b(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a[i] += std::complex<double>((double)2, (double)2) + std::complex<double>((double)i, (double)i);
				b[i] += std::complex<double>((double)5, (double)5) * std::complex<double>((double)i, (double)i);
			}
			a *= std::complex<double>((double)2, (double)2);
			b *= std::complex<double>((double)-1, (double)-1);
			Vector<std::complex<double>> a_test(5);
			Vector<std::complex<double>> b_test(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a_test[i] += std::complex<double>((double)2, (double)2) * (std::complex<double>((double)2, (double)2) + std::complex<double>((double)i, (double)i));
				b_test[i] += std::complex<double>((double)-1, (double)-1) * (std::complex<double>((double)5, (double)5) * std::complex<double>((double)i, (double)i));
				EXPECT_EQ(a_test[i], a[i]);
				EXPECT_EQ(b_test[i], b[i]);
			}
		}
		//*= but commutativity
		{
			Vector<std::complex<double>> c(5);
			Vector<std::complex<double>> d(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c[i] += std::complex<double>((double)2, (double)2) + std::complex<double>((double)i, (double)i);
				d[i] += std::complex<double>((double)5, (double)5) * std::complex<double>((double)i, (double)i);
			}
			std::complex<double>((double)2, (double)2) *= c;
			std::complex<double>((double)-1, (double)-1) *= d;
			Vector<std::complex<double>> c_test(5);
			Vector<std::complex<double>> d_test(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c_test[i] += std::complex<double>((double)2, (double)2) * (std::complex<double>((double)2, (double)2) + std::complex<double>((double)i, (double)i));
				d_test[i] += std::complex<double>((double)-1, (double)-1) * (std::complex<double>((double)5, (double)5) * std::complex<double>((double)i, (double)i));
				EXPECT_EQ(c_test[i], c[i]);
				EXPECT_EQ(d_test[i], d[i]);
			}
		}
	}
}
TEST(VectorTests, OperatorMultiplyByValue)
{
	//int
	{
		// *
		{
			Vector<int> a(5);
			Vector<int> b(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a[i] += (int)2 + (int)i;
				b[i] += (int)5 * (int)i;
			}
			a = a * 2;
			b = b * (-1);
			Vector<int> a_test(5);
			Vector<int> b_test(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a_test[i] += (int)2 * ((int)2 + (int)i);
				b_test[i] += (int)(-1) * ((int)5 * (int)i);
				EXPECT_EQ(a_test[i], a[i]);
				EXPECT_EQ(b_test[i], b[i]);
			}
		}

		//* but commutativity
		{
			Vector<int> c(5);
			Vector<int> d(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c[i] += (int)2 + (int)i;
				d[i] += (int)5 * (int)i;
			}
			c = 2 * c;
			d = (-1) * d;
			Vector<int> c_test(5);
			Vector<int> d_test(5);
			for (size_t i = 0; i < c_test.GetSize(); i++)
			{
				c_test[i] += (int)2 * ((int)2 + (int)i);
				d_test[i] += (int)(-1) * ((int)5 * (int)i);
				EXPECT_EQ(c_test[i], c[i]);
				EXPECT_EQ(d_test[i], d[i]);
			}
		}
	}
	//float
	{
		// *
		{
			Vector<float> a(5);
			Vector<float> b(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a[i] += (float)2 + (float)i;
				b[i] += (float)5 * (float)i;
			}
			a = a * 2;
			b = b * (-1);
			Vector<float> a_test(5);
			Vector<float> b_test(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a_test[i] += (float)2 * ((float)2 + (float)i);
				b_test[i] += (float)(-1) * ((float)5 * (float)i);
				EXPECT_EQ(a_test[i], a[i]);
				EXPECT_EQ(b_test[i], b[i]);
			}
		}

		//* but commutativity
		{
			Vector<float> c(5);
			Vector<float> d(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c[i] += (float)2 + (float)i;
				d[i] += (float)5 * (float)i;
			}
			c = (float)2 * c;
			d = (float)(-1) * d;
			Vector<float> c_test(5);
			Vector<float> d_test(5);
			for (size_t i = 0; i < c_test.GetSize(); i++)
			{
				c_test[i] += (float)2 * ((float)2 + (float)i);
				d_test[i] += (float)(-1) * ((float)5 * (float)i);
				EXPECT_EQ(c_test[i], c[i]);
				EXPECT_EQ(d_test[i], d[i]);
			}
		}
	}
	//double
	{
		// *
		{
			Vector<double> a(5);
			Vector<double> b(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a[i] += (double)2 + (double)i;
				b[i] += (double)5 * (double)i;
			}
			a = a * 2;
			b = b * (-1);
			Vector<double> a_test(5);
			Vector<double> b_test(5);
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				a_test[i] += (double)2 * ((double)2 + (double)i);
				b_test[i] += (double)(-1) * ((double)5 * (double)i);
				EXPECT_EQ(a_test[i], a[i]);
				EXPECT_EQ(b_test[i], b[i]);
			}
		}

		//* but commutativity
		{
			Vector<double> c(5);
			Vector<double> d(5);
			for (size_t i = 0; i < c.GetSize(); i++)
			{
				c[i] += (double)2 + (double)i;
				d[i] += (double)5 * (double)i;
			}
			c = (double)2 * c;
			d = (double)(-1) * d;
			Vector<double> c_test(5);
			Vector<double> d_test(5);
			for (size_t i = 0; i < c_test.GetSize(); i++)
			{
				c_test[i] += (double)2 * ((double)2 + (double)i);
				d_test[i] += (double)(-1) * ((double)5 * (double)i);
				EXPECT_EQ(c_test[i], c[i]);
				EXPECT_EQ(d_test[i], d[i]);
			}
		}
	}
	//std::complex<float>
	{
		//*
		{
			Vector<std::complex<float>> vec1(5);
			Vector<std::complex<float>> vec2(5);
			for (size_t i = 0; i < 5; i++)
			{
				vec1[i] = std::complex<float>((float)3 + (float)i, (float)i);
				vec2[i] = std::complex<float>((float)3 + (float)i, (float)i);
			}
			vec1 = vec1 * std::complex<float>((float)2, (float)2);
			vec2 = vec2 * std::complex<float>((float)-2, (float)-2);

			Vector<std::complex<float>> vec1_test(5);
			Vector<std::complex<float>> vec2_test(5);
			for (size_t i = 0; i < 5; i++)
			{
				vec1_test[i] += std::complex<float>((float)2, (float)2) * std::complex<float>((float)3 + (float)i, (float)i);
				vec2_test[i] += std::complex<float>((float)-2, (float)-2) * std::complex<float>((float)3 + (float)i, (float)i);
				EXPECT_EQ(vec1[i], vec1_test[i]);
				EXPECT_EQ(vec2[i], vec2_test[i]);
			}
		}
		//* but commutativity
		{
			Vector<std::complex<float>> vec1(5);
			Vector<std::complex<float>> vec2(5);
			for (size_t i = 0; i < 5; i++)
			{
				vec1[i] = std::complex<float>((float)3 + (float)i, (float)i);
				vec2[i] = std::complex<float>((float)3 + (float)i, (float)i);
			}
			vec1 = std::complex<float>((float)2, (float)2) * vec1;
			vec2 = std::complex<float>((float)-2, (float)-2) * vec2;

			Vector<std::complex<float>> vec1_test(5);
			Vector<std::complex<float>> vec2_test(5);
			for (size_t i = 0; i < 5; i++)
			{
				vec1_test[i] += std::complex<float>((float)2, (float)2) * std::complex<float>((float)3 + (float)i, (float)i);
				vec2_test[i] += std::complex<float>((float)-2, (float)-2) * std::complex<float>((float)3 + (float)i, (float)i);
				EXPECT_EQ(vec1[i], vec1_test[i]);
				EXPECT_EQ(vec2[i], vec2_test[i]);
			}
		}
	}
	//std::complex<double>
	{
		//*
		{
			Vector<std::complex<double>> vec1(5);
			Vector<std::complex<double>> vec2(5);
			for (size_t i = 0; i < 5; i++)
			{
				vec1[i] = std::complex<double>((double)3 + (double)i, (double)i);
				vec2[i] = std::complex<double>((double)3 + (double)i, (double)i);
			}
			vec1 = vec1 * std::complex<double>((double)2, (double)2);
			vec2 = vec2 * std::complex<double>((double)-2, (double)-2);

			Vector<std::complex<double>> vec1_test(5);
			Vector<std::complex<double>> vec2_test(5);
			for (size_t i = 0; i < 5; i++)
			{
				vec1_test[i] += std::complex<double>((double)2, (double)2) * std::complex<double>((double)3 + (double)i, (double)i);
				vec2_test[i] += std::complex<double>((double)-2, (double)-2) * std::complex<double>((double)3 + (double)i, (double)i);
				EXPECT_EQ(vec1[i], vec1_test[i]);
				EXPECT_EQ(vec2[i], vec2_test[i]);
			}
		}
		//* but commutativity
		{
			Vector<std::complex<double>> vec1(5);
			Vector<std::complex<double>> vec2(5);
			for (size_t i = 0; i < 5; i++)
			{
				vec1[i] = std::complex<double>((double)3 + (double)i, (double)i);
				vec2[i] = std::complex<double>((double)3 + (double)i, (double)i);
			}
			vec1 = std::complex<double>((double)2, (double)2) * vec1;
			vec2 = std::complex<double>((double)-2, (double)-2) * vec2;

			Vector<std::complex<double>> vec1_test(5);
			Vector<std::complex<double>> vec2_test(5);
			for (size_t i = 0; i < 5; i++)
			{
				vec1_test[i] += std::complex<double>((double)2, (double)2) * std::complex<double>((double)3 + (double)i, (double)i);
				vec2_test[i] += std::complex<double>((double)-2, (double)-2) * std::complex<double>((double)3 + (double)i, (double)i);
				EXPECT_EQ(vec1[i], vec1_test[i]);
				EXPECT_EQ(vec2[i], vec2_test[i]);
			}
		}
	}
}
TEST(VectorTests, OperatorDivideEqual)
{
	//int
	{
		Vector<int> a(5);
		Vector<int> b(5);
		Vector<int> a_test(5);
		Vector<int> b_test(5);
		EXPECT_THROW(a /= 0, const char*);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			int koef_a = 4 + (int)i;
			int koef_b = 15 * (int)i;
			a[i] += koef_a;
			b[i] += koef_b;
			a_test[i] += koef_a / 4;
			b_test[i] += koef_b / (-15);
		}
		a /= 4;
		b /= (-15);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			EXPECT_EQ(a_test[i], a[i]);
			EXPECT_EQ(b_test[i], b[i]);
		}
	}
	//float
	{
		Vector<float> a(5);
		Vector<float> b(5);
		Vector<float> a_test(5);
		Vector<float> b_test(5);
		EXPECT_THROW(a /= 0, const char*);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			float koef_a = 4 + (float)i;
			float koef_b = 15 * (float)i;
			a[i] += koef_a;
			b[i] += koef_b;
			a_test[i] += koef_a / 4;
			b_test[i] += koef_b / (-15);
		}
		a /= 4;
		b /= (-15);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			EXPECT_EQ(a_test[i], a[i]);
			EXPECT_EQ(b_test[i], b[i]);
		}
	}
	//double
	{
		Vector<double> a(5);
		Vector<double> b(5);
		Vector<double> a_test(5);
		Vector<double> b_test(5);
		EXPECT_THROW(a /= 0, const char*);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			double koef_a = 4 + (double)i;
			double koef_b = 15 * (double)i;
			a[i] += koef_a;
			b[i] += koef_b;
			a_test[i] += koef_a / 4;
			b_test[i] += koef_b / (-15);
		}
		a /= 4;
		b /= (-15);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			EXPECT_EQ(a_test[i], a[i]);
			EXPECT_EQ(b_test[i], b[i]);
		}
	}
	//std::complex<float>
	{
		Vector<std::complex<float>> a(5);
		Vector<std::complex<float>> b(5);
		Vector<std::complex<float>> a_test(5);
		Vector<std::complex<float>> b_test(5);
		EXPECT_THROW(a /= std::complex<float>(0,0), const char*);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			std::complex<float> koef_a = std::complex < float>((float)4, (float)4) + std::complex<float>((float)i, (float)i);
			std::complex<float> koef_b = std::complex < float>((float)15, (float)15) * std::complex<float>((float)i, (float)i);
			a[i] += koef_a;
			b[i] += koef_b;
			a_test[i] += koef_a / std::complex < float>(4, 4);
			b_test[i] += koef_b / std::complex < float>(-15, -15);
		}
		a /= std::complex < float>(4,4);
		b /= std::complex < float>(-15, -15);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			EXPECT_EQ(a_test[i], a[i]);
			EXPECT_EQ(b_test[i], b[i]);
		}
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> a(5);
		Vector<std::complex<double>> b(5);
		Vector<std::complex<double>> a_test(5);
		Vector<std::complex<double>> b_test(5);
		EXPECT_THROW(a /= std::complex<double>(0, 0), const char*);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			std::complex<double> koef_a = std::complex <double>(4, 4) + std::complex<double>((double)i, (double)i);
			std::complex<double> koef_b = std::complex < double>(15, 15) * std::complex<double>((double)i, (double)i);
			a[i] += koef_a;
			b[i] += koef_b;
			a_test[i] += koef_a / std::complex < double>(4, 4);
			b_test[i] += koef_b / std::complex < double>(-15, -15);
		}
		a /= std::complex < double>(4, 4);
		b /= std::complex < double>(-15, -15);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			EXPECT_EQ(a_test[i], a[i]);
			EXPECT_EQ(b_test[i], b[i]);
		}
	}
}
TEST(VectorTests, OperatorDivide)
{
	//int
	{
		Vector<int> a(5);
		Vector<int> b(5);
		Vector<int> a_test(5);
		Vector<int> b_test(5);
		EXPECT_THROW(a = a/ 0, const char*);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			int koef_a = 4 + (int)i;
			int koef_b = 15 * (int)i;
			a[i] += koef_a;
			b[i] += koef_b;
			a_test[i] += koef_a / 4;
			b_test[i] += koef_b / (-15);
		}
		a = a / 4;
		b = b / (-15);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			EXPECT_EQ(a_test[i], a[i]);
			EXPECT_EQ(b_test[i], b[i]);
		}
	}
	//float
	{
		Vector<float> a(5);
		Vector<float> b(5);
		Vector<float> a_test(5);
		Vector<float> b_test(5);
		EXPECT_THROW(a = a / 0, const char*);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			float koef_a = 4 + (float)i;
			float koef_b = 15 * (float)i;
			a[i] += koef_a;
			b[i] += koef_b;
			a_test[i] += koef_a / 4;
			b_test[i] += koef_b / (-15);
		}
		a = a / 4;
		b = b / (-15);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			EXPECT_EQ(a_test[i], a[i]);
			EXPECT_EQ(b_test[i], b[i]);
		}
	}
	//double
	{
		Vector<double> a(5);
		Vector<double> b(5);
		Vector<double> a_test(5);
		Vector<double> b_test(5);
		EXPECT_THROW(a = a / 0, const char*);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			double koef_a = 4 + (double)i;
			double koef_b = 15 * (double)i;
			a[i] += koef_a;
			b[i] += koef_b;
			a_test[i] += koef_a / 4;
			b_test[i] += koef_b / (-15);
		}
		a = a/ 4;
		b = b/ (-15);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			EXPECT_EQ(a_test[i], a[i]);
			EXPECT_EQ(b_test[i], b[i]);
		}
	}
	//std::complex<float>
	{
		Vector<std::complex<float>> a(5);
		Vector<std::complex<float>> b(5);
		Vector<std::complex<float>> a_test(5);
		Vector<std::complex<float>> b_test(5);
		EXPECT_THROW(a = a / std::complex<float>(0, 0), const char*);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			std::complex<float> koef_a = std::complex < float>((float)4, (float)4) + std::complex<float>((float)i, (float)i);
			std::complex<float> koef_b = std::complex < float>((float)15, (float)15) * std::complex<float>((float)i, (float)i);
			a[i] += koef_a;
			b[i] += koef_b;
			a_test[i] += koef_a / std::complex < float>(4, 4);
			b_test[i] += koef_b / std::complex < float>(-15, -15);
		}
		a = a / std::complex < float>(4, 4);
		b = b / std::complex < float>(-15, -15);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			EXPECT_EQ(a_test[i], a[i]);
			EXPECT_EQ(b_test[i], b[i]);
		}
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> a(5);
		Vector<std::complex<double>> b(5);
		Vector<std::complex<double>> a_test(5);
		Vector<std::complex<double>> b_test(5);
		EXPECT_THROW(a = a / std::complex<double>(0, 0), const char*);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			std::complex<double> koef_a = std::complex <double>(4, 4) + std::complex<double>((double)i, (double)i);
			std::complex<double> koef_b = std::complex < double>(15, 15) * std::complex<double>((double)i, (double)i);
			a[i] += koef_a;
			b[i] += koef_b;
			a_test[i] += koef_a / std::complex < double>(4, 4);
			b_test[i] += koef_b / std::complex < double>(-15, -15);
		}
		a = a/ std::complex < double>(4, 4);
		b = b/ std::complex < double>(-15, -15);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			EXPECT_EQ(a_test[i], a[i]);
			EXPECT_EQ(b_test[i], b[i]);
		}
	}
}
TEST(VectorTests, OperatorAssigment)
{
	//int
	{
		Vector<int> a(3);
		Vector<int> b(3);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			a[i] += (int)i;
			b[i] += (int)2;
		}
		//self-assigment
		{
			Vector<int> a_copy(a);
			a = a;
			EXPECT_EQ(a_copy.GetSize(), a.GetSize());
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				EXPECT_EQ(a[i], a_copy[i]);
			}
		}
		//operators +
		Vector<int> c;
		EXPECT_NO_THROW(c = a + b + b + a + a);
		EXPECT_NO_THROW(c = c);
		EXPECT_NO_THROW(c = a);
		Vector<int> d(10);
		EXPECT_NO_THROW(c = d);
	}
	//float
	{
		Vector<float> a(3);
		Vector<float> b(3);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			a[i] += i;
			b[i] += 2;
		}
		//self-assigment
		{
			Vector<float> a_copy(a);
			a = a;
			EXPECT_EQ(a_copy.GetSize(), a.GetSize());
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				EXPECT_EQ(a[i], a_copy[i]);
			}
		}
		//operators +
		Vector<float> c;
		EXPECT_NO_THROW(c = a + b);
		EXPECT_NO_THROW(c = c);
		EXPECT_NO_THROW(c = a);
		Vector<float> d(10);
		EXPECT_NO_THROW(c = d);
	}
	//double
	{
		Vector<double> a(3);
		Vector<double> b(3);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			a[i] += i;
			b[i] += 2;
		}
		//self-assigment
		{
			Vector<double> a_copy(a);
			a = a;
			EXPECT_EQ(a_copy.GetSize(), a.GetSize());
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				EXPECT_EQ(a[i], a_copy[i]);
			}
		}
		//operators +
		Vector<double> c;
		EXPECT_NO_THROW(c = a + b);
		EXPECT_NO_THROW(c = c);
		EXPECT_NO_THROW(c = a);
		Vector<double> d(10);
		EXPECT_NO_THROW(c = d);
	}
	//std::complex<float>
	{
		Vector<std::complex<float>> a(3);
		Vector<std::complex<float>> b(3);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			a[i] += std::complex<float>((float)i, (float)i);
			b[i] += std::complex <float>((float)2, (float)2);
		}
		//self-assigment
		{
			Vector<std::complex<float>> a_copy(a);
			a = a;
			EXPECT_EQ(a_copy.GetSize(), a.GetSize());
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				EXPECT_EQ(a[i], a_copy[i]);
			}
		}
		//operators +
		Vector<std::complex<float>> c;
		EXPECT_NO_THROW(c = a + b);
		EXPECT_NO_THROW(c = c);
		EXPECT_NO_THROW(c = a);
		Vector<std::complex<float>> d(10);
		EXPECT_NO_THROW(c = d);
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> a(3);
		Vector<std::complex<double>> b(3);
		for (size_t i = 0; i < a.GetSize(); i++)
		{
			a[i] += std::complex<double>((double)i, (double)i);
			b[i] += std::complex<double>((double)2, (double)2);
		}
		//self-assigment
		{
			Vector<std::complex<double>> a_copy(a);
			a = a;
			EXPECT_EQ(a_copy.GetSize(), a.GetSize());
			for (size_t i = 0; i < a.GetSize(); i++)
			{
				EXPECT_EQ(a[i], a_copy[i]);
			}
		}
		//operators +
		Vector<std::complex<double>> c;
		EXPECT_NO_THROW(c = a + b);
		EXPECT_NO_THROW(c = c);
		EXPECT_NO_THROW(c = a);
		Vector<std::complex<double>> d(10);
		EXPECT_NO_THROW(c = d);
	}
}
TEST(VectorTests, OperatorIsEqual)
{
	//int
	{
		Vector<int> a(5);
		Vector<int> b(11);
		EXPECT_FALSE(a == b);

		Vector<int> c(3);
		Vector<int> d(3);
		Vector<int> equal_one(3);
		Vector<int> equal_two(3);
		for (size_t i = 0; i < c.GetSize(); i++)
		{
			c[i] = (int)i + 1;
			d[i] = (int)i;
			equal_one[i] = (int)i * (int)i;
			equal_two[i] = (int)i * (int)i;
		}

		EXPECT_FALSE(c == d);
		EXPECT_TRUE(equal_one == equal_two);


		Vector<int> epsilon_test_one(3);
		Vector<int> epsilon_test_two(3);
		for (size_t i = 0; i < epsilon_test_one.GetSize(); i++)
		{
			epsilon_test_one[i] += (int)0.0001;
		}
		EXPECT_TRUE(epsilon_test_one == epsilon_test_two);
	}
	//float
	{
		Vector<float> a(5);
		Vector<float> b(11);
		EXPECT_FALSE(a == b);

		Vector<float> c(3);
		Vector<float> d(3);
		Vector<float> equal_one(3);
		Vector<float> equal_two(3);
		for (size_t i = 0; i < c.GetSize(); i++)
		{
			c[i] = (float)i + 1;
			d[i] = (float)i;
			equal_one[i] = (float)i * (float)i;
			equal_two[i] = (float)i * (float)i;
		}

		EXPECT_FALSE(c == d);
		EXPECT_TRUE(equal_one == equal_two);


		Vector<float> epsilon_test_one(3);
		Vector<float> epsilon_test_two(3);
		for (size_t i = 0; i < epsilon_test_one.GetSize(); i++)
		{
			epsilon_test_one[i] += (float)0.0045;
		}
		EXPECT_TRUE(epsilon_test_one == epsilon_test_two);
	}
	//double
	{
		Vector<double> a(5);
		Vector<double> b(11);
		EXPECT_FALSE(a == b);

		Vector<double> c(3);
		Vector<double> d(3);
		Vector<double> equal_one(3);
		Vector<double> equal_two(3);
		for (size_t i = 0; i < c.GetSize(); i++)
		{
			c[i] = (double)i + 1;
			d[i] = (double)i;
			equal_one[i] = (double)i * (double)i;
			equal_two[i] = (double)i * (double)i;
		}

		EXPECT_FALSE(c == d);
		EXPECT_TRUE(equal_one == equal_two);


		Vector<double> epsilon_test_one(3);
		Vector<double> epsilon_test_two(3);
		for (size_t i = 0; i < epsilon_test_one.GetSize(); i++)
		{
			epsilon_test_one[i] += 0.00048;
		}
		EXPECT_TRUE(epsilon_test_one == epsilon_test_two);
	}
	//std::complex<float>
	{
		Vector<std::complex<float>> a(5);
		Vector<std::complex<float>> b(11);
		EXPECT_FALSE(a == b);

		Vector<std::complex<float>> c(3);
		Vector<std::complex<float>> d(3);
		Vector<std::complex<float>> equal_one(3);
		Vector<std::complex<float>> equal_two(3);
		for (size_t i = 0; i < c.GetSize(); i++)
		{
			c[i] = std::complex<float>((float)i, (float)i) + std::complex <float>(1,1);
			d[i] = std::complex<float>((float)i, (float)i);
			equal_one[i] = std::complex<float>((float)i, (float)i) * std::complex<float>((float)i, (float)i);
			equal_two[i] = std::complex<float>((float)i, (float)i) * std::complex<float>((float)i, (float)i);
		}

		EXPECT_FALSE(c == d);
		EXPECT_TRUE(equal_one == equal_two);
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> a(5);
		Vector<std::complex<double>> b(11);
		EXPECT_FALSE(a == b);

		Vector<std::complex<double>> c(3);
		Vector<std::complex<double>> d(3);
		Vector<std::complex<double>> equal_one(3);
		Vector<std::complex<double>> equal_two(3);
		for (size_t i = 0; i < c.GetSize(); i++)
		{
			c[i] = std::complex<double>((double)i, (double)i) + std::complex <double>(1, 1);
			d[i] = std::complex<double>((double)i, (double)i);
			equal_one[i] = std::complex<double>((double)i, (double)i) * std::complex<double>((double)i, (double)i);
			equal_two[i] = std::complex<double>((double)i, (double)i) * std::complex<double>((double)i, (double)i);
		}

		EXPECT_FALSE(c == d);
		EXPECT_TRUE(equal_one == equal_two);
	}
}
TEST(VectorTests, OperatorNotEqual)
{
	//int
	{
		Vector<int> a(5);
		Vector<int> b(11);
		EXPECT_TRUE(a != b);

		Vector<int> c(3);
		Vector<int> d(3);
		Vector<int> equal_one(3);
		Vector<int> equal_two(3);
		for (size_t i = 0; i < c.GetSize(); i++)
		{
			c[i] = (int)i + 1;
			d[i] = (int)i;
			equal_one[i] = (int)i * (int)i;
			equal_two[i] = (int)i * (int)i;
		}
		EXPECT_TRUE(c != d);
		EXPECT_FALSE(equal_one != equal_two);
	}
	//float
	{
		Vector<float> a(5);
		Vector<float> b(11);
		EXPECT_TRUE(a != b);

		Vector<float> c(3);
		Vector<float> d(3);
		Vector<float> equal_one(3);
		Vector<float> equal_two(3);
		for (size_t i = 0; i < c.GetSize(); i++)
		{
			c[i] = (float)i + (float)1.5;
			d[i] = (float)i;
			equal_one[i] = (float)i * (float)i + (float)0.5;
			equal_two[i] = (float)i * (float)i + (float)0.5;
		}
		EXPECT_TRUE(c != d);
		EXPECT_FALSE(equal_one != equal_two);
	}
	//double
	{
		Vector<double> a(5);
		Vector<double> b(11);
		EXPECT_TRUE(a != b);

		Vector<double> c(3);
		Vector<double> d(3);
		Vector<double> equal_one(3);
		Vector<double> equal_two(3);
		for (size_t i = 0; i < c.GetSize(); i++)
		{
			c[i] = (double)i + 1.5;
			d[i] = (double)i;
			equal_one[i] = (double)i * (double)i + 0.5;
			equal_two[i] = (double)i * (double)i + 0.5;
		}
		EXPECT_TRUE(c != d);
		EXPECT_FALSE(equal_one != equal_two);
	}
	//std::complex<float>
	{
		Vector<std::complex<float>> a(5);
		Vector<std::complex<float>> b(11);
		EXPECT_TRUE(a != b);

		Vector<std::complex<float>> c(3);
		Vector<std::complex<float>> d(3);
		Vector<std::complex<float>> equal_one(3);
		Vector<std::complex<float>> equal_two(3);
		for (size_t i = 0; i < c.GetSize(); i++)
		{
			c[i] = std::complex<float>((float)i,(float)i) + std::complex<float>((float)1.5,(float)1.5);
			d[i] = std::complex<float>((float)i, (float)i);
			equal_one[i] = std::complex<float>((float)i,(float)i) + std::complex<float>((float)0.5,(float)0.5);
			equal_two[i] = std::complex<float>((float)i, (float)i) + std::complex<float>((float)0.5, (float)0.5);
		}
		EXPECT_TRUE(c != d);
		EXPECT_FALSE(equal_one != equal_two);
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> a(5);
		Vector<std::complex<double>> b(11);
		EXPECT_TRUE(a != b);

		Vector<std::complex<double>> c(3);
		Vector<std::complex<double>> d(3);
		Vector<std::complex<double>> equal_one(3);
		Vector<std::complex<double>> equal_two(3);
		for (size_t i = 0; i < c.GetSize(); i++)
		{
			c[i] = std::complex<double>((double)i, (double)i) + std::complex<double>(1.5, 1.5);
			d[i] = std::complex<double>((double)i,(double)i);
			equal_one[i] = std::complex<double>((double)i, (double)i) + std::complex<double>(0.5, 0.5);
			equal_two[i] = std::complex<double>((double)i, (double)i) + std::complex<double>(0.5, 0.5);
		}
		EXPECT_TRUE(c != d);
		EXPECT_FALSE(equal_one != equal_two);
	}
}
TEST(VectorTests, DotProductPrimitiveTypes)
{
	//int
	{
		Vector<int> vector_one(3);
		Vector<int> vector_two(3);
		Vector<int> bad_dimensions(22);
		EXPECT_THROW(vector_one.DotProduct(bad_dimensions), const char*);
		EXPECT_EQ(0, vector_two.DotProduct(vector_one));
		for (size_t i = 0; i < vector_one.GetSize(); i++)
		{
			vector_one[i] = 1 * (int)i; //0 1 2
			vector_two[i] = 2 * (int)i; //0 2 4
		}
		EXPECT_EQ(10, vector_one.DotProduct(vector_two));
	}
	//float
	{
		Vector<float> vector_one(3);
		Vector<float> vector_two(3);
		Vector<float> bad_dimensions(22);
		EXPECT_THROW(vector_one.DotProduct(bad_dimensions), const char*);
		EXPECT_EQ(0, vector_two.DotProduct(vector_one));
		for (size_t i = 0; i < vector_one.GetSize(); i++)
		{
			vector_one[i] = (float)1.5 * (float)i; //0 1.5 3
			vector_two[i] = (float)2.5 * (float)i; //0 2.5 5
		}
		EXPECT_EQ(18.75, vector_one.DotProduct(vector_two));
	}
	//double
	{
		Vector<double> vector_one(3);
		Vector<double> vector_two(3);
		Vector<double> bad_dimensions(22);
		EXPECT_THROW(vector_one.DotProduct(bad_dimensions), const char*);
		EXPECT_EQ(0, vector_two.DotProduct(vector_one));
		for (size_t i = 0; i < vector_one.GetSize(); i++)
		{
			vector_one[i] = (double)1.5 * (double)i; //0 1.5 3
			vector_two[i] = (double)2.5 * (double)i; //0 2.5 5
		}
		EXPECT_EQ(18.75, vector_one.DotProduct(vector_two));
	}
}
TEST(VectorTests, DotProductStdComplex)
{
	//std::complex<float>
	{
		Vector<std::complex<float>> vector_one(2);
		Vector<std::complex<float>> vector_two(2);
		Vector<std::complex<float>> bad_dimensions(22);
		EXPECT_THROW(vector_one.DotProduct(bad_dimensions), const char*);
		EXPECT_EQ(std::complex<float>((float)0,(float)0), vector_two.DotProduct(vector_one));
		for (size_t i = 0; i < vector_one.GetSize(); i++)
		{
			vector_one[i] = std::complex<float>((float)i,(float)-1); //(0,-1) (1,-1)
			vector_two[i] = std::complex<float>((float)1, (float)-5); //(1,-5), (1,-5)
		}
		EXPECT_EQ(std::complex<float>(1,-10), vector_one.DotProduct(vector_two));
	}
	//std::complex<double>
	{
		Vector<std::complex<double>> vector_one(2);
		Vector<std::complex<double>> vector_two(2);
		Vector<std::complex<double>> bad_dimensions(22);
		EXPECT_THROW(vector_one.DotProduct(bad_dimensions), const char*);
		EXPECT_EQ(std::complex<double>((double)0, (double)0), vector_two.DotProduct(vector_one));
		for (size_t i = 0; i < vector_one.GetSize(); i++)
		{
			vector_one[i] = std::complex<double>((double)i, (double)-1); //(0,-1) (1,-1)
			vector_two[i] = std::complex<double>((double)1, (double)-5); //(1,-5), (1,-5)
		}
		EXPECT_EQ(std::complex<double>(1, -10), vector_one.DotProduct(vector_two));
	}
}