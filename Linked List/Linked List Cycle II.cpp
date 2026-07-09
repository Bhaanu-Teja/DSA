// Brute Force [Hashing]
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> mpp;
        ListNode* temp = head;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }
        return NULL;
    }
};

// Optimal[Tortoise hare method]
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                fast = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        } 
        return NULL;
    }
};
