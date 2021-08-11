// Given the head of a linked list, rotate the list to the right by k places.

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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> list;
        ListNode* curr = head;
        
        if(curr == nullptr){
            return nullptr;
        }
        
        while(curr != nullptr){
            list.push_back(curr->val);
            curr = curr->next;
        }
        
        int pos = k%list.size();
        
        vector<int> resList(list.size());
        for(int i = 0; i < list.size(); i++){
            resList[pos] = list[i];
            pos++;
            if(pos == list.size())
                pos = 0;
        }
        
        ListNode* newHead = new ListNode();
        curr = newHead;
        for(int i = 0; i < resList.size()-1; i++){
            curr->val = resList[i];
            curr->next = new ListNode();
            curr = curr->next;
        }
        curr->val = resList[resList.size()-1];
        
        return newHead;
    }
};
