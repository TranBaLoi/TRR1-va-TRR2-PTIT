#include<bits/stdc++.h>
using namespace std;
// 4 8 5 3 10 6 3 2 5 4
int c[100]={0}, a[100]={0}, b[100], n, gt[100]; // Khai bao du lieu
double d[100], g[100];
int Fopt = -1e9, Xopt[100], x[100];
void Sort_Descending()
{
	// ham sap sap lai thu tu c/a;
	for(int i=1;i<=n;i++)
	{
		d[i] = (double) c[i]/a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(d[j] > d[i])
			{
				swap(d[j],d[i]);
				swap(a[j],a[i]);
				swap(c[j],c[i]);
			}
		}
	}
}
void Solution(int m)
{
	for(int i=1;i>=0;i--)
	{
		x[m] = i;
		b[m] = b[m-1] - a[m]*x[m];
		gt[m] = gt[m-1] + c[m]*x[m];
		g[m] = (double) gt[m] + b[m]*((double)c[m+1]/a[m+1]);
		if(m==n)	g[m] = g[m-1];
		if(b[m] < 0 || g[m] < Fopt)
		{
			continue;
		}
		if(m==n)
		{
			if(gt[m] > Fopt)
			{
				Fopt = gt[m];
				for(int j=1; j<=m; j++)
				{
					Xopt[j] = x[j];
				}
			}
		}
		else Solution(m+1);
		
	}
}
int main()
{
	cin >> n; // nhap so luong do vat;
	cin >> b[0]; // nhap khoi luong tui;
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	Sort_Descending();
	Solution(1);
	cout << Fopt << " ";
	for(int i=1;i<=n;i++)	cout << Xopt[i];
}
