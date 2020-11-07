//Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
//
//Example 1:
//Input: "aba"
//Output: True
//Example 2:
//Input: "abca"
//Output: True
//Explanation: You could delete the character 'c'.
//Note:
//The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return isValid(s, left + 1, right) || isValid(s, left, right - 1);
            left++; right--;
        }
        return true;
    }
    bool isValid(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }
};