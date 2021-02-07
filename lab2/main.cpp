#include <iostream>

using namespace std;

void superfunc(int* a, int*b, int n){
    int prod = 1;
    for (int i = 0; i < n; ++i) {
        prod *= a[i];
    }
    for (int i = 0; i < n; ++i) {
        b[i] = prod / a[i];
        cout << b[i] <<" ";
    }


}

int main() {
    int a[4]{1, 2, 3};
    int b[4];
    int *pointer_a = a;
    int *pointer_b = b;
    int n = 3;

    superfunc(pointer_a, pointer_b, n);

}
