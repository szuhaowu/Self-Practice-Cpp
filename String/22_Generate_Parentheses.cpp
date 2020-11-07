//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//
//[
//    "((()))",
//    "(()())",
//    "(())()",
//    "()(())",
//    "()()()"
//]


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int left = n, right = n;
        string temp = "";
        DFS(left, right, temp, res);
        return res;
    }
private:
    void DFS(int left, int right, string temp, vector<string>& res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(temp);
        else {
            if (left > 0) DFS(left - 1, right, temp + '(', res);
            if (right > 0) DFS(left, right - 1, temp + ')', res);
        }
    }
};