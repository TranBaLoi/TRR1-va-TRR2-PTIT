#include<bits/stdc++.h>
using namespace std;
int n,u,a[100][100],X[100]={0};
bool chuaxet[100];
void readdata()
{
    cin>>n>>u;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
}
void init()
{
    for(int i=1;i<=n;i++)
        chuaxet[i]=true;
    chuaxet[u]=false;
    X[1]=u;
}
void Halmington_Circuit(int u)
{
    for(int y=1;y<=n;y++)
    {
        if(a[X[u-1]][y]==1)
        {
            if(u==n+1 && y==X[1])
            {
                for(int i=1;i<=n;i++)
                    cout<<X[i]<<" ";
                cout<<X[1]<<endl;
            }
            else
            {
                if(chuaxet[y]==true)
                {
                    X[u]=y;
                    chuaxet[y]=false;
                    Halmington_Circuit(u+1);
                    chuaxet[y]=true;
                }
            }
        }
    }
}
int main()
{
    readdata();
    init();
    Halmington_Circuit(2);
}