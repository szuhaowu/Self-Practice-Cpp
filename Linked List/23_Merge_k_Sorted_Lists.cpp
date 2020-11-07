//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//
//Merge all the linked-lists into one sorted linked-list and return it.
//
// 
//
//Example 1:
//
//Input: lists = [[1,4,5],[1,3,4],[2,6]]
//Output: [1,1,2,3,4,4,5,6]
//Explanation: The linked-lists are:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//merging them into one sorted list:
//1->1->2->3->4->4->5->6
//Example 2:
//
//Input: lists = []
//Output: []
//Example 3:
//
//Input: lists = [[]]
//Output: []

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

//****use priority_queue to reduce the sorted time form nlogn to nlogk 
class Solution {
    // *** see the priority define method
    class Comp {
    public:
        bool operator()(ListNode* n1, ListNode* n2) {
            return n1->val > n2->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode;
        ListNode* point = ans;

        priority_queue<ListNode*, vector<ListNode*>, Comp> pq;
        for (auto node : lists) {
            if (node) pq.push(node);
        }
        while (!pq.empty()) {
            auto temp_node = pq.top(); pq.pop();
            point->next = temp_node;
            point = point->next;
            if (point->next) pq.push(point->next);
        }
        return ans->next;
    }
};