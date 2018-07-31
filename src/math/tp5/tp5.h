#ifndef TP5_H
#define TP5_H

#include <vector>

using namespace std;

#define INF 9999

const int** longueurs =
{
  {0, 2, INF, 4, INF},
  {in, 0, 2, INF, INF},
  {INF, INF, 0, 2, INF},
  {INF, -3, INF, 0, 2},
  {2, INF, INF, INF, 0}
};

class Graphe
{
  private:
    int   nombre_sommets;
    int** distances;
    int** chemins;

  public:
    Graphe(int);

    void floyd_warshall()
};

#endif
