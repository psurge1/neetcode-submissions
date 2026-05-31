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
    Node* cloneGraph(Node* node) {
        /*
        Input:
        - A node of the graph
        - The graph is connected and undirected

        Output:
        - A deep copy of the graph

        Idea:
        - maintain a hashmap of mappings between nodes and deep copies of those nodes
        - every time a new node is encountered (not in the map), create an entry in the hashmap
        - every time an already seen node is encountered, reference the deep copy in the hashmap
        - perform an ordinary graph traversal to fill out the tree
        */
        if (!node) {
            return nullptr;
        }

        unordered_map<Node*, Node*> deepCopies;
        queue<Node*> nodesToProcess;
        Node* graphCopy = new Node(node->val);

        deepCopies[node] = graphCopy;
        nodesToProcess.push(node);

        while (!nodesToProcess.empty()) {
            Node* topNode = nodesToProcess.front();
            nodesToProcess.pop();

            Node* topNodeCopy = deepCopies[topNode];

            for (Node* edgeNode : topNode->neighbors) {
                if (!deepCopies.contains(edgeNode)) {
                    deepCopies[edgeNode] = new Node(edgeNode->val);
                    nodesToProcess.push(edgeNode);
                }
                topNodeCopy->neighbors.push_back(deepCopies[edgeNode]);
            }
        }

        return graphCopy;
    }
};
