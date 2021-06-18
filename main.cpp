#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// deklarasi record utama
struct record_pengembalian{
    string id_buku, id_peminjam, id_petugas, tgl_kembali;
};

void coba_lagi(), input_data(), output_data(string nm_file, string nm_output), search_data(), sort_menu(), quick_sort(string array[][5], int first, int last, int kolom), merge_sort();

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
        system("cls");

        // kondisional pilihan menu
        switch (pilihan) {
        case 1:
            input_data();
            break;
            
        case 2:
            output_data("---", "PENGEMBALIAN BUKU");
	        coba_lagi();
            break;
            
        case 3:
            search_data();
            break;
            
        case 4:
            sort_menu();
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
    char nama_file[100];
    int banyak_data;
    record_pengembalian data_pengembalian;

    cout<<setfill('=')<<setw(35)<<'='<<"\n";
    cout<<" INPUT DATA PENGEMBALIAN BUKU\n";
    cout<<setfill('=')<<setw(35)<<'='<<"\n";

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
        arsip_pengembalian<<"\t"<<data_pengembalian.id_buku<<"\t"<<data_pengembalian.id_peminjam<<"\t"<<data_pengembalian.id_petugas<<"\t"<<data_pengembalian.tgl_kembali<<"\t\n";
        
        cout<<"\n";
    }

    // nutup file
    arsip_pengembalian.close();

    coba_lagi();
}

//no 2 tampil data
void output_data(string nm_file, string nm_output){
	string nama_file, baris_data;
	// int banyak_data=0;
    record_pengembalian data_pengembalian;
	cout<<setfill('=')<<setw(35)<<'='<<"\n";
    cout<<" OUTPUT DATA "<<nm_output<<"\n";
    cout<<setfill('=')<<setw(35)<<'='<<"\n";
    
    nama_file = nm_file;
    if(nama_file == "---") {
        //input nama file yg ingin 
        cout<<"Masukkan nama file\t= ";
        cin>>nama_file;
        cout<<"\n";
    }
    ifstream arsip_pengembalian(nama_file);

   	if(arsip_pengembalian.is_open()) {
        cout<<setfill('=')<<setw(66)<<'='<<"\n";
        cout<<"\tID Buku\t\tID Peminjam\tID Petugas\tTanggal Kembali\n";
        cout<<setfill('=')<<setw(66)<<'='<<"\n";

        while(getline(arsip_pengembalian, baris_data)) {
            cout<<baris_data<<endl;
        }
    } else cout <<"Tidak ada rekap yang ditemukan!!";
    // cout <<"\tBanyak data = "<<banyak_data;
    //nutup file
    arsip_pengembalian.close();
}

// deklarasi prosedur menu 3 (search data)
void search_data() {
    char nama_file[100];
    string baris_data, kolom_dicari;
    int i = 0, j = 0, pilihan;
    bool ketemu = false, cek = false;
    record_pengembalian data_ketemu;
    
    cout<<setfill('=')<<setw(35)<<'='<<"\n";
    cout<<" PENCARIAN DATA DENGAN SEQUENSIAL\n";
    cout<<setfill('=')<<setw(35)<<'='<<"\n";

    // input nama file asal pencarian data
    cout<<"Masukkan nama file\t= ";
    cin>>nama_file;
    ifstream arsip_pengembalian(nama_file);

    // membuat file hasil pencarian
    ofstream arsip_pencarian_input("hasil_pencarian.txt");

    // kondisi jika file ada dan terbuka
    if(arsip_pengembalian.is_open()) {
        cout<<"\nDaftar Kolom:\n\t1. ID Buku\n\t2. ID Peminjam\n\t3. ID Petugas\n\t4. Tanggal Kembali\n";
        cout<<setfill('=')<<setw(35)<<'='<<"\n";
        cout<<setfill('=')<<setw(35)<<'='<<"\n";

        // input pilihan menu
        cout<<"\nMasukkan Kolom yang Ingin Dicari\t= ";
        cin>>pilihan;

        // kondisional pilihan menu
        switch (pilihan) {
        case 1:
            cout<<"Masukkan id buku\t= ";
            break;
            
        case 2:
            cout<<"Masukkan id peminjam\t= ";
            break;
            
        case 3:
            cout<<"Masukkan id petugas\t= ";
            break;
            
        case 4:
            cout<<"Masukkan tanggal kembali\t= ";
            break;
        
        default:
            break;
        }

        if(pilihan<=4 && pilihan>0) {
            // input id buku yang dicari
            cin>>kolom_dicari;
            system("cls");

            while(arsip_pengembalian.eof()==0 && !ketemu) {
                while(getline(arsip_pengembalian, baris_data, '\t')) {
                    if(i % 5 == pilihan && baris_data == kolom_dicari) {
                        ketemu = true;
                        cek = true;
                    }

                    if(j < 5) {
                        switch(j) {
                            case 1:
                                data_ketemu.id_buku = baris_data;
                                break;
                            case 2:
                                data_ketemu.id_peminjam = baris_data;
                                break;
                            case 3:
                                data_ketemu.id_petugas = baris_data;
                                break;
                            case 4:
                                data_ketemu.tgl_kembali = baris_data;
                                break;
                        }

                        j++;
                    }

                    if(j>=5) {
                        j = 0;
                        if(ketemu) {
                            ketemu = false;

                            // menyimpan data hasil pencarian ke dalam file pencarian
                            arsip_pencarian_input<<data_ketemu.id_buku<<"\t"<<data_ketemu.id_peminjam<<"\t"<<data_ketemu.id_petugas<<"\t"<<data_ketemu.tgl_kembali<<"\n";
                        }
                    }
                    i++;
                }
            }
            arsip_pencarian_input.close();
            
            if(cek){
                // ifstream arsip_pencarian_output("hasil_pencarian.txt");

                // while(getline(arsip_pencarian_output, baris_data)) {
                //     cout<<baris_data<<endl;
                // }
                // arsip_pencarian_output.close();
                output_data("hasil_pencarian.txt", "HASIL PENCARIAN");
            } else
                cout <<"Data tidak ada ditemukan dalam file "<<nama_file;
        }
    // kondisi jika file tidak terbuka
    } else
        cout<<"File tidak dapat dibuka. Silakan coba lagi!";

    // nutup file
    arsip_pengembalian.close();

    coba_lagi();
}

// deklarasi prosedur menu 4 (menu sort data)
void sort_menu() {
    char nama_file[100];
    string data_file[100][5], data_item;
    int pilihan, i = 0, j, kolom;
    
    cout<<setfill('=')<<setw(35)<<'='<<"\n";
    cout<<" PENGURUTAN DATA PENGEMBALIAN BUKU\n";
    cout<<setfill('=')<<setw(35)<<'='<<"\n";

    // input nama file asal pencarian data
    cout<<"Masukkan nama file\t= ";
    cin>>nama_file;
    ifstream arsip_pengembalian(nama_file);

    cout<<endl<<setfill('=')<<setw(35)<<'='<<"\n";

    // kondisi jika file ada dan terbuka
    if(arsip_pengembalian.is_open()) {

        while(getline(arsip_pengembalian, data_item, '\t')) {
            j = i % 5;
            data_file[i/5][j] = data_item;
            i++;
        }

        cout<<"Jenis Pengurutan:\n\t1. Bubble Sort\n\t2. Selection Sort\n\t3. Insertion Sort\n\t4. Shell Sort\n\t5. Quick Sort\n\t6. Merge Sort\n";

        // input pilihan jenis
        cout<<"\nMasukkan Jenis Pengurutan\t= ";
        cin>>pilihan;
        cout<<setfill('=')<<setw(35)<<'='<<"\n";

        cout<<"Daftar Kolom:\n\t1. ID Buku\n\t2. ID Peminjam\n\t3. ID Petugas\n\t4. Tanggal Kembali\n";

        // input pilihan menu
        cout<<"\nMasukkan Kolom yang Ingin Diurutkan\t= ";
        cin>>kolom;
        cout<<setfill('=')<<setw(35)<<'='<<"\n";
        system("cls");

        if(kolom<=4 && kolom>=1){
            // kondisional pilihan menu
            switch (pilihan) {
            case 1:
                // bubble_sort();
                break;
                
            case 2:
                // selection_();
                break;
                
            case 3:
                // insertion_sort();
                break;
                
            case 4:
                // shell_sort();
                break;
                
            case 5:
                quick_sort(data_file, 0, (i/5)-1, kolom);
                break;
                
            case 6:
                // merge_sort();
                break;
            
            default:
                break;
            }

            ofstream arsip_sorting("hasil_sorting.txt");

            // perulangan input data
            for(int k = 0; k <= (i/5)-1; k++) {
                // input data ke dalam file
                arsip_sorting<<"\t"<<data_file[k][1]<<"\t"<<data_file[k][2]<<"\t"<<data_file[k][3]<<"\t"<<data_file[k][4]<<"\t\n";
            }

            // nutup file
            arsip_sorting.close();

            output_data("hasil_sorting.txt", "HASIL SORTING");
        } else
            cout<<"Maaf, input anda salah. Silakan coba lagi!";
    // kondisi jika file tidak terbuka
    } else
        cout<<"File tidak dapat dibuka. Silakan coba lagi!";

    // nutup file
    arsip_pengembalian.close();

    coba_lagi();
}

void quick_sort(string array[][5], int first, int last, int kolom) {
    int low, high;
    string temp[5], list_separator;
    low = first;
    high = last;
    list_separator = array[(first+last)/2][kolom];
    do {
        while (array[low][kolom] < list_separator) low++;
        while (array[high][kolom] > list_separator) high--;
        if (low <= high) {
            for(int i = 0; i < 5; i++) {
                temp[i] = array[low][i];
                array[low][i] = array[high][i];
                array[high][i] = temp[i];
            }
            low++;
            high--;
        }
    } while (low <= high);
    if (first < high) quick_sort(array, first, high, kolom);
    if (low < last) quick_sort(array, low, last, kolom);
}

