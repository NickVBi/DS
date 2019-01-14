#ifndef _Vector_h_
#define _Vector_h_

#include <iostream>

template <class ValType>
class TVector
{
protected:
	ValType *pVector;
	int size; // размер вектора
	int startIndex; // индекс первого элемента вектора
public:
	TVector(int s = 10, int si = 0) {
		size = s;
		startIndex = si;
		this->pVector = new ValType[s];
	}

	TVector(const TVector &v) { // конструктор копирования
		this->size = v.size;
		this->startIndex = v.startIndex;
		this->pVector = new ValType[v.size];
		for (int i = 0; i < this->size; i++)
			pVector[i] = v.pVector[i];

	}

	~TVector() {
		delete[] pVector;
	}

	int getSize() { return size; } // размер вектора

	int getStartIndex() { return startIndex; } // индекс первого элемента

	ValType& getValue(int pos) { // доступ с контролем индекса
		return pVector[pos];
		startIndex++;
	}

	ValType& operator[](int pos) { // доступ
		return pVector[pos];
	} 

	int operator==(const TVector &v) { // сравнение
		int max_size = (this->size > v.getSize())? this->size  : v.getSize();
		for (int i = 0; i < max_size; i++)
			if (this->pVector[i] != v.pVector[i])
				return 0;
		return 1;
	}

	TVector& operator= (const TVector &v) { // присванивание
		if (this != &v)
		{
			if (size != v.size)
			{
				delete[] pVector;
				pVector = new ValType[v.size];
			}
			size = v.size;
			startIndex = v.startIndex;
			for (int i = 0; i < size; i++)
				pVector[i] = v.pVector[i];
		}
		return *this;
	}

	// скалярные операции
	TVector operator+ (const ValType &val) {  // прибавить скаляр
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] + val;
		return temp;
	} 

	TVector operator- (const ValType &val) { // вычесть скаляр
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] - val;
		return temp;
	} 

	TVector operator* (const ValType &val) { // умножить на скаляр
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] * val;
		return temp;
	} 

	// векторные операции
	TVector operator+ (const TVector &v) {  // сложение
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] + v.pVector[i];
		return temp;
	} 

	TVector operator- (const TVector &v) {  // вычитание
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] - v.pVector[i];
		return temp;
	}
	
	TVector operator* (const TVector &v) {  // скалярное произведение
		TVector temp(1, startIndex);
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += pVector[i] * v.pVector[i];
		temp[0] = sqrt((double)sum);
		return temp;
	}
	
	// ввод-вывод
	friend std::ostream& operator<<(std::ostream &out, const TVector &v) {
		TVector v1(v);
		for (int i = v1.getStartIndex(); i < v1.getSize(); i++) {
			out << v1[i] << "\t";
		}
		return out;
	}


};


#endif