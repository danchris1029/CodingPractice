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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;
        ListNode* current;
        for(int i = 0; i < lists.size(); i++){
            current = lists[i];
            while(current != NULL){
                //printf("%d ", current->val);
                nums.push_back(current->val);
                current = current->next;
            }
        }
        
        if(nums.size() == 0)
            return NULL;
        
        sort(nums.begin(), nums.end());
        
        ListNode* head = new ListNode();
        ListNode* currentSorted = head;
        
        for(int i = 0; i < nums.size(); i++){
            currentSorted->val = nums[i];
            if(i == nums.size()-1)
                break;
            ListNode* next = new ListNode();
            currentSorted->next = next;
            currentSorted = next;
        }
        
        return head;
    }
};