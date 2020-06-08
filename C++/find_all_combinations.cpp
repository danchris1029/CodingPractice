#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int combRecur(int n, int r, int i, int j, string currStr, int index, string M[], string m[]) {
	string newString;
	string prevString = currStr;
	for (j; j < n; j++) {
		newString = prevString + m[j];
		//cin.get();
		if (i < r - 1) 
			index = combRecur(n, r, i + 1, j + 1, newString, index, M, m);
		else {
			M[index] = newString;
			if (j < n - 1)
				index = combRecur(n, r, i, j + 1, prevString, index + 1, M, m);
			else
				index++;
			return index;
			
		}
		
	}
}

int main() {
	//combAny(4, 2);
	
	string m[] = { "1", "2", "3", "4" };
	string M[20];
	string N[20];

	int index = 0;


	combRecur(4, 2, 0, 0, "", 0, M, m);

	combRecur(6, 2, 0, 0, "", 0, N, M);

	for (int i = 0; i < 20; i++)
		cout << N[i] << " " << endl;
}