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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* curr = head;
        int size = 0;
        while(curr != NULL){
            curr = curr->next;
            size++;
        }
        if(size == n){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int pos = size-n;
        curr = head;
        while(curr != NULL){
            pos--;
            if(pos == 0) break;
            curr = curr->next;
        }
        ListNode* delNode = curr->next;
        curr->next = curr->next->next;
        delete delNode;
        return head;
    }
};