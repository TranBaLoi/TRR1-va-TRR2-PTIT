#include<bits/stdc++.h>
using namespace std;

int chuaxet[100] = {0}, truoc[100];
int n, a[100][100], s, t;
void DFS(int u)
{
    stack<int> st;
    st.push(u);
    chuaxet[u] = 1;
    while (!st.empty())
    {
        int s = st.top();
        st.pop();
        for(int t = 0; t < n; t++)
        {
            if(a[s][t] == 1 && chuaxet[t] == 0)
            {
                st.push(s);
                st.push(t);
                truoc[t] = s;
                chuaxet[t] = 1;
                break;
            }
        }
    }
    
}

int main()
{
    cin >> n >> s >> t;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    DFS(s);
    if(truoc[t] == 0)   cout << "No path";
    else{
        cout << t << " ";
        int u = truoc[t];
        while(u != s)
        {
            cout << u << " ";
            u = truoc[u];
        }
        cout << s ;
    }
    return 0;
}