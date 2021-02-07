#include <iostream>

using namespace std;

int main() {
    int a[3][3]{{1, 2, 3},{4, 5, 6}, {7, 8, 9}};
    int *pointer = a[0];
    int m=3;
    int n=3;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << *(pointer + i*n + j) << " ";
        }
        cout << endl;
    }
}
