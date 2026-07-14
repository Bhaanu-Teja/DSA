class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        int reqCnt = cnt - n;
        if(reqCnt == 0){
            ListNode* del = head;
            head = head->next;
            del->next = NULL;
            delete del;
            return head;
        }

        temp = head;
        int nowCnt = 0;
        while(temp != NULL){
            nowCnt++;
            if(nowCnt == reqCnt){
                ListNode* del = temp->next;
                temp->next = temp->next->next;
                del->next = NULL;
                delete del;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};
