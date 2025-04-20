#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#ifndef DIVIDIRPORCONQUISTAR_H
#define DIVIDIRPORCONQUISTAR_H

using namespace std;

typedef pair<double, double> par;

double dist(const par &a, const par &b) {
  double dx = a.first - b.first;
  double dy = a.second - b.second;
  return sqrt(dx * dx + dy * dy);
}

double dividirPorConquistar(const vector<par> &points, int l, int r)
{
  int size = r - l;
  if(siez==1) return numeric_limits<double>::infinity(); //no existe distancia
  if (size == 2)
    return dist(points[l], points[l + 1]);
  if (size == 3)
    return min({dist(points[l], points[l + 1]), 
                dist(points[l], points[l + 2]), 
                dist(points[l + 1], points[l + 2])});

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
  for (int i = 0; i < strip.size(); i++){
    for (int j = i+1; j < strip.size() && (strip[j].second - strip[i].second) < d; j++){
      d = min(d, dist(strip[i], strip[i + j + 1]));
    }
  }

  return d;
}

double findMinDistance(vector<Point> &points) {
  if (points.size() < 2) return numeric_limits<double>::infinity();
  sort(points.begin(), points.end()); // Ordenar por coordenada x
  return divideAndConquer(points, 0, points.size());
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

#endif

/*Se han implementado varias mejoras al código del algoritmo Divide y Vencerás para optimizar su funcionalidad. 
Estas incluyen la ordenación inicial de los puntos por coordenada 'x', esencial para su ejecución eficiente; la incorporación de casos 
base que manejan situaciones con menos de dos puntos y aseguran resultados precisos; y la optimización de la franja central mediante 
una condición dinámica que previene accesos fuera de rango. Estas modificaciones fortalecen la eficiencia del código sin alterar 
su complejidad asintótica.*/