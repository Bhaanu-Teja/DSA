class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            if(head == NULL || head->next == NULL) return head;

            ListNode zeroHead(-1);
            ListNode oneHead(-1);
            ListNode twoHead(-1);

            ListNode* temp0 = &zeroHead;
            ListNode* temp1 = &oneHead;
            ListNode* temp2 = &twoHead;

            ListNode* pointer = head;
            while(pointer != NULL){
                if(pointer->data == 0){
                    temp0->next = pointer;
                    temp0 = temp0->next;
                }
                else if(pointer->data == 1){
                    temp1->next = pointer;
                    temp1 = temp1->next;
                }
                else{
                    temp2->next = pointer;
                    temp2 = temp2->next;
                }
                pointer = pointer->next;

                if(oneHead.next != NULL){
                    temp0->next = oneHead.next;
                }
                else{
                    temp0->next = twoHead.next;
                }
                temp1->next = twoHead.next;
                temp2->next = NULL;
            }
            return zeroHead.next;
        }
};
