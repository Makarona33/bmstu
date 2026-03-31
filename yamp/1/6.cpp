#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
using namespace std;

map<string, long long> vars;
string expr;
int pos = 0;

void skip_spaces() {
    while (pos < expr.size() && isspace(expr[pos])) ++pos;
}

long long expr_value();

long long factor_value() {
    skip_spaces();
    if (expr[pos] == '(') {
        ++pos;
        long long val = expr_value();
        skip_spaces();
        if (expr[pos] == ')') ++pos;
        return val;
    } else if (isdigit(expr[pos])) {
        long long val = 0;
        while (pos < expr.size() && isdigit(expr[pos])) {
            val = val * 10 + (expr[pos] - '0');
            ++pos;
        }
        return val;
    } else if (isalpha(expr[pos])) {
        string name;
        while (pos < expr.size() && isalnum(expr[pos])) {
            name += expr[pos];
            ++pos;
        }
        return vars[name];
    }
    return 0;
}

long long term_value() {
    long long val = factor_value();
    while (true) {
        skip_spaces();
        char op = expr[pos];
        if (op == '*' || op == '/') {
            ++pos;
            long long next = factor_value();
            if (op == '*') val *= next;
            else if (next != 0) val /= next;
        } else break;
    }
    return val;
}

long long expr_value() {
    long long val = term_value();
    while (true) {
        skip_spaces();
        char op = expr[pos];
        if (op == '+' || op == '-') {
            ++pos;
            long long next = term_value();
            if (op == '+') val += next;
            else val -= next;
        } else break;
    }
    return val;
}

int main() {
    getline(cin, expr);
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string name;
        long long val;
        if (iss >> name >> val) vars[name] = val;
    }
    cout << expr_value() << endl;
    return 0;
}
