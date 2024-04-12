#include<bits/stdc++.h>
using namespace std;
int n,a[100][100];
bool chuaxet[100];
void readdata()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
}
void init()
{
    for(int i=1;i<=n;i++){
        chuaxet[i]=true;
    }
        
}
void dequydfs(int u)
{   //Xet dinh u
    chuaxet[u]=false;       //Danh dau da xet dinh u
    for(int v=1;v<=n;v++)   //Duyet cac dinh ke voi dinh u
    {
        if(a[u][v]==1 && chuaxet[v]==true){
            dequydfs(v);
        }
    }
}
bool check()
{
   for(int i=1;i<=n;i++)
        if(chuaxet[i]==true)
            return false;
    return true;
}
void dinhtru()
{
    init();
    for(int u=1;u<=n;u++)
    {
        chuaxet[u]=false;
        if(u==1)
            dequydfs(2);
        else dequydfs(1);
        if(check()==false)
            cout<<u<<" ";
        init();
    }
}
int main()
{
    readdata();
    dinhtru();
}