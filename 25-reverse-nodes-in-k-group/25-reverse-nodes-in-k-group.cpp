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
        // This step is just to check if there are k nodes available
        // in the linked list or not. If we don't k nodes to reverse, 
        // we simply return the head of that sublist.
        ListNode *temp = head;
        for (int i = 0; i < k; ++i) {
            if (temp == NULL) {
                return head;
            }
            temp = temp -> next;
        }
        // Reverse the first k nodes and then call recursion
        ListNode *prev = NULL;
        ListNode *curr = head;
        for (int i = 0; i < k && curr; ++i) {
            ListNode *next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        if (curr) {
            head -> next = reverseKGroup(curr, k);
        }
        return prev;
    }
};



// Iterative Solution
// https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/183356/Java-O(n)-solution-with-super-detailed-explanation-and-illustration