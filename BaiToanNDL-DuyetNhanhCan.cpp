#include<bits/stdc++.h>
using namespace std;
int n, c[100][100], Fopt=0, Xopt[100], vs[100]={0},x[100]={0}; 
int g[100]={0}, gt[100]={0}, C_min=1e9;
void Min_Fopt() // phuong phap tham lam
{
	set<int> s;
	int i=1,k=2, tmp;
	s.insert(i);
	Xopt[1] = i;
	while(i<=n && i>0 && k<=n)
	{
		int min = 1e9;
		for(int j=1;j<=n;j++)
		{
			if(c[i][j] < min && s.count(j) == 0)
			{
				min = c[i][j];
				tmp = j; // tim thanh pho tiep theo can den
			}
		}
		i = tmp;
		s.insert(i);
		Xopt[k]=i;
		k++;
	}
	for(int j =1 ;j<n;j++)	Fopt += c[Xopt[j]][Xopt[j+1]];
	Fopt += c[Xopt[n]][Xopt[1]];
}
void Travel_expenses(int m)
{
	if(m>n && g[m-1]< Fopt)
	{
		Fopt = gt[m-1] + c[x[m-1]][1];
		for(int i=1;i<=n;i++)
		{
			Xopt[i] = x[i];
		}
		return;
	}
	for(int i=2;i<=n;i++)
	{ 
		if(vs[i]==0)
		{
			x[m]=i;
			vs[i]=1;
			gt[m] = gt[m-1] + c[x[m-1]][x[m]]; 
			g[m] = gt[m] + C_min*(n-m+1);
			if(g[m] >= Fopt) 
			{
				vs[i]=0;
				continue;
			}
			Travel_expenses(m+1);
			vs[i]=0;
		}
	}
}
int main()
{
	cin >> n; //so thanh pho
	for(int i=1;i<=n;i++) // ma tran tri phi
	{
		for(int j=1;j<=n;j++)
		{
			cin >> c[i][j];
			if(c[i][j] < C_min && i != j)	C_min = c[i][j];
		}
	}
	x[1]=1;
	vs[1]=1;
	Min_Fopt();
	Travel_expenses(2);
	cout << Fopt << " ";
	for(int i=1;i<=n;i++)	cout << Xopt[i];
}
