// DataStructudes_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Main.h"


using namespace std;

int main()
{
	int n, m, k, count;
	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки множества" << endl;
	cout << " Решето Эратосфена" << endl;
	cout << "Введите верхнюю границу целых значений - ";
	cin >> n;
	TSet s(n + 1);
	// заполнение множества
	for (m = 2; m <= n; m++)
		s.insElem(m);
	cout << endl << s << endl;
	// проверка до sqrt(n) и удаление кратных
	for (m = 2; m * m <= n; m++) {

		// если м в s, удаление кратных
		cout << m << " " << s.isMember(m) << endl;
		if (s.isMember(m))
			for (k = 2 * m; k <= n; k += m) {
				if (s.isMember(k))
					s.delElem(k);
			}
	}
	// оставшиеся в s элементы - простые числа
	cout << endl << "Печать множества некратных чисел" << endl << s << endl;
	cout << endl << "Печать простых чисел" << endl;
	count = 0;
	k = 1;
	for (m = 2; m <= n; m++)
		if (s.isMember(m))
		{
			count++;
			cout << m << " ";
			if (k++ % 10 == 0)
				cout << endl;
		}
	cout << endl;
	cout << "В первых " << n << " числах " << count << " простых" << endl;
}

