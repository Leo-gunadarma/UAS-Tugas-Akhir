#include <stdio.h> //Library Standar Input Output
#include <windows.h> //Library untuk mengakses system windows
#include <string.h> //Library Untuk mengguaka fugsi strig


//Daftar Prosedur Yang digunakan
void start(); //Prosesdur untuk memulai Aplikasi
void menuAdmin(); //Prosedur Untuk menampilkan menu admin

int main(void) {
  start(); //Prosesdur yang Nantinya dipanggil untuk memulai program
}


//Prosedur start
void start(){
	int pilihan; //Variable yang digunakan untuk memilih menu
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
		scanf("%d",&pilihan);
		if(pilihan==1){
			system("cls"); //Membersihkan tampilan yang ada pada command prompt
		}
		else if(pilihan==2){
			system("cls");
			menuAdmin();

		}
		else if(pilihan==3){
			system("cls");
			exit(1);//Menghentikan program
		}else{
			system("cls");
		    printf ("\t\t\t|====================================================|\n");      
		    printf ("\t\t\t| INPUTAN YANG ANDA MASUKAN SALAH SILAKAN COBA LAGI! |\n");
		    printf ("\t\t\t|====================================================|\n");
		    printf("\n");
		}
	}while(pilihan<1 || pilihan>3); //Validasi pilihan menu berupa perulangan
}



//Prosedur admin
void menuAdmin(){
	char admin[6]; // Menyimpan Password
	int attempt=1; // Menyimpan percobaan
	do{
		printf ("Masukkan Password :");
		scanf ("%s",& admin);			
		if(attempt == 3 && strcmp (admin,"admin") != 0){
			printf ("Anda Gagal masuk\n");
			printf ("Anda akan diarahkan ke menu utama\n");
			getch();// Berfungsi menerima inputan, dalam kasus ini berfungsi untuk menerima inputan keyboard apa saja, baru dapat melanjutkan program
			system ("cls");
			start();
		}else{
			if (strcmp (admin,"admin")==0){ //Meggunakan fungsi strcmp untuk membandigkan string yang dimana mengembalika nilai 0 jika bernilai true
				printf ("Anda Berhasil masuk\n");
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

