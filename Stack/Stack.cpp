#include "Stack.h"

int TStack::GetNextIndex(int index)
{
	return ++index;
}

TStack::TStack(int Size)
{
	DataCount = 0;
	if (Size = 0) { Size = MaxMemSize; }
	MemSize = Size;
	pMem = new TElem[MemSize];
	Hi = -1;
}

TStack::~TStack()
{
	delete[]pMem;
}

int TStack::IsEmpty(void) const
{
	return DataCount == 0;
}

int TStack::IsFull(void) const
{
	return DataCount == MemSize;
}

void TStack::Put(const TElem & Val)
{
	Hi = GetNextIndex(Hi);
	pMem[Hi] = Val;
	DataCount++;

	Hi = GetNextIndex(Hi);
	pMem[Hi] = Val;
	DataCount++;
}

TElem TStack::Get(void)
{
	DataCount--;
	return pMem[Hi--];
}