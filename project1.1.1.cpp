#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// deklarasi record utama
struct record_pengembalian{
    int id_peminjam, id_petugas;
    char id_buku[50], tgl_kembali[10];
};

void coba_lagi(), input_data(),output_data();

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
        	system("cls");
        	output_data();
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
    char nama_file[100];
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
    	cout <<"\tInput data ke-"<<i+1<<endl;
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

    // nutup file
    arsip_pengembalian.close();

    coba_lagi();
}

//no 2 tampil data

void output_data(){
	
	char nama_file[100];
	int banyak_data=0;
    record_pengembalian data_pengembalian;
	
	cout<<setfill('=')<<setw(25)<<'='<<"\n";
    cout<<" OUTPUT DATA PEMINJAMAN\n";
    cout<<setfill('=')<<setw(25)<<'='<<"\n";
    
    
    //input nama file yg ingin 
    cout <<"Masukkan nama fle\t= ";
    cin>>nama_file;
    cout <<"\n";
    ifstream arsip_pengembalian(nama_file);
   
   	if(arsip_pengembalian.is_open())
	   {
	   		arsip_pengembalian>>data_pengembalian.id_buku>>data_pengembalian.id_peminjam>>data_pengembalian.id_petugas>>data_pengembalian.tgl_kembali;	
		   
		   //perulangan output data
		   while (arsip_pengembalian.eof()==0)
		   {
		   	cout <
	    	cout <<"\tId Buku \t = "<<data_pengembalian.id_buku<<endl;
	    	cout <<"\tId Peminjam\t = "<<data_pengembalian.id_peminjam<<endl;
	    	cout <<"\tId Petugas\t = "<<data_pengembalian.id_petugas<<endl;
	    	cout <<"\tTanggal Kembali\t = "<<data_pengembalian.tgl_kembali<<endl;
	    	cout <<"\n";
	    	
	    	banyak_data = banyak_data+1;
	    	//gatau fungsinya klo ga dipake jd infinite loop
	    	arsip_pengembalian>>data_pengembalian.id_buku>>data_pengembalian.id_peminjam>>data_pengembalian.id_petugas>>data_pengembalian.tgl_kembali;
	    	}
		}
    else cout <<"Tidak ada rekap yang ditemukan!!";
    
    cout <<"\tBanyak data = "<<banyak_data;
    //nutup file
    arsip_pengembalian.close();
    
	coba_lagi();	
	
}
