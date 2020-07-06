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
    ListNode* swapPairs(ListNode* head) {
        ListNode* currNode = head;
        bool first = true;
        
        while(currNode != nullptr && currNode->next != nullptr){
            ListNode* tempNode = currNode;
            currNode = currNode->next;
            tempNode->next = currNode->next;
            currNode->next = tempNode;
            if (first){
                head = currNode;
                first = false;
            }
            currNode = tempNode->next;
            if(currNode != nullptr){
                if(currNode->next != nullptr)
                    tempNode->next = currNode->next;
                else
                    break;
            }
            else
                break;
        }
        return head;
    }
};
