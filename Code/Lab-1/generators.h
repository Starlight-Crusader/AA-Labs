// GENERAL INTERFACE

class Generator {
    public:
        long long generate(int);
};


// RECURSIVE APPROACH

class RecursiveGenerator: public Generator {
    public:
        long long generate(int n) {
            if(n <= 1) {
                return n;
            }

            return generate(n-1) + generate(n-2);
        };
};


// DYNAMIC PROGRAMMING APPROACH

class DPGenerator: public Generator {
    public:
        long long generate(int n) {
            long long n1 = 1; long long n2 = 1;

            for(int i = 1; i < n-1; i++) {
                n2 = n1 + n2;
                n1 = n2 - n1;
            }
 
            return n2;
        };
};


// METHOD DESCRIBED IN THE ANNOTATION TO THIS LAB. WORK

class Example3Generator: public Generator {
    public:
        long long generate(int n) {
            long long n1 = 1; long long n2 = 0; 
            long long k = 0; long long h = 1; long long t = 0;

            while(n > 0) {
                if(n % 2 == 1) {
                    t = n2 * h;
                    n2 = n1*h + n2*k + t;
                    n1 = n1*k + t;
                }

                t = h*h;
                h = 2*k*h + t;
                k = k*k + t;
                n = n / 2;
            };

            return n2;
        };
};


// MATRIX EXPONENTIATION METHOD

class MatrixExpGenerator: public Generator {
    public:
        long long generate(int n) {
            long long F[2][2] = {{1, 1}, {1, 0}};

            if (n == 0) {
                return 0;
            }
            
            pow(F, n);
            return F[0][0];
        };

        void pow(long long F[2][2], int n) {
            long long M[2][2] = {{1, 1}, {1, 0}};

            for(int i = 2; i < n; i++) {
                mult(F, M);
            }

            // OPTIMIZATION
            /*
            if(n == 0 || n == 1) {
                return;
            }
    
            int M[2][2] = {{1, 1}, {1, 0}};
     
            power(F, n/2);
            multiply(F, F);
     
            if (n % 2 != 0) {
                multiply(F, M);
            }
            */
        };

        void mult(long long m1[2][2], long long m2[2][2]) {
            long long m11 =  m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0];
            long long m12 =  m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1];
            long long m21 =  m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0];
            long long m22 =  m1[1][0]*m2[0][1] + m1[1][1]*m2[1][1];
 
            m1[0][0] = m11;
            m1[0][1] = m12;
            m1[1][0] = m21;
            m1[1][1] = m22;
        };
};


// OPTIMIZATION
            /*
            if(n == 0 || n == 1) {
                return;
            }
    
            int M[2][2] = {{1, 1}, {1, 0}};
     
            power(F, n/2);
            multiply(F, F);
     
            if (n % 2 != 0) {
                multiply(F, M);
            }
            */

// KARTIK'S K SEQUENCE METHOD

class KartiksGenerator: public Generator {
    public:
        long long generate(int n) {
            long long tmp = 0;
            long long n1, n2;

            if(n > 0) {
                if(n % 3 == 1) {
                    n1 = 1;
                    n2 = 3;
                } else if (n % 3 == 2) {
                    n1 = 1;
                    n2 = 5;
                } else if (n % 3 == 0) {
                    n1 = 2;
                    n2 = 8;
                }
                
                int m;
                if(n % 3 == 0) {
                    m = n/3 - 1;
                } else {
                    m = n/3;
                }

                for(int i = 0; i < m; i++) {
                    tmp = n2;
                    n2 = n2*4 + n1;
                    n1 = tmp;
                }

                return n1;
            } else {
                return -1;
            }
        };
};


// FAST DOUBLING METHOD (DERIVED FROM MATRIX EXPONENTIATION)

class FDGenerator: public Generator {
    public:
        long long generate(int n) {
            if (n == 0) {
                return 0;
            } else if(n == 1 || n == 2) {
                return 1;
            }

            long long k = (n & 1) ? 
                (n+1)/2 
                : n/2;

            long long ans = (n & 1) ? 
                (generate(k)*generate(k) + generate(k-1)*generate(k-1))
                : (2*generate(k-1) + generate(k)) * generate(k);
 
            return ans;
        };
};
