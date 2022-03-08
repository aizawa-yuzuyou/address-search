#include<stdio.h>
#include<stdlib.h>
#include"LIST.h"
#include"lib2.h"
#define N 200
struct address gFront = {"","","",NULL};
void read(struct address *p){
    infile_scanf("%s",p->aa);
    infile_scanf("%s",p->bb);
    infile_scanf("%s",p->cc);
}
void fre(struct address *p){
    struct address *q;
    p = gFront.next;
    while(p != NULL){
         q = p->next; 
         free(p);
         p = q;
    }
}
void insert(struct address *pre, struct address *new){
    new->next = pre->next;
    pre->next = new;
    return;
}
void printList(struct address *p){
        printf("%s %s\n",p->aa,p->bb);
}
