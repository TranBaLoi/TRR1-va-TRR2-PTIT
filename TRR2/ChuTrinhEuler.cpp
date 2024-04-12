#include<bits/stdc++.h>
using namespace std;

int n;
int a[100][100];

void readdata()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
}

void euler(int u)
{
    stack<int> st, CE;
    st.push(u);
    while(!st.empty())
    {
        int s = st.top();
        bool flag = false;
        for(int i = 1; i <= n; i++)
        {
            if(a[s][i] == 1)
            {
                flag = true;
                st.push(i);
                a[s][i] = 0;
                a[i][s] = 0;
                break;
            }
        } 
        if(!flag)   
        {
            CE.push(s);
            st.pop();
        }
    }
    while (!CE.empty())
    {
        cout << CE.top() << " ";
        CE.pop();
    }
    
}

int main()
{
    int u;
    cin >> n >> u;
    readdata();
    euler(u);
}