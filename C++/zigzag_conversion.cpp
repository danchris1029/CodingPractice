#include <iostream>
#include <vector>
using namespace std;


/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

string convert(string s, int numRows) {
	vector<vector<string> > arr(s.length(), vector<string>(numRows));

	int x = 0;
	int y = 0;
	bool top = true;

	for (int letterIndex = 0; letterIndex < s.length(); letterIndex++) {
		if (top) {
			arr[x][y] = s[letterIndex];
			if (y != numRows - 1) 
				y++;
			else {
				y--;
				top = false;
				x++;
			}
			
		}
		else {
			arr[x][y] = s[letterIndex];
			if (y == 1) {
				top = true;
				x++;
			}
			y--;
		}
	}

	for (y = 0; y < numRows; y++) {
		for (x = 0; x < arr.size(); x++) {
			if (arr[x][y] != "")
				cout << arr[x][y];
		}

	}

}

int main() {

	convert("PAYPALISHIRING", 4);
}