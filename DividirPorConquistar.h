
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#ifndef DIVIDIRPORCONQUISTAR_H
#define DIVIDIRPORCONQUISTAR_H

using namespace std;

typedef pair<double, double> par;

inline double dividirPorConquistar(const vector<par> &points, int l, int r)
{
    int size = r - l;
    // Casos base
    if (size == 2)
        return hypot(points[l].first - points[l + 1].first, points[l].second - points[l + 1].second);
    if (size == 3)
        return min({
            hypot(points[l].first - points[l + 1].first, points[l].second - points[l + 1].second),
            hypot(points[l].first - points[l + 2].first, points[l].second - points[l + 2].second),
            hypot(points[l + 1].first - points[l + 2].first, points[l + 1].second - points[l + 2].second)
        });
    
    int m = l + (r - l) / 2;
    double dl = dividirPorConquistar(points, l, m);
    double dr = dividirPorConquistar(points, m, r);
    double d = min(dl, dr);

    int sl = m, sr = m;
    while (sl > l && points[m].first - points[sl - 1].first < d) sl--;
    while (sr < r - 1 && points[sr + 1].first - points[m].first < d) sr++;

    vector<par> strip(points.begin() + sl, points.begin() + sr + 1);
    sort(strip.begin(), strip.end(), [](const par &a, const par &b) {
        return a.second < b.second;
    });

    for (size_t i = 0; i < strip.size(); ++i) {
        for (int j = 0; j < 7; ++j) {
            if (i + j + 1 >= strip.size()) break;
            d = min(d, hypot(strip[i].first - strip[i + j + 1].first, strip[i].second - strip[i + j + 1].second));
        }
    }

    return d;
}

inline double dividir_por_conquistar(par arr[], int n)
{
    vector<par> points(arr, arr + n);
    sort(points.begin(), points.end()); // Ordenar por coordenada x
    return dividirPorConquistar(points, 0, n);
}

#endif

