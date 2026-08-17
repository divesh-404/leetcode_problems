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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* mid=slow;

        ListNode* last=nullptr;
        ListNode* curr=mid->next;
        while(curr){
            ListNode* next=curr->next;
            curr->next=last;
            last=curr;
            curr=next;
        }

        ListNode* s1=head;
        ListNode* s2=last;

        while(s2){
            if(s1->val!=s2->val) return false;
            s1=s1->next;
            s2=s2->next;
        }

        return true;
    }
};