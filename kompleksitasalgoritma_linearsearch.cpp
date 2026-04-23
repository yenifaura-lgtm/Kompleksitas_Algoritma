#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 9;

    int hasil = linearSearch(arr, n, x);

    cout << "Ditemukan di index: " << hasil;
}
