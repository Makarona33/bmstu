#include <iostream>
#include <cstring>
using namespace std;

const int n = 6;
const char* U[n] = {"zero", "one", "two", "three", "four", "five"};

class Set {
private:
    int shk[n];
    
public:
    Set() {
        for(int i = 0; i < n; i++) shk[i] = 0;
    }
    
    void add_member(int t) {
        if(t >= 0 && t < n) shk[t] = 1;
    }
    
    void del_member(int t) {
        if(t >= 0 && t < n) shk[t] = 0;
    }
    
    bool is_member(int t) {
        if(t >= 0 && t < n) return shk[t] == 1;
        return false;
    }
    
    bool is_empty() {
        for(int i = 0; i < n; i++) 
            if(shk[i]) return false;
        return true;
    }
    
    Set union_of(Set& s1) {
        Set s3;
        for(int i = 0; i < n; i++) {
            if(shk[i] == 1 || s1.shk[i] == 1) s3.shk[i] = 1;
        }
        return s3;
    }
    
    Set intersection(Set& s1) {
        Set s3;
        for(int i = 0; i < n; i++) {
            if(shk[i] == 1 && s1.shk[i] == 1) s3.shk[i] = 1;
        }
        return s3;
    }
    
    Set difference(Set& s1) {
        Set s3;
        for(int i = 0; i < n; i++) {
            if(shk[i] == 1 && s1.shk[i] == 0) s3.shk[i] = 1;
        }
        return s3;
    }
    
    void print() {
        cout << "{";
        bool first = true;
        for(int i = 0; i < n; i++) {
            if(shk[i]) {
                if(!first) cout << ", ";
                cout << U[i];
                first = false;
            }
        }
        cout << "}";
    }
};

int member_of_universum(char* x) {
    for(int i = 0; i < n; i++) {
        if(strcmp(x, U[i]) == 0) return i;
    }
    return -1;
}

void show_u() {
    cout << "{";
    for(int i = 0; i < n; i++) {
        cout << U[i];
        if(i < n-1) cout << ", ";
    }
    cout << "}" << endl;
}

int main() {
    show_u();
    
    Set A, B;
    
    cout << "\n1. Создание множеств А и В" << endl;
    
    A.add_member(member_of_universum("two"));
    A.add_member(member_of_universum("three"));
    A.add_member(member_of_universum("four"));
    
    B.add_member(member_of_universum("one"));
    B.add_member(member_of_universum("three"));
    B.add_member(member_of_universum("five"));
    
    cout << "A = "; A.print(); cout << endl;
    cout << "B = "; B.print(); cout << endl;
    
    cout << "\n2. Принадлежит?" << endl;
    cout << "'three' в A: " << (A.is_member(member_of_universum("three")) ? "да" : "нет") << endl;
    cout << "'one' в A: " << (A.is_member(member_of_universum("one")) ? "да" : "нет") << endl;
    
    cout << "\n3. A пусто?: " << (A.is_empty() ? "да" : "нет") << endl;
    
    cout << "\n4. Объединение" << endl;
    Set C = A.union_of(B);
    cout << "A ∪ B = "; C.print(); cout << endl;
    
    cout << "\n5. Пересечение" << endl;
    Set D = A.intersection(B);
    cout << "A ∩ B = "; D.print(); cout << endl;
    
    cout << "\n6. Разность" << endl;
    Set E = A.difference(B);
    cout << "A \\ B = "; E.print(); cout << endl;
    
    cout << "\n7. Исключить 'three' из A" << endl;
    A.del_member(member_of_universum("three"));
    cout << "A = "; A.print(); cout << endl;
    
    return 0;
}
