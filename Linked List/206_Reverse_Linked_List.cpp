//Reverse a singly linked list.
//
//Example:
//
//Input: 1->2->3->4->5->NULL
//Output : 5->4->3->2->1->NULL
//Follow up :
//
//A linked list can be reversed either iteratively or recursively.Could you implement both ?

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
    ListNode* reverseList(ListNode* head) {
        ListNode* new_node = NULL;
        while (head)
        {
            ListNode* next = head->next;
            head->next = new_node;
            new_node = head;
            head = next;
        }
        return new_node;
    }
};