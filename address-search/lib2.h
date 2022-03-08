/* 引数に与えたファイル名のファイルを入力用として内部に開いておく． */
void infile_open(char *filename);

/* 開いておいた入力ファイルからscanfする．戻り値はscanfと同じ． */
int infile_scanf(char *fmt, ...);

/* 開いておいた入力ファイルを閉じる． */
void infile_close(void);

/* 引数に指定した文字列が数字の列であることを確認する */
int is_number_string(char *str);

/* 引数に指定した文字列が読みに現れる文字の列であることを判定する */
int is_yomi_string(char *str);
