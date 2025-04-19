#ifndef N_RANDOM_H
#define N_RANDOM_H
#include <random>

using namespace std;

void n_random(pair<double,double> arr[], int a){

    std::random_device rd;
    std::mt19937_64 rng(rd());
    std::uniform_int_distribution<std::int64_t> u_distr1(0,100); // change depending on app

    for(int i = 0; i < a; i++){
        double x = u_distr1(rng);
        double y = u_distr1(rng);
        arr[i].first = x;
        arr[i].second = y;
    }
    
}

#endif