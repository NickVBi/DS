#ifndef _Matrix_h_
#define _Matrix_h_

template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &mt); // копирование
	TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
	TMatrix& operator==(const TMatrix &mt); // сравнение
	TMatrix& operator= (const TMatrix &mt); // присваивание
	TMatrix operator+ (const TMatrix &mt); // сложение
	TMatrix operator- (const TMatrix &mt); // вычитание
	TMatrix operator* (const TMatrix &mt); // умножение
};

#endif

