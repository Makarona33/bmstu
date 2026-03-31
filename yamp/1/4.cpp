#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>
using namespace std;

unordered_set<string> seen;

string parse(const string& s, int& pos) {
    while (pos < s.size() && isspace(s[pos])) ++pos;
    if (pos >= s.size()) return "";

    if (s[pos] == '(') {
        ++pos;
        while (pos < s.size() && isspace(s[pos])) ++pos;
        string op(1, s[pos]);
        ++pos;

        string left = parse(s, pos);
        string right = parse(s, pos);

        while (pos < s.size() && isspace(s[pos])) ++pos;
        if (s[pos] == ')') ++pos;

        string hash = "(" + op + left + right + ")";
        seen.insert(hash);
        return hash;
    }
    else if (isalpha(s[pos])) {
        string var(1, s[pos]);
        ++pos;
        return var;
    }
    return "";
}

int main() {
    string s;
    getline(cin, s);
    int pos = 0;
    parse(s, pos);
    cout << seen.size() << endl;
    return 0;
}
