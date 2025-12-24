struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};
class MyLinkedList {
private:
    Node* temp;   // dummy head
    int size;
public:
    MyLinkedList() {
       temp = new Node(0);
        size = 0;
    }
    
    int get(int index) {
         if (index < 0 || index >= size) return -1;

        Node* curr = temp->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node*node= new Node(val);
        node->next= temp->next;
        temp->next= node;
        size++;
    }
    
    void addAtTail(int val) {
        Node* curr = temp;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        Node* prev = temp;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* node = new Node(val);
        node->next = prev->next;
        prev->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        Node* prev = temp;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        size--;
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