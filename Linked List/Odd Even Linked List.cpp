// Brute
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        vector<int>output;
        ListNode* temp = head;
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        while(temp != NULL){
            output.push_back(temp->val);
            if(temp->next == NULL) break;
            temp= temp->next->next;
        }
        temp = head->next;
        while(temp != NULL){
            output.push_back(temp->val);
            if(temp->next == NULL) break;
            temp= temp->next->next;
        }
        temp = head;
        int i = 0;
        while(temp != NULL){
            temp->val = output[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};

// Optimal
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* even = head->next;
        ListNode* odd = head;
        ListNode* evenHead = even;
        while(even != NULL && even->next != NULL ){
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
