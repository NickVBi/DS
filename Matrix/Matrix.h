#ifndef _Matrix_h_
#define _Matrix_h_

template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &mt); // �����������
	TMatrix(const TVector<TVector<ValType> > &mt); // �������������� ����
	TMatrix& operator==(const TMatrix &mt); // ���������
	TMatrix& operator= (const TMatrix &mt); // ������������
	TMatrix operator+ (const TMatrix &mt); // ��������
	TMatrix operator- (const TMatrix &mt); // ���������
	TMatrix operator* (const TMatrix &mt); // ���������
};

#endif

