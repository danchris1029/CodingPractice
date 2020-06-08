#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
	int nLStack = atoi(argv[1]);
	int nRStack = atoi(argv[2]);

	int i = 1;
	while (i <= 1000) {

		if (nLStack == nRStack) {
			if (nLStack >= i)
				nLStack -= i;
			else
				break;
		}
		else {
			if (nLStack > nRStack) {
				if (nLStack >= i)
					nLStack -= i;
				else
					break;
			}
			else {
				if (nRStack >= i)
					nRStack -= i;
				else
					break;
			}
		}
		i++;
	}

	cout << i-1 << " " << nLStack << " " << nRStack << endl;
}