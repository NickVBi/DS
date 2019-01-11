#ifndef _Stack_h_
#define _Stack_h_

const int MaxMemSize = 25; // ������������ ������ ������ ��� �����
typedef int TElem; // ��� �������� ��
typedef TElem *PTElem; // ��� ��������� �� ��
class TStack {
protected: // ����
	PTElem pMem; // ��������� �� ������ ���������
	int MemSize; // ������ ������ ��� ��
	int DataCount; // ���������� ��������� � ��
	int Hi; // ������ ������� �����
	virtual int GetNextIndex(int index); // �������� ��������� ������
public:
	TStack(int Size = MaxMemSize);//�����������
	~TStack(); //����������
	int IsEmpty(void) const; // �������� �������
	int IsFull(void) const; // �������� ������������
	void Put(const TElem &Val);// �������� ��������
	virtual TElem Get(void); // ������� ��������
};
#endif