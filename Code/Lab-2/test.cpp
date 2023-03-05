#include <iostream>
#include <cstdlib>
#include <chrono>
#include <bits/stdc++.h>
#include <unistd.h>
#include <math.h>

#include "algorithms.h"

using namespace std;
using namespace std::chrono;


int main() {
    int n, *arr, *test;
    time_t start, end;
    double time_taken1, time_taken2;

    Sort *s;

    system("clear");
    srand(time(0));
    
    for(int j = 1; j <= 10; j++) {
        n = 10000*j;
        test = (int*)malloc(n*sizeof(int));
        arr = (int*)malloc(n*sizeof(int));

        for(int i = 0; i < n; i++) { *(test+i) = rand(); }

        cout << "+====================+" << '\n';
        cout << "RESULTS FOR N = " << n << ':' << '\n';

        for(int i = 0; i < n; i++) { *(arr+i) = *(test+i); }
        s = new BubbleSort(0);
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        static_cast<BubbleSort*>(s)->sort(arr, n);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken1 = end - start;

        for(int i = 0; i < n; i++) { *(arr+i) = *(test+i); }
        s = new BubbleSort(1);
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        static_cast<BubbleSort*>(s)->sort(arr, n);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken2 = end - start;

        cout << "BUBBLE SORT: " << (time_taken1 + time_taken2) / 2 << " ms" << '\n';

        for(int i = 0; i < n; i++) { *(arr+i) = *(test+i); }
        s = new InsertionSort(0);
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        static_cast<InsertionSort*>(s)->sort(arr, n);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken1 = end - start;

        for(int i = 0; i < n; i++) { *(arr+i) = *(test+i); }
        s = new InsertionSort(1);
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        static_cast<InsertionSort*>(s)->sort(arr, n);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken2 = end - start;

        cout << "INSERTION SORT: " << (time_taken1 + time_taken2) / 2 << " ms" << '\n';

        delete test, arr;
    }

    cout << "+====================+" << '\n';

    for(int j = 1; j <= 10; j++) {
        n = 100000*j;
        test = (int*)malloc(n*sizeof(int));
        arr = (int*)malloc(n*sizeof(int));

        for(int i = 0; i < n; i++) { *(test+i) = rand(); }

        cout << "+====================+" << '\n';
        cout << "RESULTS FOR N = " << n << ':' << '\n';

        for(int i = 0; i < n; i++) { *(arr+i) = *(test+i); }
        s = new MergeSort(0);
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        static_cast<MergeSort*>(s)->sort(arr, 0, n-1);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken1 = end - start;

        for(int i = 0; i < n; i++) { *(arr+i) = *(test+i); }
        s = new MergeSort(1);
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        static_cast<MergeSort*>(s)->sort(arr, 0, n-1);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken2 = end - start;

        cout << "MERGE SORT: " << (time_taken1 + time_taken2) / 2 << " ms" << '\n';

        for(int i = 0; i < n; i++) { *(arr+i) = *(test+i); }
        s = new QuickSort(0);
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        static_cast<QuickSort*>(s)->sort(arr, 0, n-1);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken1 = end - start;

        for(int i = 0; i < n; i++) { *(arr+i) = *(test+i); }
        s = new QuickSort(1);
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        static_cast<QuickSort*>(s)->sort(arr, 0, n-1);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken2 = end - start;

        cout << "QUICK SORT: " << (time_taken1 + time_taken2) / 2 << " ms" << '\n';

        for(int i = 0; i < n; i++) { *(arr+i) = *(test+i); }
        s = new HeapSort(0);
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        static_cast<HeapSort*>(s)->sort(arr, n);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken1 = end - start;

        for(int i = 0; i < n; i++) { *(arr+i) = *(test+i); }
        s = new HeapSort(1);
        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        static_cast<HeapSort*>(s)->sort(arr, n);
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time_taken2 = end - start;

        cout << "HEAP SORT: " << (time_taken1 + time_taken2) / 2 << " ms" << '\n';

        delete arr, test;
    }

    cout << "+====================+" << '\n';

    return 0;
};
