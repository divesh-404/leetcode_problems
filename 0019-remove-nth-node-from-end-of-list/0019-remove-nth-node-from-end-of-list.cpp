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
        // ListNode* mover=head;
        // int size=0;
        // while(mover!=nullptr){
        //     size++;
        //     mover=mover->next;
        // }
        // if(n==size){
        //    ListNode* temp=head;
        //    head=head->next;
        //    delete temp;
        //    return head;
        // }
        // ListNode* curr=head;
        // ListNode* prev=nullptr;
        // for(int i=0;i<size-n;i++){
        //     prev=curr;
        //     curr=curr->next;
        // }
        // prev->next=curr->next;
        // delete(curr);

        // return head;

        ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        ListNode* first=dummy;
        ListNode* second=dummy;

        while(n>=0){
            n--;
            first=first->next;
        }

        while(first!=nullptr){
            first=first->next;
            second=second->next;
        }

        ListNode* temp=second->next;
        second->next=temp->next;
        delete temp;

        ListNode* ans=dummy->next;
        delete dummy;
        return ans;
    }
};