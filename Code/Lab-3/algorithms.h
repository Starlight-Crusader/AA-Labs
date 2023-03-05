using namespace std;
using namespace std::chrono;


class Algorithms {
    public:
        double a1(int);
        double a2(int);
        double a3(int);
        double a4(int);
        double a5(int);
};

double Algorithms::a1(int n) {
    time_t start, end;
    
    bool* c = (bool*)malloc(n*sizeof(bool));
    int i, j;

    for(i = 1; i <= n; i++) { *(c+i) = true; }

    start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    *(c+1) = false; i = 2;

    while(i <= n) {
        if(*(c+i) == true) {
            j = 2 * i;

            while(j <= n) {
                *(c+j) = false;
                j = j + i;
            }
        }

        i = i + 1;
    }

    end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    
    delete c;

    return end - start;
};

double Algorithms::a2(int n) {
    time_t start, end;
    
    bool* c = (bool*)malloc(n*sizeof(bool));
    int i, j;

    for(i = 1; i <= n; i++) { *(c+i) = true; }

    start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    *(c+1) = false; i = 2;
    
    while(i <= n) {
        j = 2 * i;
  
        while(j <= n) {
            *(c+j) = false;
            j = j + i;
        }

        i = i + 1;
    }

    end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    
    delete c;

    return end - start;
};

double Algorithms::a3(int n) {
    time_t start, end;
    
    bool* c = (bool*)malloc(n*sizeof(bool));
    int i, j;

    for(i = 1; i <= n; i++) { *(c+i) = true; }

    start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    *(c+1) = false; i = 2;

    while(i <= n) {
        if(*(c+i) == true) {
            j = i + 1;

            while(j <= n) {
                if(j % i == 0) {
                    *(c+j) = false;
                }
                
                j = j + 1;
            }
        }
        
        i = i + 1;
    }

    end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    
    delete c;

    return end - start;
};

double Algorithms::a4(int n) {
    time_t start, end;
    
    bool* c = (bool*)malloc(n*sizeof(bool));
    int i, j;

    for(i = 1; i <= n; i++) { *(c+i) = true; }

    start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    *(c+1) = false; i = 2;

    while(i <= n) {
        j = 2;
  
        while(j < i) {
            if(i % j == 0) {
                *(c+i) = false;
            }
            
            j = j + 1;
        }
  
        i = i + 1;
    }

    end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    
    delete c;

    return end - start;
};


double int2double(int iVal) {
    double dVal = iVal;
    return dVal;
};


double Algorithms::a5(int n) {
    time_t start, end;
    
    bool* c = (bool*)malloc(n*sizeof(bool));
    int i, j;

    for(i = 1; i <= n; i++) { *(c+i) = true; }

    start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    *(c+1) = false; i = 2;

    while(i <= n) {
        j = 2;
  
        while(j <= sqrt(int2double(i))) {
            if(i % j == 0) {
                c[i] = false;
            }
    
            j = j + 1;
        }

        i = i + 1;
    }

    end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    
    delete c;

    return end - start;
};
