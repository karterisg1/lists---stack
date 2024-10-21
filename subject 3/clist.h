typedef struct list * Clist;

Clist Create(void);
void PrintList(Clist L);
void Add(Clist *L, int x);
void Advance(Clist *L);
void Remove(Clist *L);