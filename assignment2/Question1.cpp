#include <iostream>
using namespace std;

int main()
{
	short drinks, sandwiches, total;

	//menu
	cout << "-------------------MENU------------------\n"
		<< "Drinks.............................. $2\n"
		<< "Sandwiches.......................... $4\n"
		<< "    How many drinks? ";
	cin >> drinks;
	cout << "    How many sandwiches: ";
	cin >> sandwiches;

	//compute total bill
	_asm
	{
		mov		ax, drinks;     // ax = drinks
		imul	ax, 2;			// ax:dx = 2 * drinks
		mov		bx, sandwiches;	// bx = sandwiches
		imul	bx, 4;			// bx:dx = 2 * sandwiches
		add		bx, ax;         // bx = (2 * sandwiches) + (2 * drinks)
		mov		total, bx;		// total = bx
	}

	cout << "       Your total bill $ " << total << endl;

	cout << endl;
	system("Pause");
	return 0;
}