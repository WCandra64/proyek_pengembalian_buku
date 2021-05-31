#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// deklarasi record utama
struct record_pengembalian{
    int id_peminjam, id_petugas;
    char id_buku[50], tgl_kembali[10];
};

void coba_lagi(), input_data();

int main() {
    int pilihan = 0;

    // perulangan menu utama
    while (pilihan != 6) {
        cout<<setfill('=')<<setw(25)<<'='<<"\n";
        cout<<" TUGAS PROJECT ALGO 2021\n";
        cout<<setfill('=')<<setw(25)<<'='<<"\n";
        cout<<"\t1. INPUT DATA\n\t2. TAMPILKAN DATA\n\t3. SEARCHING DATA\n\t4. SORTING DATA\n\t5. TRANSAKSI\n\t6. KELUAR\n";
        cout<<setfill('=')<<setw(25)<<'='<<"\n";
        cout<<setfill('=')<<setw(25)<<'='<<"\n";

        // input pilihan menu
        cout<<"Masukkan Pilihan\t= ";
        cin>>pilihan;

        // kondisional pilihan menu
        switch (pilihan) {
        case 1:
            system("cls");
            input_data();
            break;
            
        case 2:
            break;
            
        case 3:
            break;
            
        case 4:
            break;
            
        case 5:
            break;
            
        case 6:
            break;
        
        default:
            coba_lagi();
            break;
        }
        system("cls");
    }

    return 0;
}

// deklarasi prosedur untuk kembali ke menu utama
void coba_lagi() {
    char pilih;

    cout<<"\n\nKembali ke Menu Utama?\n\n";
    cout<<"Y = Kembali\nN = Keluar\nMasukkan Pilihan\t= ";
    cin>>pilih;

    // jika pilih bukan y, maka program dikeluarkan
    if(pilih != 'y')
        exit(0);
}

// deklarasi prosedur menu 1 (input data)
void input_data() {
    string nama_file;
    int banyak_data;
    record_pengembalian data_pengembalian;

    cout<<setfill('=')<<setw(25)<<'='<<"\n";
    cout<<" INPUT DATA KEPENDUDUKAN\n";
    cout<<setfill('=')<<setw(25)<<'='<<"\n";

    // input nama file
    cout<<"Masukkan nama file\t= ";
    cin>>nama_file;
    ofstream arsip_pengembalian(nama_file);

    // input banyak data
    cout<<"\nBanyaknya Data = ";
    cin>>banyak_data;

    // perulangan input data
    for(int i = 0; i < banyak_data; i++) {
        cout<<"\tId Buku\t\t= ";
        cin>>data_pengembalian.id_buku;
        cout<<"\tId Peminjam\t= ";
        cin>>data_pengembalian.id_peminjam;
        cout<<"\tId Petugas\t= ";
        cin>>data_pengembalian.id_petugas;
        cout<<"\tTanggal Kembali\t= ";
        cin>>data_pengembalian.tgl_kembali;

        // input data ke dalam file
        arsip_pengembalian<<data_pengembalian.id_buku<<"\t"<<data_pengembalian.id_peminjam<<"\t"<<data_pengembalian.id_petugas<<"\t"<<data_pengembalian.tgl_kembali<<"\n";
        
        cout<<"\n";
    }

    coba_lagi();
}