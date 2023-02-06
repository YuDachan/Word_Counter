#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void srtpurg(char* str, char* newstr) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
		}
		else if (!(isalpha(str[i]))) {
			for (int y = i; y < strlen(str); y++) {
				str[y] = str[y + 1];
			}
			i = i - 2;
		}
		else if (isupper(str[i])) {
			str[i] = tolower(str[i]);
		}
	}
	strcpy(newstr, str);
}

void search(char* newstr, char* word) {
	int n = 0, y = 0;
	for (int i = 0; i <= (strlen(newstr)-1); i++) {
		if (newstr[i] == word[n]) {
			n = n + 1;
			if ((n == (strlen(word))) && (newstr[i+1] == ' ')) {
				y = y + 1;
			}
		}
		else {
			n = 0;
		}
	}
	cout << word << ": " << y << endl;
}

int main() {
	int x, i;
	char str[1024];
	char newstr[1024];
	char sword[1024];
	char* word[1024];

	cout << "enter string" << endl;
	if (!(cin.getline(str, 1024))) {
		cout << "poor input" << endl;
		cin.ignore(1024, '\n');
		cin.clear();
	}

	srtpurg(str, newstr);

	cout << endl;
	cout << "enter # of words to search for" << endl;
	cin >> x;
	cout << endl;

	for (int i = 0; i <= x; i++) {
		word[i] = (char*)malloc(1024 * 1024);
	}

	cout << "enter word" << endl;
	for (int i = 0; i <= x; i++) {
		cin.getline(word[i], 1024);
	}
	cout << endl;

	for (int i = 0; i <= x; i++) {
		strcpy(sword, word[i]);
		search(newstr, sword);
	}

	cout << newstr << endl;
	for (int i = 0; x >= i; i++) {
		delete[] word[i];
	}

	return 0;
}