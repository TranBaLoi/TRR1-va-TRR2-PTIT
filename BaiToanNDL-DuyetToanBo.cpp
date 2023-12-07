#include<bits/stdc++.h>
using namespace std;
int n, x[100], vs[100],Fopt = 1e9, Xopt[100];
int c[100][100];
void Try(int m)
{
	if(m>n)
	{
		int fx = 0;
		for(int i=1;i<=n;i++)
		{
			if(i!=n)
			{
				fx += c[x[i]][x[i+1]];
			}
			else 
			{
				fx += c[x[i]][x[1]];
			}
		}
		if(fx < Fopt)
		{
			Fopt = fx;
			for(int i=1;i<=n;i++)
			{
				Xopt[i] = x[i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vs[i]==0)
		{
			x[m] = i;
			vs[i] = 1;
			Try(m+1);
			vs[i] = 0;
		}
		
	}
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		vs[i] = 0;
		for(int j=1;j<=n;j++)	cin >> c[i][j];
	}
	Try(1);
	cout << Fopt << endl;
	for(int i=1;i<=n;i++)	cout << Xopt[i];
	return 0;
}
