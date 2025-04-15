#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

typedef pair<double, double> par;

double dist(par x1, par x2)
{
  return sqrt((x1.first - x2.first) * (x1.first - x2.first) + (x1.second - x2.second) * (x1.second - x2.second));
}

double dividirPorConquistar(const vector<par> &points, int l, int r)
{
  int size = r - l;
  if (size == 2)
    return dist(points[l], points[l + 1]);
  if (size == 3)
    return min({dist(points[l], points[l + 1]), dist(points[l], points[l + 2]), dist(points[l + 1], points[l + 2])});

  int m = l + (r - l) / 2;
  double dl = dividirPorConquistar(points, l, m);
  double dr = dividirPorConquistar(points, m, r);
  double d = min(dl, dr);

  int sl = m, sr = m;
  while (sl > l && points[m].first - points[sl - 1].first < d)
    sl--;
  while (sr < r - 1 && points[sr + 1].first - points[m].first < d)
    sr++;

  vector<par> strip(points.begin() + sl, points.begin() + sr + 1);
  sort(strip.begin(), strip.end(), [](const par &a, const par &b)
       { return a.second < b.second; });

  // Comparar puntos
  for (int i = 0; i < strip.size(); i++)
  {
    for (int j = 0; j < 7; j++)
    {
      if (i + j + 1 >= strip.size())
        break;
      d = min(d, dist(strip[i], strip[i + j + 1]));
    }
  }

  return d;
}

void generateRandomPoints(vector<par> &points, int count, mt19937_64 &rng, int minCoord = 100, int maxCoord = 1100) {
  uniform_real_distribution<double> distX(minCoord, maxCoord);
  uniform_real_distribution<double> distY(minCoord, maxCoord);

  points.clear();
  points.reserve(count);
  for (int i = 0; i < count; ++i) {
      points.emplace_back(distX(rng), distY(rng));
  }
}

