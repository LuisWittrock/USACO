#include <iostream>
#include <math.h>
#include <vector>

#define ll long long

using namespace std;

const ll MAX_INT = 1e15;
const int MAX_N = 5e2+1;

ll graph[MAX_N][MAX_N];

ll n,m,q;

int main()
{
    cin >> n >> m >> q;

    for(int i = 1; i<=n; i++)   //Making every edge between two nodes weigth to the max value.
    {
        for(int j = 1; j<=n; j++)
        {
            graph[i][j] = MAX_INT;
            graph[j][i] = MAX_INT;
        }
    }
    for(int i = 1; i<=n; i++) graph[i][i] = 0; //from any node to the same node weight is one.
    ll a, b, w;
    for(int i = 0; i<m; i++)    //adding the weigth given by the input between node a and b with weigth w.
    {
        cin >> a >> b >> w;
        graph[a][b] = min(graph[a][b], w);
        graph[b][a] = min(graph[b][a], w);
    }

    for(int relax = 1; relax <= n; relax++)
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][relax]+graph[relax][j]);    //Floyd-Warshall Algorithm where we try to find a shorter way by going over another node k to the destination node.
            }
        }
    }

    for(int i = 0; i<q; i++)
    {
        cin >> a >> b;
        if(graph[a][b] == MAX_INT)  //if the weight hasnt changed from the max value there is no possible path so -1
        {
            cout << -1 << endl;
            continue;
        }
        cout << graph[a][b] << endl;    //otherwise print the value listed in the 2D-Matrix

    }
}