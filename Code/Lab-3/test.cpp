#include <iostream>
#include <cstdlib>
#include <chrono>
#include <bits/stdc++.h>
#include <unistd.h>
#include <cmath>

#include "algorithms.h"

using namespace std;


int main() {
    Algorithms as;

    system("clear");

    for(int n = 10000; n <= 10240000; n = n * 2) {
        cout << "N = " << n << ':' << '\n';
        cout << "A1: " << as.a1(n) << " ms," << '\n';
        cout << "A2: " << as.a2(n) << " ms," << '\n';
        if(n <= 320000) { cout << "A3: " << as.a3(n) << " ms," << '\n'; }
        if(n <= 80000) { cout << "A4: " << as.a4(n) << " ms," << '\n'; }
        if(n <= 2560000) { cout << "A5: " << as.a5(n) << " ms" << '\n'; }

        cout << '\n';
    }

    return 0;
};