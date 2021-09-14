
```c

void swap(int *a, int *b){
    int temp = *a;
    *a= *b;
    *b = temp;
}
// C++ 限定
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
// 以下不需要額外變數
void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swap(int *a, int *b){
    *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;
}

void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
```