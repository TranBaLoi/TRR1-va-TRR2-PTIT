#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[n][n];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    int u;  cin >> u;
    int chuaxet[100] = {0};
    stack<int> st;
    st.push(u);
    cout << u << " ";
    chuaxet[u] = 1;
    while (!st.empty())
    {
        int s = st.top();   
        st.pop();
        for(int t = 1; t <= n; t++)
        {
            if(a[s][t] == 1 && chuaxet[t] == 0)
            {
                st.push(s);
                st.push(t);
                cout << t << " ";
                chuaxet[t] = 1;
                break;
            }
        }
    }
    return 0;
    
}