#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int start, end;
    int sum = 0;
    int i, j;
    int k = 0;
    int *p_numbers = NULL;
    p_numbers = calloc(1000, sizeof(int));

    scanf("%d %d", &start, &end);
    
    for(i=1;i<100;i++) {
        for(j=0;j<i;j++){
            p_numbers[k++] = i;
        }
    }
    
    for(i = start; i <= end; i++) {
        sum = sum + p_numbers[i-1];
    }
    printf("%d", sum);
    return 0;
}
