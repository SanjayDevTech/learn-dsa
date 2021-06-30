#include<iostream>
struct Node {
	Node *left;
	int data;
	Node *right;
};
class BST {

	Node *root = NULL;


	// Helper method for creating a node
	Node* create_node(int data) {
		Node *new_node = (Node*)malloc(sizeof(Node));
		new_node->left = NULL;
		new_node->data = data;
		new_node->right = NULL;
		return new_node;
	}


	// Helper method for printing
	void print(Node* root) {
		if(root == NULL) {
			return;
		}
		print(root->left);
		std::cout << " " << root->data;
		print(root->right);
	}
	
	Node* high_value(Node* ptr) {
		Node* high = ptr;
		while (high && high->right != NULL) {
			high = high->right;
		}
		return high;
	}

	public:
	
	// It will intialize tree with given elements
	void create_tree(int n, int array[]) {
		for (int i = 0; i < n; ++i) {
			add_to_tree(array[i]);
		}
	}
	
	// It will add the element
	void add_to_tree(int data, Node *ptr = NULL) {
	
		// If root is null, add the element as root
		if (root == NULL) {
			Node *new_node = create_node(data);
			root = new_node;
			return;
		}
		if (ptr == NULL) {
			ptr = root;
		}
		if(data <= ptr->data) {
		
			// Left sub tree
			if(ptr->left == NULL) {
				ptr->left = create_node(data);
			 } else {
			 	add_to_tree(data, ptr->left);
			 }
		} else if(data > ptr->data) {
		
			// Right sub tree
			if(ptr->right == NULL) {
				ptr->right = create_node(data);
			 } else {
			 	add_to_tree(data, ptr->right);
			 }
		}
	}
	
	// It will delete the element
	void delete_from_tree(int data, Node *ptr = NULL, Node *prev = NULL) {
		if (root == NULL) {
			return;
		}
		if (ptr == NULL) {
			ptr = root;
		}
		if(data < ptr->data) {
			// Left sub tree
			if(ptr->left == NULL) {
				return;
			 } else {
			 	delete_from_tree(data, ptr->left, ptr);
			 }
		} else if(data > ptr->data) {
			// Right sub tree
			if(ptr->right == NULL) {
				return;
			 } else {
			 	delete_from_tree(data, ptr->right, ptr);
			 }
		} else {
			// Equals
			// case 1: No children
			if (ptr->left == NULL && ptr->right == NULL) {
				Node* temp = ptr;
				if (temp->data == prev->left->data) {
					// Parent's left
					prev->left = NULL;
				} else {
					// Parent's right
					prev->right = NULL;
				}
				free(temp);
			}
			// case 2: 2 childrens
			else if (ptr->left != NULL && ptr->right != NULL) {
				// Inorder predecessor
				Node* temp = ptr;
				if (temp->data == prev->left->data) {
					// Parent's left
					prev->left = high_value(ptr->left);
				} else {
					// Parent's right
					prev->right = high_value(ptr->right);
				}
				free(temp);
			}
			// case 3: 1 children
			else {
				Node* temp = ptr;
				if (temp->data == prev->left->data) {
					// Parent's left
					if (ptr->left != NULL) {
						prev->left = ptr->left;					
					} else {
						prev->left = ptr->right;
					}
				} else {
					// Parent's right
					if (ptr->left != NULL) {
						prev->right = ptr->left;					
					} else {
						prev->right = ptr->right;
					}
				}
				free(temp);
			}
		}
	}

	void print_tree() {	
		if(root == NULL) {
			std::cout << "Empty tree!!!" << std::endl;
			return;
		}
		print(root->left);
		std::cout << " " << root->data;
		print(root->right);
		std::cout << std::endl;
	}

};
int main() {
	BST bst;
	char temp;
	std::cout << "======= Binary Search Tree =======\n";
	std::cout << "Do you want to initialize BST? y/n: ";
	std::cin >> temp;
	if(temp == 'Y' || temp == 'y') {
		int array[] = {10, 5, 0, 12, 8};
		bst.create_tree(5, array);
		std::cout << "Printing tree\n";
		bst.print_tree();
	}
	std::cout << "1. Add an element\n2. Delete an element\n3. Print the tree\n";
	while(1) {
		std::cout << "Enter choice: ";
		std::cin >> temp;
		if(temp == '1') {
			// Add an element
			std::cout << "Data: ";
			int data;
			std::cin>> data;
			bst.add_to_tree(data);
		} else if (temp == '2') {
			// Delete an element
			std::cout << "Data: ";
			int data;
			std::cin>> data;
			bst.delete_from_tree(data);
		} else if (temp == '3') {
			// Print the tree
			bst.print_tree();
		} else {
			break;
		}
	}

	
	return 0;
}




