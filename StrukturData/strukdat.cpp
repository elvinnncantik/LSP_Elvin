#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MAHASISWA 100

// Definisi struktur untuk tanggal
struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};

// Definisi struktur untuk mahasiswa
struct Mahasiswa {
    char npm[15];
    char nama[50];
    char tempat_lahir[30];
    struct Tanggal tanggal_lahir;
    char prodi[50];
};

// Variabel global
struct Mahasiswa daftarMahasiswa[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

// Fungsi untuk menambah data mahasiswa
void tambahData() {
    if (jumlahMahasiswa < MAX_MAHASISWA) {
        struct Mahasiswa mhs;
        
        printf("Masukkan NPM: ");
        scanf("%s", mhs.npm);
        printf("Masukkan Nama: ");
        scanf(" %[^\n]s", mhs.nama);
        printf("Masukkan Tempat Lahir: ");
        scanf(" %[^\n]s", mhs.tempat_lahir);
        printf("Masukkan Tanggal Lahir (DD MM YYYY): ");
        scanf("%d %d %d", &mhs.tanggal_lahir.hari, &mhs.tanggal_lahir.bulan, &mhs.tanggal_lahir.tahun);
        printf("Masukkan Program Studi: ");
        scanf(" %[^\n]s", mhs.prodi);

        daftarMahasiswa[jumlahMahasiswa++] = mhs;
        printf("Data mahasiswa berhasil ditambahkan.\n");
    } else {
        printf("Kapasitas maksimum mahasiswa telah tercapai.\n");
    }
}

// Fungsi untuk menghapus data mahasiswa
void hapusData() {
    char npm[15];
    printf("Masukkan NPM mahasiswa yang akan dihapus: ");
    scanf("%s", npm);

    int index = -1;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (strcmp(daftarMahasiswa[i].npm, npm) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < jumlahMahasiswa - 1; i++) {
            daftarMahasiswa[i] = daftarMahasiswa[i + 1];
        }
        jumlahMahasiswa--;
        printf("Data mahasiswa berhasil dihapus.\n");
    } else {
        printf("Mahasiswa dengan NPM tersebut tidak ditemukan.\n");
    }
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData() {
    if (jumlahMahasiswa == 0) {
        printf("Belum ada data mahasiswa.\n");
        return;
    }

    for (int i = 0; i < jumlahMahasiswa; i++) {
        printf("\nData Mahasiswa ke-%d:\n", i + 1);
        printf("NPM: %s\n", daftarMahasiswa[i].npm);
        printf("Nama: %s\n", daftarMahasiswa[i].nama);
        printf("Tempat Lahir: %s\n", daftarMahasiswa[i].tempat_lahir);
        printf("Tanggal Lahir: %02d-%02d-%04d\n", 
               daftarMahasiswa[i].tanggal_lahir.hari, 
               daftarMahasiswa[i].tanggal_lahir.bulan, 
               daftarMahasiswa[i].tanggal_lahir.tahun);
        printf("Program Studi: %s\n", daftarMahasiswa[i].prodi);
    }
}

int main() {
    int pilihan;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Hapus Data Mahasiswa\n");
        printf("3. Tampilkan Data Mahasiswa\n");
        printf("4. Keluar\n");
        printf("Pilih menu (1-4): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                hapusData();
                break;
            case 3:
                tampilkanData();
                break;
            case 4:
                printf("Terima kasih, program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 4);

    return 0;
}