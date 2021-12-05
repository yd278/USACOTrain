#include <iostream>
#include <stack>
using namespace std;
int isNum(char c){
    return c <= '9' && c >= '0';
}
stack<int> stk;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("1449.in","r",stdin);
        freopen("1449.out","w",stdout);
    #endif
    string s;
    cin>>s;
    int parse = 0;
    for(char x : s){
        if(isNum(x)){
            parse = parse * 10 + x-'0';
        }
        if(x=='.'){
            stk.push(parse);
            parse = 0;
        }
        if(x=='+'){
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            int c = a + b;
            stk.push(c);
        }
        if(x=='-'){
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            int c = b-a;
            stk.push(c);

        }
        if(x=='*'){
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            int c = b*a;
            stk.push(c);

        }
        if(x=='/'){
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            int c = b/a;
            stk.push(c);

        }
        if(x=='@'){
            cout<<stk.top()<<endl;
            return 0;
        }
    }
    return 0;   
}