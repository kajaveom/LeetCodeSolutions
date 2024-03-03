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
    
    ListNode* deleteNode(ListNode* head, int pos){
        
        int cnt = 1,len = 0;
        ListNode* tmp = head;
        while(tmp!=NULL)
        {
            len++;
            tmp = tmp->next;
        }
        
        len = len - pos + 1;
        tmp = head;
        
        cout<<len<<endl;
        
        if(len == 1){
            head = head->next;
            return head;
        }
        
        while(tmp!=NULL){
            if(cnt+1==len){
               tmp->next = (tmp->next)->next;
                break;
            }
            tmp = tmp->next;
            cnt++;
        }
        
        return head;
        
    }
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        return deleteNode(head,n);
    }
};