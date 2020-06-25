/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*/

#include <iostream>
#include <algorithm>
#include <cstdlib>

int maxArea(int arr[], int n) {
	int maxArea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int x = std::min(arr[i], arr[j]);
			int y = j - i;
			int area = std::abs(x * y);
			if (area > maxArea)
				maxArea = area;
		}
	}
	return maxArea;
}

int main() {
	int arr[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << maxArea(arr, n) << std::endl;
}