#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int rev(int num){
    int rem,rev=0;
    while(num>0){
        rem = num%10;
        rev = rev*10 + rem;
        num = num/10;
    }
    return rev;
}

int isAdams(int num){
    int numsq= num*num;
    int revnum = rev(num);
    int revsq = revnum*revnum;
    return (revsq=rev(numsq));
}

bool isPrime(int num){
    if((num==2)||(num==3)){
        return true;
    }
    else{
        for(int i=2;i<num;i++){
            int k = num%i;
            if(k==0){
                return false;
                break;
            }
        }
        return true;
    }
}

bool isPalindrome(int num){
    return (num == rev(num));
}

int isPrimePalindrome(int num){
    return(isPalindrome(num)&&isPrime(num));
}

int isArmstrong(int num){
    int original=num;
    int sum=0;
    int n=0;
    int temp=num;
    
    while(temp!=0){
        temp/=10;
        n++;
    }
    temp=num;
    while(temp!=0){
        int digit=temp%10;
        sum+=pow(digit,n);
        temp/=10;
    }
    return(original==sum);
}

int main(){
    printf("Enter a number: ");
    int n;
    scanf("%d",&n);
    if(isArmstrong(n)){
    printf("\n%d is an Armstrong number.\n",n);}
    else{
    printf("\n%d is not an Armstrong number.\n",n);}
    
    if(isPrimePalindrome(n)){
    printf("\n%d is a Prime Palindrome number.\n",n);}
    else{
    printf("\n%d is not a Prime Palindrome number.\n",n);}
    
    if(isAdams(n)){
    printf("\n%d is an Adams number.\n",n);}
    else{
    printf("\n%d is not an Adams number.\n",n);}
    
    return 0;
}