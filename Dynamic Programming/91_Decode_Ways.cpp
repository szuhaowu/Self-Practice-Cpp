//A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
//Example 1:
//
//Input: "12"
//Output: 2
//Explanation: It could be decoded as "AB" (1 2) or "L" (12).
//Example 2:
//
//Input: "226"
//Output: 3
//Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).


//dp[-1] = 1
//dp[i] = 
//1. ans = 0   if s[i], s[i-1]s[i] is invalid
//2. dp[i-1]+dp[i-2]   if s[i], s[i-1]s[i] is valid
//3. dp[i-1]   if s[i] is valid
//4. dp[i-2]   if s[i-1]s[i] is valid

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        //because we need to initialize dp[-1] = 1, we set the dp size as s.size()+1
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); i++) {
            if (isValid(s[i - 1])) dp[i] += dp[i - 1];
            if (i > 1 && isValid(s[i - 2], s[i - 1])) dp[i] += dp[i - 2];
        }
        return dp.back();
    }
private:
    bool isValid(char c) { return c != '0'; }
    bool isValid(char c1, char c2) {
        int num = (c1 - '0') * 10 + (c2 - '0');
        return num >= 10 && num <= 26;
    }
};