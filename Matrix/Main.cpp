// Matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

using namespace std;

int main()
{
/*	TVector<int> v(10, 0);
	for (int i = 0; i < v.getSize(); i++) {
		v[i] = i + 1;
	}
	cout << v << endl;
	cout << v + 2 << endl;
	cout << v - 2 << endl;
	cout << v * 2 << endl;
	*/


	TMatrix<int> a(5), b(5), c(5);
	int i, j;

	cout << endl << a.getSize() << " " << a[0].getSize() << endl;

	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки треугольных матриц" << endl;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = (i * 10 + j) * 100;
		}
	c = a + b;
	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b = " << endl << b << endl;
	cout << "Matrix c = a + b" << endl << c << endl;
	return 0;
}