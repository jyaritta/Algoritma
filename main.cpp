#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

// iteratif
int iteratif(int n){
    long long f1 = 1, f2 = 2, temp;
    for(int i = 2; i <= n; i++){
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
    cout << f2;
    cout << " ";
    return f2;
}

int main(){
    int angka[] = {10, 20, 30, 40, 50};
    auto start = high_resolution_clock::now();
    for(int n : angka){
        iteratif(n);
    }
    auto end = high_resolution_clock::now();
    cout << "\nWaktu Eksekusi: " << selisih.count() << " detik" << endl;
}
