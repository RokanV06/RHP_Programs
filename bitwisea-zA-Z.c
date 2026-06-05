// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
int main() {
    char str[1000001];
    scanf("%s",str);
    int up=0;int lo=0;
    for (int i=0;str[i];i++){
        if(str[i]>='a'&& str[i]<='z'){
            lo=(lo|(1<<(str[i]-'a')));
        }
        else if(str[i]>='A'&& str[i]<='Z'){
            up=(up|(1<<(str[i]-'A')));
        }
    }
        printf((lo==(1<<26)-1) && (up==(1<<26)-1)?"Yes":"NO");
    
    return 0;
}