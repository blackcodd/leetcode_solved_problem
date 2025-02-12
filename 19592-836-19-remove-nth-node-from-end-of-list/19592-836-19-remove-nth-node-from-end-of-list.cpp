class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode * prev=nullptr;
        ListNode * curr=nullptr;

       ListNode*temp=head;
       ListNode*nex=head;
       int cnt=0;
       while(temp){
        cnt++;
        prev=curr;
        curr=temp;
        temp=temp->next;
       }
       if(cnt==1){
           if(n==1){
               return nullptr;
           }
       }
       if(n==1){
        prev->next=nullptr;
        delete(curr);
        return head;
       }
       int c=0;
       temp=head;
       prev=nullptr;
       curr=nullptr;
       if(cnt-n+1==1){
           head=head->next;
           return head;
       }

       while(temp)
       {
        c++;
        prev=curr;
        curr=temp;
        temp=temp->next;
        if(c==cnt-n+1){
            prev->next=curr->next;
            delete(curr);
            break;

        }
       }
       return head;

    
    }

 };
