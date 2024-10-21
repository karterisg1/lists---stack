typedef struct list *List;

List Create(void);
void Print(List);
int DeQueue(List *);
int Pop(List *);
void EnQueue(List *, int);
void Push(List *, int);
int SizeOf(List);
int IsEmpty(List);