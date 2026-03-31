#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
    a = abs(a); 
    b = abs(b);
    while (b) { 
        long long t = b; 
        b = a % b;
        a = t; 
    }
    return a;
}

struct Rational {
    long long num, den;
    Rational(long long n = 0, long long d = 1) : num(n), den(d) { 
        normalize(); 
    }
    
    void normalize() {
        if (den < 0) { num = -num; den = -den; }
        if (num == 0) { den = 1; return; }
        long long g = gcd(abs(num), den);
        num /= g; den /= g;
    }
    
    Rational operator+(const Rational& r) const {
        return Rational(num * r.den + r.num * den, den * r.den);
    }
    
    Rational operator-(const Rational& r) const {
        return Rational(num * r.den - r.num * den, den * r.den);
    }
    
    Rational operator*(const Rational& r) const {
        return Rational(num * r.num, den * r.den);
    }
    
    Rational operator/(const Rational& r) const {
        return Rational(num * r.den, den * r.num);
    }
    
    bool operator==(const Rational& r) const {
        return num == r.num && den == r.den;
    }
    
    bool operator!=(const Rational& r) const {
        return !(*this == r);
    }
    
    void print() const {
        if (den == 1) cout << num;
        else cout << num << '/' << den;
    }
};

int main() {
    int n, x;
    cin >> n;
    vector<vector<Rational>> a(n, vector<Rational>(n + 1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j) {
            cin >> x;
            a[i][j] = Rational(x);
        }

    for (int i = 0; i < n; ++i) {
        int pivot = i;
        while (pivot < n && a[pivot][i] == Rational(0)) ++pivot;
        if (pivot == n) continue;
        if (pivot != i) swap(a[i], a[pivot]);
    
        Rational divisor = a[i][i];
        for (int j = i; j <= n; ++j)
            a[i][j] = a[i][j] / divisor;
    
        for (int k = i + 1; k < n; ++k) {
            Rational factor = a[k][i];
            for (int j = i; j <= n; ++j)
                a[k][j] = a[k][j] - factor * a [i][j];
        }
    }
    
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            Rational factor = a[j][i];
            for (int k = i; k <= n; ++k)
                a[j][k] = a[j][k] - factor * a[i][k];
        }
    }

    for (int i = 0; i < n; ++i) {
        bool all_zeros = true;
        
        for (int j = 0; j < n; ++j)
            if (a[i][j] != Rational(0)) { 
                all_zeros = false; 
                break; 
            }
            
        if (all_zeros && a[i][n] != Rational(0)) {
            cout << "No solution" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        a[i][n].print();
    }
    cout << endl;

    return 0;
}
