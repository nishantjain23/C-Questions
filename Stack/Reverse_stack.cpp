#include <iostream>
#include <stack>
using namespace std;
void pushatbottom(stack<int> &s, int val)
{
    // base case
    if (s.empty())
    {
        s.push(val);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    pushatbottom(s, val);
    s.push(num);
}
void reverseStack(stack<int> &s)
{
    if (s.empty())
        return;

    int num = s.top();
    s.pop();

    // recursive call
    reverseStack(s);
    pushatbottom(s, num);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(4);
    st.push(7);
    st.push(2);
    st.push(8);
    reverseStack(st);
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}