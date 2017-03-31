#include <iostream>

using namespace std;

int main()
{
	//enter the input
	cout << "Enter a 3 digit int number: ";
	int n, t = 100, s = 10, first, second, sum;
	cin >> n;

	//compute total of digits in number n
	_asm
	{
		mov		eax, n;			//eax = n
		cdq;					//edx:eax = n
		idiv	t;				//eax = n / t, edx = n % t
								//eax = first digit, edx = next two digits
		mov		first, eax;		// first = eax = first digit
		mov		eax, edx;		// eax = edx
		cdq;					//edx:eax = next two digits
		idiv	s;				//eax = second digit, edx = third digit
		mov		second, eax;	//second = eax = second digit
		add		edx, second;	//edx = third + second 
		add		edx, first;		//edx = third + second + first
		mov		sum, edx;		//sum = edx
	}

	cout << "  The total of digits in " << n << " is " << sum << endl;

	cout << endl;
	system("pause");
	return 0;
}