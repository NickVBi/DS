
#include <iomanip>
#include <stdexcept>
#include <memory.h>
#include "BitField.h"
#include "pch.h"

using namespace std;

const int TBitField::wordBitSize = 8 * sizeof(TBitField::WORD);

int TBitField::getWordIndex(const int n) const
{
	return n / wordBitSize;
}

TBitField::WORD TBitField::getWordMask(const int n) const
{
	WORD mask = 1 << n % wordBitSize;
	return mask;
}

TBitField::TBitField(int len) {
	this->lenBit = len;
	this->lenWord = getWordIndex(len + wordBitSize - 1);
	this->words = new WORD[lenWord];
}


TBitField::TBitField(const TBitField &bf) {
	this->lenBit = bf.lenBit;
	this->words = bf.words;
	this->lenWord = bf.lenWord;

	//memcpy(this->words, bf.words, lenWord * sizeof(WORD));
	// this->pMem = bf;
}

TBitField::~TBitField() {
	delete[] words;
}

// доступ к битам

int TBitField::getLength(void) const { // получить длину (к-во битов)
	return this->lenBit;
} 

void TBitField::setBit(const int n) { // установить бит
	words[getWordIndex(n)] |= getWordMask(n);
} 

void TBitField::clrBit(const int n) { // очистить бит
	words[getWordIndex(n)] &= ~getWordMask(n);
} 

int TBitField::getBit(const int n) const { // получить значение бита 
	return (words[getWordIndex(n)] & getWordMask(n)) >> n;
}

TBitField & TBitField::operator|=(int n)
{
	setBit(n);
	return *this;
}


TBitField & TBitField::operator-=(int n)
{
	clrBit(n);
	return *this;
}

TBitField& TBitField::operator |=(const TBitField& bf)
{
	for (int i = bf.lenWord - 1; i >= 0; i--)
	{
		words[i] |= bf.words[i];
	}
	return *this;
}

TBitField& TBitField::operator &=(const TBitField& bf)
{
	for (int i = this->lenWord - 1; i >= 0; i--)
	{
		words[i] &= bf.words[i];
	}
	return *this;
}
TBitField& TBitField::operator -=(const TBitField& bf)
{
	for (int i = this->lenWord - 1; i >= 0; i--)
	{
		words[i] &= ~bf.words[i];
	}
	return *this;
}

// битовые операции
int TBitField::operator==(const TBitField &bf) { // сравнение
	for (int i = this->lenWord - 1; i >= 0; i--)
	{
		if (words[i] != bf.words[i])
			return 1;
	}
	return 0;
}

TBitField & TBitField::operator=(const TBitField & bf)
{
	return *(new TBitField(bf));
}

TBitField TBitField::operator|(const TBitField & bf)
{
	return *this |= bf;
}

TBitField TBitField::operator&(const TBitField & bf)
{
	return *this &= bf;
}

TBitField TBitField::operator~(void)
{
	for (int i = this->lenWord - 1; i >= 0; i--)
	{
		words[i] = ~words[i];
	}
	return *this;
}

std::ostream & operator<<(std::ostream & ostr, const TBitField & bf)
{
	for (int i = 0; i < bf.lenBit; i++) {

		std::cout << bf.getBit(i) << " ";
	}
	return std::cout;
}

