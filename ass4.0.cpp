/*********************************************************************
** Program Filename: Assignment4
** Author: Dachan Yu
** Date: Feb/28/2021
** Description: Enter txt file with a string and modify that string
** Input: .txt file
** Output: A prompted string or a .txt file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

/********************************************************************* 
** Function: Input
** Description:  Asks user what he wants to do with string
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: an integer
*********************************************************************/

int input() {
	char x[1024];

	int y;

	do {

		cout << "what you like to do with your string?" << endl;

		cout << "(1)switch letter  (2)flip string  (3)word count" << endl;

		cin.getline(x, 1023);

		y = atoi(x);

		if (strlen(x) > 1) {

			cout << "error, please try again" << endl;

		}

		else if ((y != 1) && (y != 2) && (y != 3)) {

			cout << "error, please try again" << endl;
		}

		cout << endl;
		
	} while ((y != 1) && (y != 2) && (y != 3));
 
	return y;
}

/********************************************************************* 
** Function: einput
** Description: asks user if he wants to keep modifying the string
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: obtains an integer
*********************************************************************/

int einput() {

	char x[1024];

	int y;

	do {

		cout << "would you like to continue?" << endl;

		cout << "(1)Exit  (2)Continue" << endl;

		cin.getline(x, 1023);

		y = atoi(x);

		if (strlen(x) > 1) {

			cout << "error, please try again" << endl;

		}

		else if ((y != 1) && (y != 2)) {

			cout << "error, please try again" << endl;
		}

	} while ((y != 1) && (y != 2));

	return y;
}

/*********************************************************************  
** Function: text
** Description: reads the .txt file        *note words must have a spacde after in order to count as a word
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: converts .txt file to a c-string
*********************************************************************/

int text(char* input) {

	ifstream f;

	f.open("input.txt", ios::in);

	if (!(f.is_open())) {

		cout << "text has failed to open" << endl;

		cout << endl;

		return 1;
	}

	f.getline(input, 1023);

	f.close();

	return 0;
}

/*********************************************************************
** Function: texto
** Description:  outputs a .txt file for option 3
** Parameters: word chose, # word appearance, # of times function ran
** Pre-Conditions: needs a word, word number, number of times function ran, and option 3 must be chosen
** Post-Conditions: displays results in .txt file and terminal
*********************************************************************/

void texto(char* word, int y, int f) {

	ofstream fout;							

	fout.open("output.txt", ios::app);	

	for (int i = 1; f >= i; i++) {

		fout << word << ": " << y << endl;

	}

	f++;

	fout.close();
}

/*********************************************************************  
** Function: lswap
** Description: asks user a letter to find and a letter to replace in the string and does that accordingly
** Parameters: string  
** Pre-Conditions:  c-string input, chooses option 1
** Post-Conditions:  c-string will be overwritten with the new string
*********************************************************************/

void lswap(char* str) {

	char c[1024], r[1024];

	do {

		cout << "letter search ";

		cin.getline(c, 1023);

		if ((strlen(c) > 1) || (isupper(c[0]))) {

			cout << "error, please try again" << endl;
		}

		cout << endl;

	} while (strlen(c) > 1);

	do{

		cout << "letter replace ";

		cin.getline(r, 1023);

		if (strlen(r) > 1) {

			cout << "error, please try again" << endl;

		}
		cout << endl;

	} while (strlen(r) > 1);

	for (int i = 0; i <= (strlen(str)-1); i++) {

		if (str[i] == toupper(c[0])) {

			str[i] = toupper(r[0]);
		}

		else if (str[i] == c[0]) {

			str[i] = r[0];
		}
	}
}

/*********************************************************************  
** Function: flip
** Description:  reserses the string
** Parameters:   string, new string
** Pre-Conditions: chooses option 2
** Post-Conditions: outputs the string in reverse
*********************************************************************/

void flip(char str[1024], char* cstr) {

	char mstr[1024] = { 0 };

	int x = 0;

	cout << mstr << endl;

	for (int i = strlen(str); i >= 0; i--) {

		mstr[x] = str[i - 1];

		x++;
	}

	strcpy(cstr, mstr);
}

/********************************************************************* 
** Function: strpurg
** Description: removes all unnecessary characters (not alphabet characters) from string
** Parameters:  .txt string, new string
** Pre-Conditions:  chooses option 3
** Post-Conditions: outputs a string that only contains alphebet characters
*********************************************************************/

void strpurg(char* str, char* newstr) {

	char cstr[1024];

	strcpy(cstr, str);

	for (int i = 0; i < strlen(cstr); i++) {

		if (cstr[i] == ' ') {

		}
		else if (!(isalpha(cstr[i]))) {

			for (int y = i; y < strlen(cstr); y++) {

				cstr[y] = cstr[y + 1];
			}

			i = i - 2;
		}

		else if (isupper(cstr[i])) {

			cstr[i] = tolower(cstr[i]);
		}
	}
	strcpy(newstr, cstr);
}

/*********************************************************************  
** Function: search
** Description: searches and counts the number of words in the string
** Parameters:  oldstring, word array
** Pre-Conditions:  chooses option 3
** Post-Conditions:  outputs the number of time a word is used
*********************************************************************/

void search(char* newstr, char* word) {

	int n = 0, y = 0, f = 1;

	for (int i = 0; i <= (strlen(newstr) - 1); i++) {

		if (newstr[i] == word[n]) {

			n = n + 1;

			if ((n == (strlen(word))) && (newstr[i + 1] == ' ')) {

				y = y + 1;

			}
		}

		else {

			n = 0;
		}
	}

	cout << word << ": " << y << endl;

	texto(word, y, f);
}

/*********************************************************************  
** Function: sinput
** Description:  user input words into program
** Parameters: newstring
** Pre-Conditions: choose option 3
** Post-Conditions: creates an array of words in c-string
*********************************************************************/

void sinput(char* newstr) {

	char* word[1024];

	char x[1024], sword[1024];

	int y = 0;

	do {

		cout << "enter # of words to search for " << endl;

		cin.getline(x, 1023);

		if (strlen(x) > 1) {

			cout << "error, please try again" << endl;

		}

		else {

			y = atof(x);

			if (y == 0) {

				cout << "error, please try again" << endl;
			}
		}

	} while (y == 0);

	cout << endl;

	for (int i = 0; i <= y; i++) {

		word[i] = (char*)malloc(1024 * 1024);
	}

	for (int i = 0; i < y; i++) {

		cout << "enter word (case sensitive)" << endl;

		cin.getline(word[i], 1023);

		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < y; i++) {

		strcpy(sword, word[i]);

		search(newstr, sword);
	}

	for (int i = 0; y >= i; i++) {

		delete[] word[i];
	}
}



int main() {
	char str[1024];

	int cinput = 0, y = 0, x;

	char newstr[1024];

	char sstr[1024];

	char* cstr = new char[1024];

	x = text(str);

	if (x == 1) {

		return 0;

	}
	
	do {

		cinput = input();

		if (cinput == 1) {

			lswap(str);

			cout << str << endl;
		}

		else if (cinput == 2) {

			flip(str, cstr);

			cout << cstr << endl;
		}

		else if (cinput == 3) {

			strpurg(str, newstr);

			sinput(newstr);
		}

		cout << endl;

		cinput = einput();

		cout << endl;

	} while (cinput != 1);

	delete[] cstr;

	return 0;
}