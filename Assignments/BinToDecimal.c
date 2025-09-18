#include <stdio.h>
#include <math.h>

int main(){
    printf("Enter a binary number : "); 
    int binNum; 
    scanf("%d", &binNum); 
    int copy = binNum, decNum=0, bits, count =0; 
    while(copy>0){
        bits = copy%10; 
        if(bits==1)
            decNum = decNum + pow(2, count); 
        count++;
        copy/=10;  
    }
    printf("%d in decimal = %d", binNum, decNum); 

}