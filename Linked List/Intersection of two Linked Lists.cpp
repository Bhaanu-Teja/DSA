// Brute
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> mpp;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1 != NULL){
            mpp[temp1] = 1;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            if(mpp.count(temp2)){
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
};

// Better
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int count1 = 0;
        int count2 = 0;
        while(temp1 != NULL){
            temp1 = temp1->next;
            count1++;
        }
        while(temp2 != NULL){
            temp2 = temp2->next;
            count2++;
        }
        int diff = abs(count1 - count2);
        temp1 = headA;
        temp2 = headB;
        if(count1 > count2){
            while(diff > 0 && temp1 != NULL){
                temp1 = temp1->next;
                diff--;
            }
        }
        else{
            while(diff > 0 && temp2 != NULL){
                temp2 = temp2->next;
                diff--;
            }
        }
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }       
        return NULL;
    }
};

// Optimal
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
       
       while(a != b){
            if(a==NULL){
                a = headB;
            }
            else{
                a = a->next;
            }
            if(b== NULL){
                b = headA;
            }
            else{
                b = b->next;
            }
       }
       return a;
    }
};
