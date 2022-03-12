/*
    #include <queue>

    queue<int> Q;

    Q.empty() -> 1 (true) coada goala / 0 (false) coada nu e goala
    Q.push() -> adauga in coada elemente
    Q.front() -> returneaza prima valoare din coada (primul adaugat - primul scos)
    Q.pop() -> sterge primul element din coada

    pair<int, int> P;

    P.first = val; -> prima valoare din pair
    P.second = val; -> a doua valoare din pair

    ! queue< pair<int, int> > Q;

    Q.push(make_pair(i_start,j_start)) -> adaugam in coada cele doua pozitii
    a[1001][1001] -> matricea principala
    b[1001][1001] -> matricea secundara menita sa numere pozitiile

*/

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("roboti.in");
ofstream fout("roboti.out");

int n, m, a[1001][1001], b[1001][1001];
short int rbi, rbj, rfi, rfj;

// int dx[] = {1, 0, -1, 0};
// int dy[] = {0, 1, 0, -1};

//         {S, N, V, E}

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool inmat(int i, int j) // daca suntem in matrice sau nu
{
    return i >= 1 && j >= 1 && i <= n && j <= m;
}

void aLee(int is, int js)
{
    queue<pair<int, int> > Q;
    // initializare coada

    Q.push(make_pair(is, js));
    // marcare pozitie de start

    b[is][js] = 1;
    // plecam de la valoarea 1 - distanta este b[is][js] -= 1;

    while (!Q.empty()) // cat timp coada nu este goala
    {
        pair<int, int> P = Q.front();
        int x = P.first;
        int y = P.second;
        for (int d = 0; d <= 3; ++d)
        {
            int inou = dx[d] + x;
            int jnou = dy[d] + y;
            if (inmat(inou, jnou) && a[inou][jnou] == 0 && b[inou][jnou] == 0)
            {
                b[inou][jnou] = b[x][y] + 1;
                Q.push(make_pair(inou, jnou));
            }
        }
        Q.pop();
    }
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> a[i][j];
    fin >> rbi >> rbj;
    fin >> rfi >> rfj;
    aLee(rbi, rbj);
    fout << b[rfi][rfj] - 1;
    return 0;
}
