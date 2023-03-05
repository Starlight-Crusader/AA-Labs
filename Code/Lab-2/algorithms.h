class Sort {
    protected:
        int order;

    public:
        void sort();
};


class BubbleSort: public Sort {
    public:
        BubbleSort(int order_val) {
            order = order_val;
        };

        void sort(int *arr, int n) {
            for(int i = 0; i < n-1; i++) {
                for(int j = 0; j < n-i-1; j++) {
                    if(!order) {
                        if(*(arr+j) > *(arr+j+1)) {
                            swap(arr+j, arr+j+1);
                        }
                    } else if(order) {
                        if(*(arr+j) < *(arr+j+1)) {
                            swap(arr+j, arr+j+1);
                        }
                    }
                }
            }
        };

        void swap(int *v1, int *v2) {
            int temp = *v1; *v1 = *v2; *v2 = temp;
        };
};


class InsertionSort: public Sort {
    public:
        InsertionSort(int order_val) {
            order = order_val;
        };

        void sort(int *arr, int n) {
            int i, j, key;

            for(i = 1; i < n; i++) {
                key = *(arr+i); j = i - 1;

                if(!order) {
                    while(j >= 0 && *(arr+j) > key) {
                        *(arr+j+1) = *(arr+j); j = j - 1;
                    }
                } else if(order) {
                    while(j >= 0 && *(arr+j) < key) {
                        *(arr+j+1) = *(arr+j); j = j - 1;
                    }
                }

                *(arr+j+1) = key;
            }
        };
};


class MergeSort: public Sort {
    public:
        MergeSort(int order_val) {
            order = order_val;
        };

        void merge(int *arr, int left, int mid, int right) {
            int subArr1 = mid - left + 1;
            int subArr2 = right - mid;

            int *tmpLeft = (int*)malloc(subArr1*sizeof(int));
            int *tmpRight = (int*)malloc(subArr2*sizeof(int));

            for(int i = 0; i < subArr1; i++) { *(tmpLeft+i) = *(arr+left+i); }
            for(int j = 0; j < subArr2; j++) { *(tmpRight+j) = *(arr+mid+1+j); }

            int idxSubArr1 = 0; int idxSubArr2 = 0; int idxMerged = left;

            while(idxSubArr1 < subArr1 && idxSubArr2 < subArr2) {
                if(!order) {
                    if(*(tmpLeft+idxSubArr1) <= *(tmpRight+idxSubArr2)) {
                        *(arr+idxMerged) = *(tmpLeft+idxSubArr1);
                        idxSubArr1++;
                    } else {
                        *(arr+idxMerged) = *(tmpRight+idxSubArr2);
                        idxSubArr2++;
                    }
                } else if(order) {
                    if(*(tmpLeft+idxSubArr1) >= *(tmpRight+idxSubArr2)) {
                        *(arr+idxMerged) = *(tmpLeft+idxSubArr1);
                        idxSubArr1++;
                    } else {
                        *(arr+idxMerged) = *(tmpRight+idxSubArr2);
                        idxSubArr2++;
                    }
                }

                idxMerged++;
            }

            while(idxSubArr1 < subArr1) {
                *(arr+idxMerged) = *(tmpLeft+idxSubArr1);
                idxSubArr1++; idxMerged++;
            }

            while(idxSubArr2 < subArr2) {
                *(arr+idxMerged) = *(tmpRight+idxSubArr2);
                idxSubArr2++; idxMerged++;
            }

            delete tmpLeft; delete tmpRight;

        };

        void sort(int *arr, int begin, int end) {
            if(begin >= end) {
                return;
            }

            int mid = begin + (end - begin) / 2;

            sort(arr, begin, mid);
            sort(arr, mid+1, end);

            merge(arr, begin, mid, end);
        };
};


class QuickSort: public Sort {
    public:
        QuickSort(int order_val) {
            order = order_val;
        };

        int partition(int *arr, int low, int high) {
            int pivot = *(arr+high);
            int i = low - 1;

            for(int j = low; j <= high-1; j++) {
                if(!order) {
                    if(*(arr+j) < pivot) {
                        i++;
                        swap(arr+i, arr+j);
                    }
                } else if(order) {
                    if(*(arr+j) > pivot) {
                        i++;
                        swap(arr+i, arr+j);
                    }
                }
            }

            swap(arr+i+1, arr+high);

            return i+1;
        };

        void sort(int *arr, int start, int end) {
            if (start >= end) { return; }
            
            int p = partition(arr, start, end);
            sort(arr, start, p-1);
            sort(arr, p+1, end);
        };

        void swap(int *v1, int *v2) {
            int temp = *v1; *v1 = *v2; *v2 = temp;
        };
};


class HeapSort: public Sort {
    public:
        HeapSort(int order_val) {
            order = order_val;
        };

        void heapify(int *arr, int n, int i) {
            int compareTo = i;
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(!order) {    
                if(left < n && *(arr+left) > *(arr+compareTo)) { compareTo = left; }
                if(right < n && *(arr+right) > *(arr+compareTo)) { compareTo = right; }
            } else {
                if(left < n && *(arr+left) < *(arr+compareTo)) { compareTo = left; }
                if(right < n && *(arr+right) < *(arr+compareTo)) { compareTo = right; }
            }
            
            if(compareTo != i) {
                swap(arr+i, arr+compareTo);
                heapify(arr, n, compareTo);
            }
        };

        void sort(int *arr, int n) {
            for(int i = n/2-1; i >= 0; i--) {
                heapify(arr, n, i);
            }

            for(int i = n-1; i > 0; i--) {
                swap(arr, arr+i);
                heapify(arr, i, 0);
            }
        };

        void swap(int *v1, int *v2) {
            int temp = *v1; *v1 = *v2; *v2 = temp;
        };
};