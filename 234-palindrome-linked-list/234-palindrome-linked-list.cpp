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
    ListNode* reverse(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }
        ListNode* _head = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return _head;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head -> next) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* _head = reverse(slow -> next);
        slow -> next = _head;
        slow = slow -> next;
        ListNode* curr = head;
        while (slow) {
            if (slow -> val != curr -> val) {
                return false;
            }
            slow = slow -> next;
            curr = curr -> next;
        }
        return true;
    }
};