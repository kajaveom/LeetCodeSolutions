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

class Compare{
    public:
    
    bool operator()(ListNode* l1, ListNode* l2){
        
        if(l1->val > l2->val)
            return true;
        return false;
    }
};

class Solution {
public:
    
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0)
            return NULL;
        
        priority_queue<ListNode* , vector<ListNode*>, Compare> pq;
        
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]!=NULL)
            pq.push(lists[i]);
        }
        
        ListNode* tmp = NULL;
        ListNode* res = NULL;
        
        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            
            if(top->next!=NULL)
                pq.push(top->next);
            
            if(tmp==NULL){
                tmp = top;
                res = top;
            }
            else{
                tmp->next = top;
                tmp = tmp->next;
            }
        }
        
        return res;
        
        
        
        
        
        
    }
};