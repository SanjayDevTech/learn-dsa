#include<iostream>
#include<string>
#define SIZE 100

class Integer {
	int intValue;
	public:
	Integer (int a = 0) {
		intValue = a;
	}
	Integer (const Integer &copy) {
		intValue = copy.intValue;
	}
	void operator = (int i) {
		intValue = i;
	}
	int get() {
		return intValue;
	}
};

template<typename T>
class HashMap {
	T* array[SIZE] = {NULL};
	int hash(std::string key) {
		int sum = 0;
		for (char ch : key) {
			sum += ch;
		}
		return sum % 100;
	}
	public:
	bool put(std::string key, T value) {
		int hash_code = hash(key);
		while (array[hash_code] != NULL) {
			if (hash_code >= SIZE) {
				return false;
			}
			++hash_code;
		}
		std::cout << "HashCode: " << hash_code << std::endl;
		array[hash_code] = new Integer(value);
		return true;
	}
	
	T* operator [] (std::string key) {
		return array[hash(key)];
	}
	
	~HashMap() {
		for (int i = 0; i < SIZE; ++i) {
			if (array[i] != NULL) {
				delete array[i];
			}
		}
	}
};
int main() {
	HashMap<Integer> hashmap;
	Integer integer;
	std::string key;
	std::cout << "1. Put element\n2. Get element\n3. Exit\n";
	char ch;
	while(1) {
		std::cout << "Enter choice: ";
		std::cin >> ch;
		if (ch == '1') {
			int value;
			std::cout << "Enter key and value: ";
			std::cin >> key >> value;
			integer = value;
			hashmap.put(key, integer);
		} else if (ch == '2') {
			std::cout << "Enter key: ";
			std::cin >> key;
			Integer* integer = hashmap[key];
			if (integer == NULL) {
				std::cout << "NULL value\n";
			} else {
				std::cout << integer->get() << "\n";
			}
		} else {
			break;
		}
	}
}




