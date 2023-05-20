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
    
    int getLen(ListNode* head){
        int cnt = 0;
        ListNode* tmp = head;
        while(tmp!=NULL){
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL)
            return head;
        
        int n = getLen(head);
        k = k%n;
        if(k==0)
            return head;
        
        int cnt = 0;
        ListNode* tmp = head;
        while(cnt < n-k-1){
            tmp = tmp->next;
            cnt++;
        }
        ListNode* tmp2 = tmp->next;
        ListNode* newhead = tmp->next;

        tmp->next = NULL;
        while(tmp2->next!=NULL){
            tmp2 = tmp2->next;
        }
        tmp2->next = head;
        
        
        return newhead;
        
        
        
        
        
        
    }
};