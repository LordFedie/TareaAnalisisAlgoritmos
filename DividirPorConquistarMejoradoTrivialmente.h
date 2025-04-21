#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#ifndef TRIVIAL_H
#define TRIVIAL_H


using par = std::pair<double, double>;
constexpr int MAX_NEIGHBOR_CHECK = 7;

// Calcula la distancia euclidiana al cuadrado entre dos puntos
double distSquared(const par& x1, const par& x2) {
    double dx = x1.first - x2.first;
    double dy = x1.second - x2.second;
    return dx * dx + dy * dy;
}

// Algoritmo de dividir y conquistar para encontrar la menor distancia entre puntos
double dividirPorConquistar2(const std::vector<par>& points, int l, int r) {
    int size = r - l;
    if (size == 2) return std::sqrt(distSquared(points[l], points[l + 1]));
    if (size == 3) {
        double d1 = distSquared(points[l], points[l + 1]);
        double d2 = distSquared(points[l], points[l + 2]);
        double d3 = distSquared(points[l + 1], points[l + 2]);
        return std::sqrt(std::min({d1, d2, d3}));
    }

    int m = l + (r - l) / 2;
    double dl = dividirPorConquistar2(points, l, m);
    double dr = dividirPorConquistar2(points, m, r);
    double d = std::min(dl, dr);
    double minDistSq = d * d;

    int sl = m, sr = m;
    while (sl > l && (points[m].first - points[sl - 1].first) * (points[m].first - points[sl - 1].first) < minDistSq) sl--;
    while (sr < r - 1 && (points[sr + 1].first - points[m].first) * (points[sr + 1].first - points[m].first) < minDistSq) sr++;

    std::vector<par> strip(points.begin() + sl, points.begin() + sr + 1);
    std::sort(strip.begin(), strip.end(), [](const par& a, const par& b) {
        return a.second < b.second;
    });

    for (size_t i = 0; i < strip.size(); ++i) {
        for (int j = 0; j < MAX_NEIGHBOR_CHECK && i + j + 1 < strip.size(); ++j) {
            double dSq = distSquared(strip[i], strip[i + j + 1]);
            if (dSq < minDistSq) minDistSq = dSq;
        }
    }

    return std::sqrt(minDistSq);
}

// Generador de puntos aleatorios


#endif