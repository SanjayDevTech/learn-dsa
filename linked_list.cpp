#include<iostream>
struct Node {
	int data;
	Node* next;
};

class LinkedList {
	private:
		int length;
		Node* head;
	public:
		LinkedList() {
			length = 0;
			head = NULL;
		}
		void create_demo(int array[], int n) {
			Node* ptr = head;
			for(int iter = 0; iter < n; iter++) {
				if(ptr == NULL) {
					Node* temp = (Node*) malloc(sizeof(Node));
					temp->data = array[iter];
					temp->next = NULL;
					head = temp;
					ptr = head;
					length++;
					continue;
				}
				Node* temp = (Node*) malloc(sizeof(Node));
				temp->data = array[iter];
				temp->next = NULL;
				ptr->next = temp;
				ptr = ptr->next;
				length++;
			}
		}
		int insert(Node* temp, int index) {
			if(index < 0 || index > length) {
				return 0;
			}
			
			if(index == 0) {
				temp->next = head;
				head = temp;
				length++;
				return 1;
			}
			Node* ptr = head;
			if(index == length) {
				while(ptr->next != NULL) {
					ptr = ptr->next;
				}
				temp->next = NULL;
				ptr->next = temp;
				length++;
				return 1;
			}
			int count = 0;
			while(ptr->next != NULL) {
				if(count == index-1) {
					temp->next = ptr->next;
					ptr->next = temp;
					length++;
					break;
				}
				ptr = ptr->next;
				count++;
			}
			return 1;

		}
		void clear() {
			Node* ptr = head;
			while(ptr->next != NULL) {
				Node* dead = ptr;
				ptr = ptr->next;
				free(dead);
			}
			head = NULL;
			length = 0;

		}
		int remove(int index) {
			if(index < 0 || index > length) {
				return 0;
			}
			if(index == 0) {
				Node* dead = head;
				head = head->next;
				free(dead);
				length--;
				return 1;
			}
			Node* ptr = head;
			if(index == length) {
				return 0;
				Node* last;
				while(ptr->next != NULL) {
					if(ptr->next->next != NULL) {
						last = ptr;
					}
					ptr = ptr->next;

				}
				last->next = NULL;
				free(ptr);
				length--;
				return 1;
			}
			int count  = 0;
			while(ptr->next != NULL) {
				if(count == index-1) {
					Node* dead = ptr->next;
					ptr->next = dead->next;
					free(dead);
					length--;
					break;
				}
				ptr = ptr->next;
				count++;
			}
			return 1;

		}
		void print() {
			Node* ptr = head;
			if(ptr == NULL) {
				std::cout << "Empty list\n";
				return;
			}
			std::cout << " " << ptr->data;
			while(ptr->next != NULL) {
				ptr = ptr->next;
				std::cout << " " << ptr->data;
			}
			std::cout << "\n";
		}
		~LinkedList() {
			Node* ptr = head;
			if(ptr == NULL) {
				return;
			}
			while(ptr->next != NULL) {
				Node* dead = ptr;
				ptr = ptr->next;
				free(dead);
			}
		}
};
Node* create_node(int value) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = value;
	return temp;
}
int main() {
	LinkedList list;
	int array[5] = {1, 2, 3, 5, 6};
	list.create_demo(array, 5);	
	list.insert(create_node(4), 3);
	list.clear();
	list.print();
	return 0;
}
