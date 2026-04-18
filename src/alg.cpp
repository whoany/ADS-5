// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> stack;
    std::string result = "";

    for (size_t i = 0; i < inf.length(); i++) {
        char c = inf[i];

        if (c == ' ') continue;
        if (isDigit(c)) {
            while (i < inf.length() && isDigit(inf[i])) {
                result += inf[i];
                i++;
            }
            result += ' ';
            i--;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                result += stack.pop();
                result += ' ';
            }
            stack.pop();
        } else if (isOperator(c)) {
            while (!stack.isEmpty() && stack.peek() != '(' &&
                   priority(stack.peek()) >= priority(c)) {
                result += stack.pop();
                result += ' ';
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        result += stack.pop();
        result += ' ';
    }

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int eval(const std::string& post) {
    TStack<int, 100> stack;

    for (size_t i = 0; i < post.length(); i++) {
        char c = post[i];

        if (c == ' ') continue;

        if (isDigit(c)) {
            int num = 0;
            while (i < post.length() && isDigit(post[i])) {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            stack.push(num);
            i--;
        } else if (isOperator(c)) {
            int b = stack.pop();
            int a = stack.pop();
            int res = 0;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;
            stack.push(res);
        }
    }

    return stack.pop();
}
