#include<iostream>
template<typename T>
struct Node {
	T data;
	Node<T>* next;
};
template<typename T>
class LinkedList {
	private:
		Node<T>* head;
		int length;
	public:
		LinkedList() {
			head = NULL;
			length = 0;
		}
		void create_demo(T array[], int n) {
			Node* ptr = head;
			for(int i = 0; i < n; i++) {
				if(head == NULL) {
					head = array[i];
					head->next = NULL;
					continue;
				}
				ptr->next = array[i];
			}
		}
};
int main() {}
