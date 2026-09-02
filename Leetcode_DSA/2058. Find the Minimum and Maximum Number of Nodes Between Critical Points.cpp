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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> index ;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int itr = 0;
        while(curr->next !=NULL){
            if((curr->val > curr->next->val && curr->val > prev->val) ||
            (curr->val < curr->next->val && curr->val < prev->val )){
                index.push_back(itr);
            }
            prev = prev->next;
            curr = curr->next;
            itr++;
        }

        int mini = INT_MAX;
        for(int i=1;i<index.size();i++){
            mini = min(mini,abs(index[i-1]-index[i]));
        }

        vector<int> res = {-1,-1};
        res[1] = index.size()>1 ? (index[index.size()-1]-index[0]) : -1;
        res[0] = mini==INT_MAX ? -1 : mini;
        return res;
    }
};