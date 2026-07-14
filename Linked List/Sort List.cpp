// Brute
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int>arr;
        ListNode* temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(),arr.end());
        temp = head;
        int i = 0;
        while(temp != NULL){
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};

// Optimal
class Solution {
public:
    ListNode* merge(ListNode* leftHead, ListNode* rightHead){
        ListNode dummy(0);
        ListNode* temp = &dummy;
        ListNode* l = leftHead;
        ListNode* r = rightHead;
        while(l != NULL && r != NULL){
            if(l->val <= r->val){
                temp->next = l;
                l = l->next;
            }
            else{
                temp->next = r;
                r = r->next;
            }
            temp = temp->next;
        }
        while(l != NULL){
            temp->next = l;
            l = l->next;
            temp = temp->next;
        }
        while(r != NULL){
            temp->next = r;
            r = r->next;
            temp = temp->next;
        }
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head; 
        ListNode* middle = NULL;
        while(fast != NULL && fast->next != NULL){
            middle = slow;
            slow = slow->next;
            fast = fast->next->next;
        }       
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = NULL;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return merge(leftHead,rightHead);        
    }
};

