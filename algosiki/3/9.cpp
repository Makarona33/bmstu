#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

class my_AV
{
private:
    char* p;
    
    int priority(char op)
    {
        if(op=='(') return 0;
        if(op=='+'||op=='-') return 1;
        if(op=='*'||op=='/') return 2;
        return 0;
    }
    
    bool isOperand(char c)
    {
        return (c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9');
    }
    
public:
    my_AV(char* s)
    {
        p = new char[strlen(s)+1];
        strcpy(p, s);
    }
    
    ~my_AV()
    {
        delete[] p;
    }
    
    void show()
    {
        cout << p << endl;
    }
    
    char* postfix()
    {
        stack<char> st;
        int len = strlen(p);
        char* result = new char[len*2+1];
        int idx = 0;
        
        for(int i=0; i<len; i++)
        {
            if(p[i]==' ') continue;
            
            if(isOperand(p[i]))
            {
                result[idx++] = p[i];
            }
            else if(p[i]=='(')
            {
                st.push(p[i]);
            }
            else if(p[i]==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    result[idx++] = st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            else if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/')
            {
                while(!st.empty() && priority(st.top())>=priority(p[i]))
                {
                    result[idx++] = st.top();
                    st.pop();
                }
                st.push(p[i]);
            }
        }
        
        while(!st.empty())
        {
            result[idx++] = st.top();
            st.pop();
        }
        
        result[idx] = '\0';
        return result;
    }
};

int main()
{
    char expr[128];
    cout << "Enter AV";
    cin.getline(expr, 128);
    
    my_AV av(expr);
    
    char* post = av.postfix();
    cout << "\n\n" << post << endl;
    
    delete[] post;
    return 0;
}
