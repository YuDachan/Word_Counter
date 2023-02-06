#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;


int main() {
	int x = 0;
	char cinput[1023];
	char input[1023];
	ifstream f;
	f.open("input.txt", ios::in);			// open input.txt

	if (!(f.is_open())) {					//if file doesn't open:
		cout << "txt failed" << endl;
		cout << endl;
	}

	f.getline(cinput, 1023);

	cout << cinput << endl;

	ofstream fout;							//set file to write
	fout.open("output.txt", ios::out);		//open write file
	
	cin.getline(input, 1023);			
	fout << input << endl;					//write input into fout

	f.close();								//close both files
	fout.close();

	return 0;
}