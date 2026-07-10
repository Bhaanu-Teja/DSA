// Brute --> Stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode* temp = head;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            if(temp->val == st.top()){
                st.pop();
                temp= temp->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

// Optimal
class Solution {
public:

    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow= slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second!= NULL){
            if(first->val != second->val){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
