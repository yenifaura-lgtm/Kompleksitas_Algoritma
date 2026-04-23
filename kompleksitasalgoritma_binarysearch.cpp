#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int kiri = 0, kanan = n - 1;

    while(kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if(arr[tengah] == x)
            return tengah;
        else if(arr[tengah] < x)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 5, 5, 6, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;

    int hasil = binarySearch(arr, n, x);

    cout << "Ditemukan di index: " << hasil;
}
