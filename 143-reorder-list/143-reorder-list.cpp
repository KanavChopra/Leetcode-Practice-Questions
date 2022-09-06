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
    ListNode* reverseList(ListNode *head) {
        if (!head || !head -> next) {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (!head || !head -> next || !head -> next -> next) {
            return;
        }
        
        // Step1: Find middle node (in case of even length, find first middle node)
        ListNode *slow = head;
        ListNode *fast = head -> next;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *head1 = head;
        ListNode *head2 = slow -> next;
        slow -> next = NULL;
        
        // Step2: Reverse second half of the list
        head2 = reverseList(head2);
        
        // Step3: Merge both lists alternatively
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *curr = dummy;
        while (head1 || head2) {
            if (head1) {
                curr -> next = head1;
                curr = curr -> next;
                head1 = head1 -> next;
            }
            if (head2) {
                curr -> next = head2;
                curr = curr -> next;
                head2 = head2 -> next;
            }
        }
        head = dummy -> next;
    }
};