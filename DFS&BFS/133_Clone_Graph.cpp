//Given a reference of a node in a connected undirected graph.
//
//Return a deep copy (clone) of the graph.
//
//Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
//
//class Node {
//    public int val;
//    public List<Node> neighbors;
//}
// 
//
//Test case format:
//
//For simplicity sake, each node's value is the same as the node's index (1-indexed). For example, the first node with val = 1, the second node with val = 2, and so on. The graph is represented in the test case using an adjacency list.
//
//Adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
//
//The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


//DFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        //use hashmap to store already cloned node
        unordered_map<Node*, Node*> m;
        return DFS(node, m);
    }

    Node* DFS(Node* node, unordered_map<Node*,Node*>& m){
        if(!node) return NULL;
        if(m.count(node)) return m[node];
        Node* new_node = new Node(node->val);
        m[node] = new_node;
        for(Node* neigh: node->neighbors){
            new_node->neighbors.push_back(DFS(neigh,m));
        }
        return new_node;
    }
};

//BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        //use hashmap to store already cloned node
        unordered_map<Node*, Node*> m;
        if (!node) return NULL;
        queue<Node*> q{ {node} };
        Node* new_node = new Node(node->val);
        m[node] = new_node;

        while (!q.empty()) {
            Node* temp = q.front(); q.pop();
            for (auto neigh : temp->neighbors) {
                if (!m.count(neigh)) {
                    m[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }
                m[temp]->neighbors.push_back(m[neigh]);
            }
        }
        return new_node;
    }

};