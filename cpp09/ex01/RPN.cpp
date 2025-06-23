#include "RPN.hpp"

bool rpn(std::string args){
    std::stack<int> stack;
    std::stringstream line(args);
    std::string word;
    int num1 = 0, num2 = 0;

    while (line >> word){
        if (word == "+" || word == "-" || word == "*" || word == "/"){
            if (stack.size() < 2){
                std::cerr << "Not enough operands!" << std::endl;
                return false;
            }
            num2 = stack.top(); stack.pop();
            num1 = stack.top(); stack.pop();
            if (word == "+")
				stack.push(num1 + num2);
            else if (word == "-")
				stack.push(num1 - num2);
            else if (word == "*")
				stack.push(num1 * num2);
            else if (word == "/"){
                if (num2 == 0){
                    std::cerr << "Division by zero!" << std::endl;
                    return false;
                }
                stack.push(num1 / num2);
            }
        }
		else{
            // Only accept single digit numbers
            if (word.size() != 1 || !isdigit(word[0])){
                std::cerr << "Invalid token: " << word << std::endl;
                return false;
            }
            stack.push(word[0] - '0');
        }
    }
    if (stack.size() != 1){
        std::cerr << "Invalid expression!" << std::endl;
        return false;
    }
    std::cout << stack.top() << std::endl;
    return true;
}