class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        if(t2->next == nullptr){
            t2->next = t1;
            t1->next = nullptr;
            return t2;
        }
        ListNode* t3 = t2->next;
        t1->next = nullptr;
        while(t3 != nullptr){
            t2->next = t1;
            t1 = t2;
            t2 = t3;
            t3 = t3->next;
        }
        t2->next = t1;
        return t2;
    }
};
