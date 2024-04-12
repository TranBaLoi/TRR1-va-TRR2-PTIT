#include<bits/stdc++.h>
using namespace std;

int chuaxet[100] = {0};
int n, a[100][100];
void DFS(int u)
{
    stack<int> st;
    st.push(u);
    cout << u << " ";
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
                cout << t << " ";
                chuaxet[t] = 1;
                break;
            }
        }
    }
    
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    int soTPLT = 0;
    for(int u = 0; u < n; u++)
    {
        if(chuaxet[u] == 0)
        {
            soTPLT++;
            DFS(u);
            cout << endl;
        }
    }
    cout << "so TPLT: " << soTPLT;
    return 0;
}