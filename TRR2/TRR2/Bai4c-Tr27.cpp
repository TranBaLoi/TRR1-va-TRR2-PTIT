#include<bits/stdc++.h>
using namespace std;

int a[100][100] = {0}, vs[100][100] = {0};
int n;

vector<int> v[100];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    string s;
    int k = 0;
    while(getline(cin, s))
    {
        stringstream ss(s);
        string tmp;
        v[k].push_back(199);
        while(ss >> tmp)
        {
            v[k].push_back(stoi(tmp));
        }
        k++;
    }
    cout << "Ma Tran Ke:" << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j = 1; j<v[i].size(); j++)  a[i][v[i][j]] = 1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j = 1; j<=n; j++)  cout << a[i][j] << " ";
        cout << endl;
    }
    cout << "Danh Sach Canh :" << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j =1; j<=n; j++)  
        {
            if(vs[i][j] == 0 && a[i][j] == 1)
            {
                vs[i][j] = vs[j][i] = 1;
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}