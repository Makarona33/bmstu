#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Instruction {
    string start_state;
    char cell_value;
    char action;
    string end_state;

    static bool comp_for_state(Instruction a, Instruction b) {
        return a.start_state < b.start_state;
    }
};

int main() {
    string filename;
    cout << "Enter filename:" << endl;
    cin >> filename;
    ifstream f(filename);

    string title, line, current_state;
    int n_cells, head, n_instructions;
    vector<char> cells;
    vector<Instruction> instructions;
    bool flag;

    f >> title;
    f >> n_cells;
    f >> line;
    for (int i = 0; i < line.size(); i++) cells.push_back(line[i]);

    f >> head >> n_instructions;
    string q, q_; char s, d;
    for (int i = 0; i < n_instructions; i++) {
        f >> q >> s >> d >> q_;
        instructions.push_back(Instruction{q, s, d, q_});
    }

    current_state = (*min_element(instructions.begin(), instructions.end(), Instruction::comp_for_state)).start_state;

    for (int i = 0; i < cells.size(); i++) cout << cells.at(i);
    cout << endl;

    flag = true;
    while (flag) {
        flag = false;
        for (auto inst : instructions) {
            if (inst.start_state != current_state) continue;
            
            if (cells.at(head - 1) != inst.cell_value) continue;

            if (inst.action == 'R') head++;
            else if (inst.action == 'L') head--;
            else cells.at(head - 1) = inst.action;

            if (head == 0) {
                cells.insert(cells.begin(), '0');
                head++;
            }
            else if (cells.size() < head) cells.push_back('0');

            // cout << "Выполнено: " << inst.start_state << ' ' << inst.cell_value << ' ' << inst.action << ' ' << inst.end_state << endl;

            current_state = inst.end_state;
            flag = true;
            break;
        }     
    }

    for (int i = 0; i < cells.size(); i++) cout << cells.at(i);
    cout << endl;

    return 0;
}
