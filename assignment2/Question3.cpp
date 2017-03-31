#include <iostream>

using namespace std;

int main()
{
	//ask for the input
	cout << "enter temperature in Fahrenheit: ";
	short cDeg, fDeg, n = 5, t = 9;
	cin >> fDeg;

	//temperature conversion
	_asm
	{
		mov		ax, fDeg;   //ax = fDeg
		sub		ax, 32;     //ax = fDeg - 32
		imul	n;          //dx:ax = 5 * (fDeg - 32)
		idiv	t;			// ax = 5 * (fDeg -32) / 9
		mov		cDeg, ax;   //cDeg = ax
	}

	cout << fDeg << " F\370 is " << cDeg << " C\370";
	cout << endl;
	system("pause");
	return 0;
}