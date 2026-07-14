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

// Optimal
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            if(fast==NULL || fast->next==NULL){
                ListNode* del = slow->next;
                slow->next = slow->next->next;
                del->next = nullptr;
                return head;
            }
            slow = slow->next;
        }
        return head;
    }
};
