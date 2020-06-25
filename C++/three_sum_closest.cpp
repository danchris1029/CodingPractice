#include <iostream>
#include <cstdlib>

/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

void threeSumClosest(int arr[], int n, int target) {
	int sumDifference = 0;
	int closestTripleSum[] = { 0, 0, 0 };
	// Set initial closest number
	int closest = 10000;
	
	for(int first = 0; first < n; first++){
		for (int second = first + 1; second < n; second++) {
			for (int third = second + 1; third < n; third++) {
				// get difference between sum and target
				sumDifference = (arr[first] + arr[second] + arr[third])-target;
				// is the absolute difference less than the current absolute closest difference to the target
				if (abs(sumDifference) < abs(closest)) {
					closest = sumDifference;
					closestTripleSum[0] = arr[first];
					closestTripleSum[1] = arr[second];
					closestTripleSum[2] = arr[third];
				}
			}
		}
	}

	int sum = closestTripleSum[0] + closestTripleSum[1] + closestTripleSum[2];
	// information goes out to console
	std::cout << "The sum that is closest to the target is " << sum << ". ("
		<< closestTripleSum[0] << " + " << closestTripleSum[1] << " + " << closestTripleSum[2] << " = " << sum << ")." << std::endl;
}

int main() {
	int arr[] = { -1, 2, 1, -4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 1;
	threeSumClosest(arr, n, target);
}