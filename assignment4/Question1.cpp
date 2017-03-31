#include <iostream>
#include <string>

using namespace std;

string starsY, starsN;
char c;
int numOfYes, numOfNo, i, j;

void askForString();
void readChar();
void starYes();
void starNo();

int main()
{
	_asm
	{
		call	askForString; 
		call	readChar;			//read first character
		mov		numOfYes, 0;		//numOfYes = 0
		mov		numOfNo, 0;			//numOfNo = 0
	
	//while loop
	whileloop:
		cmp		c, '\n';			//compare c == '\n'?
		Je		yesLoop;			//jump to yesLoop if they are equal
		cmp		c, 'y';				//compare c == 'y'
		Je		incYes;				//jump to incYes if c == 'y'
		Jne		incNo;				//jump to incNo if c is not equal 'y'
		call	readChar;			//read the next character
		Jmp		whileloop;			//jump back to the whileloop when c is not '\n'

	incYes:
		inc		numOfYes;			//numOfYes++
		call	readChar;			//read the next character
		Jmp		whileloop;			//jump back to the whileloop

	incNo:
		inc		numOfNo;			//numOfNo++
		call	readChar;			//read the next character
		Jmp		whileloop;			//jump back to the whileloop

		mov		i, 0;				//i = 0
		mov		j, 0;				//j = 0

	//for loop to print 'y' vote
	yesLoop:
		mov		eax, numOfYes;		//eax = numOfYes
		cmp		i, eax;				//compare i < numOfYes
		Jge		noLoop;				//jump to noLoop if i is not less than numOfYes
		inc		i;					//i++
		call	starYes;			//increment the stars for each 'y'
		Jmp		yesLoop;			//jump back to yesLoop

	//for loop to print 'n' vote
	noLoop:
		mov		eax, numOfNo;		//eax = numOfNo
		cmp		j, eax;				//compare j < numOfNo
		Jge		done;				//jump to done if j is not less than numOfNo
		inc		j;					//j++
		call	starNo;				//increment the stars for each 'n'
		Jmp		noLoop;				//jump back to noLoop
	done:
	}

	cout << "No. of YES votes = " << numOfYes << " = " << starsY << endl;
	cout << "No. of NO votes = " << numOfNo << " = " << starsN << endl;

	cout << endl;
	system("pause");
	return 0;
}

void askForString()
{
	cout << "Enter a string of votes: ";
}

void readChar()
{
	cin.get(c);
}

void starYes()
{
	starsY += "* ";
}

void starNo()
{
	starsN += "* ";
}