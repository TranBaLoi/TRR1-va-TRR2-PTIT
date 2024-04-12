#include<bits/stdc++.h>
using namespace std;

    // 9
    // 0 1 1 0 1 0 0 0 0
    // 1 0 1 1 0 0 0 0 0
    // 1 1 0 1 1 0 0 0 1
    // 0 1 1 0 0 0 0 1 1
    // 1 0 1 0 0 1 0 0 0
    // 0 0 0 0 1 0 1 0 1
    // 0 0 0 0 0 1 0 1 1
    // 0 0 0 1 0 0 1 0 1
    // 0 0 1 1 0 1 1 1 0 

//  9 
// 1 2
// 1 3
// 1 5
// 2 3
// 2 4
// 3 4
// 3 5
// 3 9
// 4 8
// 4 9
// 5 6
// 6 7
// 6 9
// 7 8
// 7 9
// 8 9

// Ke(1) = 2 3 5 
// Ke(2) = 1 3 4 
// Ke(3) = 1 2 4 5 9 
// Ke(4) = 2 3 8 9 
// Ke(5) = 1 3 6 
// Ke(6) = 5 7 9 
// Ke(7) = 6 8 9 
// Ke(8) = 4 7 9 
// Ke(9) = 3 4 6 7 8 


int vs[100][100] = {0};
int n;
void reset()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)      vs[i][j] = 0;
    }
}

int cnt = 0;
void chuyendoiDSC(int a[][100], int n)
{

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(vs[i][j] == 0)
            {
                if(a[i][j] != 0)
                {
                    vs[i][j] = vs[j][i] = 1;
                    cnt++;
                    cout << i << " " << j << endl;
                }
            }
        }
    }
}
void chuyendoiDSK(int a[][100], int n)
{

    for(int i=1; i<=n; i++)
    {
         cout << "Ke(" << i << ") = " ;
        for(int j=1; j<=n; j++)
        {
          
            if(a[i][j] != 0)
            {

                cout << j << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    int a[100][100];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }
    cout << n << " "  << endl;
    chuyendoiDSC(a, n);
    chuyendoiDSK(a, n);

    return 0;
}