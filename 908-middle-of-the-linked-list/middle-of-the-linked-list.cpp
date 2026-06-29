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
    ListNode* middleNode(ListNode* head) {
        //since the fast pointer is travelling twice as fast as the slow pointer, by the time woh last mei pahuchega slow wala exactly middle mei hoga and then we will return that value to get out answer

        ListNode *slow = head;
        ListNode *fast = head;
        while(fast !=nullptr && fast->next !=nullptr){
            slow = slow->next;
            fast=fast->next->next;
        }
        return slow;
        
    }
};