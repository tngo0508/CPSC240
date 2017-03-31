#include <iostream>
#include <string>

using namespace std;

char c;
string sentence;

void askForSentence();
void readChar();
void result();

int main()
{
	_asm
	{
		call	askForSentence;
		call	readChar;
	
	whileLoop:
		cmp		c, '\n';
		Je		done;
		cmp		c, 'a';
		Je		changeUpper;
		cmp		c, 'e';
		Je		changeUpper;
		cmp		c, 'i';
		Je		changeUpper;
		cmp		c, 'o';
		Je		changeUpper;
		cmp		c, 'u';
		Je		changeUpper;
		cmp		c, 'y';
		Je		changeUpper;

		call	result;
		call	readChar;
		Jmp		whileLoop;

	changeUpper:
		sub		c, 32;
		call	result;
		call	readChar;
		Jmp		whileLoop;
	done:
	}

	cout << " Output: " << sentence << endl;

	cout << endl;
	system("pause");
	return 0;
}

void askForSentence()
{
	cout << "Enter a sentence: ";
}

void readChar()
{
	cin.get(c);
}

void result()
{
	sentence += c;
}