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
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp=new ListNode(-1,nullptr);
        ListNode* right=list1;
        ListNode* left=list2;

        ListNode* mover=temp;
        while(right!=nullptr && left!=nullptr){
            if(right->val<=left->val){
                mover->next=right;
                mover=right;
                right=right->next;
            }
            else{
                mover->next=left;
                mover=left;
                left=left->next;
            }
        }

        while(right!=nullptr){
            mover->next=right;
            mover=right;
            right=right->next;
        }

        while(left!=nullptr){
            mover->next=left;
            mover=left;
            left=left->next;
        }

        return temp->next;
    }
};