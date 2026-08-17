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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* mover=head;
        // if(n==1) return NULL;
        int size=0;
        while(mover!=nullptr){
            size++;
            mover=mover->next;
        }
        if(n==size){
           ListNode* temp=head;
           head=head->next;
           delete temp;
           return head;
        }
        ListNode* curr=head;
        ListNode* prev=nullptr;
        for(int i=0;i<size-n;i++){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete(curr);

        return head;
    }
};