/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

ListNode* getMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

public:
    bool isPalindrome(ListNode* head) {
        if (head==NULL){
            return true;
        }

        ListNode* middle = getMiddle(head);

        // reverse linked list after middle
        ListNode* temp = middle->next;
        middle->next = reverse(temp);

        // compare both halves
        ListNode* h1 = head;
        ListNode* h2 = middle->next;

        while(h2!=NULL){
            if(h1->val != h2->val){
                return false;
            }

            h1 = h1->next;
            h2 = h2->next;
        }

        return true;
    }
};