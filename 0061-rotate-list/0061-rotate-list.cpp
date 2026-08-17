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
        if(!head || !head->next || k==0) return head;
        int size=0;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        
        int n=k%size;
        if(n==0) return head;
        ListNode* first=head;
        ListNode* second=head;
        
        while(n>0){
            n--;
            first=first->next;
        }

        while(first->next){
            first=first->next;
            second=second->next;
        }

        ListNode* newHead=second->next;
        second->next=nullptr;

        first->next=head;

        return newHead;

    }
};