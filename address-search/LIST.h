#define N 200
struct address{ 
    char aa[N];
    char bb[N];
    char cc[N];
    struct address *next;
};
 void read(struct address *p);
void fre(struct address *p);
void insert(struct address *pre,struct address *new);
void printList(struct address *p);