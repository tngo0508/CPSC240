#include <iostream>

using namespace std;

int numOfDrink = 0,
	numOfSan = 0,
	sanSize = 0,
	totalDrink = 0,
	total = 0;
char drinkType = 'c';

void displayMenu();
void readData();
void displayTotal();

int main()
{
	_asm
	{
		call	displayMenu;
		call	readData;
		
		cmp		drinkType, 's';				//drinkType == 's'?
		Jne		else1;						//Jump to else1 if drinkType is not 's'
	true1:
		mov		eax, 2;						//eax = 2 if drinkType == 's' || drinkType == 'S'
		Jmp		done1;						//jump to done1
	else1:
		cmp		drinkType, 'S';				//drinkType == 'S'
		Jne		else2;						//jump to else2 if drinkType is not 'S'
		Je		true1;
	else2:
		mov		eax, 1;						//eax = 1 if drinkType is neither 's' nor 'S'
	done1:
		imul	numOfDrink;					//eax = eax * numOfDrink
		mov		totalDrink, eax;			//totalDrink = eax

		cmp		sanSize, 10;				//sanSize == 10?
		Jne		else3;						//jup to else3 if sanSize is not equal 10

		mov		eax, 3;						//ebx = 3 if sanSize = 10
		Jmp		done2;						//jump to done2
	else3:
		mov		eax, 5;						//ebx = 5 if sanSize is not equal 10 (sanSize=12) 
	done2:
		imul	eax, numOfSan;				//ebx = ebx * numOfSan
		add		eax, totalDrink;			//ebx = ebx + eax
		mov		total, eax;					//total = ebx
		call	displayTotal;
	}
 
	cout << endl;
	system("pause");
	return 0;
}

void displayMenu()
{
	//menu
	cout << "-------------7-11 Convenient Store ------------------\n"
		<< "Drinks\n"
		<< " Soda(S)........................................$2\n"
		<< " Water(W).......................................$1\n"
		<< "Sandwiches\n"
		<< " 10 inches......................................$3\n"
		<< " 12 inches......................................$5\n";
}

void readData()
{
	//ask for input
	cout << "How many drinks? ";
	cin >> numOfDrink;

	cout << " what kind of drink(S=Soda, W=Water)? ";
	cin >> drinkType;

	cout << "How many Sandwiches? ";
	cin >> numOfSan;

	cout << " what size of sandwich (10/12 inches)? ";
	cin >> sanSize;
}

void displayTotal()
{
	cout << "Your total bill = " << total << endl;
}
