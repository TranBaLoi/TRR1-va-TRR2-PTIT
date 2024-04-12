#include<bits/stdc++.h>
using namespace std;

int n;
int a[100][100];
bool chuaxet[100];
void readdata()
{
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)   cin >> a[i][j];
    }
}

void init()
{
    for(int i=1; i<=n; i++) chuaxet[i] = false;
}

void dfs(int u)
{
    chuaxet[u] = true;
    for(int i = 1; i<=n; i++)
    {
        if(!chuaxet[i] && a[u][i] == 1) dfs(i);
    }
}

void connected()
{
    int cnt = 0;
    init();
    for(int i = 1; i<=n; i++)
    {
        if(!chuaxet[i])
        {
            ++cnt;
            dfs(i);
        }
        if(cnt > 1) 
        {
            cout << "Do thi khong lien thong";
            return;
        }
    }
    if(cnt == 1)    cout << "Do thi lien thong";
}

int main()
{
    cin >> n;
    readdata();
    connected();
    return 0;
}