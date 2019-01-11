#ifndef _Set_h_
#define _Set_h_
#include "BitField.h"
#include<iostream>

class TSet
{
private:
	int maxPower; // ������������ �������� ���������
	TBitField bitField; // ������� ���� ��� �������� ���-�� �������
public:
	TSet(int mp);
	TSet(const TSet &s); // ����������� �����������
	TSet(const TBitField &bf); // ����������� �������������� ����
	operator TBitField(); // �������������� ���� � �������� ����
	// ������ � �����
	int getMaxPower(void) const; // ������������ �������� ���������
	void insElem(const int n); // �������� ������� � ���������
	void delElem(const int n); // ������� ������� �� ���������
	int isMember(const int n) const; // ��������� ������� �������� � ���������
	
	// ���������-������������� ��������
	int operator== (const TSet &s); // ���������
	TSet& operator=(const TSet &s); // ������������
	TSet operator+ (const int n); // ��������� �������� � ���������
	TSet operator- (const int n); // �������� �������� �� ���������
	TSet operator+ (const TSet &s); // �����������
	TSet operator* (const TSet &s); // �����������
	TSet operator~ (void); // ����������
	friend std::istream &operator>>(std::istream &istr, TSet &bf);
	friend std::ostream &operator<<(std::ostream &ostr, const TSet &bf);
};

#endif