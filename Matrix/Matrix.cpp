#include "pch.h"
#include "Matrix.h"


template<class ValType>
inline TMatrix<ValType>::TMatrix(int s)
{
	pVector = new TVector<ValType>[s];
	size = s;
	startIndex = 0;
	for (int i = 0; i < size; i++)
		pVector[i] = mt.pVector[i];
}

template<class ValType>
TMatrix<ValType>::TMatrix(const TMatrix & mt)
{
	TMatrix<ValType> copies;
	copies.
	if (this != &mt)
	{
		if (size != mt.size)
		{
			pVector = new TVector<ValType>[mt.size];
		}
		size = mt.size;
		startIndex = mt.startIndex;
		for (int i = 0; i < size; i++)
			pVector[i] = mt.pVector[i];
	}
	return *this;
}

template<class ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType>>& mt)
{
	return mt.pVector;
}

template<class ValType>
TMatrix<ValType> & TMatrix<ValType>::operator==(const TMatrix & mt)
{
	for (int i = 0; i < this->size; i++)
		if (this-> pVector[i] != mt.pVector[i])
			return 0;
	return 1;
}

template <class ValType>
TMatrix<ValType>& TMatrix<ValType>::operator=(
	const TMatrix<ValType> &mt)
{
	if (this != &mt)
	{
		if (size != mt.size)
		{
			delete[] pVector;
			pVector = new TVector<ValType>[mt.size];
		}
		size = mt.size;
		startIndex = mt.startIndex;
		for (int i = 0; i < size; i++)
			pVector[i] = mt.pVector[i];
	}
	return *this;
}
template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix & mt)
{
	for (int i = 0; i < this->size; i++) {
		this->pVector[i] += v.pVector[i];
	}
	return *this;
}

template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix & mt)
{
	for (int i = 0; i < this->size; i++) {
		this->pVector[i] -= v.pVector[i];
	}
	return *this;
}

template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix & mt)
{
	for (int i = 0; i < this->size; i++) {
		this->pVector[i] *= v.pVector[i];
	}
	return *this;
}
