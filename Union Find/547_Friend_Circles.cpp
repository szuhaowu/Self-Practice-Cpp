//There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.
//
//Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.
//
//Example 1:
//
//Input: 
//[[1,1,0],
// [1,1,0],
// [0,0,1]]
//Output: 2
//Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
//The 2nd student himself is in a friend circle. So return 2.
// 
//
//Example 2:
//
//Input: 
//[[1,1,0],
// [1,1,1],
// [0,1,1]]
//Output: 1
//Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
//so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
//
// 
//
//Constraints:
//
//1 <= N <= 200
//M[i][i] == 1
//M[i][j] == M[j][i]


//Union Find
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        vector<int> parent(n,0), treeSize(n,1);
        for(int i=0; i<n; i++) parent[i] = i;
        int res = n;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(M[i][j]){
                    Union(i,j,res,parent,treeSize);
                }
            }
        }
        return res;
    }
    
    int findroot(int i, vector<int>& parent){
        while(parent[i] != i){
            parent[i] = parent[parent[i]]; //壓縮樹的高度，讓find, union, connected time complexity to O(1) (原本是O(N))
            i = parent[i];
        }
        return i;
    }
    
    void Union(int i, int j, int& res, vector<int>& parent, vector<int>& treeSize){
        int root_i = findroot(i,parent);
        int root_j = findroot(j,parent);
        if(root_i == root_j) return;
        
        //balance樹的左右分枝，避免把size較大的樹接到較小的樹，這樣會更趨近於O(logN)
        if(treeSize[root_i] > treeSize[root_j]){
            parent[root_j] = root_i;
            treeSize[root_i] += treeSize[root_j];
        }
        else{
            parent[root_i] = root_j;
            treeSize[root_j] += treeSize[root_i];
        }
        res--;
    }
    
};

//DFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            helper(M, i, visited);
            ++res;
        }
        return res;
    }
    void helper(vector<vector<int>>& M, int k, vector<bool>& visited) {
        visited[k] = true;
        for (int i = 0; i < M.size(); ++i) {
            if (!M[k][i] || visited[i]) continue;
            helper(M, i, visited);
        }
    }
};

//BFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = 0;
        vector<bool> visited(n, false);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            q.push(i);
            while (!q.empty()) {
                int t = q.front(); q.pop();
                visited[t] = true;
                for (int j = 0; j < n; ++j) {
                    if (!M[t][j] || visited[j]) continue;
                    q.push(j);
                }
            }
            ++res;
        }
        return res;
    }
};