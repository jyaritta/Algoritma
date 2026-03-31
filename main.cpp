#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// iteratif
int iteratif(int n){
    long long f1 = 0, f2 = 1, temp;
    for(int i = 2; i <= n; i++){
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
    cout << f2;
    cout << " ";
    return f2;
}

// rekursif dengan deret
long long temp[100] = {0};
long long rekursif(int n) {
    if (n <= 1) return n;

    if (temp[n] != 0) return temp[n];
    temp[n] = rekursif(n - 1) + rekursif(n - 2);
    return temp[n];
}

// rekursif F(n) = F(n−1) + F(n−2)
long long rekursif_standar(int n) {
    if (n <= 1) return n;
    return rekursif_standar(n - 1) + rekursif_standar(n - 2);
}

int main(){
    int angka[] = {10, 20, 30, 40, 50};
    
    cout << "Metode Iteratif\n";
    for(int n : angka){
        auto start = high_resolution_clock::now();
        iteratif(n);
        auto end = high_resolution_clock::now();
        duration<double> durasi = end - start;
        cout << "\nWaktu Eksekusi: " << fixed << setprecision(9) << durasi.count() << " detik" << endl;
    }

    cout << "\nMetode Rekursif dengan Deret\n";
    for(int n : angka){
        auto start = high_resolution_clock::now();
        cout << rekursif(n);
        auto end = high_resolution_clock::now();
        duration<double> durasi = end - start;
        cout << "\nWaktu Eksekusi: " << fixed << setprecision(9) << durasi.count() << " detik" << endl;
    }

    cout << "\nMetode Rekursif Standar\n";
    for(int n : angka) {
        auto start = high_resolution_clock::now();
        long long hasil = rekursif_standar(n); 
        cout << hasil;
        auto end = high_resolution_clock::now();
        duration<double> durasi = end - start;
        cout << "\nWaktu Eksekusi: " << fixed << setprecision(9) << durasi.count() << " detik" << endl;
    }
    return 0;
}
