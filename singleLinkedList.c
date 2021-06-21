#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct karyawan{
	char nama[30]; //menampung karakter nama karyawan
	int jenis_kelamin; //menampung jenis kelamin karyawan
	char kota[30]; //menampung karakter kota karyawan
	int status_karyawan; //menampung status karyawan
	int status_kawin; //menampung status kawin karyawan
	int umur; //menampung integer umur karyawan
	struct karyawan *next; //menampung alamat data selanjutnya
}*head, *tail, *current;
//head => pointer yang menyimpan alamat data pertama
//tail => pointer yang menyimpan alamat data terakhir
//current => pointer yang digunakan sebagai temporary variabel

void pushHead(char nama[], int jenis_kelamin, char kota[], int status_karyawan, int status_kawin, int umur){
    //alokasi memory untuk data baru
	current = (struct karyawan*)malloc(sizeof(struct karyawan));
	strcpy(current->nama, nama); //copy nilai variabel parameter nama ke current->nama
	current->jenis_kelamin = jenis_kelamin; //assign data ke dalam struct
	strcpy(current->kota, kota); //copy nilai variabel parameter kota ke current->kota
	current->status_karyawan= status_karyawan; //assign data ke dalam struct
	current->status_kawin= status_kawin; //assign data ke dalam struct
	current->umur = umur; //assign data ke dalam struct

	if(head == NULL){ //jika nilai head adalah null, maka set head = tail = current
		head = tail = current; //set nilai head = tail = current
	}
	else{ //jika nilai head tidak null, maka
		current->next = head; //set nilai current->next = head
		head = current; //kemudian set nilai head = current
	}
}

void pushTail(char nama[], int jenis_kelamin, char kota[], int status_karyawan, int status_kawin, int umur){
	current = (struct karyawan*)malloc(sizeof(struct karyawan)); //alokasi memory untuk data baru
	strcpy(current->nama, nama); //copy nilai variabel parameter nama ke current->nama
	current->jenis_kelamin = jenis_kelamin; //assign data ke dalam struct
	strcpy(current->kota, kota); //copy nilai variabel parameter kota ke current->kota
	current->status_karyawan= status_karyawan; //assign data ke dalam struct
	current->status_kawin= status_kawin; //assign data ke dalam struct
	current->umur = umur; //assign data ke dalam struct

	if(head == NULL){ //jika nilai head adalah null, maka set head = tail = current
		head = tail = current; //set nilai head = tail = current
	}
	else{ //jika nilai head tidak null, maka
		tail->next = current; //set nilai tail->next = current
		tail = current; //kemudian set nilai tail = current
	}
	tail->next = NULL; //kemudian set nilai tail menjadi null
}

void popHead(){
	current=head; //set nilai current sebagai head
	if(head==NULL){ //jika head bernilai null
		printf("No data"); //tampilkan info tidak ada data
	}else if(head==tail){ //jika nilai head = tail
		head=tail=NULL; //set nilai head = tail = null
		free(current); //hapus nilai current (head)
	}else{ //jika nilai head bukan null dan bukan tail
		head=head->next; //set nilai head menjadi data selanjutnya dari head
		free(current);// hapus nilai current (head)
	}
}

void popTail(){
	if(head==NULL){ //jika nilai head = null
		printf("No data"); //tampilkan info tidak ada data
	}else if(head==tail){ //jika nilai head = tail
		head=tail=NULL; //set nilai head = tail = null
		free(current); //hapus nilai current
	}else{ //jika nilai head bukan null dan bukan tail
		struct karyawan *temp=head; //buat variabel penampung baru dan assign/beri nilai mulai dari head
		while(temp->next!=tail){ //looping untuk mencari posisi 1 data sebelum tail
			temp=temp->next; //set nilai temp menjadi 1 data setelahnya
		}
		current=tail; //set nilai current menjadi tail
		tail=temp; //set nilai tail menjadi 1 data sebelum tail (hasil looping)
		free(current); //hapus nilai current
		tail->next=NULL; //set nilai setelah next menjadi null/pointer next punya tail diset null
	}
}

void print(){
    char *jk, *status, *statKawin;
	current = head; //set current sebagai head
	while(current != NULL){ //looping selama current bukan null
        if(current->jenis_kelamin == 1){
            jk = "Laki-laki";
        } else if(current->jenis_kelamin == 0){
            jk = "Perempuan";
        } else{
            jk = "Bukan Manusia";
        }
        if(current->status_karyawan == 1){
            status = "Tetap";
        } else if(current->status_karyawan == 0){
            status = "Tidak Tetap";
        } else{
            status = "Bukan Karyawan";
        }
        if(current->status_kawin == 1){
            statKawin = "Kawin";
        } else{
            statKawin = "Tidak Kawin";
        }
		printf("Nama: %s \t Jenis Kelamin: %s \t Kota: %s \t Status Karyawan: %s \t Status Kawin: %s \t Umur: %d \n",current->nama, jk, current->kota, status, statKawin, current->umur); //tampilkan data karyawan
		current = current->next; //set current menjadi nilai setelahnya
	}
}

int main(){
    int jumlah, i, jk, status_karyawan, status_kawin, umur;
    char nama[30], kota[30], hapustambah, pilihan, lagi;
    awal:
    system("clear");
    printf("Masukkan Jumlah Data: "); scanf("%d", &jumlah);
    for(i=1; i<=jumlah; i++){
        printf("Masukkan data ke %d: \n", i);
        printf("Nama: "); scanf("%s", nama);
        printf("Jenis Kelamin (1 untuk Laki-laki, 0 untuk Perempuan): "); scanf("%d", &jk);
        printf("Kota: "); scanf("%s", kota);
        printf("Status Karyawan (1 untuk Tetap, 0 untuk Tidak Tetap): "); scanf("%d", &status_karyawan);
        printf("Status Kawin (1 untuk Kawin, 0 untuk Tidak Kawin): "); scanf("%d", &status_kawin);
        printf("Umur: "); scanf("%d", &umur);
        if(i == 1){
            pushHead(nama, jk, kota, status_karyawan, status_kawin, umur);
        } else{
            printf("Masukkan data ke Depan atau Belakang? (d untuk depan, b untuk belakang): ");
            scanf("%s", &pilihan);
            if(pilihan == 'd'){
                pushHead(nama, jk, kota, status_karyawan, status_kawin, umur);
            } else{
                pushTail(nama, jk, kota, status_karyawan, status_kawin, umur);
            }
        }
    }
    print();
    printf("Mau Menghapus atau Menambah Data? (y untuk nambah, n untuk hapus) ");
    scanf("%s", &hapustambah);
    if(hapustambah == 'y'){
        printf("Masukkan data ke %d: \n", i);
        printf("Nama: "); scanf("%s", nama);
        printf("Jenis Kelamin (1 untuk Laki-laki, 0 untuk Perempuan): "); scanf("%d", &jk);
        printf("Kota: "); scanf("%s", kota);
        printf("Status Karyawan (1 untuk Tetap, 0 untuk Tidak Tetap): "); scanf("%d", &status_karyawan);
        printf("Status Kawin (1 untuk Kawin, 0 untuk Tidak Kawin): "); scanf("%d", &status_kawin);
        printf("Umur: "); scanf("%d", &umur);
        printf("Masukkan data ke Depan atau Belakang? (d untuk depan, b untuk belakang): ");
        scanf("%s", &pilihan);
        if(pilihan == 'd'){
            pushHead(nama, jk, kota, status_karyawan, status_kawin, umur);
        } else{
            pushTail(nama, jk, kota, status_karyawan, status_kawin, umur);
        }
    } else{
        printf("Hapus Depan atau Belakang? (d untuk depan, b untuk belakang) ");
        scanf("%s", &pilihan);
        if(pilihan == 'd'){
            popHead();
        } else{
            popTail();
        }
    }

    print();
    printf("Mau Menambah Data? (y untuk nambah, n untuk tidak) ");
    scanf("%s", &lagi);
    if(lagi == 'y'){
        goto awal;
    } else{
        goto akhir;
    }
    akhir:
	getchar();
	return 0;
}