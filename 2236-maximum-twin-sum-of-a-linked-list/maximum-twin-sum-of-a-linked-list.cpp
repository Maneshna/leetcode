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
    int pairSum(ListNode* head) {
        vector<int> values;
        //head creation 
        ListNode *curr = head;
        while(curr!=nullptr){
            values.push_back(curr->val);
            curr=curr->next;
        }

        int maxsum =0;
        int n = values.size();
        for(int i =0; i<n/2; i++){
            int twinsum = values[i]+values[n-i-1];
            maxsum = max(maxsum, twinsum);
        }
        return maxsum;
        
    }
};