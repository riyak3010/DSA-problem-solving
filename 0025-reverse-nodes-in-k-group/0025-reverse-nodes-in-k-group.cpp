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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        // Check if there are at least k nodes left
       ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (check == NULL) {
                return head; // Less than k nodes left, keep original order
            }
            check = check->next;
        }

        // base case
        if (head==NULL){
            return NULL;
        }

        // step1 - Reverse first K nodes

        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;

        while(curr!= NULL && count<k){

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // step 2: Recursion will handle the next part

        if(next!=NULL){
            head->next = reverseKGroup(next, k);
        }
        
        // step 3: return head of reversed Linked list
        return prev;
    }
};