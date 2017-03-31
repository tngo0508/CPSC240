#include <iostream>

using namespace std;

int sanSize = 0;

float numOfDrink = 0.0,
numOfSan = 0.0,
totalDrink = 0.0,
total = 0.0;

double soda = 2.25,
water = 1.75,
ten = 3.45,
twelve = 5.25;

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

		cmp		drinkType, 's';         //drinkType == 's'?
		Jne		else1;					//Jump to else1 if drinkType is not 's'
	true1:
		fld		soda;					//st = 2.25 if drinkType is soda
		Jmp		done1;					//jump to done1
	else1:
		cmp		drinkType, 'S';         //drinkType == 'S'
		Jne		else2;                  //jump to else2 if drinkType is not 'S'
		Je		true1;
	else2:
		fld		water;					//st = 1.75 if drinkType is water
	done1:
		fld		numOfDrink;				//st = numOfDrink, st[1] = 3.25 or 1.75
		fmul;							//st = st[1] * st = (3.25 or 1.75) * numOfDrink
		fstp	totalDrink;				//totalDrink = (3.25 or 1.75) * numOfDrink

		cmp		sanSize, 10;            //sanSize == 10?
		Jne		else3;                  //jump to else3 if sanSize is not equal 10

		fld		ten;					//st = 3.45 if sanSize = 10
		Jmp		done2;                  //jump to done2
	else3:
		fld		twelve;					//st = 5.25 if sanSize is not equal 10 (sanSize=12) 
	done2:
		fld		numOfSan;				//st = numOfSan, st[1] = 3.45 or 5.25
		fmul;							//st = st[1] * st = (3.45 or 5.25) * numOfSan
		fld		totalDrink;				//st = totalDrink, st[1] = totalSandwich
		fadd;							//st = st[1] + st = totalDrink + totalSanwich
		fstp	total;					//total = totalDrink + total Sandwich
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
		<< " Soda(S)........................................$2.25\n"
		<< " Water(W).......................................$1.75\n"
		<< "Sandwiches\n"
		<< " 10 inches......................................$3.45\n"
		<< " 12 inches......................................$5.25\n";
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
