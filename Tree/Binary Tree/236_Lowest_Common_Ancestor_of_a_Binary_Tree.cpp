//Given a binary tree, find the lowest common ancestor(LCA) of two given nodes in the tree.
//
//According to the definition of LCA on Wikipedia : “The lowest common ancestor is defined between two nodes pand q as the lowest node in T that has both pand q as descendants(where we allow a node to be a descendant of itself).”
//
//Given the following binary tree : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
//
//
//
//
//Example 1 :
//
//    Input : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 1
//    Output : 3
//    Explanation : The LCA of nodes 5 and 1 is 3.
//    Example 2 :
//
//    Input : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 4
//    Output : 5
//    Explanation : The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 There are 3 conditions in this problem
 1. p & q are in the left subtree of root -> return the first parent of p&q or return the first meet of p or q.
 2. p & q are in the right subtree of root -> return the first parent of p&q or return the first meet of p or q.
 3. p in the left and q in the right -> return root.
 Binary tree -> Recursive function!!
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || p == root || q == root) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        //當p&q都在root 的left subtree 但是分別在 root->left 的左右兩子樹，會提早得到結果，進入以下條件
        if (left && left != p && left != q) return left;
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if (p == root || q == root) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(left && right) return root;
        if(!left && !right) return nullptr;
        return left? left:right;
    }
}; 