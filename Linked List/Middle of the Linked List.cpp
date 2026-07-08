// Approach 1
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

// Approach 2 -> Optimal
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next == NULL) return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while(temp1 != nullptr && temp1->next != nullptr){
            temp1 = temp1->next->next;
            temp2=temp2->next;
        }
        return temp2;
    }
};
