#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float a, b, c, root1, root2, temp;
	float two = 2, four = 4, negOne = -1;
	cout << "To see real roots of aX^2 + bX + c = 0, enter the a, b, and c values: ";
	cin >> a >> b >> c;
	_asm
	{
		fld		b;			//st = b
		fld		b;			//st = b, st[1] = b
		fmul;				//st = st[1] * st = b^2
		fld		four;		//st = 4, st[1] = b^2
		fld		a;			//st = a, st[1] = 4, st[2] = b^2
		fmul;				//st = st[1] * st = 4a, st[1] = b^2
		fld		c;			//st = c, st[1] = 4a, st[2] = b^2
		fmul;				//st = st[1] * st = 4ac, st[1] = b^2
		fsub;				//st = st[1] - st = b^2 - 4ac
		fsqrt;				//st = sqrt(st) = sqrt(b^2 -4ac)
		fstp	temp;		//temp = sqrt(b^2 - 4ac)

		fld		negOne;		//st = -1
		fld		b;			//st = b, st[1] = -1
		fmul;				//st = st[1] * st = -b
		fld		temp;		//st = sqrt(b^2 -4ac), st[1] = -b
		fadd;				//st = st[1] + st = -b + sqrt(b^2 -4ac)
		fld		a;			//st = a, st[1] = -b + sqrt(b^2 -4ac)
		fld		two;		//st = 2, st[1] = a, st[2] = -b + sqrt(b^2 -4ac)
		fmul;				//st = st[1] * st = 2a, st[1] = -b + sqrt(b^2 -4ac)
		fdiv;				//st = st[1] / st = -b + sqrt(b^2 -4ac) / 2a
		fstp	root1;		

		fld		negOne;		//st = -1
		fld		b;			//st = b, st[1] = -1
		fmul;				//st = st[1] * st = -b
		fld		temp;		//st = sqrt(b^2 -4ac), st[1] = -b
		fsub;				//st = st[1] - st = -b - sqrt(b^2 -4ac)
		fld		a;			//st = a, st[1] = -b + sqrt(b^2 -4ac)
		fld		two;		//st = 2, st[1] = a, st[2] = -b - sqrt(b^2 -4ac)
		fmul;				//st = st[1] * st = 2a, st[1] = -b - sqrt(b^2 -4ac)
		fdiv;				//st = st[1] / st = -b - sqrt(b^2 -4ac) / 2a
		fstp	root2;
	}
	cout << fixed << setprecision(2);
	cout << "        X1=" << root1;
	cout << "        X2=" << root2;

	cout << endl;
	system("pause");
	return 0;
}