class Solution {
public:

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *addOne(ListNode *head) {
        head = reverse(head);
        ListNode* temp = head;
        int carry = 1;
        while(temp != NULL){
            temp->val = temp->val + carry;
            if(temp-> val < 10){
                carry = 0;
                break;
            }
            else{
                temp->val = 0;
                carry = 1;
            }
            temp = temp->next;
        }
        if(carry == 1){
            ListNode* newNode = new ListNode(1);
            head = reverse(head);
            newNode->next = head;
            head = newNode;
            return head;
        }
        head = reverse(head);
        return head;
    }
};
