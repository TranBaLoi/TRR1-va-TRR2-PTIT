#include <bits/stdc++.h>
using namespace std;
struct dt
{
    int ts;
    int I;
    int J;
};
int b[50][50];
int n, h = 0;
vector<dt> vt;
bool xet(dt x, dt y)
{
    if (x.ts != y.ts)
        return x.ts < y.ts;
    if (x.I != y.I)
        return x.I < y.I;
    return x.J < y.J;
}
void in()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> b[i][j];
            if (b[i][j] != 0 && j > i)
            {
                struct dt trso;
                trso.ts = b[i][j];
                trso.I = i;
                trso.J = j;
                vt.push_back(trso);
            }
        }
    }
    sort(vt.begin(), vt.end(), xet);
    // for(int i=0;i<vt.size();i++)
    // {
    //     cout<<vt[i].I<<" "<<vt[i].J<<" "<<vt[i].ts<<endl;
    // }
}
int kt(int t, int t1)
{
    for (int i = 0; i < t1; i++)
    {
        if (t == vt[i].J)
            return 0;
    }
    return 1;
}
void Kruskal()
{
    int t = 0;
    vector<int> vec;
    for (int i = 0; i < vt.size(); i++)
    {
        if (kt(vt[i].J, i))
        {
            vec.push_back(vt[i].I);
            vec.push_back(vt[i].J);
            h = h + vt[i].ts;
            t++;
        }
        if (t == n - 1)
            break;
    }
    cout << "dH = " << h << endl;
    for (int i = 0; i < vec.size(); i = i + 2)
    {
        cout << vec[i] << " " << vec[i + 1] << endl;
    }
}
int main()
{
    in();
    Kruskal();
}