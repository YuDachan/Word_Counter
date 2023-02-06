#include <iostream>
#include <cstring>


using namespace std;

void flip(char str[1023], char *cstr) {
	char mstr[1023] = { 0 };
	int x = 0;
	cout << mstr << endl;
	for (int i = strlen(str); i >= 0; i--) {
		mstr[x] = str[i-1];
		x++;
	}
	strcpy(cstr, mstr);
}

int main() {
	
	char str[1023];
	char* cstr = new char[1023];
	
	cin.getline(str, 1023);

	flip(str, cstr);

	cout << endl;
	cout << str << endl;
	cout << cstr << endl;

	delete[] cstr;
	return 0;
}