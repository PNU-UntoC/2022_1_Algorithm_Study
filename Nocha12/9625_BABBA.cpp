#include <iostream>

using namespace std;

int A[45];
int B[45];

int main() {
    int K;
    
    cin >> K;
    
    A[0] = 0; B[0] = 1;
    A[1] = 1; B[1] = 1;
    
    for(int i = 2; i < K; i++) {
        A[i] = A[i - 2] + A[i - 1];
        B[i] = B[i - 2] + B[i - 1];
    }
    
    cout << A[K - 1] << " " << B[K - 1];

    return 0;
}
