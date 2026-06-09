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


if(operation == '+'){
   std::cout << "Result: " << first_num + second_num << std::endl;
}

else if(operation == '-'){
   std::cout << "Result: " << first_num - second_num << std::endl;
}

else if(operation == '*'){
   std::cout << "Result: " << first_num * second_num << std::endl;
}

else if(operation == '/'){
   std::cout << "Result: " << first_num / second_num << std::endl;
}

else if(operation = '%'){
   std::cout << "Result: " << first_num % second_num << std::endl;
}

return 0;
}