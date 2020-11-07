// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

// Example 1:


// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
// Example 4:

// Input: root = [1,2]
// Output: [1,2]


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//因為我們在serialize的過程有把nullptr的位置記住，只需要一種序列就可以寫出原本的tree
//一般情況下需要至少兩種序列才能
//Pre order 寫法
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        serialize(root,res);
        return res;
    }
    void serialize(TreeNode* node, string& res){
        if(!node) {
            res += "# ";
            return;
        }
        res += to_string(node->val);
        res += " ";
        serialize(node->left, res);
        serialize(node->right, res);
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserialize(iss);
    }

    TreeNode* deserialize(istringstream& nodes){
        string s;
        if(!(nodes >> s) || s == "#") return nullptr; 
        TreeNode* node = new TreeNode(stoi(s));
        
        node->left = deserialize(nodes);
        node->right = deserialize(nodes);
        
        return node;
    }
};


