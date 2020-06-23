#include <iostream>
#include <unordered_map>
#include <string>

/*
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.However, the numeral for four is not IIII.Instead, the number four is written as IV.Because the one is before the five we subtract it making four.The same principle applies to the number nine, which is written as IX.There are six instances where subtraction is used :

I can be placed before V(5) and X(10) to make 4 and 9.
X can be placed before L(50) and C(100) to make 40 and 90.
C can be placed before D(500) and M(1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.Input is guaranteed to be within the range from 1 to 3999.
*/


int romanNumeral(std::string str) {
	static std::unordered_map<std::string, int> const single = { {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000} };
	static std::unordered_map<std::string, int> const multi = { {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900} };
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		std::string currentLetter = str.substr(i, 1);
		std::string nextLetter = "";
		if (i+1 < str.length())
			nextLetter = str.substr(i+1, 1);
		std::string multiLetter = currentLetter + nextLetter;

		if (multi.find(multiLetter) != multi.end()) {
			sum += multi.find(multiLetter)->second;
			i++;
		}
		else
			sum += single.find(currentLetter)->second;
	}
	return sum;
}

int main() {
	std::cout << romanNumeral("MMXXV") << std::endl;
}