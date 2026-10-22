
class Node {
public:
    int val, key;
    Node *prev, *next;

    Node(int key, int val) {
        this->val = val;
        this->key = key;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> map;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.find(key) == map.end())
            return -1;

        Node* currNode = map[key];

        remove(currNode);
        insert(currNode);

        return currNode->val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (map.find(key) != map.end()) {
            Node* currNode = map[key];
            currNode->val = value;

            remove(currNode);
            insert(currNode);
            return;
        }

        if (map.size() == capacity) {
            Node* currNode = tail->prev;
            remove(currNode);
            map.erase(currNode->key);
            delete currNode;
        }

        Node* newNode = new Node(key, value);
        map[key] = newNode;
        insert(newNode);
    }
};
