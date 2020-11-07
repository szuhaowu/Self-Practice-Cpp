//Given an array of strings, group anagrams together.
//
//Example:
//
//Input: ["eat", "tea", "tan", "ate", "nat", "bat"] ,
//Output :
//    [
//        ["ate", "eat", "tea"],
//        ["nat", "tan"],
//        ["bat"]
//    ]
//Note :
//
//    All inputs will be in lowercase.
//    The order of your output does not matter.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for (string str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            if (!map.count(s)) map[s] = { str };
            else map[s].push_back(str);
        }
        for (auto a : map) res.push_back(a.second);
        return res;
    }
};