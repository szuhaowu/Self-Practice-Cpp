//Given two words(beginWordand endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//Only one letter can be changed at a time.
//Each transformed word must exist in the word list.
//Note:
//
//Return 0 if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.
//You may assume no duplicates in the word list.
//You may assume beginWordand endWord are non - empty and are not the same.
//Example 1:
//
//Input:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
//
//Output : 5
//
//Explanation : As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//return its length 5.
//Example 2 :
//
//	Input :
//	beginWord = "hit"
//	endWord = "cog"
//	wordList = ["hot", "dot", "dog", "lot", "log"]
//
//	Output : 0
//
//	Explanation : The endWord "cog" is not in wordList, therefore no possible transformation.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //When we need to search element in vector -> transfer vector to unorderset
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        //BFS path length -> unordered map
        unordered_map<string, int> wordCount{ {beginWord,1} };
        //BFS -> queue
        queue<string> q{ {beginWord} };
        int wordSize = beginWord.length();
        while (!q.empty()) {
            string tempWord = q.front(); q.pop();
            for (int i = 0; i < wordSize; i++) {
                string new_tempWord = tempWord;
                for (char k = 'a'; k <= 'z'; k++) {
                    new_tempWord[i] = k;
                    if (wordSet.count(new_tempWord) && new_tempWord == endWord) return wordCount[tempWord] + 1;
                    if (wordSet.count(new_tempWord) && !wordCount.count(new_tempWord)) {
                        q.push(new_tempWord);
                        wordCount[new_tempWord] = wordCount[tempWord] + 1;
                    }
                }
            }
        }
        return 0;
    }
};