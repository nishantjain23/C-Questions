#include <iostream>
#include <stack>
using namespace std;
void sortinsert(stack<int> &st, int num)
{
    // base case
    if (st.empty() || (!st.empty() && st.top() < num))
    {
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();

    // recursice call
    sortinsert(st, num);
    st.push(n);
}
void sort(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int num = st.top();
    st.pop();

    // recursive call
    sort(st);
    sortinsert(st, num);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(41);
    st.push(7);
    st.push(22);
    st.push(8);
    sort(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}