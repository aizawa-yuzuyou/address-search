# address-search
"address-search" is a find program by using postal code.

# Features
 "address-search" used split compilation only
# Requirement
 
* gcc (GCC) 9.1.0
 
Environments under (https://www.msys2.org/) is tested.


# Usage
 Create an environment its can execute C.
 
 then go to the directory where the folder named "address-serach" is located.
 
 please compile as follows
```bash
cc main.c lib2.c LIST.c -o main
```
and you can run main as
```bash
./main input.txt
``` 
if you enterd
```bash
検索文字列を入力して下さい: 1000001
``` 

it return 
```bash
1000001 東京都千代田区千代田
1件見つかりました
``` 
# Note
 
I don't test environments under Linux and Mac.
 
# Author
 
* ozawa
