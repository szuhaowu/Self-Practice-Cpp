//Given a paragraphand a list of banned words, return the most frequent word that is not in the list of banned words.It is guaranteed there is at least one word that isn't banned, and that the answer is unique.
//
//Words in the list of banned words are given in lowercase, and free of punctuation.Words in the paragraph are not case sensitive.The answer is in lowercase.
//
//
//
//Example:
//
//Input:
//paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
//banned = ["hit"]
//Output : "ball"
//Explanation :
//	"hit" occurs 3 times, but it is a banned word.
//	"ball" occurs twice(and no other word does), so it is the most frequent non - banned word in the paragraph.
//	Note that words in the paragraph are not case sensitive,
//	that punctuation is ignored(even if adjacent to words, such as "ball,"),
//	and that "hit" isn't the answer even though it occurs more because it is banned.
//
//
//	Note:
//
//		1 <= paragraph.length <= 1000.
//			0 <= banned.length <= 100.
//			1 <= banned[i].length <= 10.
//			The answer is unique, and written in lowercase(even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
//			paragraph only consists of letters, spaces, or the punctuation symbols !? ',;.
//			There are no hyphens or hyphenated words.
//			Words only consist of letters, never apostrophes or other punctuation symbols.


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());  // use HashSet to record banned words, make us easy to find
        unordered_map<string, int> freq;
        int max_num = 0;
        for (auto& l : paragraph) l = isalpha(l) ? tolower(l) : ' ';  // ****isalpha, tolower, toupper
        istringstream iss(paragraph);  //c++ 用來分割文字的方法,以空白建為分割
        string s, res;
        while (iss >> s) {  // <<為重載輸出,>>為重載輸入 , iss>>s 為c++ istringstream的寫法 記起來!!
            if (!ban.count(s) && ++freq[s] > max_num) {
                max_num = freq[s];
                res = s;
            }
        }
        return res;

    }
};