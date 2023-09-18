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
int main()
{
    stack<int> st;
    st.push(1);
    st.push(4);
    st.push(7);
    st.push(2);
    st.push(8);
    int val, cnt = 0;
    cout << "Enter the number to push: ";
    cin >> val;
    pushatbottom(st, val);
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}