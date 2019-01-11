#include "pch.h"
#include "Vector.h"

template<class ValType>
TVector<ValType>::TVector(int s, int si)
{
	size = s;
	startIndex = si;
	this->pVector = new ValType[s];
}

template<class ValType>
TVector<ValType>::TVector(const TVector & v)
{
}

template<class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
}

template<class ValType>
ValType & TVector<ValType>::getValue(int pos)
{
	return pVector[pos];
}

template<class ValType>
ValType & TVector<ValType>::operator[](int pos)
{
	return *pVector[pos];
}

template<class ValType>
int TVector<ValType>::operator==(const TVector & v)
{
	for (int i = 0; i < this->size; i++)
		if (this->pVector[i] != v.pVector[i])
			return 0;
	return 1;
}

template <class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
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

template<class ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType & val)
{
	for (int i = 0; i < this->size; i++)
		this->pVector[i] += val;
	return *this;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType & val)
{
	for (int i = 0; i < this->size; i++)
		this->pVector[i] -= val;
	return *this;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType & val)
{
	for (int i = 0; i < this->size; i++)
		this->pVector[i] *= val;
	return *this;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector & v)
{
	for (int i = 0; i < this->size; i++) {
		this->pVector[i] += v.pVector[i];
	}
	return *this;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector & v)
{
	for (int i = 0; i < this->size; i++) {
		this->pVector[i] -= v.pVector[i];
	}
	return *this;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator*(const TVector & v)
{
	int res = 0;
	for (int i = 0; i < this->size; i++) {
		res += this->pVector[i] * v.pVector[i];
	}
	return sqrt(res);
}
