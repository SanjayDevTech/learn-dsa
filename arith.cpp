#include<iostream>
#include<string>
#define SIZE 10

class Stack {
    int array[SIZE] = {0};
    int length = 0;
    public:
    bool is_empty() {
        return (length <= 0);
    }
    bool is_full() {
        return (length >= SIZE); 
    }
    void push(int value) {
        if(is_full()) {
            return;
        }
        array[length++] = value;
    }
    int pop() {
        if(is_empty()) {
            return 0;
        }
        length--;
        return array[length+1];
    }
    void print() {
        for(int i = length-1; i >= 0; --i) {
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }
};
bool is_digit(std::string str) {
    for(char letter:str) {
        if(!isdigit(letter)) {
            return false;
        }
    }
    return true;
}
int main() {
    Stack stack;
    std::string str;
    std::cout << "Enter the sequence: ";
    getline(std::cin, str);
    int index = 0;
    std::string temp = "";
    while(index < str.length()) {
        if(str[index]==' ') {
            if(is_digit(temp)) {
                stack.push(atoi(temp.c_str()));
            }
            temp = "";
            index++;
            continue;
        }
        temp += str[index];
        index++;
    }
    if(is_digit(temp)) {
        stack.push(atoi(temp.c_str()));
    }
    stack.print();
}