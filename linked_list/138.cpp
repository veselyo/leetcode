/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            std::unordered_map<Node*, Node*> nodeMap;
            Node* currNode = head;
    
            // Iterate through the original list.
            while (currNode != NULL) {
                // Copy and save head in hashmap.
                if (nodeMap.find(currNode) == nodeMap.end()) {
                    Node* copiedHead = new Node(currNode->val);
                    nodeMap[currNode] = copiedHead;
                }
    
                if (currNode->next != NULL) {
                    Node* nextNode;
                    // Copy and save next node in hashmap if it hasn't been.
                    if (nodeMap.find(currNode->next) == nodeMap.end()) {
                        nextNode = new Node(currNode->next->val);
                        nodeMap[currNode->next] = nextNode;
                    }
                    else {
                        nextNode = nodeMap[currNode->next];
                    }
    
                    // Assign ptr of this node to the next.
                    nodeMap[currNode]->next = nextNode;
                }
    
                if (currNode->random != NULL) {
                    Node* randNode;
                    // Copy and save random node in hashmap if it hasn't been.
                    if (nodeMap.find(currNode->random) == nodeMap.end()) {
                        randNode = new Node(currNode->random->val);
                        nodeMap[currNode->random] = randNode;
                    }
                    else {
                        randNode = nodeMap[currNode->random];
                    }
    
                    // Assign ptr of this node to its random one.
                    nodeMap[currNode]->random = randNode;
                }
    
                // Go to the next node in original list.
                currNode = currNode->next;
            }
    
            // Return head of copied linked list.
            return nodeMap[head];
        }
    };