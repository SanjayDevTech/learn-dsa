#include<iostream>
template<typename T>
struct Node {
	Node<T>* prev;
	T data;
	Node<T>* next;
};
template<typename T>
class Stack {
	Node<T> *top = NULL, *head = NULL;
	Node<T>* createNode(T data) {
		Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
	public:
	void create(T array[], int n) {
		for(int i = 0; i < n; i++) {
			if(top == NULL) {
				head = createNode(array[i]);
				top = head;
				continue;
			}
			top->next = createNode(array[i]);
			top->next->prev = top;
			top = top->next;
		}
	}
	Node<T>* pop() {
		Node<T>* dead = top;
		if(top != NULL) {
			top = top->prev;
			top->next = NULL;
		} else {
			head = NULL;
		}
		return dead;
	}
	void push(T data) {
		if(top == NULL) {
			head = createNode(data);
			top = head;
			return;
		}
		top->next = createNode(data);
		top->next->prev = top;
		top = top->next;
	}
	void print() {
		Node<T>* ptr = head;
		while(ptr != NULL) {
			std::cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
};
int main() {
	Stack<int> stack;
	int array[5] = {1, 2, 3, 4, 5};
	//stack.create(array, 5);
//	stack.create(array, 5);
//	stack.push(10);
	if(stack.pop() == NULL) {
		std::cout << "Not popped\n";
	}
	stack.print();
}
