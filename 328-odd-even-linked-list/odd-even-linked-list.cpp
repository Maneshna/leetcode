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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){return head;}

        ListNode* odd= head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even !=nullptr && even->next !=nullptr){
            odd->next = even->next;
            odd = odd->next; // jumps to next odd jisse woh connect hua hai just

            even->next = odd->next;
            even = even->next; //jumps to next even jisse woh connect hua hai just
        }
        odd->next = evenHead;
        return head;
        
    }
};