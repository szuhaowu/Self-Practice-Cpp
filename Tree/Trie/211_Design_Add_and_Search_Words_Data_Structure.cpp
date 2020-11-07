//Design a data structure that supports adding new words and finding if a string matches any previously added string.
//
//Implement the WordDictionary class:
//
//WordDictionary() Initializes the object.
//void addWord(word) Adds word to the data structure, it can be matched later.
//bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
// 
//
//Example:
//
//Input
//["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
//[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
//Output
//[null,null,null,null,false,true,true,true]
//
//Explanation
//WordDictionary wordDictionary = new WordDictionary();
//wordDictionary.addWord("bad");
//wordDictionary.addWord("dad");
//wordDictionary.addWord("mad");
//wordDictionary.search("pad"); // return False
//wordDictionary.search("bad"); // return True
//wordDictionary.search(".ad"); // return True
//wordDictionary.search("b.."); // return True


class TrieNode {
public:
    TrieNode* child[26];
    bool isWord;
    TrieNode() :isWord(false) {
        for (auto& a : child) a = nullptr;
    }

};



class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for (auto& a : word) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode;
            p = p->child[i];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    
    // Use DFS to search
    bool search(string word) {
        return searchWord(word, root, 0);
    }

    bool searchWord(string word, TrieNode* p, int i) {
        if (i == word.size()) return p->isWord;
        if (word[i] == '.') {
            for (auto& a : p->child) {
                if (a && searchWord(word, a, i + 1)) return true;
            }
            return false;
        }
        else {
            int ind = word[i] - 'a';
            return (p->child[ind] && searchWord(word, p->child[ind], i + 1));
        }

    }

private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */