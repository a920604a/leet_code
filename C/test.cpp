#include <limits.h>
#include <stack>
#include <iostream>
using namespace std;

void printInBinary(int num){
    cout<<CHAR_BIT<<endl;
    int n = CHAR_BIT*sizeof(num);
    stack<bool> s;
    for(int i =1 ;i<=n;++i){
        s.push(num&1);
        num >>=1;
    }
    for(int i=1;i<=n;++i){
        cout << s.top() ;
        s.pop();

        // Put a space after every byte. 
        if (i % CHAR_BIT == 0)
        cout << " "; 
    }
}

int get(unsigned int n){
    return (n & (1<<9) );
}
void set(unsigned int &n){
    n = (n | (1<<9));
}

void clear(unsigned int &n){
    n = (n & ~(1<<9));
}

void inverse(unsigned int &n){
    n = (n^ (1<<9));
}


int main()
{
    // int num = 12;
    // printInBinary(num);
    // return 0;
    
    // printf("1/2 = %f", (float)(1/2));


    // int x = 5, y =2;
    // cout<<(x& y)<<endl;
    // if(x& y) cout<<"A";
    // else cout<<"B";
    unsigned int a = 5;
    cout<<get(a)<<endl;
    set(a);
    cout<<a<<endl;
    a = 5;
    clear(a);
    cout<<a<<endl;
    inverse(a);
    inverse(a);
    cout<<a<<endl;
    return 0;
}


