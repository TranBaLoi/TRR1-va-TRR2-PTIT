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
    queue<int> hd;
    hd.push(u);
    chuaxet[u] = 1;
    while (!hd.empty())
    {
        int s = hd.front();   
        hd.pop();
        cout << s << " ";
        for(int t = 1; t <= n; t++)
        {
            if(a[s][t] == 1 && chuaxet[t] == 0)
            {
                hd.push(t);
                chuaxet[t] = 1;
            }
        }
    }
    return 0;
    
}