#include "pch.h"
#include <String>
#include <iostream>


using namespace std;

void main()
{
	string infixStr = "1+2*(3-2)-4";
	TFormula f(infixStr.c_str);
	cout << "Infix: " << infixStr << endl;
	cout << "Postfix: " << f.FormulaConverter() << endl;
	cout << "Result: " << f.FormulaCalculator() << endl;
}