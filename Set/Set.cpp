#include "Set.h"
#include "pch.h"


TSet::TSet(int mp) : bitField(mp)
{
	this->maxPower = mp;
}

TSet::TSet(const TSet & s) : bitField(s.bitField)
{
	this->maxPower = s.maxPower;
}

TSet::TSet(const TBitField & bf) : bitField(bf)
{
	this->maxPower = bf.getLength();
}

TSet::operator TBitField()
{
	return bitField;
}

int TSet::getMaxPower(void) const
{
	return maxPower;
}

void TSet::insElem(const int n)
{
	bitField.setBit(n);
}

void TSet::delElem(const int n)
{
	bitField.clrBit(n);
}

int TSet::isMember(const int n) const
{
	return bitField.getBit(n);
}

int TSet::operator==(const TSet & s)
{
	return this->bitField == s.bitField;
}

TSet & TSet::operator=(const TSet & s)
{
	return *(new TSet(s));
}

TSet TSet::operator+(const int n)
{
	this->bitField.setBit(n);
	return *this;
}

TSet TSet::operator-(const int n)
{
	this->bitField.clrBit(n);
	return *this;
}

TSet TSet::operator+(const TSet &s)
{
	TSet temp(bitField | s.bitField);
	return temp;
}

TSet TSet::operator*(const TSet &s)
{
	TSet temp(bitField & s.bitField);
	return temp;
}

std::istream & operator>>(std::istream & istr, TSet & bf)
{
	return std::cin;
}

std::ostream & operator<<(std::ostream & ostr, const TSet & bf)
{
	return std::cout << bf.bitField;
}
