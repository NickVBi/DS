#include "pch.h"
#include "Formula.h"
#include "string.h"
#include "Stack.h"

TFormula::TFormula(char form[])
{
	for (int i = 0; strlen(form); i++) 
		Formula[i] = form[i];
}

int TFormula::FormulaChecker(int Brackets[], int size)
{
	return 0;
}

int TFormula::FormulaConverter(void)
{
	TStack s;
	int p = 0;
	for (int i = 0; i < strlen(Formula); i++)
	{
		if (Formula[i] == '(') s.Put(Formula[i]);
		else if ((Formula[i] == '+') || (Formula[i] == '-') || (Formula[i] == '/') || (Formula[i] == '*'))
		{
			while (!s.IsEmpty())
			{
				p++;
				PostfixForm[p] = s.Get();
			}
			s.Put(Formula[i]);
		}
		else if (Formula[i] == ')')
		{
			while ((!s.IsEmpty()) && (s.Get() != '('))
			{
				p++;
				PostfixForm[p] = s.Get();
			}
			s.Get();
		}
		else
		{
			p++;
			PostfixForm[p] = Formula[i];
		}
	}
	while (!s.IsEmpty())
	{
		p++;
		PostfixForm[p] = s.Get();
	}
}

int Eval(int left, char oper, int right)
{
	int a = left;
	int b = right;
	switch (oper)
	{
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '+':
		return a + b;
	case '-':
		return a - b;
	default:
		return 0;
	}

}

double TFormula::FormulaCalculator(void)
{
	TStack s;

	for (int i = 0; i < strlen(PostfixForm); i++)
	{
		char cur = PostfixForm[i];


		if (cur == '+' || cur == '-' || cur == '*' || cur == '/')
		{
			int right = s.Get();
			int left = s.Get();
			int res = Eval(left, cur, right);
			s.Put(res);
		}
		else {
			s.Put(cur);
		}
	}
	return  s.Get();
}
