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
        if(!head){
            return NULL;
        }
        ListNode*temp=head;

        int count=0;
        while(temp){
            count++;
         temp=temp->next;
        }
        count=count-n;
         
        if(count==0){
            ListNode* tod=head;
            head=head->next;
            delete tod;
            return head;
        }
        ListNode* prev;
        ListNode* aftr=head;
        while(count>0) {
            prev=aftr;
            aftr=aftr->next;
             count--;
        }
        prev->next=aftr->next;
        aftr->next=NULL;
        delete(aftr);
        return head;

    }
};