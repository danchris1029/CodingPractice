class Solution {
public:
    struct ListNode {
        string str;
        ListNode *next;
        ListNode() : str(""), next(nullptr) {}
    };
    
    void generate (string A, int n, ListNode* currNode){
        string ans = "";
        if (A.length() == 2*n){
            if (valid(A)){
                while(currNode->next != nullptr)
                    currNode = currNode->next;
                currNode->str = A;
                ListNode *prevNode = currNode;
                currNode = new ListNode();
                prevNode->next = currNode;
            }
        }
        else{
            A.append("(");
            generate(A, n, currNode);
            A.pop_back();
            A.append(")");
            generate(A, n, currNode);
            A.pop_back();
        }
    }
    
    int valid(string A){
        int balance = 0;
        for( int i = 0; i < A.length(); i++){
            if (A[i] == '(')
                balance++;
            else
                balance--;
            if (balance < 0)
                return false;
        }
        return (balance == 0);
    }
    
    vector<string> generateParenthesis(int n) {
        ListNode* head = new ListNode();
        generate("", n, head);
        ListNode* currNode = head;
        
        vector<string> strReturn;
        while(currNode->next != nullptr){
            strReturn.push_back(currNode->str);
            currNode = currNode->next;
        }
        return strReturn;
    }
};
