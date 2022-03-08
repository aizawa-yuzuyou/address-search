#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lib2.h"
#include"LIST.h"
#define N 200
struct address gRear = {"","","",NULL};
int main(int argc,char *argv[]){
    int e,cnt = 0;
    struct address *p;
    char str[N];
    char a[N];
    if(argc != 2){ 
        fprintf(stderr, "プログラム引数を1つ指定してください\n");
        exit(1);
    }
    infile_open(argv[1]);
    infile_scanf("%s",str);
    e = atoi(str);
    printf("検索文字列を入力して下さい: ");
    scanf("%s",a);
    while(e > 0){
        p = malloc(sizeof(struct address));
        read(p);
        insert(&gRear,p);
        p = p ->next;
        e--;
    }
    while(strcmp(a,"0") != 0){
        p = gRear.next;
        cnt = 0;
        while(p != NULL){
        if(strcmp(a,p->aa) == 0){
            cnt++;
            printList(p);
        }
        p = p ->next;
    }
    printf("%d件見つかりました\n",cnt);
    printf("検索文字列を入力して下さい: ");
    scanf("%s",a);
    }
    printf("プログラムを終了します\n");
    fre(p);
    return 0;
}
