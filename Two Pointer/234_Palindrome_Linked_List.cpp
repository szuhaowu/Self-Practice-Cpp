// Given a singly linked list, determine if it is a palindrome.

// Example 1:

// Input: 1->2
// Output: false
// Example 2:

// Input: 1->2->2->1
// Output: true
// Follow up:
// Could you do it in O(n) time and O(1) space?



// 參考https://mp.weixin.qq.com/s/A-dQ9spsP_Iu1Y4iCRP9nA

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

//O(n) time complexity and O(1) space complexity
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* fast = head, *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next; //當長度為奇數時，fast不會指到NULL，偶數會，長度為奇數時需從mid point的後一個開始reverse
        
        ListNode* left = head;
        ListNode* right = reverse(slow,nullptr);
        while(right){
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* start, ListNode* end){
        ListNode* pre = nullptr, *cur = start, *next = start;
        while(cur != end){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
