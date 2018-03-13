// SaeedReza AlipourFard
// 9412032
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

const int MAX = 100 * 100;
int adjac[MAX][MAX]; // checking that is an edge between i and j vertices
int weight[MAX][MAX]; // weight of edges
vector < int > finished;
int wPath[MAX] ,mark[MAX];

void Dijkstra (int v) // v is number of all vertices !!
{
    for (int i = 0; i <= v; i++) // distance between vertex number 1 to other INF
        wPath [i] = INT_MAX;
    // wPath[0] is junk for checking minimum of distances
    wPath[1] = 0;
    mark[1] = 1;
    int last;
    while (finished.size () != v) // checking all vertices is in finished or not
    {
        last = finished.back();
        for (int thisV = 2; thisV <= v; thisV ++)
            if (!mark[thisV] && adjac[last][thisV]) // checking that vertex was not in the finished and edges
            {
                int check = wPath[last] + weight[last][thisV];
                wPath[thisV] = (wPath[thisV] > check ? check : wPath[thisV]);
            }
        int minV = 0;
        for (int i = 2; i <= v; i++)
            if (!mark[i])
                minV = (wPath[i] < wPath[minV] ? i : minV);
        finished.push_back (minV); // minV should push to finished
        mark[minV] = 1; // minV pushed to finished
    }
}

int main ()
{
    // all of matrices is one base
    // it means that we don't use index = 0
    int n ,e;
    cout << " Enter a number for vertices " << endl;
    cin >> n;
    cout << " Enter a number for edges " << endl;
    cin >> e;
    cout << "now enter edge vertex#1 and vertex#2 and weight between vertices !" << endl;
    for (int i = 0;  i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adjac[a][b] = adjac[b][a] = 1;
        weight[a][b] = weight[b][a] = w;
    }

    // Dijkstra !!
    finished.push_back (1); // Preparation for Dijkstra !
    Dijkstra (n);

    cout << endl << "Distance of vertex number 1 to others is ---->" << endl;
    for (int i = 1; i <= n; i++)
        cout << "Distance to vertex #" << i << " is ---> " << wPath[i] << endl;

    return 0;
}
