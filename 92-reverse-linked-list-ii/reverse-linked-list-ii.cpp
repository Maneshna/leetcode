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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == nullptr || head->next == nullptr){
            return head;

        }
        ListNode dummy(0);
        dummy.next=head;

        ListNode *before = &dummy;
        for(int i =1; i<left; i++){
            before = before->next;
        }
        //now reverse 
        ListNode *curr = before->next;
        ListNode *prev = nullptr;
        for(int i =0;i<right-left+1; i++){
            ListNode *nextnode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }

        //reconnect

        before->next->next = curr;

        before->next = prev;
        
        return dummy.next;



        
    }
    
};