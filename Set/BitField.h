#ifndef _BitField_h_
#define _BitField_h_

#include<iostream>

class TBitField
{
private:

	typedef unsigned int WORD;
	// Размер слова шкалы битов (в битах)
	static const int wordBitSize;

	WORD *words; // память для представления битового поля
	int lenBit; // длина битового поля - макс. к-во битов
	int lenWord; // к-во эл-тов Мем для представления бит.поля
	// методы реализации
	int getWordIndex(const int n) const; // индекс в words для бита n
	WORD getWordMask(const int n) const; // битовая маска для бита n
public:
	TBitField(int len);
	TBitField(const TBitField &bf);
	~TBitField();
	// доступ к битам
	int getLength(void) const; // получить длину (к-во битов)
	void setBit(const int n); // установить бит
	void clrBit(const int n); // очистить бит
	int getBit(const int n) const; // получить значение бита

	// Операция занесения элемента
	// (то же , что установка бита)
	TBitField& operator|= (int n);
	
	// Операция удаления элемента
	// (то же , что очистка бита)
	TBitField& operator -=(int n);

	// Операции над множествами
	TBitField& operator |=(const TBitField& bf); // Объединение
	TBitField& operator &=(const TBitField& bf); // Пересечение
	TBitField& operator -=(const TBitField& bf); // Разность


	// битовые операции
	int operator==(const TBitField &bf); // сравнение
	TBitField& operator=(const TBitField &bf); // присваивание
	TBitField operator|(const TBitField &bf); // операция "или"
	TBitField operator&(const TBitField &bf); // операция "и"
	TBitField operator~(void); // отрицание
//	friend std::istream &operator>>(std::istream &istr, TBitField &bf);
	friend std::ostream &operator<<(std::ostream &ostr, const TBitField &bf);
};

#endif