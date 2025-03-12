class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        unordered_map<Node*, Node*> copies;
        queue<Node*> q;
        
        q.push(node);
        copies[node] = new Node(node->val);
        
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            
            for (auto neighbor : cur->neighbors) {
                if (copies.find(neighbor) == copies.end()) {
                    copies[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                copies[cur]->neighbors.push_back(copies[neighbor]);
            }
        }
        
        return copies[node];
    }
};
