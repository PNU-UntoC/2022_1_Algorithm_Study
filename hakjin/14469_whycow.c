#include <stdio.h>
#include <stdlib.h>

typedef struct cow {
    int t_arrival;
    int t_stay;
} COW;

int static compare (const void* first, const void* second) {
    COW *pt_first = (COW*)first;
    COW *pt_second = (COW*)second;
    
    if (pt_first->t_arrival < pt_second->t_arrival)
        return -1;
    else if(pt_first->t_arrival > pt_second->t_arrival)
        return 1;
    else
        return 0;
}

int main(void) {
    int N, cur_time=0;
    scanf("%d", &N);
    COW line[N];
    for(int i=0; i<N; i++) {
        scanf("%d %d", &line[i].t_arrival, &line[i].t_stay);
    }
    qsort(line, N, sizeof(COW), compare);
    for(int i=0; i<N; i++) {
        if(line[i].t_arrival > cur_time) {
            cur_time = line[i].t_arrival + line[i].t_stay;
        } else {
            cur_time = cur_time + line[i].t_stay;
        }
    }
    printf("%d\n", cur_time);
    
    return 0;
}
