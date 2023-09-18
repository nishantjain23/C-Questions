#include <iostream>
#include <stack>
using namespace std;
void deletemiddle(stack<int>&s, int cnt, int n)
{
    // base call
    if (cnt == n / 2)
    {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    deletemiddle(s, cnt + 1, n);
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
    int cnt = 0;
    int n = st.size();
    deletemiddle(st, cnt, n);
    while (!st.empty())
    {
        cout << st.top() <<endl;
        st.pop();
    }
}