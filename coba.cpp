#include <iostream>
using namespace std;

// ========== FUNGSI UNTUK MENAMPILKAN ARRAY ==========
void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ========== 1. BUBBLE SORT ==========
// Cara kerja: Membandingkan dua angka bersebelahan, jika salah urutan maka ditukar
// Proses ini diulang sampai semua data terurut
void bubbleSort(int arr[], int n) {
    cout << "\n=== BUBBLE SORT ===" << endl;
    cout << "Data awal: ";
    tampilkanArray(arr, n);
    
    // Loop untuk setiap putaran
    for (int i = 0; i < n - 1; i++) {
        cout << "\nPutaran " << i + 1 << ":" << endl;
        
        // Loop untuk membandingkan elemen bersebelahan
        for (int j = 0; j < n - i - 1; j++) {
            // Jika elemen kiri lebih besar dari kanan, tukar
            if (arr[j] > arr[j + 1]) {
                // Proses penukaran (swap)
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                cout << "  Tukar " << arr[j+1] << " dengan " << arr[j] << " -> ";
                tampilkanArray(arr, n);
            }
        }
    }
    
    cout << "\nHasil akhir: ";
    tampilkanArray(arr, n);
}

// ========== 2. SELECTION SORT ==========
// Cara kerja: Mencari elemen terkecil, lalu pindahkan ke posisi paling depan
// Ulangi untuk posisi berikutnya
void selectionSort(int arr[], int n) {
    cout << "\n=== SELECTION SORT ===" << endl;
    cout << "Data awal: ";
    tampilkanArray(arr, n);
    
    // Loop untuk setiap posisi
    for (int i = 0; i < n - 1; i++) {
        int indexMin = i; // Anggap elemen pertama adalah yang terkecil
        
        // Cari elemen terkecil dari sisa array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[indexMin]) {
                indexMin = j; // Update index elemen terkecil
            }
        }
        
        // Tukar elemen terkecil dengan elemen di posisi i
        if (indexMin != i) {
            int temp = arr[i];
            arr[i] = arr[indexMin];
            arr[indexMin] = temp;
            
            cout << "Langkah " << i + 1 << ": Tukar posisi " << i << " dengan " << indexMin << " -> ";
            tampilkanArray(arr, n);
        }
    }
    
    cout << "\nHasil akhir: ";
    tampilkanArray(arr, n);
}

// ========== 3. INSERTION SORT ==========
// Cara kerja: Seperti menyusun kartu di tangan, ambil satu kartu
// lalu sisipkan ke posisi yang tepat di antara kartu yang sudah tersusun
void insertionSort(int arr[], int n) {
    cout << "\n=== INSERTION SORT ===" << endl;
    cout << "Data awal: ";
    tampilkanArray(arr, n);
    
    // Mulai dari elemen kedua
    for (int i = 1; i < n; i++) {
        int kunci = arr[i]; // Simpan elemen yang akan disisipkan
        int j = i - 1;
        
        cout << "\nLangkah " << i << ": Sisipkan " << kunci << endl;
        
        // Geser elemen yang lebih besar dari kunci ke kanan
        while (j >= 0 && arr[j] > kunci) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Sisipkan kunci di posisi yang tepat
        arr[j + 1] = kunci;
        cout << "  Hasil: ";
        tampilkanArray(arr, n);
    }
    
    cout << "\nHasil akhir: ";
    tampilkanArray(arr, n);
}

// ========== 4. LINEAR SEARCH (Pencarian Linear) ==========
// Cara kerja: Mencari data satu per satu dari awal sampai akhir
int linearSearch(int arr[], int n, int cari) {
    cout << "\n=== LINEAR SEARCH ===" << endl;
    cout << "Mencari angka: " << cari << endl;
    
    // Cek setiap elemen satu per satu
    for (int i = 0; i < n; i++) {
        cout << "Cek posisi " << i << ": " << arr[i];
        
        if (arr[i] == cari) {
            cout << " -> KETEMU!" << endl;
            return i; // Kembalikan posisi/index dimana data ditemukan
        }
        cout << " -> Bukan" << endl;
    }
    
    return -1; // Kembalikan -1 jika data tidak ditemukan
}

// ========== 5. BINARY SEARCH (Pencarian Biner) ==========
// Cara kerja: Data HARUS SUDAH TERURUT! Cari di tengah, lalu bagi dua area pencarian
// Lebih cepat dari linear search
int binarySearch(int arr[], int n, int cari) {
    cout << "\n=== BINARY SEARCH ===" << endl;
    cout << "Mencari angka: " << cari << endl;
    cout << "CATATAN: Data harus sudah terurut!" << endl;
    
    int kiri = 0;        // Index paling kiri
    int kanan = n - 1;   // Index paling kanan
    int langkah = 1;
    
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2; // Hitung posisi tengah
        
        cout << "\nLangkah " << langkah << ":" << endl;
        cout << "  Area pencarian: index " << kiri << " sampai " << kanan << endl;
        cout << "  Cek tengah (index " << tengah << "): " << arr[tengah] << endl;
        
        // Cek apakah elemen tengah adalah yang dicari
        if (arr[tengah] == cari) {
            cout << "  -> KETEMU!" << endl;
            return tengah;
        }
        
        // Jika yang dicari lebih kecil, cari di bagian kiri
        if (arr[tengah] > cari) {
            cout << "  -> " << cari << " lebih kecil, cari di sebelah kiri" << endl;
            kanan = tengah - 1;
        }
        // Jika yang dicari lebih besar, cari di bagian kanan
        else {
            cout << "  -> " << cari << " lebih besar, cari di sebelah kanan" << endl;
            kiri = tengah + 1;
        }
        
        langkah++;
    }
    
    return -1; // Data tidak ditemukan
}

// ========== FUNGSI UTAMA (MAIN) ==========
int main() {
    cout << "========================================" << endl;
    cout << "PROGRAM SORTING DAN SEARCHING UNTUK PEMULA" << endl;
    cout << "========================================" << endl;
    
    // Data untuk sorting
    int dataBubble[] = {64, 34, 25, 12, 22, 11, 90};
    int dataSelection[] = {64, 34, 25, 12, 22, 11, 90};
    int dataInsertion[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7; // Jumlah elemen
    
    // Jalankan Bubble Sort
    bubbleSort(dataBubble, n);
    
    cout << "\n========================================" << endl;
    
    // Jalankan Selection Sort
    selectionSort(dataSelection, n);
    
    cout << "\n========================================" << endl;
    
    // Jalankan Insertion Sort
    insertionSort(dataInsertion, n);
    
    cout << "\n========================================" << endl;
    
    // Data untuk searching
    int dataSearch[] = {64, 34, 25, 12, 22, 11, 90};
    int cari = 22;
    
    // Linear Search
    int hasil = linearSearch(dataSearch, n, cari);
    if (hasil != -1) {
        cout << "\nAngka " << cari << " ditemukan di posisi/index " << hasil << endl;
    } else {
        cout << "\nAngka " << cari << " tidak ditemukan" << endl;
    }
    
    cout << "\n========================================" << endl;
    
    // Binary Search (data harus terurut dulu)
    int dataBinary[] = {11, 12, 22, 25, 34, 64, 90}; // Data sudah terurut
    cari = 25;
    
    cout << "Data terurut: ";
    tampilkanArray(dataBinary, n);
    
    hasil = binarySearch(dataBinary, n, cari);
    if (hasil != -1) {
        cout << "\nAngka " << cari << " ditemukan di posisi/index " << hasil << endl;
    } else {
        cout << "\nAngka " << cari << " tidak ditemukan" << endl;
    }
    
    return 0;
}