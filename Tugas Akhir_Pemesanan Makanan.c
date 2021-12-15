#include <stdio.h> //Library Standar Input Output
#include <windows.h> //Library untuk mengakses system windows
#include <string.h> //Library Untuk mengguaka fugsi strig


//Daftar Prosedur Yang digunakan
void start(); //Prosesdur untuk memulai Aplikasi
void menuAdmin(); //Prosedur Untuk menampilkan menu admin
void adminMenuMakananMinuman(); //Prosedur yang digunakan untuk menampilkan sub menu admin
void daftarMenu(); //Prosedur yang digunakan untuk menampilkan daftar makanan dan minuman
void tambahMenu(); //Prosedur yang digunakan untuk menambahkan makanan ataupun minuman
void tambahMakanan(); // Prosedur yang digunakan untuk menambahkan makanan
void tambahMinuman(); //Prosedur yang digunakan untuk menambahkan minuman
void user(); //Prosedur untuk Customer yang ingin berbelanja

int main(void) {
  start(); //Prosesdur yang Nantinya dipanggil untuk memulai program
}


//Prosedur start
void start(){
	int pilihanMenuUtama; //Variable yang digunakan untuk memilih menu
	char admin[6]; // Menyimpan inputan password admin
	int attempt=1; // Menyimpan percobaan
	do{
		printf ("\t\t\t|====================================================|\n");      
		printf ("\t\t\t|          Selamat Datang di Pemesanan Makanan       |\n");
		printf ("\t\t\t|----------------------------------------------------|\n");
		printf ("\t\t\t|Silahkan pilih menu yang diinginkan                 |\n");
		printf ("\t\t\t|1.Memesan Makanan dan Minuman                       |\n");
		printf ("\t\t\t|2.Admin                                             |\n");
    	printf ("\t\t\t|3.Exit                                              |\n");
		printf ("\t\t\t|====================================================|\n");
		printf ("\t\t\tNomor menu yang ingin dipilih :");
		scanf("%d",&pilihanMenuUtama);
		if(pilihanMenuUtama==1){
			system("cls"); //Membersihkan tampilan yang ada pada command prompt
			user();
		}
		else if(pilihanMenuUtama==2){
			system("cls");
			do{
				printf ("Masukkan Password :");
				scanf ("%s",& admin); //%[^\n]s berfungsi untuk menerima inputan karakter hingga diinputkan new line			
				if(attempt == 3 && strcmp (admin,"admin") != 0){
					printf ("Anda Gagal masuk\n");
					printf ("Anda akan diarahkan ke menu utama\n");
					getch();// Berfungsi menerima inputan, dalam kasus ini berfungsi untuk menerima inputan keyboard apa saja, baru dapat melanjutkan program
					system ("cls");
					start();
				}else{
					if (strcmp (admin,"admin")==0){ //Meggunakan fungsi strcmp untuk membandigkan string yang dimana mengembalika nilai 0 jika bernilai true
						system ("cls");
						menuAdmin();
					}else{
						printf ("!!!Password salah!!!\n");
						printf ("!!!Coba masukan kembali!!!\n");
						attempt++;
						getch();
						system ("cls");
					}	
				}
			} while (strcmp (admin,"admin") != 0 || attempt <3); // Melakukan perulangan ketika password salah

		}
		else if(pilihanMenuUtama==3){
			system("cls");
			exit(1);//Menghentikan program
		}else{
			system("cls");
		    printf ("\t\t\t|====================================================|\n");      
		    printf ("\t\t\t| INPUTAN YANG ANDA MASUKAN SALAH SILAKAN COBA LAGI! |\n");
		    printf ("\t\t\t|====================================================|\n");
		    printf("\n");
		}
	}while(pilihanMenuUtama<1 || pilihanMenuUtama>3); //Validasi pilihan menu berupa perulangan
}



//Prosedur admin
void menuAdmin(){
	int pilihanMenuAdmin; //Variable yang digunakan untuk memilih menu
		do{
			printf ("\t\t\t|====================================================|\n");      
			printf ("\t\t\t|           Selamat Datang Kembali Admin             |\n");
			printf ("\t\t\t|----------------------------------------------------|\n");
			printf ("\t\t\t|Silahkan pilih menu yang diinginkan                 |\n");
			printf ("\t\t\t|1.Daftar Menu                                       |\n");
			printf ("\t\t\t|2.Daftar Transaksi                                  |\n");
			printf ("\t\t\t|3.Kembali ke Menu Utama                             |\n");
			printf ("\t\t\t|====================================================|\n");
			printf ("\t\t\tNomor menu yang ingin dipilih :");
			scanf("%d",&pilihanMenuAdmin);
			if(pilihanMenuAdmin==1){
				system("cls"); //Membersihkan tampilan yang ada pada command prompt
				adminMenuMakananMinuman();
			}else if(pilihanMenuAdmin==2){
				system("cls");			
			}else if(pilihanMenuAdmin==3){
				system("cls");
				start(); // Kembali ke menu utama
			}else{
				system("cls");
				printf ("\t\t\t|====================================================|\n");      
				printf ("\t\t\t| INPUTAN YANG ANDA MASUKAN SALAH SILAKAN COBA LAGI! |\n");
				printf ("\t\t\t|====================================================|\n");
				printf("\n");
			}
		}while(pilihanMenuAdmin<1 || pilihanMenuAdmin>3); //Validasi pilihan menu berupa perulangan

}

//Prosedur daftar menu untuk admin
void adminMenuMakananMinuman(){
	int pilihanMenuAdminMakananMinuman; //Variable yang digunakan untuk memilih menu
	do{
		printf ("\t\t\t|====================================================|\n");      
		printf ("\t\t\t|           Selamat Datang Kembali Admin             |\n");
		printf ("\t\t\t|----------------------------------------------------|\n");
		printf ("\t\t\t|Silahkan pilih menu yang diinginkan                 |\n");
		printf ("\t\t\t|1.Daftar Makanan dan Minuman                        |\n");
		printf ("\t\t\t|2.Tambah Menu Makanan atau Minuman                  |\n");
    	printf ("\t\t\t|3.Kembali ke menu utama admin                       |\n");
		printf ("\t\t\t|====================================================|\n");
		printf ("\t\t\tNomor menu yang ingin dipilih :");
		scanf("%d",&pilihanMenuAdminMakananMinuman);
		if(pilihanMenuAdminMakananMinuman==1){
			system("cls"); //Membersihkan tampilan yang ada pada command prompt
			daftarMenu();
		}
		else if(pilihanMenuAdminMakananMinuman==2){
			system("cls");
			tambahMenu();
		}
		else if(pilihanMenuAdminMakananMinuman==3){
			system("cls");
			menuAdmin(); //Kembali ke menu utama admin 
		}else{
			system("cls");
		    printf ("\t\t\t|====================================================|\n");      
		    printf ("\t\t\t| INPUTAN YANG ANDA MASUKAN SALAH SILAKAN COBA LAGI! |\n");
		    printf ("\t\t\t|====================================================|\n");
		    printf("\n");
		}
	}while(pilihanMenuAdminMakananMinuman<1 || pilihanMenuAdminMakananMinuman>3); //Validasi pilihan menu berupa perulangan
}

//Prosedur untuk menampilkan daftar makanan dan minuman
void daftarMenu(){
	char makanan;
	char minuman;
	printf ("\t\t\t|====================================================|\n");      
	printf ("\t\t\t|             BERIKUT DAFTAR MENU MAKANAN            |\n");
	printf ("\t\t\t|====================================================|\n");
	FILE*list_makanan;
	list_makanan=fopen ("../UAS-Tugas Akhir/DaftarMakanan.txt","r");
	if (list_makanan != NULL){
		while ((makanan=fgetc(list_makanan))!=EOF){
			printf ("%c",makanan);
		}
	}else {
		printf ("\tError : File tidak terbaca\n");
		printf ("\tPress any key to continue ...\n");
		getch();
	}
	fclose(list_makanan);

	
	printf ("\t\t\t|====================================================|\n");      
	printf ("\t\t\t|             BERIKUT DAFTAR MENU MINUMAN            |\n");
	printf ("\t\t\t|====================================================|\n");
	FILE*list_minuman;
	list_minuman=fopen ("../UAS-Tugas Akhir/DaftarMinuman.txt","r");
	if (list_minuman != NULL){
		while ((minuman=fgetc(list_minuman))!=EOF){
			printf ("%c",minuman);
		}
	}else {
		printf ("\tError : File tidak terbaca\n");
		printf ("\tPress any key to continue ...\n");
		getch();
	}
	fclose(list_minuman);
	printf ("\tTekan tombol apa saja untuk kembali ke menu admin utama\n");
	getch();
	system("cls");
	menuAdmin();
}


//Prosedur untuk menambahkan menu makanan ataupun minuman
void tambahMenu(){
	int pilihanMenuTambahMakananMinuman; //Variable yang digunakan untuk memilih menu
	do{
		printf ("\t\t\t|====================================================|\n");      
		printf ("\t\t\t|           Selamat Datang Kembali Admin             |\n");
		printf ("\t\t\t|----------------------------------------------------|\n");
		printf ("\t\t\t|Silahkan pilih menu yang diinginkan                 |\n");
		printf ("\t\t\t|1.Tambah Makanan                                    |\n");
		printf ("\t\t\t|2.Tambah Minuman                                    |\n");
    	printf ("\t\t\t|3.Kembali                                           |\n");
		printf ("\t\t\t|====================================================|\n");
		printf ("\t\t\tNomor menu yang ingin dipilih :");
		scanf("%d",&pilihanMenuTambahMakananMinuman);
		if(pilihanMenuTambahMakananMinuman==1){
			system("cls"); //Membersihkan tampilan yang ada pada command prompt
			tambahMakanan(); //Menampilkan menu tambah makanan
		}
		else if(pilihanMenuTambahMakananMinuman==2){
			system("cls");
			tambahMinuman(); //Menampilkan menu tambah minuman
		}
		else if(pilihanMenuTambahMakananMinuman==3){
			system("cls");
			adminMenuMakananMinuman(); //Kembali ke menu makanan dan minuman
		}else{
			system("cls");
		    printf ("\t\t\t|====================================================|\n");      
		    printf ("\t\t\t| INPUTAN YANG ANDA MASUKAN SALAH SILAKAN COBA LAGI! |\n");
		    printf ("\t\t\t|====================================================|\n");
		    printf("\n");
		}
	}while(pilihanMenuTambahMakananMinuman<1 || pilihanMenuTambahMakananMinuman>3); //Validasi pilihan menu berupa perulangan
}

//Prosedur untuk menambahkan menu makanan
void tambahMakanan(){
	char namaMakanan[100];//menyimpan string nama makanan
	int hargaMakanan;//menyimpan harga makanan
	char opsi;
	printf ("\t\t\t|====================================================|\n");      
	printf ("\t\t\t|             Menambahkan Menu Makanan               |\n");
	printf ("\t\t\t|----------------------------------------------------|\n");
	printf ("\t\t\t|Silahkan masukan nama makanan dan harga makanan     |\n");
	printf ("\t\t\t|====================================================|\n");
	printf ("\t\t\tNama Makanan :");
	scanf(" %[^\n]s",& namaMakanan); // Untuk membaca inputan hingga new line diiputkan
	printf ("\t\t\tHarga Makanan :");
	scanf(" %d",& hargaMakanan);
	FILE*tambah_makanan;
	tambah_makanan=fopen ("../UAS-Tugas Akhir/DaftarMakanan.txt","a+"); //Membuka file dengan cara a+ yang dimana dapat menambahkan data dan membuat file txt jika tidak ada
	fprintf (tambah_makanan,"\tNama Makanan:%s\n",namaMakanan); //Fungsi fprintf adalah menulis kedalam file txt
	fprintf	(tambah_makanan,"\tHarga Makanan:%d\n",hargaMakanan);
	fclose(tambah_makanan);
	printf ("\t\t\tBerhasil Menambahkan Menu Makanan\n");
	printf ("\t\t\tJika ingin menambahkan menu makanan lagi masukan 'Y'?  \n\t\t\t Masukan inputan :");
	scanf (" %c",&opsi);
	if ((opsi=='y')||(opsi=='Y')){
		system("cls");
		tambahMakanan();
	}else{
		system("cls");
		menuAdmin();
	}
}
//Prosedur untuk menambahkan menu Minuman
void tambahMinuman(){
	char namaMinuman[100];//menyimpan string nama Minuman
	int hargaMinuman;//menyimpan harga minuman
	char opsi;
	printf ("\t\t\t|====================================================|\n");      
	printf ("\t\t\t|             Menambahkan Menu Minuman               |\n");
	printf ("\t\t\t|----------------------------------------------------|\n");
	printf ("\t\t\t|Silahkan masukan nama minuman dan harga minuman     |\n");
	printf ("\t\t\t|====================================================|\n");
	printf ("\t\t\tNama Minuman :");
	scanf(" %[^\n]s",& namaMinuman); // Untuk membaca inputan hingga new line diiputkan
	printf ("\t\t\tHarga Minuman :");
	scanf(" %d",& hargaMinuman);
	FILE*tambah_minuman;
	tambah_minuman=fopen ("../UAS-Tugas Akhir/DaftarMinuman.txt","a+"); //Membuka file dengan cara a+ yang dimana dapat menambahkan data dan membuat file txt jika tidak ada
	fprintf (tambah_minuman,"\tNama Minuman:%s\n",namaMinuman); //Fungsi fprintf adalah menulis kedalam file txt
	fprintf	(tambah_minuman,"\tHarga Minuman:%d\n",hargaMinuman);
	fclose(tambah_minuman);
	printf ("\t\t\tBerhasil Menambahkan Menu Minuman\n");
	printf ("\t\t\tJika ingin menambahkan menu minuman lagi masukan 'Y'?  \n\t\t\t Masukan inputan :");
	scanf (" %c",&opsi);
	if ((opsi=='y')||(opsi=='Y')){
		system("cls");
		tambahMinuman();
	}else{
		system("cls");
		menuAdmin();
	}
}

void user(){
	int usermakananminuman;
	printf ("\t\t\t|====================================================|\n");      
	printf ("\t\t\t|           Selamat Datang di Kedai F                |\n");
	printf ("\t\t\t|----------------------------------------------------|\n");
	printf ("\t\t\t|Silahkan pilih menu yang diinginkan                 |\n");
	printf ("\t\t\t|1.Daftar Makanan dan Minuman                        |\n");
	printf ("\t\t\tNomor menu yang ingin dipilih :");
	scanf("%d",&usermakananminuman);
		if(usermakananminuman==1){
			system("cls"); //Membersihkan tampilan yang ada pada command prompt
			daftarMenuUser();
		}
}

void daftarMenuUser(){
	char makanan;
	char minuman;
	printf ("\t\t\t|====================================================|\n");      
	printf ("\t\t\t|             BERIKUT DAFTAR MENU MAKANAN            |\n");
	printf ("\t\t\t|====================================================|\n");
	FILE*list_makanan;
	list_makanan=fopen ("../UAS-Tugas Akhir/DaftarMakanan.txt","r");
	if (list_makanan != NULL){
		while ((makanan=fgetc(list_makanan))!=EOF){
			printf ("%c",makanan);
		}
	}else {
		printf ("\tError : File tidak terbaca\n");
		printf ("\tPress any key to continue ...\n");
		getch();
	}
	fclose(list_makanan);

	
	printf ("\t\t\t|====================================================|\n");      
	printf ("\t\t\t|             BERIKUT DAFTAR MENU MINUMAN            |\n");
	printf ("\t\t\t|====================================================|\n");
	FILE*list_minuman;
	list_minuman=fopen ("../UAS-Tugas Akhir/DaftarMinuman.txt","r");
	if (list_minuman != NULL){
		while ((minuman=fgetc(list_minuman))!=EOF){
			printf ("%c",minuman);
		}
	}else {
		printf ("\tError : File tidak terbaca\n");
		printf ("\tPress any key to continue ...\n");
		getch();
	}
	fclose(list_minuman);
	printf ("\tTekan tombol apa saja untuk kembali ke menu admin utama\n");
	getch();
	system("cls");
	start();
}
