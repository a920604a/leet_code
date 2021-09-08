

## introduction
1. "Hello World!" in C

```c
int main() 
{
    char s[100];
    scanf("%[^\n]%*c", &s);
  	
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    printf("Hello, World!\n");
    int i=0;
    while(s[i]!='\0' && i<100) printf("%c", s[i++]);

    return 0;
}
```
2. Playing With Characters

```c
int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n = 3;
    while(n){
        char s[100];
        scanf("%[^\n]%*c", &s);
        int i=0;
        while(s[i]!='\0' && i<100) printf("%c", s[i++]);
        printf("\n");
        n--;
    }

    return 0;
}
```

3. Sum and Difference of Two Numbers

```c
int main()
{
	int a , b;
    float fa, fb;
    scanf("%d %d %f %f", &a, &b, &fa, &fb);
    printf("%d %d\n%.1f %.1f", a+b, a-b, fa+fb, fa-fb);
    return 0;

    
}
```

4. Functions in C

```c
#define max(a,b) ((a>b)?a:b);
int max_of_four(int a, int b, int c, int d){
    // int ab = max(a,b);
    // int cd = max(c,d);
    // return max( ab, cd);
    
    // option no variable
    int mx = a;
    if(mx<b) mx=b;
    if(mx<c) mx =c;
    if(mx<d) mx=d;
    return mx;
}
```

5. Pointers in C
```c
void update(int *a,int *b) {
    // Complete this function  
    *a = *a + *b;
    *b = abs(*a -  2*(*b)); 
    // *b = abs(*a -  2**b); 
    // *b = abs(*a -  *b*2); 
}
```




## Conditionals and Loops
6. Conditional Statements in C

```c
int main()
{
    // Write Your Code Here
    int n ;
    scanf("%d", &n);
    const static char *strings[] = {"one","two","three","four","five",
                                "six","seven","eight","nine"};
    if(n>=1 && n<=9){
        printf("%s", strings[n-1]);
    }
    else printf("Greater than 9");
    return 0;
}
```

7. For Loop in C

```c
int main() 
{
    int a, b;
    const static char *strings[] = {"one","two","three","four","five",
                                "six","seven","eight","nine"};
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    for(int i=a;i<=b ;++i){
        if(i>=1 && i<=9) printf("%s\n", strings[i-1]);
        else if(i%2){
            printf("odd\n");
        }
        else{
            printf("even\n");
        }
    }
    return 0;
}

```

9. Sum of Digits of a Five Digit Number

```c
int main() {
	
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int ret = 0;
    while(n){
        ret +=(n%10);
        n /=10;
    }
    printf("%d", ret);
    return 0;
}
```


10. Bitwise Operators

```c
void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int and = 0, or = 0, xor = 0;
  for(int i=1;i<=n-1 ;++i){
      for(int j=i+1;j<=n ;++j){
          int a = i&j, o = i|j, x = i^j;
          if(a<k) and = max(and, a);
          if(o<k ) or = max(or, o);
          if(x<k ) xor = max(xor, x);      
      }
  }
  printf("%d\n%d\n%d", and, or, xor);
}

```

11. Printing Pattern Using Loops

```c
int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int arr[2*n-1][2*n-1] ;
    int len = 2*n-1;
    for(int i=0;i<len;++i){
        for(int j=0;j<len ;++j){
            int m = min(i, j);
            m = min(m, len - i - 1);
            m = min(m, len - j - 1);
            printf("%d ", n - m);
        }
        printf("\n");
    }
    
    return 0;
}

```
## Arrays and Strings

12. Array Reversal

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    /* Write the logic to reverse the array. */
    // printf("\n%d\n", *(arr+3));
    for(int i=0;i< (int)num/2 ;++i){
        int temp = *(arr+i);
        *(arr+i) = *(arr+num-1-i);
        *(arr+num-i-1) = temp;
    }

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}

```

13. Printing Tokens
```c
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    for(int i=0;i<strlen(s) ; ++i){
        if(*(s+i)==' ') printf("\n");
        else printf("%c", *(s+i));
    }
    return 0;
}

```

14. Digit Frequency

```c
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char s[1000];
    scanf("%[^\n]%*c", &s);
    int i=0;
    int freq[10] ={0};
    while(i<1000 && s[i]!='\0'){
        if(*(s+i) >='0' && *(s+i) <='9'){
            freq[ *(s+i)-'0']++;            
        }
        i++;       
    }
    for(int i=0;i<10;++i) printf("%d ", freq[i]);
    
    return 0;
}
```

15. 1D Arrays in C

```c
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n;
    scanf("%d", &n);
    int ret =0;
    int *val = malloc(n*sizeof(int));
    for(int i=0;i<n;++i){
        scanf("%d",&val[i]);
        ret += *(val+i);
    }
    printf("%d", ret);
    free(val);
    return 0;
}

```
16. Dynamic Array in C

```c
#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    total_number_of_books=(int*)malloc(sizeof(int)*total_number_of_shelves);
    
    total_number_of_pages=(int**)malloc(sizeof(int*)*total_number_of_shelves);
    for(int i = 0; i < total_number_of_shelves; i++)
    {
        total_number_of_books[i] = 0;
        total_number_of_pages[i] = (int*)malloc(sizeof(int));
    }

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            *(total_number_of_books+x)+=1;
            *(total_number_of_pages+x)=realloc(*(total_number_of_pages+x), *(total_number_of_books+x)*sizeof(int));
            *(*(total_number_of_pages+x)+*(total_number_of_books+x)-1)=y;
    
    
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}

```

## function



1. Calculate the Nth term

```c
int find_nth_term(int n, int a, int b, int c) {
  //Write your code here.
  if(n== 1) return a;
  if(n== 2) return b;
  int ret = c;
  for(int i=4;i<=n;++i){
      ret = a+b+c;
      a = b;
      b = c;
      c = ret;      
  }
  return ret;
}
```


2. Students Marks Sum

```c

int marks_summation(int* marks, int number_of_students, char gender) {
  //Write your code here.
  int i, ret= 0;
  if(gender == 'b') i = 0;
  else if(gender =='g') i=1;
  
  for(int j = i;j<number_of_students;j+=2) ret += *(marks+j);
  return ret;
}
```

3. Permutations of Strings

```c
int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    int i = n-2;
    for(i=n-2; i>-1 ;i--) {
        if(strcmp(s[i] , s[i+1])<0) break;
    }    
    if(i<0) return 0;   
    int j ;
    for(j=n-1;j>i;j--){
        if(strcmp(s[j], s[i]) >0) break;
    }
    char *temp = s[i];
    s[i] = s[j];
    s[j] = temp;    
    j = n-1;
    i++;
    while(i<j){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    return 1;
}


```

4. Variadic functions in C

```c
int  sum (int count,...) {

    va_list ap;
    va_start(ap, count);
    int total =0;
    for(int i=0;i<count;++i){
        total += va_arg(ap,int);        
    }
    va_end(ap);
    return total;
    
}

int min(int count,...) {
    va_list ap;
    va_start(ap, count);
    int mn = MAX_ELEMENT;
    for(int i=0;i<count;++i){
        int cur = va_arg(ap,int);
        if(cur < mn ) mn = cur;
    }
    va_end(ap);
    return mn;    
}

int max(int count,...) {
    va_list ap;
    va_start(ap, count);
    int mx = MIN_ELEMENT;
    for(int i=0;i<count;++i){
        int cur = va_arg(ap,int);
        if(cur > mx )mx = cur;
    }
    va_end(ap);
    return mx;

}


```

## Structs and Enums

1. Boxes through a Tunnel

```c
struct box
{
	/**
	* Define three fields of type int: length, width and height
	*/
    int length , width, height;
};

typedef struct box box;

int get_volume(box b) {
	/**
	* Return the volume of the box
	*/
    return b.length*b.height*b.width;
}

int is_lower_than_max_height(box b) {
	/**
	* Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
	*/
    return b.height<MAX_HEIGHT;
}
```


2. Small Triangles, Large Triangles

```c
struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float area(triangle tr){
    float p = (tr.a + tr.b+ tr.c )/2.0;
    return p* (p-tr.a) * (p-tr.b) * (p-tr.c);
    
}
void swap(triangle* a,triangle* b)
{
    triangle temp=*a;
    *a=*b;
    *b=temp;
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    // bubble sort; smallest in the tail
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(area(tr[j]) > area(tr[j+1]) ){
                swap(&tr[j], &tr[j+1]);
            }
        }
    }
    
}

```