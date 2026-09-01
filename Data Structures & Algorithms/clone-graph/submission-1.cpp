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

class Solution {
   public:
    unordered_map<Node*, Node*> clone;
    unordered_map<Node*, bool> visited;
    void traverse(Node* node) {
        visited[node] = true;

        vector<Node*> neighs = node->neighbors;
        for (auto it : neighs) {
            Node* newNd;
            if (clone.find(node) == clone.end()) {
                newNd = new Node(node->val);
                clone[node] = newNd;
            } else
                newNd = clone[node];

            Node* newNeigh;
            if (clone.find(it) == clone.end()) {
                newNeigh = new Node(it->val);
                clone[it] = newNeigh;
            } else {
                newNeigh = clone[it];
            }

            newNd->neighbors.push_back(newNeigh);
            if (!visited[it]) {
                traverse(it);
            }
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        traverse(node);
        if (clone.find(node) == clone.end()) {
            Node* retNode = new Node(node->val);
            return retNode;
        }
        return clone[node];
    }
};
