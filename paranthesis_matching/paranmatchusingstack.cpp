#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
bool balanced(const string& expression) {
    stack<char> s;
    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') s.push(ch);
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty() || !isMatching(s.top(), ch)) return false;
            s.pop();
        }
    }
    return s.empty();
}
int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    cout << (balanced(expression) ? "Balanced\n" : "Not balanced\n");
}