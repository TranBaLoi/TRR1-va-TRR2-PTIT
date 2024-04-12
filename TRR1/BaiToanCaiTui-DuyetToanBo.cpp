#include<bits/stdc++.h>
using namespace std;
int n=4, x[100];
int Fopt = -1e9;
int Xopt[100];
void Try(int i)
{
	for(int j=0;j<=1;j++)
	{
		x[i]=j;
		if(i==n)
		{
			if(3*x[1] + 6*x[2] + 3*x[3] + 2*x[4] <=11)
			{
				if(6*x[1] + 8*x[2] + 5*x[3] + 2*x[4] > Fopt)
				{
					Fopt = 6*x[1] + 8*x[2] + 5*x[3] + 2*x[4];
					for(int k=1;k<=n;k++)
					{
						Xopt[k] = x[k];
					}
				}
			}
		}
		else Try(i+1);
	}
}
int main()
{
	Try(1);
	cout << Fopt << " ";
	for(int l=1;l<=n;l++)	cout << Xopt[l];
	cout <<endl;
	return 0;
}
