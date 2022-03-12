#include <iostream>
using namespace std;

int a[100000], b[100000];

void mergeSort(int st, int dr)
{
    if (st < dr)
    {
        int mij = (st + dr) / 2;
        mergeSort(st, mij);
        mergeSort(mij + 1, dr);
        int ind1 = st;
        int ind2 = mij + 1;
        int ind0 = 0;
        while (ind1 <= mij && ind2 <= dr)
        {
            if (a[ind1] <= a[ind2])
                b[++ind0] = a[ind1++];
            else
                b[++ind0] = a[ind2++];
        }
        while (ind1 <= mij)
            b[++ind0] = a[ind1++];
        while (ind2 <= dr)
            b[++ind0] = a[ind2++];
        for (int i = st; i <= dr; ++i)
            a[i] = b[i - st + 1];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    mergeSort(1, n);
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    return 0;
}
