#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

extern int vfscanf(FILE *stream, const char *format, va_list ap);

static FILE *InputFileFp = NULL;

/* 引数に与えたファイル名のファイルを入力用として内部に開いておく． */
void infile_open(char *filename){
    static int opennum = 0;
    if (InputFileFp != NULL){
        fprintf(stderr, "エラー: infile_open: 既にファイルを開いています．\n");
        fprintf(stderr, "        2重に開くことはできません．\n");
        exit(1);
    }

    if (opennum > 0){
        fprintf(stderr, "エラー: infile_open: ファイルを開けるのは1回だけです．\n");
        exit(1);
    }

    InputFileFp = fopen(filename, "r");
    if (InputFileFp == NULL){
        fprintf(stderr, "エラー: infile_open: '%s'を開けませんでした．\n", filename);
        fprintf(stderr, "        ファイルが無いかスペルミスしていませんか？\n");
        exit(1);
    }
    opennum++;
}


/* 開いておいた入力ファイルからscanfする．戻り値はscanfと同じ． */
int infile_scanf(char *format, ...){
    static int eof_read_cnt=0;
    int ret;
    va_list ap;

    va_start(ap, format);
    ret = vfscanf(InputFileFp, format, ap);
    va_end(ap);

    if (ret == EOF){
        if (eof_read_cnt++ >= 2){
            fprintf(stderr, "警告: infile_scanf: すでにファイルの終端に達していますが\n");
            fprintf(stderr, "                    複数回scanfしようとしています\n");
        }
    }

    return ret;
}


/* 開いておいた入力ファイルを閉じる． */
void infile_close(void){
    if (InputFileFp != NULL){
        fclose(InputFileFp);
        InputFileFp = NULL;
    }
}


/* 引数に指定した文字列が数字の列であることを確認する */
int is_number_string(char *str){
    int i;
    for (i=0; str[i]!='\0'; i++){
        if ('0' <= str[i] && str[i] <= '9'){
            /* 何もしない */
        }else{
            return 0;
        }
    }
    return 1;
}

/* 読みに現れる文字列であることを判定する */
int is_yomi_string(char *str){
    int i;
    for (i=0; str[i]!='\0'; i++){
        if ( ('0' <= str[i] && str[i] <= '9') ||
             ('A' <= str[i] && str[i] <= 'Z') ||
             ('a' <= str[i] && str[i] <= 'z') ||
             str[i]=='(' ||
             str[i]==')' ||
             str[i]=='<' ||
             str[i]=='>' ||
             str[i]=='.' ||
             str[i]=='-' )
        {
            /* 何もしない */
        }else{
            return 0;
        }
    }
    return 1;
}
