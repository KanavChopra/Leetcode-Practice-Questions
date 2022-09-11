class Node {
    public:
    int val;
    Node *next;
    
    Node(): val(0), next(NULL) {}
    Node(int val): val(val), next(NULL) {}
};


class MyLinkedList {
public:
    Node *head;
    int length;
    
    MyLinkedList(): head(NULL), length(0) {}
    
    int get(int index) {
        if (index >= length || index < 0) {
            return -1;
        } else {
            Node *curr = head;
            for (int i = 0; i < index; ++i) {
                curr = curr -> next;
            }
            return curr -> val;
        }
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(length, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > length || index < 0) {
            return;
        }
        Node *node = new Node(val);
        if (index == 0) {
            node -> next = head;
            head = node;
        } else {
            Node *curr = head;
            for (int i = 0; i < index - 1; ++i) {
                curr = curr -> next;
            }
            node -> next = curr -> next;
            curr -> next = node;
        }
        ++length;
    }
    
    void deleteAtIndex(int index) {
        if (index >= length || index < 0) {
            return;
        }
        if (index == 0) {
            Node *temp = head;
            head = head -> next;
            delete (temp);
        } else {
            Node *curr = head;
            for (int i = 0; i < index - 1; ++i) {
                curr = curr -> next;
            }
            Node *temp = curr -> next;
            curr -> next = curr -> next -> next;
            delete (temp);
        }
        --length;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */