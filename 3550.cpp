#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("liceu.in");
ofstream fout("liceu.out");

int inou, jnou;
#define na a[inou][jnou]
#define nb b[inou][jnou]

const int NMAX = 401;

short int n, z, s, t[1];
short int zi, zj, si[1], sj[1], ti, tj, mi, mj;
short int k; // contor
int a[NMAX][NMAX], b[NMAX][NMAX];

//         {S, N, V, E}

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void citire()
{
    fin >> n >> z >> s >> t[0]; // citim prima linie
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = 0; // initializam toata matricea pe valoarea 0

    for (int i = 1; i <= z; ++i)
        for (int j = 1; j <= 2; ++j)
        {
            fin >> zi >> zj; // citim coordonatele zidurilor
            a[zi][zj] = 3;   // setam zidurile pe valoarea 3
        }
    for (int i = 1; i <= s; ++i, k = 0)
        for (int j = 1; j <= 2; ++j)
        {
            fin >> si[++k] >> sj[++k]; // citim coordonatele scurtaturilor

            if (k == 1)
                a[si[++k]][sj[++k]] = 1; // setam prima scurtatura pe valoarea 1
            else
                a[si[++k]][sj[++k]] = 2; // setam a doua scurtatura pe valoarea 2
        }

    fin >> mi >> mj; // citim coordonatele magazinului
}

bool inmat(int i, int j) // daca suntem in matrice sau nu
{
    return i >= 1 && j >= 1 && i <= n && j <= n;
}

void aLee(int is, int js)
{
    queue<pair<int, int> > Q;
    // initializare coada

    Q.push(make_pair(is, js));
    // marcare pozitie de start

    b[is][js] = 1;
    // plecam de la valoarea 1 - distanta este b[is][js] -= 1;

    while (!Q.empty()) // cat timp coada nu este parcursa
    {
        pair<int, int> P = Q.front();
        int x = P.first;
        int y = P.second;
        for (int d = 0; d <= 3; ++d)
        {
            inou = dx[d] + x;
            jnou = dy[d] + y;
            if (inmat(inou, jnou) && (na == nb == 1 || na == nb == 2))
            {

                b[si[na]][sj[na]] = b[x][y] + 1;
                Q.push(make_pair(si[na], si[na]));
                t[1]++;
            }
            else if (inmat(inou, jnou) && na == nb == 0)
            {
                b[inou][jnou] = b[x][y] + 1;
                Q.push(make_pair(inou, jnou));
                t[1]++;
            }
        }
        Q.pop();
    }
}

int main()
{
    citire();
    aLee(1, 1);          // pozitia de start este i = 1 / j = 1
    fout << b[n][n] - 1; // distanta pana la clasa
    return 0;
}
