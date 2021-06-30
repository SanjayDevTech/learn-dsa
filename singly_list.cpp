#include<iostream>
struct Node { // Data node
    int data;
    Node *next;
};
class List {
    private:
    Node *head = NULL;
    int length = 0;
    Node* make(int data) { // To make a New Node
        Node *temp = (Node*) malloc(sizeof(Node));
        temp->data = data;
        temp->next = NULL;
        return temp;
    }
    public:
    void create(int array[], int size) { // To create a sample list
        Node *ptr = head;
        length += size;
        for(int iter = 0; iter < size; iter+=1) {
            if(ptr == NULL) {
                head = make(array[iter]);
                ptr = head;
                continue;
            }
            ptr->next = make(array[iter]);
            ptr = ptr->next;
        }
    }
    void print(const char *msg) { // To display the list
        std::cout << "[ ";
        Node *ptr = head;
        while(ptr != NULL) {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << "]";
        std::cout << " <= " << msg << "\n";
    }
    void add(int data, int index = -1) { // To insert a node in the list
        length += 1;
        if(index == 0 || head == NULL) {
            Node *new_node = make(data);
            new_node->next = head;
            head = new_node;
            return;
        }
        int ptr_index = 0;
        Node *ptr = head;
        while(ptr->next != NULL) {
            if(ptr_index == index-1) {
                break;
            }
            ptr = ptr->next;
            ptr_index+=1;
        }
        Node *new_node = make(data);
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
    void remove(int index) { // To delete a node in the list
        if(head == NULL || index < 0 || index >= length) {
            return;
        }
        length -= 1;
        if(index == 0) {
            Node *dead_node = head;
            head = dead_node->next;
            free(dead_node);
            return;
        }
        int ptr_index = 0;
        Node *ptr = head;
        while(ptr->next != NULL) {
            if(ptr_index == index-1) {
                break;
            }
            ptr = ptr->next;
            ptr_index+=1;
        }
        Node *dead_node = ptr->next;
        ptr->next = dead_node->next;
        free(dead_node);
    }
    int find(int data) { // To search for a data in the list
        Node *ptr = head;
        int index = 0;
        while(ptr != NULL) {
            if(ptr->data == data) {
                return index; 
            }
            ptr = ptr->next;
            index += 1;
        }
        return -1;
    }
    int size() {
        return length;
    }
};
int main() {
    List list;
    char choice, operation;
    int data, index;
    std::cout << "Do you want to initialise list? y/n: ";
    std::cin >> choice;
    if(choice == 'y') {
        int num;
        std::cout << "Enter the number of elements: ";
        std::cin >> num;
        int array[num];
        std::cout << "Enter the elements\n";
        for(int iter = 0; iter < num; iter+=1) {
            std::cin >> array[iter];
        }
        list.create(array, num);
    }
    std::cout << " ====== MENU ======\n";
    std::cout << " 1. Insert\n 2. Delete\n 3. Find\n";
    do {
        std::cout << "Enter the id of the operation: ";
        std::cin >> operation;
        switch (operation) {
            case '1':
                std::cout << "Enter the element to be inserted: ";
                std::cin >> data;
                std::cout << "Enter the position: ";
                std::cin >> index;
                list.add(data, index);
                list.print("Insertion");
                break;

            case '2':
                std::cout << "Enter the position: ";
                std::cin >> index;
                list.remove(index);
                list.print("Deletion");
                break;

            case '3':
                std::cout << "Enter the element to find: ";
                std::cin >> data;
                index = list.find(data);
                if(index == -1) {
                    std::cout << "Element is not found\n";
                } else {
                    std::cout << data << " is found at " << index << " index\n";
                }
                break;

            default:
                std::cout << "Invalid operation\n";
        }
        std::cout << "Do you want to continue? y/n: ";
        std::cin >> choice;
    } while(choice == 'y');
}