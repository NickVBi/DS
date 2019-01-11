#ifndef _Vector_h_
#define _Vector_h_

template <class ValType>
class TVector
{
protected:
	ValType *pVector;
	int size; // размер вектора
	int startIndex; // индекс первого элемента вектора
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v); // конструктор копирования
	~TVector();
	int getSize() { return size; } // размер вектора
	int getStartIndex() { return startIndex; } // индекс первого элемента
	ValType& getValue(int pos); // доступ с контролем индекса
	ValType& operator[](int pos); // доступ
	int operator==(const TVector &v); // сравнение
	TVector& operator= (const TVector &v); // присванивание
	// скалярные операции
	TVector operator+ (const ValType &val); // прибавить скаляр
	TVector operator- (const ValType &val); // вычесть скаляр
	TVector operator* (const ValType &val); // умножить на скаляр
	// векторные операции
	TVector operator+ (const TVector &v); // сложение
	TVector operator- (const TVector &v); // вычитание
	TVector operator* (const TVector &v); // скалярное произведение
	// ввод-вывод
};

#endif