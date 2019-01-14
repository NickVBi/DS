#ifndef _Vector_h_
#define _Vector_h_

#include <iostream>

template <class ValType>
class TVector
{
protected:
	ValType *pVector;
	int size; // ������ �������
	int startIndex; // ������ ������� �������� �������
public:
	TVector(int s = 10, int si = 0) {
		size = s;
		startIndex = si;
		this->pVector = new ValType[s];
	}

	TVector(const TVector &v) { // ����������� �����������
		this->size = v.size;
		this->startIndex = v.startIndex;
		this->pVector = new ValType[v.size];
		for (int i = 0; i < this->size; i++)
			pVector[i] = v.pVector[i];

	}

	~TVector() {
		delete[] pVector;
	}

	int getSize() { return size; } // ������ �������

	int getStartIndex() { return startIndex; } // ������ ������� ��������

	ValType& getValue(int pos) { // ������ � ��������� �������
		return pVector[pos];
		startIndex++;
	}

	ValType& operator[](int pos) { // ������
		return pVector[pos];
	} 

	int operator==(const TVector &v) { // ���������
		int max_size = (this->size > v.getSize())? this->size  : v.getSize();
		for (int i = 0; i < max_size; i++)
			if (this->pVector[i] != v.pVector[i])
				return 0;
		return 1;
	}

	TVector& operator= (const TVector &v) { // �������������
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

	// ��������� ��������
	TVector operator+ (const ValType &val) {  // ��������� ������
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] + val;
		return temp;
	} 

	TVector operator- (const ValType &val) { // ������� ������
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] - val;
		return temp;
	} 

	TVector operator* (const ValType &val) { // �������� �� ������
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] * val;
		return temp;
	} 

	// ��������� ��������
	TVector operator+ (const TVector &v) {  // ��������
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] + v.pVector[i];
		return temp;
	} 

	TVector operator- (const TVector &v) {  // ���������
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] - v.pVector[i];
		return temp;
	}
	
	TVector operator* (const TVector &v) {  // ��������� ������������
		TVector temp(1, startIndex);
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += pVector[i] * v.pVector[i];
		temp[0] = sqrt((double)sum);
		return temp;
	}
	
	// ����-�����
	friend std::ostream& operator<<(std::ostream &out, const TVector &v) {
		TVector v1(v);
		for (int i = v1.getStartIndex(); i < v1.getSize(); i++) {
			out << v1[i] << "\t";
		}
		return out;
	}


};


#endif