// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Example 3:

// Input: haystack = "", needle = ""
// Output: 0

//Implement KMP to solve this problem
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.empty()) return -1;
        int n = haystack.size(), m = needle.size();
        vector<vector<int>> dp_kmp = KMP(needle);
        int j=0; //初始目前狀態
        for(int i=0; i<n; i++){
            j = dp_kmp[j][haystack[i]-'a'];
            if(j == m) return i-m+1;
        }
        return -1;
    }
    
    vector<vector<int>> KMP(string& pat){
        int m = pat.size();
        vector<vector<int>> dp(m,vector<int>(256,0)); //dp[狀態][遇到的字符] = 下個狀態
        dp[0][pat[0]-'a'] = 1;
        int X = 0; //影子狀態初始為0
        for(int i=1; i<m; i++){
            for(int c=0; c<256; c++) dp[i][c] = dp[X][c];
            dp[i][pat[i]-'a'] = i+1;
            X = dp[X][pat[i]-'a'];
        }
        return dp;
    }
};