#include <iostream>
#include <cstdlib>
#include <chrono>
#include <bits/stdc++.h>
#include <unistd.h>
#include <math.h>

#include "generators.h"

using namespace std;
using namespace std::chrono;


int main() {
    time_t start, end;
    double time_taken;
    long long val;
    Generator* gen;

    int cases0[] = {5, 7, 12, 17, 20, 22, 27, 30, 35, 37, 42, 45};
    int cases[] = {10000, 100000, 200000, 500000, 1000000, 5000000, 10000000, 20000000, 50000000, 100000000, 200000000, 300000000};

    system("clear");

    cout << "RECURSIVE GENERATOR TESTS (cases0[i] - {5, 7, 12, 17, ...}):" << '\n';

    for(int i = 0; i < 12; i++) {
        gen = new RecursiveGenerator;
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        val = static_cast<RecursiveGenerator*>(gen)->generate(cases0[i]);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken = end - start;

        cout << "n = " << cases0[i] << " : " << val << ", " << time_taken << " ms" << '\n';
    }

    cout << "+============================+" << '\n';
    cout << "DP GENERATOR TESTS " << '\n' << "(cases[i] - {10000, 100000, 200000, ...}):" << '\n';

    for(int i = 0; i < 12; i++) {

        gen = new DPGenerator;
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        val = static_cast<DPGenerator*>(gen)->generate(cases[i]);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken = end - start;

        if(cases[i] > 60) {
            cout << "n = " << cases[i] << " : > 2^64, " << time_taken << " ms" << '\n';
        } else {
            cout << "n = " << cases[i] << " : " << val << ", " << time_taken << " ms" << '\n';
        }
    }

    cout << "+============================+" << '\n';
    cout << "E3 GENERATOR TESTS " << '\n' << "(cases[i] - {10000, 100000, 200000, ...}):" << '\n';

    for(int i = 0; i < 12; i++) {
        gen = new Example3Generator;
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        val = static_cast<Example3Generator*>(gen)->generate(cases[i]);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken = end - start;

        if(cases[i] > 60) {
            cout << "n = " << cases[i] << " : > 2^64, " << time_taken << " ms" << '\n';
        } else {
            cout << "n = " << cases[i] << " : " << val << ", " << time_taken << " ms" << '\n';
        }
    }

    cout << "+============================+" << '\n';
    cout << "MATRIX EXP. GENERATOR TESTS " << '\n' << "(cases[i] - {10000, 100000, 200000, ...}):" << '\n';

    for(int i = 0; i < 12; i++) {
        gen = new MatrixExpGenerator;
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        val = static_cast<MatrixExpGenerator*>(gen)->generate(cases[i]);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken = end - start;

        if(cases[i] > 60) {
            cout << "n = " << cases[i] << " : > 2^64, " << time_taken << " ms" << '\n';
        } else {
            cout << "n = " << cases[i] << " : " << val << ", " << time_taken << " ms" << '\n';
        }
    }

    cout << "+============================+" << '\n';
    cout << "KARTIK'S K SEQ. GENERATOR TESTS " << '\n' << "(cases[i] - {10000, 100000, 200000, ...}):" << '\n';

    for(int i = 0; i < 12; i++) {
        gen = new KartiksGenerator;
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        val = static_cast<KartiksGenerator*>(gen)->generate(cases[i]);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken = end - start;

        if(cases[i] > 60) {
            cout << "n = " << cases[i] << " : > 2^64, " << time_taken << " ms" << '\n';
        } else {
            cout << "n = " << cases[i] << " : " << val << ", " << time_taken << " ms" << '\n';
        }
    }

    cout << "+============================+" << '\n';
    cout << "FAST DOUBLING GENERATOR TESTS " << '\n' << "(cases[i] - {10000, 100000, 200000, ...}):" << '\n';

    for(int i = 0; i < 12; i++) {
        if(cases[i] <= 500000) {
            gen = new FDGenerator;
            start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
            val = static_cast<FDGenerator*>(gen)->generate(cases[i]);
            end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
            time_taken = end - start;

            cout << "n = " << cases[i] << " : > 2^64, " << time_taken << " ms" << '\n';
        } else {
            cout << "n = " << cases[i] << " : ???, > 5000 ms" << '\n';
        }
    }

    return 0;
};
