#include <iostream>

using namespace std;

char gender = 'c';
int age = 0,
	price = 0;

void displayMenu();
void readData();
void displayError();

int main()
{
	_asm
	{
		call	displayMenu;
		call	readData;
		cmp		age, 19;                     //age > 19?
		Jng		else1;                       //jump to else1 if age <= 19
	true1:
		cmp		gender, 'm';                //gender == 'm'?
		Jne		else2;                      //jump to else2 if gender is not 'm'
	true2:
		mov		eax, 100;                   //eax = 100 if gender == 'm'
		Jmp		display;                    //jump to display when price = 100, gender == 'm', age >19
	else2:
		cmp		gender, 'M';                //gender == 'M'?
		Jne		else3;                      //jump to else3 if gender is female
		Je		true2;                      //jump back to else2 if gender is 'M'
	else3:
		mov		eax, 80;                    //eax = 80
		Jmp		display;                    //price = 80, gender is female, age > 19 

	else1:
		cmp		age, 13;                    //age >= 13?
		Jl		else4;                      //jump to else4 if age < 13
	true3:
		cmp		gender, 'm';                //gender == 'm'?
		Jne		else5;                      //jump to else5 if gender is not 'm'
	true4:
		mov		eax, 75;                    //eax = 75
		Jmp		display;                    //price = 75, gender is 'm', 13 <= age <= 19
	else5:
		cmp		gender, 'M';                //gender == 'M'?
		Jne		else6;                      //jump to else6 if gender is female
		Je		true4;                      //jump back to true5 if gender is 'M'
	else6:
		mov		eax, 85;                    //eax =85
		Jmp		display;
	else4:
		call	displayError;
	display:
		mov		price, eax;                 //price = eax
	}

	cout << "   Your membership is $" << price << endl;
	cout << endl;
	system("pause");
	return 0;
}

void displayMenu()
{
	cout << "------------ACE CLUB --------------\n"
		<< "Male\n"
		<< "    Adult(age>19)................$100\n"
		<< "    Teenager(age 13-19)...........$75\n"
		<< "Female\n"
		<< "    Adult(age>19).................$90\n"
		<< "    Teenager(age 13-19)...........$85\n";
}

void readData()
{
	cout << "How old are you? ";
	cin >> age;
	cout << "what is your gender(M/F)? ";
	cin >> gender;
}

void displayError()
{
	cout << "\nSorry! don't have membership for children.\n";
	cout << endl;
	system("pause");
	exit(1);
}