#include <iostream>

using namespace std;

char ans;
int cDeg, fDeg, n = 5, t = 9;

void dipslayContinue();
void enterInput();
void result();

int main()
{
	_asm
	{
	doLoop:
		call	enterInput;
		mov		eax, fDeg;
		sub		eax, 32;
		imul	n;
		idiv	t;
		mov		cDeg, eax;
		call	result;
		call	dipslayContinue;
		cmp		ans, 'y';
		Je		doLoop;
		cmp		ans, 'Y';
		Je		doLoop;
	}
	

	cout << endl;
	system("pause");
	return 0;
}

void dipslayContinue()
{
	cout << "CONTINUE(y/n)? ";
	cin >> ans;
}

void enterInput()
{
	cout << "Enter temperature in Fahrenheit: ";
	cin >> fDeg;
}

void result()
{
	cout << "     " << fDeg << " F is " << cDeg << " C\n";
}