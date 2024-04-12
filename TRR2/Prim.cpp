#include <bits/stdc++.h>
using namespace std;
int v,s;
int a[100][100];
bool chuaxet[100];
vector<int> VH[100];
void prim()
{
    chuaxet[s]=false;
    int vt[v]={s};
    int dh=0,idx=1;
    while(idx!=v)
    {
        int minn=INT_MAX,y,k;
        for(int i=0;i<idx;i++)
        {
            int x=vt[i];
            for(int j=0;j<v;j++)
            {
                if(chuaxet[j] && a[x][j]<minn && x!=j && a[x][j]!=0)
                {
                    minn=a[x][j];
                    y=j;
                    k=x;
                }
            }
        }
        vt[idx++]=y;
        sort(vt,vt+idx);
        VH[k+1].push_back(y+1);
        chuaxet[y]=false;
        dh+=minn;
    }
    cout<<"dH = "<<dh<<endl;
    for(int i=1;i<=v;i++)
        for(int j=0;j<VH[i].size();j++)
            cout<<i<<" "<<VH[i][j]<<endl;
}
int main()
{
    memset(chuaxet,true,sizeof(chuaxet));
    cin>>v;
    cin>>s;
    s-=1;
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            cin>>a[i][j];
    prim();   
}