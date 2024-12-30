#include<stdio.h>
int ucln(int a,int b){
    while (a != b)
    {
        if (a > b)  
        {
            a-=b;
        }
        else{
            b-=a;
        }
        
    }
    return a;
}
int main(){
    printf("%d",ucln(6,12));
    return 0;
}