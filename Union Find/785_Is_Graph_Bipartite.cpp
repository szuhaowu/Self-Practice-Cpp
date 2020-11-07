//Given an undirected graph, return true ifand only if it is bipartite.
//
//Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.
//
//The graph is given in the following form : graph[i] is a list of indexes j for which the edge between nodes iand j exists.Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges : graph[i] does not contain i, and it doesn't contain any element twice.
//
//Example 1 :
//	Input : [[1, 3], [0, 2], [1, 3], [0, 2]]
//	Output : true
//	Explanation :
//	The graph looks like this :
//	0----1
//	|    |
//	|    |
//	3----2
//	We can divide the vertices into two groups : {0, 2}and {1, 3}.
//	Example 2 :
//	Input : [[1, 2, 3], [0, 2], [0, 1, 3], [0, 2]]
//	Output : false
//	Explanation :
//	The graph looks like this :
//	0----1
//	| \  |
//	|  \ |
//	3----2
//	We cannot find a way to divide the set of nodes into two independent subsets.

//Any two connected points could not be in the same classification
//There are only two classification 1 and -1
//DFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size());
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] == 0 && !valid(graph, 1, i, colors)) {
                return false;
            }
        }
        return true;
    }
    bool valid(vector<vector<int>>& graph, int color, int cur, vector<int>& colors) {
        if (colors[cur] != 0) return colors[cur] == color;
        colors[cur] = color;
        for (int i : graph[cur]) {
            if (!valid(graph, -1 * color, i, colors)) {
                return false;
            }
        }
        return true;
    }
};


//BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(),0);
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] != 0) continue;
            colors[i] = 1;
            queue<int> q{{i}};
            while (!q.empty()) {
                int t = q.front(); q.pop();
                for (auto a : graph[t]) {
                    if (colors[a] == colors[t]) return false;
                    if (colors[a] == 0) {
                        colors[a] = -1 * colors[t];
                        q.push(a);
                    }
                }
            }
        }
        return true;
    }

};


//Union Find
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> root(graph.size());
        for (int i = 0; i < graph.size(); ++i) root[i] = i;
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].empty()) continue;
            int x = find(root, i), y = find(root, graph[i][0]);
            if (x == y) return false;
            for (int j = 1; j < graph[i].size(); ++j) {
                int parent = find(root, graph[i][j]);
                if (x == parent) return false;
                root[parent] = y;
            }
        }
        return true;
    }
    int find(vector<int>& root, int i) {
        return root[i] == i ? i : find(root, root[i]);
    }

};
