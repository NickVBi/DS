#ifndef _Matrix_h_
#define _Matrix_h_

template <class ValType>
class TMatrix : public TVector<TVector<ValType>>
{
public:
	TMatrix(int s = 10) {
		this->size = s;
		this->startIndex = 0;
		this->pVector = new TVector<ValType>[s];
		for (int i = 0; i < this->size; i++) {
			TVector<ValType> t(s, i);
			this->pVector[i] = t;
		}

	}

	TMatrix(const TMatrix &mt) { // �����������

		this->size = mt.size;
		this->startIndex = mt.startIndex;
		this->pVector = new TVector<ValType>[mt.size];
		for (int i = 0; i < this->size; i++)
			this->pVector[i] = mt.pVector[i];
	}

	TMatrix(const TVector<TVector<ValType> > &mt) { // �������������� ����
		return mt.pVector;
	} 

	TMatrix& operator==(const TMatrix &mt){ // ���������
		for (int i = 0; i < this->size; i++)
			if (this->pVector[i] != mt.pVector[i])
				return 0;
		return 1;
	} 

	TMatrix& operator= (const TMatrix &mt) { // ������������
		if (this != &mt)
		{
			if (this->size != mt.size)
			{
				delete[] this->pVector;
				this->pVector = new TVector<ValType>[mt.size];
			}
			this->size = mt.size;
			this->startIndex = mt.startIndex;
			for (int i = 0; i < this->size; i++)
				this->pVector[i] = mt.pVector[i];
		}
		return *this;
	} 

	TMatrix operator+ (const TMatrix &mt) { // ��������
		TMatrix temp(this->size);
		for (int i = 0; i < this->size; i++)
			temp.pVector[i] = this->pVector[i] + mt.pVector[i];
		return temp;
	}

	TMatrix operator- (const TMatrix &mt) { // ���������
		TMatrix temp(this->size);
		for (int i = 0; i < this->size; i++)
			temp.pVector[i] = this->pVector[i] - mt.pVector[i];
		return temp;
	}

	TMatrix operator* (const TMatrix &mt) { // ���������
		TMatrix temp(this->size);
		for (int i = 0; i < this->size; i++)
			temp.pVector[i] = this->pVector[i] * mt.pVector[i];
		return temp;
	}

	friend std::ostream & operator<<(std::ostream &out, const TMatrix &mt) {
		TMatrix mt1(mt);
		for (int i = 0; i < mt1.getSize(); i++) {
			out << mt1[i] << std::endl;
		}
		return out;
	}
};


#endif

