typedef int * PQ;

PQ Init(int N);
void InsertHeap(PQ A, int *n, int key);
int DeleteMax(PQ A, int *n);
void FixHeap(PQ A, int n, int i);
void PrintHeap(PQ A, int n);
void HeapSort(PQ A, int n);