#include <iostream>

using namespace std;

void displayError();
void displayResult();

short x = 0,
	  y = 0,
	  temp = 0;

int main()
{
	cout << "This program solves the system\n"
		<< "     aX + bY = c\n"
		<< "     dX + eY = f\n";
	cout << "Enter the values of a, b, and c: ";
	short a, b, c;
	cin >> a >> b >> c;
	cout << "Enter the values of d, e, and f: ";
	short d, e, f;
	cin >> d >> e >> f;

	_asm
	{
		//check if denominator is 0 or not
		mov		ax, a;				//ax = a
		imul	ax, e;				//dx:ax = a * e
		mov		bx, b;				//bx = b
		imul	bx, d;				//dx:bx = b * d

		sub		ax, bx;				//ax = a * e - b * d

		mov		temp, ax;			//temp = ax
		cmp		ax, 0;				//a*e - b*d == 0?
		Je		true1;              //if ax is equal 0, jump to true1
									//otherwise, continue
		
		//calculation for Y
		mov		bx, a;				//bx = a
		imul	bx, f;				//dx:bx = a * f
		mov		cx, c;				//cx = c
		imul	cx, d;				//dx:cx = c * d

		sub		bx, cx;				//ax = a * f - c * d

		mov		ax, bx;				//reassign ax to do division
		cwd;						//dx:ax = a * f - c * d
		idiv	temp;				//ax = (a*f-c*d)/(a*e-b*d)
									//dx = (a*f-c*d)%(a*e-b*d)
		mov		y, ax;				//y = (a*f-c*d)/(a*e-b*d)

		//calculation for X
		mov		bx, c;				//bx = c
		imul	bx, e;				//dx:bx = e * c
		mov		cx, b;				//cx = b
		imul	cx, f;				//dx:cx = b * f

		sub		bx, cx;				//ax = e * c - b * f

		mov		ax, bx;				//reassign ax to do division
		cwd;						//dx:ax = a * c - b * f
		idiv	temp;				//ax = (e*c-b*f)/(a*e-b*d)
									//dx = (e*c-b*f)%(a*e-b*d)
		mov		x, ax;				//x = (e*c-b*f)/(a*e-b*d)
		Jmp		display;			//jump to display when calculation is finished
	true1:
		call	displayError;
		Jmp		done;
	display:
		call	displayResult;
	done:
	}

	cout << endl;
	system("pause");
	return 0;
}

void displayError()
{
	cerr << "There is no solution.\n";
}

void displayResult()
{
	cout << "     X = " << x << "\t   " << "Y = " << y << endl;
}