#include<iostream>
struct Node {
	Node* prev;
	int data;
	Node* next;
};
Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = value;
	return newNode;
}
class DoublyLinkedList {
	Node* head = NULL;
	int length = 0;
	public:
	void add(int data, int index = -1) {}

	void create_demo(int array[], int n) {
		Node* ptr = head;
		for(int iter = 0; iter < n; iter++) {
			length++;
			if(head == NULL) {
				head = createNode(array[iter]);
				ptr = head;
				continue;
			}
			Node* temp = createNode(array[iter]);
			ptr->next = temp;
			temp->prev = ptr;
			ptr = ptr->next;
		}
	}
	void print() {
		if(head == NULL) {
			std::cout << "Empty list\n";
			return;
		}
		Node* ptr = head;
		std::cout << "[ " << ptr->data;
		while(ptr->next != NULL) {
			ptr = ptr->next;
			std::cout << ", " << ptr->data;
		}
		std::cout << "]\n";
	}

};
int main() {
	DoublyLinkedList list;
	int array[5] = {0, 1, 2, 3, 4};
	list.create_demo(array, 5);
	list.print();
}
