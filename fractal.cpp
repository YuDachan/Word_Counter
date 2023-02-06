/*********************************************************************
** Program Filename: Fractal
** Author: Dachan Yu
** Date: Feb/28/2021
** Description: Creates a fractal based on the number of stars and offset by the columns
** Input: # of stars and # of columns shifted
** Output: Picture of fractal
*********************************************************************/
#include <iostream>

using namespace std;
/*********************************************************************
** Function: Creates and prints the fractal pattern given the inputs
** Description: Creates and prints the fractal pattern given the inputs
** Parameters: # of stars, # of columns
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void pattern(int n, int col) {
	if (n > 0) {
		pattern( n - 2, col+2);

		for (int i = 0; i < col; i++)
			cout << " ";
		for (int i = 0; i < n; i++)
			cout << "* ";
		cout << endl;

		pattern(n - 2, col+2);
	}
}

int main() {
	int x, y;
	cout << "enter number of stars: ";
	cin >> x;
	cout << "enter column offset: ";
	cin >> y;

	pattern(x, y);

	return 0;
}