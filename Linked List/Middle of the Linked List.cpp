class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next == NULL) return head;
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp=temp->next;
        }
        int ans = ((cnt/2)+1);
        temp = head;
        cnt = 0;
        while(temp!=NULL){
            cnt++;
            if(cnt == ans){
                head = temp;
                return head;
            }
            temp=temp->next;
        }
        return head;
    }
};
