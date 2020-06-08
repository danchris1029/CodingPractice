/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <math.h>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int power = 0;
		int l1Num = 0;
		int l2Num = 0;
		ListNode* lCurr = l1;

		while (lCurr != nullptr) {
			l1Num += lCurr->val*pow(10, power);
			power++;
			lCurr = lCurr->next;
		}
		l1Num++;
		lCurr = l2;
		power = 0;
		while (lCurr != nullptr) {
			l2Num += lCurr->val*pow(10, power);
			power++;
			lCurr = lCurr->next;
		}
		power--;
		l2Num++;

		int sum = l1Num + l2Num;
		
		ListNode* currNode;
		ListNode* prevNode = nullptr;
		for (power; power >= 0; power--) {
			currNode = new ListNode();
			int digit = sum / pow(10, power);
			currNode->val = digit;
			currNode->next = prevNode;
			prevNode = currNode;
			sum -= digit * (pow(10, power));

		}

		return currNode;
	}
};

int main() {
	Solution sol;


	int digitArr1[] = { 3, 4, 2 };
	int digitArr2[] = { 4, 6, 5 };

	ListNode* currNode = nullptr;
	ListNode* prevNode = nullptr;
	for (int i = 0; i < sizeof(digitArr2)/sizeof(digitArr2[0]); i++) {
		
		currNode = new ListNode();
		currNode->next = prevNode;
		currNode->val = digitArr1[i];
		prevNode = currNode;
		
		
	}
	ListNode l1;
	l1.next = currNode->next;
	l1.val = currNode->val;

	
	currNode = nullptr;
	prevNode = nullptr;
	for (int i = 0; i < sizeof(digitArr2) / sizeof(digitArr2[0]); i++) {
		currNode = new ListNode();
		currNode->next = prevNode;
		currNode->val = digitArr2[i];
		prevNode = currNode;
	}
	ListNode l2;
	l2.next = currNode->next;
	l2.val = currNode->val;

	currNode = sol.addTwoNumbers(&l1, &l2);

	while (currNode != nullptr) {
		cout << currNode->val;
		currNode = currNode->next;
		if (currNode != nullptr)
			cout << " -> ";
	}
}

