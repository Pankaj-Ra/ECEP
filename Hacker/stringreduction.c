#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char a[100] = {'\0'};
    scanf("%s",a);
    int n = strlen(a);
    int j = 0;
    for(int i = 1; i < n;i++){
        if(a[i] == a[i-1]){
            if(i == n-2){
                printf("%c",a[i+1]);
                j++;
                break;
            }

            i++;
            continue;
        }
        if(a[i] != a[i-1]){
            j++;
            printf("%c",a[i-1]);
            if(i == n-1)
                printf("%c",a[i]);
        }
    }
    if(!j)
        printf("Empty String");
    return 0;
}

