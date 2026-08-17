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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;

        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;

        int c=0;
        while(temp1 || temp2){
            int n1=(temp1)?temp1->val:0;
            int n2=(temp2)?temp2->val:0;

            int digit;

            int sum=n1+n2+c;

            if(sum>=10){
                digit=sum%10;
                c=sum/10;
            }
            else{
                digit=sum%10;
                c=0;
            }

            temp->next=new ListNode(digit);
            temp=temp->next;

            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;

        }

        if(c) temp->next=new ListNode(c);

        ListNode* ans=dummy->next;
        delete dummy;
        return ans;
    }
};