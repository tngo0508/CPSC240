#include <iostream>

using namespace std;

int main()
{
	//drawing triangle and rectangle
	cout << "             /|\\            --------------------\n"
		<< "            / | \\           |                  |\n"
		<< "         a /  |  \\ b        |                  | width\n"
		<< "          /  h|   \\         |                  |\n"
		<< "         /    |    \\        |                  |\n"
		<< "        -------------       --------------------\n"
		<< "             c                   length\n";
	//enter input
	cout << "Enter the values of a,b,c and h for the triangle: ";
	int a, b, c, h, n = 2;
	cin >> a >> b >> c >> h;
	cout << "Enter the length and the width of the rectangle: ";
	int len, wid;
	cin >> len >> wid;

	//compute area and perimeter
	int areaT, periT, areaR, periR;

	_asm
	{
		mov		eax, a;			// eax = a
		add		eax, b;			// eax = a + b
		add		eax, c;			// eax = a + b + c
		mov		periT, eax;		// periT = a + b + c

		mov		eax, len;		// eax = len
		add		eax, wid;		// eax = wid
		add		eax, eax;		// eax = 2 * len + 2 * wid
		mov		periR, eax;		// periR = 2 * len + 2 * wid

		mov		eax, h;			// eax = h
		imul	c;				// edx:eax = h * c
		idiv	n;				// eax = (h * c) / 2
		mov		areaT, eax;		// areaT = (h * c) / 2

		mov		eax, len;		// eax = len
		imul	wid;			// eax = len * wid
		mov		areaR, eax;		// areaR = len * wid
	}

	//output the resutls
	cout << "         Triangle\n";
	cout << "                 Area........................" << areaT << endl;
	cout << "                 Perimeter..................." << periT << endl;
	cout << "         Rectangle\n";
	cout << "                 Area........................" << areaR << endl;
	cout << "                 Perimeter..................." << periR << endl;

	cout << endl;
	system("pause");
	return 0;
}
