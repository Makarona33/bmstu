#include <iostream>
#include <cstring>

using namespace std;

class my_PAV {
    private: char * p;
    
    public: my_PAV(char * s) {
        cout << "Constructor" << endl;
        p = new char[strlen(s) + 1];
        strcpy(p, s);
    }
    
    void show() { cout << p << endl; }
    
    char * postfix();
};

int main() {
    char stroke[128];
    cout << "Enter PAV" << endl;
    cin >> stroke;
    my_PAV str1(stroke);
    str1.show();
    char * result = str1.postfix();
    cout << result << endl;
    delete[] result;
    return 0;
}

char * my_PAV::postfix() {
    int len = strlen(p);
    char* stroke = new char[len + 1];
    char* temp = new char[len + 1];
    int istroka = 0, itemp = 0;

    for (int i = 0; i < len; i++) {
        if (p[i] >= 'a' && p[i] <= 'z') stroke[istroka++] = p[i];
        else if (p[i] == ')') stroke[istroka++] = temp[--itemp];
        else if (p[i] == '(') {}
        else temp[itemp++] = p[i];
    }

    while (itemp > 0) stroke[istroka++] = temp[--itemp];

    stroke[istroka] = '\0';
    delete[] temp;
    return stroke;
}
