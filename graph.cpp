#include<iostream>
#define SIZE 5
struct Node {
	int data;
	Node* next;
};
class Graph {
	Node* array[SIZE] = {NULL};
	Node* create_node(int data) {
		Node* new_node = (Node*) malloc(sizeof(Node));
		new_node->data = data;
		new_node->next = NULL;
		return new_node;
	}
	public:
	void put_node(int data, int neighbour) {
		if (data >= SIZE || data < 0 || neighbour >= SIZE || neighbour < 0) {
			std::cout << "Data or neighbour is not valid\n";
			return;
		}
		Node* temp_node = array[data];
		if (temp_node == NULL) {
			array[data] = create_node(neighbour);
		} else {
			while(temp_node->next != NULL) {
				temp_node = temp_node->next;
			}
			temp_node->next = create_node(neighbour);
		}
	}
	void print_for_node(int data) {
		if (data >= SIZE || data < 0) {
			std::cout << "Data is not valid\n";
			return;
		}
		std::cout<< data << " -> ";
		Node* ptr_node = array[data];
		while (ptr_node != NULL) {
			std::cout << ptr_node->data << " -> ";
			ptr_node = ptr_node->next;
		}
		std::cout << "NULL\n";
	}
};

int main() {
	Graph g;
	int data, neighbour, neighbour_num;
	for (int i = 0; i < SIZE; ++i) {
		std::cout << "Enter the no. of neighbours for " << i << " node : ";
		std::cin >> neighbour_num;
		for (int j = 0; j < neighbour_num; ++j) {
			std::cin >> neighbour;
			g.put_node(i, neighbour);
		}
	}
	while (1) {
		std::cout << "Enter the node to print: ";
		std::cin >> data;
		if (data < 0) {
			break;
		}
		g.print_for_node(data);
	}
}
