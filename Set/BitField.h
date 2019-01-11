#ifndef _BitField_h_
#define _BitField_h_

#include<iostream>

class TBitField
{
private:

	typedef unsigned int WORD;
	// ������ ����� ����� ����� (� �����)
	static const int wordBitSize;

	WORD *words; // ������ ��� ������������� �������� ����
	int lenBit; // ����� �������� ���� - ����. �-�� �����
	int lenWord; // �-�� ��-��� ��� ��� ������������� ���.����
	// ������ ����������
	int getWordIndex(const int n) const; // ������ � words ��� ���� n
	WORD getWordMask(const int n) const; // ������� ����� ��� ���� n
public:
	TBitField(int len);
	TBitField(const TBitField &bf);
	~TBitField();
	// ������ � �����
	int getLength(void) const; // �������� ����� (�-�� �����)
	void setBit(const int n); // ���������� ���
	void clrBit(const int n); // �������� ���
	int getBit(const int n) const; // �������� �������� ����

	// �������� ��������� ��������
	// (�� �� , ��� ��������� ����)
	TBitField& operator|= (int n);
	
	// �������� �������� ��������
	// (�� �� , ��� ������� ����)
	TBitField& operator -=(int n);

	// �������� ��� �����������
	TBitField& operator |=(const TBitField& bf); // �����������
	TBitField& operator &=(const TBitField& bf); // �����������
	TBitField& operator -=(const TBitField& bf); // ��������


	// ������� ��������
	int operator==(const TBitField &bf); // ���������
	TBitField& operator=(const TBitField &bf); // ������������
	TBitField operator|(const TBitField &bf); // �������� "���"
	TBitField operator&(const TBitField &bf); // �������� "�"
	TBitField operator~(void); // ���������
//	friend std::istream &operator>>(std::istream &istr, TBitField &bf);
	friend std::ostream &operator<<(std::ostream &ostr, const TBitField &bf);
};

#endif