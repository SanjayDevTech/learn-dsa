#include<iostream>
struct Node {
    int data;
    Node* next;
};
class List {
    private:
    int length = 0;
    Node* head = NULL;
    public:
    Node* createNode(int data) {
        Node* tempNode =(Node*) malloc(sizeof(Node));
        tempNode->data = data;
        tempNode->next = NULL;
    }
    int size() {
        return length;
    }
    void createDemo(int array[], int n) {
        Node* ptr = head;
        for(int i = 0; i < n; i++) {
            if(head == NULL) {
                head = createNode(array[i]);
                ptr = head;
                length++;
                continue;
            }
            Node* newNode = createNode(array[i]);
            ptr->next = newNode;
            ptr= ptr->next;
            length++;
        }
    }
    void print() {
        if(head==NULL) {
            std::cout << "[]\n";
            return;
        }
        Node*ptr = head;
        std::cout << "[ " << ptr->data;
        while(ptr->next != NULL) {
            ptr = ptr->next;
            std::cout << ", " << ptr->data;
        }
        std::cout <<"]\n";
    }
    bool pop(int index) {
        if(index < 0 || index > length) {
            return false;
        }
        length--;
        if(index == 0) {
            Node* deadNode = head;
            head = deadNode->next;
            return true;
        }
        int count = 0;
        Node* ptr = head;
        while(ptr->next != NULL) {
            if(count == index-1) {
                break;
            }
            count++;
            ptr = ptr->next;
        }
        Node* deadNode = ptr->next;
        ptr->next = deadNode->next;
        free(deadNode);
        return true;
    }
    bool insert(int index, int data) {
        if(index < 0 || index > length) {
            return false;
        }
        length++;
        Node* newNode = createNode(data);
        if(index == 0) {
            newNode->next = head;
            head = newNode;
            return true;
        }
        Node* ptr = head;
        int count  = 0;
        while(ptr->next != NULL) {
            if(count == index-1) {
                break;
            }
            count++;
            ptr=ptr->next;
        }
        if(ptr->next == NULL) {
            ptr->next = newNode;
        } else {
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
        return true;
    }
};
int main() {
    List list;
    int array[5] = {1, 2, 3, 4, 5};
    list.createDemo(array, 5);
    list.insert(5, 15);
    list.pop(5);
    list.print();
    return 0;
}
