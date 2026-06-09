#include <iostream>

int main(){

int first_num = 0;
std::cout << "Enter first number: ";
std::cin >> first_num;

int second_num = 0;
std::cout << "Enter second number: ";
std::cin >> second_num;

char operation;
std::cout << "Choose operation (+, -, *, /, %): ";
std::cin >> operation;


switch(operation){
    case '+':
        std::cout << "Result: " << first_num + second_num << std::endl;
        break;
    case '-':
        std::cout << "Result: " << first_num - second_num << std::endl;
        break;
    case '*':
        std::cout << "Result: " << first_num * second_num << std::endl;
        break;
    case '/':
        if(second_num == 0)
            std::cout << "Error: Division by zero is not allowed." << std::endl;
        else
            std::cout << "Result: " << first_num / second_num << std::endl;
        break;
    case '%':
        if(second_num == 0)
            std::cout << "Error: Modulo by zero is not allowed." << std::endl;
        else
            std::cout << "Result: " << first_num % second_num << std::endl;
        break;
}

return 0;
}