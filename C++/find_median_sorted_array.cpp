#include<iostream>
#include<algorithm>
using namespace std;

double findMedianSortedArray( int xArr[], int yArr[], int sizeX, int sizeY){

	int start = 0;
	int end = sizeX;
	int positionX;
	int positionY;
	int maxLeftX;
	int minRightX;
	int maxLeftY;
	int minRightY;
	while (true) {
		positionX = (start + end) / 2;
		positionY = (sizeX + sizeY + 1) / 2 - positionX;

		if (positionX != 0)
			maxLeftX = xArr[positionX - 1];
		else
			maxLeftX = -1;

		minRightX = xArr[positionX];
		maxLeftY = yArr[positionY - 1];
		minRightY = yArr[positionY];

		if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
			if ((sizeX + sizeY) % 2 != 0)
				return max(maxLeftX, maxLeftY);
			else
				return ((double)(max(maxLeftX, maxLeftY) + (double)min(minRightX, minRightY)) / 2);
		}
		else if(maxLeftX > minRightY) 
			end = positionX - 1;
		else
			start = positionX + 1;
	}
	
}


int main() {
	int xArr[] = {23, 26, 31, 35};
	int yArr[] = { 3, 5, 7, 9, 11, 16};

	cout << findMedianSortedArray(xArr, yArr, sizeof(xArr)/ sizeof(xArr[0]), sizeof(yArr) / sizeof(yArr[0]));

}
