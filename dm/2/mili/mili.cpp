#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Rules {
    string from;
    string to;
};

struct Func {
    string start_state;
    string value;
    string end_state;
    string out;
};

bool check(string expression, string current_state, vector<Func> func, vector<string> final_states) {
    string cur_state = current_state;

    for (int i = 0; i < expression.size(); i++) {
        bool flag = false;
        for (auto c : func) {
            if (c.start_state != cur_state) continue;
            if (c.value == "digit" && !isdigit(expression[i])) continue;
            else if (c.value == "alpha" && !isalpha(expression[i])) continue;
            else if (c.value.size() == 1 && tolower(c.value[0]) != tolower(expression[i])) continue;
            
            cur_state = c.end_state;
            flag = true;
            break;
        }
        if (!flag) return 0;
    }

    if (count(final_states.begin(), final_states.end(), cur_state) == 0) return 0;
    return 1;
}

int main() {
    string filename = ".txt";
    string test_filename = ".txt";
    ifstream f(filename), test_f(test_filename);
    string S, I, line, word;
    vector<string> N, T, V, Q, F, test;
    vector<Rules> P;
    vector<Func> dl;

    getline(f, line);
    istringstream n_s(line);
    while (n_s >> word) N.push_back(word);

    getline(f, line);
    istringstream t_s(line);
    while (t_s >> word) T.push_back(word);

    getline(f, S);

    while (getline(f, line)) {
        if (line.length() <= 1) break;
        istringstream r_s(line);
        string s1, s2;
        r_s >> s1 >> s2;
        P.push_back(Rules{s1, s2});
    }

    getline(f, line);
    istringstream v_s(line);
    while (v_s >> word) V.push_back(word);

    getline(f, line);
    istringstream q_s(line);
    while (q_s >> word) Q.push_back(word);

    getline(f, line);
    istringstream F_s(line);
    while (F_s >> word) F.push_back(word);

    getline(f, I);

    while (getline(f, line)) {
        istringstream tf_s(line);
        string s1, s2, s3, s4;
        tf_s >> s1 >> s2 >> s3 >> s4;
        dl.push_back(Func{s1, s2, s3, s4});
    }

    while (getline(test_f, line)) test.push_back(line);
    
    string cur_state = I;
    
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " - " << (check(test[i], I, dl, F) ? "Access" : "Error") << endl;
    }

    return 0;
}