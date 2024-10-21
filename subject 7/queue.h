typedef struct list *Queue;

void EnQueue(Queue *, int);
int DeQueue(Queue *);
Queue Init(void);
int IsEmpty(Queue);
void ProcessQueue(int);