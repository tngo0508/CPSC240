#include <iostream>
#include <iomanip>

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
	float a, b, c, h, n = 2.0;
	cin >> a >> b >> c >> h;
	cout << "Enter the length and the width of the rectangle: ";
	float len, wid;
	cin >> len >> wid;

	//compute area and perimeter
	float areaT, periT, areaR, periR;

	_asm
	{
		fld		a;			//st = a
		fld		b;			//st = b, st[1] = a
		fadd;				//st = st[1] + st = a + b
		fld		c;			//st = c, st[1] = a + b
		fadd;				//st = st[1] + st = a + b + c
		fstp	periT;		//periT = st = a + b + c

		fld		c;			//st = c
		fld		h;			//st = h, st[1] = c
		fmul;				//st = st[1] * st = c * h
		fld		n;			//st = n, st[1] = c * h
		fdiv;				//st = st[1] / st
		fstp	areaT;		//areaT = (c * h)/2

		fld		len;		//st = len
		fld		wid;		//st = wid, st[1] = len
		fadd;				//st = st[1] + st = len + wid
		fld		n;			//st = 2, st[1] = len + wid
		fmul;				//st = st[1] * st = 2 * (len + wid)
		fstp	periR;		//periR = st = 2len + 2wid

		fld		len;
		fld		wid;
		fmul;
		fstp	areaR;
	}

	//output the resutls
	cout << fixed << setprecision(2);
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
