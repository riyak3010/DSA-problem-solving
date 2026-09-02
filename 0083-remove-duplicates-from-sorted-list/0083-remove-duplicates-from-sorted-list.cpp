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
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;
    // EMPTY LINKED LIST
    if(curr==NULL){
            return NULL;
        }

    while(curr!=NULL){
        if(curr->next!=NULL && (curr->val == curr->next->val)){
            ListNode* next_next = curr->next->next;
            ListNode* node_to_delete = curr->next;
            delete(node_to_delete);
            curr->next = next_next;

        }

        else{
            curr = curr->next;
        }  
    }
    return head;
}
        
};