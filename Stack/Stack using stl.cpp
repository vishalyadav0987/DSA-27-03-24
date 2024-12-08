#include<iostream>
#include<stack>
using namespace std;



int main(){
    // creation of stack
    stack<int> s;

    s.push(4);
    s.push(2);
    s.push(3);
    s.push(1);

    s.pop();

    cout<<s.empty();
}