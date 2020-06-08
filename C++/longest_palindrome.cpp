#include <iostream>
#include <string>
using namespace std;

struct ListNode{
	string word;
	ListNode *next;
	ListNode() : word(""), next(nullptr) {}
};

bool checkIfPalindromic(string tempStr) {
	bool palindromic = false;
	string reverseStr = "";
	for (int letterIndex = tempStr.length() - 1; letterIndex >= 0; letterIndex--) {
		reverseStr += tempStr[letterIndex];
	}
	if (tempStr == reverseStr)
		return true;
	else
		return false;
}

string longestPalindrome(string s) {
	ListNode* currNode = nullptr;
	ListNode* prevNode = nullptr;
	string tempStr = "";
	bool palindromic = false;
	for (int firstLetter = 0; firstLetter < s.length(); firstLetter++) {
		for (int letterIndex = firstLetter; letterIndex < s.length(); letterIndex++) {
			tempStr += s[letterIndex];
			palindromic = checkIfPalindromic(tempStr);
			if (palindromic) {
				currNode = new ListNode();
				currNode->next = prevNode;
				currNode->word = tempStr;
				prevNode = currNode;
				
			}
		}
		tempStr = "";
	}
	string longest = "";
	while (currNode != nullptr) {
		if (currNode->word.length() > longest.length())
			longest = currNode->word;
		currNode = currNode->next;
	}
	return longest;
}

int main() {
	cout << longestPalindrome("racecar") << endl;
	return 0;
}