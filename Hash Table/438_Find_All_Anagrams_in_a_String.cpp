//Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
//
//Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
//
//The order of output does not matter.
//
//Example 1:
//
//Input:
//s: "cbaebabacd" p: "abc"
//
//Output:
//[0, 6]
//
//Explanation:
//The substring with start index = 0 is "cba", which is an anagram of "abc".
//The substring with start index = 6 is "bac", which is an anagram of "abc".
//Example 2:
//
//Input:
//s: "abab" p: "ab"
//
//Output:
//[0, 1, 2]
//
//Explanation:
//The substring with start index = 0 is "ab", which is an anagram of "ab".
//The substring with start index = 1 is "ba", which is an anagram of "ab".
//The substring with start index = 2 is "ab", which is an anagram of "ab".

//建立兩個hash table
//用vector建立hash table 並透過slide window 比較
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, sht(26, 0), pht(26, 0);
        int ns = s.size(), np = p.size();
        for (auto a : p) pht[a - 'a']++;
        for (int i = 0; i < ns; i++) {
            sht[s[i] - 'a']++;
            if (i >= np) sht[s[i - np] - 'a']--;
            if (sht == pht) res.push_back(i - np + 1);
        }
        return res;
    }
};