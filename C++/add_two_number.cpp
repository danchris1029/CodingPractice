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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int prevSum = 0;
        int power = 0;
        int carry = 0;
        int currDigit = 0;                  
        ListNode* l1Curr = l1;
        ListNode* l2Curr = l2;
        ListNode* finalNode;
        ListNode* tempNode;
        ListNode* head;
        bool first = true;
        
        while (l1Curr != nullptr || l2Curr != nullptr){
            int xTerm = 0,
                yTerm = 0;
            if(l1Curr != nullptr){
                xTerm = l1Curr->val;
                l1Curr = l1Curr->next;
            }
            if(l2Curr != nullptr){
                yTerm = l2Curr->val;
                l2Curr = l2Curr->next;
            }
            
            sum = (xTerm + yTerm) + carry;      // (x + y) + carry is equal to the sum
            carry = (sum/10);                   // if (sum/10) is more than or equal to 1, that is assigned to carry
            currDigit = sum%10;                 // remove digit over 10
            
            if(first){
                finalNode = new ListNode(currDigit, nullptr);       // create head for first time, and insert currDigit
                head = finalNode;
                first = false;
            }
            else{
                tempNode = new ListNode(currDigit, nullptr);        // insert currDigit into in the val of new node.
                finalNode->next = tempNode;
                finalNode = tempNode;
            }
            power++;
        }
        if(carry){
            tempNode = new ListNode(carry, nullptr);            // If carry, then insert carry in the val of new node.
            finalNode->next = tempNode;
            finalNode = tempNode;
        }
        return head;
    }
};
