class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* temp = head;
        int cnt = 0;
        while(temp!= NULL){
            cnt++;
            temp= temp->next;
        }
        int mid = cnt/2;
        temp = head;
        int nowCnt = 0;
        while(nowCnt < mid-1){
            temp=temp->next;
            nowCnt++;
        }
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        del->next = nullptr;
        return head;
    }
};
