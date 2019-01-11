#ifndef _Vector_h_
#define _Vector_h_

template <class ValType>
class TVector
{
protected:
	ValType *pVector;
	int size; // ������ �������
	int startIndex; // ������ ������� �������� �������
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v); // ����������� �����������
	~TVector();
	int getSize() { return size; } // ������ �������
	int getStartIndex() { return startIndex; } // ������ ������� ��������
	ValType& getValue(int pos); // ������ � ��������� �������
	ValType& operator[](int pos); // ������
	int operator==(const TVector &v); // ���������
	TVector& operator= (const TVector &v); // �������������
	// ��������� ��������
	TVector operator+ (const ValType &val); // ��������� ������
	TVector operator- (const ValType &val); // ������� ������
	TVector operator* (const ValType &val); // �������� �� ������
	// ��������� ��������
	TVector operator+ (const TVector &v); // ��������
	TVector operator- (const TVector &v); // ���������
	TVector operator* (const TVector &v); // ��������� ������������
	// ����-�����
};

#endif