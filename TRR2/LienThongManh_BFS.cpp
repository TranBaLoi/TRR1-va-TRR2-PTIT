#include<bits/stdc++.h>
using namespace std;

int n, a[100][100], chuaxet[100];
void reinit()
{
    for(int i = 0; i < n; i++)  chuaxet[i] = 0;
}

void BFS(int u)
{
    queue<int> hd;
    hd.push(u);
    chuaxet[u] = 1;
    while (!hd.empty())
    {
        int s = hd.front();
        hd.pop();
        for(int i = 0; i < n; i++)
        {
            if(a[s][i] == 1 && chuaxet[i] == 0)
            {
                hd.push(i);
                chuaxet[i] = 1;
            }
        }
    }
}

bool Strongly_Connected()
{
    reinit();
    for(int i = 0; i < n; i++)
    {
        BFS(i);
        for(int j = 0; j < n; j++)
        {
            if(chuaxet[j] == 0) return false;
        }
        reinit();
    }
    return true;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    if(Strongly_Connected()) cout << "YES";
    else cout << "NO";
    return 0;
}