#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N;
    int numbers[10010] = { 0, };
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        int temp;
        
        scanf("%d", &temp);
        
        numbers[temp]++;
    }
    
    for(int i = 1; i <= 10000; i++)
        for(int j = 0; j < numbers[i]; j++)
            printf("%d\n", i);
}
