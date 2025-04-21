#include <iostream>
#include <vector>
#include <cmath>
#include <utility> // Para std::pair
#ifndef FUERZABRUTATRIVIALMENTEMEJORADO_H
#define FUERZABRUTATRIVIALMENTEMEJORADO_H

using namespace std;

void better_brute_force(const vector<pair<double, double>>& puntos) {
    double result = INFINITY; // mejor que 10000000

    for (int i = 0; i < puntos.size(); i++) {
        for (int j = i+1 ; j < puntos.size(); j++) { // j = i + 1 evita colisiones
            
            double dx = puntos[i].first - puntos[j].first;
            double dy = puntos[i].second - puntos[j].second;
            double distancia = dx * dx + dy * dy; // cálculo directo sin ifs
            if (distancia < result) {
                result = distancia;
            }
        }
    }
}
#endif

/*Dado este arreglo de puntos donde buscamos comparar su distancia para hallar la menor distancia entre cada punto, con un enfoque que 
utiliza la fuerza bruta. Podemos observar que en el algoritmo pueden haber colisiones entre ambos loops principales, lo cual nos hace 
tener que verificar si los puntos están repetidos o no. Además de ello, existen otras condiciones que nos hacen realizar hasta 
4 verificaciones en el peor caso, las cuales acarrean consigo más verificaciones a hacer antes de realizar el cálculo de distancias. 
La complejidad total sería de n^2 + C1.
Una mejora a esto, trivial pues las operaciones mencionadas son constantes de complejidad O(1), es eliminar las verificaciones y realizar 
modificaciones en las condiciones de los loops principales. De esta manera obtenemos una constante C2 de operaciones menor a C1.*/