#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct admin
{
    char username[20];
    char password[20];
} admin;

struct seller
{
    char username[20];
    char password[20];
    char jasa[20];
    int harga;
    char keterangan[50];
    char nama[20];
    char feedback[20];
    char laporan[100];
    char customer[20];
} data_seller, selleraktif;

struct customer
{
    char username[20];
    char password[20];
    char feedback[20];
    int saldo;
    int frekuensi, pengeluaran;
    char status[20];
    char laporan[50];
    char pengirim[20];
    char seller[20];
} data, useraktif;

struct feedback_customer_seller
{
    char customer_username[20];
    char seller_username[20];
    char feedback[50];
};

int loginadmin(int attempt);
int loginseller(int attempt);
int logincustomer(int attempt);
void registrasi_customer();
void registrasi_seller();
void menu_registrasi();
void menucustomer();
void menuadmin();
void menuseller();
void saldo();
void menu_hapus_akun();
void hapus_akun_customer();
void hapus_akun_seller();
void menambahkan_jasa();
void marketplace();
void feedback();
void lihat_feedback();
void cekstatus();
void laporan_customer();
void laporan_seller();
void laporan();
void lihat_laporan_customer();
void lihat_laporan_seller();

int main()
{
    int menu;

    printf("============================================================\n");
    printf("------------------------ Indolance -------------------------\n");
    printf("============================================================\n");
    printf("1.Login admin\n2.Registrasi akun\n3.Login Seller\n4.Login Customer\n5.Keluar\n");
    printf("pilih menu (1/2/3/4/5) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        printf("============================================================\n");
        printf("------------------------ Indolance -------------------------\n");
        printf("============================================================\n");
        loginadmin(3);
        menuadmin();
        break;

    case 2:
        printf("============================================================\n");
        printf("------------------------ Indolance -------------------------\n");
        printf("============================================================\n");
        menu_registrasi();
        break;

    case 3:
        printf("============================================================\n");
        printf("------------------------ Indolance -------------------------\n");
        printf("============================================================\n");
        loginseller(3);
        menuseller();
        break;

    case 4:
        printf("============================================================\n");
        printf("------------------------ Indolance -------------------------\n");
        printf("============================================================\n");
        logincustomer(3);
        menucustomer();
        break;

    case 5:
        printf("Exiting the program. Goodbye!\n");
        break;

    default:
        printf("maaf pilihan anda tidak tersedia\n");
        main();
        break;
    }
    return 0;
}

int loginadmin(int attempt)
{
    printf("Masukkan username : ");
    gets(admin.username);
    printf("Masukkan password : ");
    gets(admin.password);
    system("cls");

    if (strcmp(admin.username, "admin") == 0 && strcmp(admin.password, "admin123") == 0)
    {
        printf("Selamat datang admin\n");
        return 1;
    }
    else
    {
        attempt--;
    }

    if (attempt > 0)
    {
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        printf("Username atau password admin salah. Sisa percobaan %d \n", attempt);
        loginadmin(attempt);
    }
    else
    {
        printf("Maaf anda sudah 3 kali percobaan salah\n");
        system("pause");
        system("cls");
        main();
    }
}

void menu_registrasi()
{
    int menu;

    printf("1.Registrasi Seller\n2.Registrasi Customer\n3.Keluar\n");
    printf("pilih menu (1/2/3) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        registrasi_seller();
        break;

    case 2:
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        registrasi_customer();
        break;

    case 3:
        main();
        break;

    default:
        printf("maaf pilihan anda tidak tersedia\n");
        main();
        break;
    }
}

int logincustomer(int attempt)
{
    FILE *akun_customer;
    struct customer data;

    akun_customer = fopen("akun_customer.dat", "rb");

    char username[50], password[50];

    printf("Masukkan Username : ");
    gets(username);

    while (fread(&data, sizeof(data), 1, akun_customer) == 1)
    {
        if (strcmp(data.username, username) == 0)
        {
            printf("Masukkan Password : ");
            gets(password);
            if (strcmp(data.password, password) == 0)
            {
                useraktif = data;
                fclose(akun_customer);
                system("cls");
                attempt = -1;
                break;
            }
            else
            {
                attempt--;
            }
        }
    }

    if (attempt == -1)
    {
        menucustomer();
    }
    else if (attempt > 0)
    {
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        printf("Username atau password salah. Sisa percobaan %d \n", attempt);
        fclose(akun_customer);
        logincustomer(attempt);
    }
    else
    {
        printf("Maaf anda sudah 3 kali percobaan salah \n");
        system("pause");
        system("cls");
        fclose(akun_customer);
        main();
    }
}

int loginseller(int attempt)
{
    FILE *akun_seller;
    struct seller data_seller;

    akun_seller = fopen("akun_seller.dat", "rb");

    char username[50], password[50];

    printf("Masukkan Username : ");
    gets(username);

    while (fread(&data_seller, sizeof(data_seller), 1, akun_seller) == 1)
    {
        if (strcmp(data_seller.username, username) == 0)
        {
            printf("Masukkan Password : ");
            gets(password);
            if (strcmp(data_seller.password, password) == 0)
            {
                selleraktif = data_seller;
                fclose(akun_seller);
                system("cls");
                attempt = -1;
                break;
            }
            else
            {
                attempt--;
            }
        }
    }

    if (attempt == -1)
    {
        menuseller();
    }
    else if (attempt > 0)
    {
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        printf("Username atau password salah. Sisa percobaan %d \n", attempt);
        fclose(akun_seller);
        loginseller(attempt);
    }
    else
    {
        printf("Maaf anda sudah 3 kali percobaan salah \n");
        system("pause");
        system("cls");
        fclose(akun_seller);
        main();
    }
}

void menuadmin()
{
    int menu;
    printf("============================================================\n");
    printf("------------------------ Menu Admin -------------------------\n");
    printf("=============================================================\n");
    printf("1. Melihat Report\n");
    printf("2. Hapus akun\n");
    printf("3. Pendapatan \n");
    printf("4. History\n");
    printf("5. Logout\n");
    printf("Pilih menu (1/2/3/4/5): ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        laporan();
        break;

    case 2:
        menu_hapus_akun();
        break;

    case 3:
        // pendapatan();
        break;

    case 4:
        // history();
        break;

    case 5:
        printf("Logout berhasil.\n");
        system("pause");
        system("cls");
        main();
        break;

    default:
        printf("Maaf pilihan tidak tersedia\n");
        break;
    }
}

void menucustomer()
{
    int menu;
    printf("============================================================\n");
    printf("------------------------ INDOLANCE -------------------------\n");
    printf("============================================================\n");
    printf("1.Informasi Saldo\n2.Marketplace\n3.Status Pesanan\n4.Feedback\n5.Report\n6.Log out\n");
    printf("Pilih menu (1/2/3/4/5): ");
    scanf("%d", &menu);
    getchar();
    system("cls");
    switch (menu)
    {
    case 1:
        saldo();
        break;
    case 2:
        marketplace();
        break;
    case 3:
        cekstatus();
        break;
    case 4:
        feedback();
        break;
    case 5:
        laporan_customer();
        break;
    case 6:
        printf("Logout Berhasil\n");
        system("pause");
        system("cls");
        main();
    default:
        printf("Maaf pilihan anda tidak tersedia\n");
        exit(0);
        break;
    }
}

void menuseller()
{
    int menu;
    printf("============================================================\n");
    printf("------------------------ INDOLANCE -------------------------\n");
    printf("============================================================\n");
    printf("1.Menambahkan Jasa\n2.Update status\n3.Penghasilan\n4.Report\n5.Melihat feedback\n6.Logout\n");
    printf("Pilih menu (1/2/3/4/5): ");
    scanf("%d", &menu);
    getchar();
    system("cls");
    switch (menu)
    {
    case 1:
        menambahkan_jasa();
        break;
    case 2:
        // update_status();
        break;
    case 3:
        // penghasilan();
        break;
    case 4:
        laporan_seller();
        break;
    case 5:
        lihat_feedback();
    case 6:
        printf("Logout Berhasil\n");
        system("pause");
        system("cls");
        main();
    default:
        printf("Maaf pilihan anda tidak tersedia\n");
        exit(0);
        break;
    }
}

void registrasi_customer()
{
    FILE *akun;
    struct customer baru = {0};

    strcpy(baru.status, "tidak ada pesanan\n");

    akun = fopen("akun_customer.dat", "ab");

    printf("Masukkan Username : ");
    gets(baru.username);
    printf("Masukkan Password : ");
    gets(baru.password);

    fwrite(&baru, sizeof(baru), 1, akun);
    fclose(akun);

    printf("Registrasi Berhasil\n");
    system("pause");
    system("cls");
    main();
}

void registrasi_seller()
{
    FILE *akun;
    struct seller new_seller = {0};

    akun = fopen("akun_seller.dat", "ab");

    printf("Masukkan Username : ");
    gets(new_seller.username);
    printf("Masukkan Password : ");
    gets(new_seller.password);

    fwrite(&new_seller, sizeof(new_seller), 1, akun);
    fclose(akun);

    printf("Registrasi Berhasil\n");
    system("pause");
    system("cls");
    main();
}

void saldo()
{
    int jumlah;
    int pilihan;
    int hasilTopUp = 0;
    FILE *akun;
    FILE *akun2;

    printf("========================= Menu Saldo ========================\n");
    printf("1. Cek saldo\n");
    printf("2. Topup saldo\n");
    printf("3. Kembali ke menu customer\n");
    printf("Pilih menu (1/2/3) : ");
    scanf("%d", &pilihan);
    system("cls");
    switch (pilihan)
    {
    case 1:
        akun = fopen("akun_customer.dat", "rb");
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        while (fread(&data, sizeof(data), 1, akun) == 1)
        {
            if (strcmp(data.username, useraktif.username) == 0)
            {
                printf("Saldo Anda: Rp %d\n", data.saldo);
            }
        }
        system("pause");
        system("cls");
        fclose(akun);
        saldo();
        break;

    case 2:
        hasilTopUp = useraktif.saldo;
        akun = fopen("akun_customer.dat", "rb");
        akun2 = fopen("akun_customer2.dat", "wb");

        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        printf("Masukkan jumlah yang ingin ditambahkan : Rp ");
        scanf("%d", &jumlah);
        hasilTopUp = data.saldo + jumlah;
        while (fread(&data, sizeof(data), 1, akun) == 1)
        {
            if (strcmp(data.username, useraktif.username) == 0)
            {
                data.saldo = hasilTopUp;
            }
            fwrite(&data, sizeof(data), 1, akun2);
        }
        printf("Topup berhasil Saldo sekarang : Rp %d\n", hasilTopUp);
        fclose(akun);
        fclose(akun2);

        remove("akun_customer.dat");
        rename("akun_customer2.dat", "akun_customer.dat");

        system("pause");
        system("cls");
        menucustomer();
        break;

    case 3:
        fclose(akun);
        menucustomer();
        break;

    default:
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
        saldo();
        break;
    }
}

void menu_hapus_akun()
{
    printf("============================================================\n");
    printf("------------------------ INDOLANCE -------------------------\n");
    printf("============================================================\n");
    int menu;

    printf("1.Hapus akun seller\n2.Hapus akun customer\n3.Keluar\n");
    printf("pilih menu (1/2/3) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        hapus_akun_seller();
        break;

    case 2:
        printf("============================================================\n");
        printf("------------------------ INDOLANCE -------------------------\n");
        printf("============================================================\n");
        hapus_akun_customer();
        break;

    case 3:
        menuadmin();
        break;

    default:
        printf("maaf pilihan anda tidak tersedia\n");
        main();
        break;
    }
}

void hapus_akun_customer()
{
    FILE *file;
    struct seller seller_data;

    file = fopen("akun_customer.dat", "rb");

    if (file == NULL)
    {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("Data Akun Customer:\n");
    while (fread(&data, sizeof(data), 1, file) == 1)
    {
        printf("Username: %s\n", data.username);
        printf("Password: %s\n", data.password);
        printf("\n");
    }

    // Menutup file setelah selesai membacanya
    fclose(file);

    FILE *akun;
    FILE *akun2;
    char dicari[20];

    akun = fopen("akun_customer.dat", "rb");
    akun2 = fopen("akun_customer2.dat", "wb");

    printf("Masukkan Username Akun Yang Ingin Dihapus : ");
    gets(dicari);

    int akun_ditemukan = 0;

    while (fread(&data, sizeof(data), 1, akun) == 1)
    {
        if (strcmp(data.username, dicari) == 0)
        {
            akun_ditemukan = 1;
        }
        else
        {
            fwrite(&data, sizeof(data), 1, akun2);
        }
    }

    fclose(akun);
    fclose(akun2);

    if (akun_ditemukan)
    {
        remove("akun_customer.dat");
        rename("akun_customer2.dat", "akun_customer.dat");
        printf("Akun dengan username '%s' berhasil dihapus.\n", dicari);
    }
    else
    {
        printf("Akun dengan username '%s' tidak ditemukan.\n", dicari);
    }

    system("pause");
    system("cls");
    menuadmin();
}

void hapus_akun_seller()
{
    FILE *file;
    struct seller seller_data;

    // Membuka file untuk dibaca dalam mode binary
    file = fopen("akun_seller.dat", "rb");

    // Memeriksa apakah file berhasil dibuka
    if (file == NULL)
    {
        printf("Gagal membuka file.\n");
        return;
    }

    // Membaca data dari file dan menampilkannya
    printf("Data Akun Seller:\n");
    while (fread(&seller_data, sizeof(seller_data), 1, file) == 1)
    {
        printf("Username: %s\n", seller_data.username);
        printf("Password: %s\n", seller_data.password);
        printf("\n");
    }

    // Menutup file setelah selesai membacanya
    fclose(file);

    FILE *akun;
    FILE *akun2;
    char dicari[20];

    akun = fopen("akun_seller.dat", "rb");
    akun2 = fopen("akun_seller2.dat", "wb");

    printf("Masukkan Username Akun Yang Ingin Dihapus : ");
    gets(dicari);

    int akun_ditemukan = 0;

    while (fread(&data_seller, sizeof(data_seller), 1, akun) == 1)
    {
        if (strcmp(data_seller.username, dicari) == 0)
        {
            akun_ditemukan = 1;
        }
        else
        {
            fwrite(&data_seller, sizeof(data_seller), 1, akun2);
        }
    }

    fclose(akun);
    fclose(akun2);

    if (akun_ditemukan)
    {
        remove("akun_seller.dat");
        rename("akun_seller2.dat", "akun_seller.dat");
        printf("Akun dengan username '%s' berhasil dihapus.\n", dicari);
    }
    else
    {
        printf("Akun dengan username '%s' tidak ditemukan.\n", dicari);
    }

    system("pause");
    system("cls");
    menuadmin();
}

void menambahkan_jasa()
{
    FILE *jasa;
    struct seller baru = {0};

    jasa = fopen("jasa.dat", "ab");

    printf("Masukkan Nama Toko: ");
    gets(baru.nama);
    printf("Masukkan Jasa: ");
    gets(baru.jasa);
    printf("Masukan keterangan: ");
    gets(baru.keterangan);
    ;
    printf("Masukkan Harga: ");
    scanf("%d", &baru.harga);

    fwrite(&baru, sizeof(baru), 1, jasa);
    fclose(jasa);

    printf("Penambahan Jasa Berhasil\n");
    system("pause");
    system("cls");
    menuseller();
}

void marketplace()
{
    FILE *file;
    struct seller seller_data;

    file = fopen("jasa.dat", "rb");

    if (file == NULL)
    {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("Marketplace:\n");
    while (fread(&seller_data, sizeof(seller_data), 1, file) == 1)
    {
        printf("Nama Toko : %s\n", seller_data.nama);
        printf("Seller    : %s\n", seller_data.username); // Menampilkan username seller
        printf("Jasa      : %s\n", seller_data.jasa);
        printf("Keterangan: %s\n", seller_data.keterangan);
        printf("Harga     : %d\n", seller_data.harga);
        printf("\n");
    }

    system("pause");
    system("cls");
    menucustomer();

    fclose(file);
}

void feedback()
{
    FILE *file;
    struct feedback_customer_seller feedback_data;

    file = fopen("feedback.dat", "ab"); // Buka file feedback untuk ditulis dalam mode append binary

    if (file == NULL)
    {
        printf("Gagal membuka file.\n");
        return;
    }

    char seller_tujuan[20];
    printf("Masukkan username seller yang ingin diberi feedback: ");
    gets(seller_tujuan);

    printf("Masukkan komentar: ");
    gets(feedback_data.feedback);

    strcpy(feedback_data.customer_username, useraktif.username);
    strcpy(feedback_data.seller_username, seller_tujuan);
    fwrite(&feedback_data, sizeof(feedback_data), 1, file);
    fclose(file);

    printf("Komentar telah dikirim\n");

    system("pause");
    system("cls");
    menucustomer();
}

void lihat_feedback()
{
    FILE *file;
    struct feedback_customer_seller feedback_data;

    file = fopen("feedback.dat", "rb");
    if (file == NULL)
    {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("============================================================\n");
    printf("---------------------- Umpan Balik dari Pembeli -------------\n");
    printf("============================================================\n");

    while (fread(&feedback_data, sizeof(feedback_data), 1, file) == 1)
    {
        if (strcmp(feedback_data.seller_username, selleraktif.username) == 0)
        {
            printf("Pembeli: %s\n", feedback_data.customer_username);
            printf("Komentar: %s\n", feedback_data.feedback);
        }
    }

    fclose(file);

    system("pause");
    system("cls");
    menuseller();
}

void cekstatus()
{
    printf("============================================================\n");
    printf("------------------------ INDOLANCE -------------------------\n");
    printf("============================================================\n");
    printf("status pesanan : %s", useraktif.status);
    system("pause");
    system("cls");
    menucustomer();
}

void laporan_customer()
{
    FILE *file;
    file = fopen("laporan_customer.dat", "ab");

    printf("==============================================================\n");
    printf("------------------------- INDOLANCE --------------------------\n");
    printf("==============================================================\n");
    printf("Masukkan nama          : ");
    gets(data.username);

    printf("Masukkan nama seller   : ");
    gets(data.seller);

    printf("Masukkan komentar      : ");
    gets(data.laporan);

    fwrite(&data, sizeof(data), 1, file);

    fclose(file);

    printf("Komentar telah dikirim\n");
    system("pause");
    system("cls");
    menucustomer();
}

void laporan_seller()
{
    FILE *file;

    file = fopen("laporan_seller.dat", "ab");

    printf("==============================================================\n");
    printf("-------------------------- INDOLANCE -------------------------\n");
    printf("==============================================================\n");
    printf("Masukkan nama          : ");
    gets(data_seller.username);

    printf("Masukkan nama customer : ");
    gets(data_seller.customer);

    printf("Masukkan komentar      : ");
    gets(data_seller.laporan);

    fwrite(&data_seller, sizeof(data_seller), 1, file);

    fclose(file);

    printf("Komentar telah dikirim\n");
    system("pause");
    system("cls");
    menucustomer();
}

void laporan()
{
    int menu;
    printf("==============================================================\n");
    printf("-------------------------- INDOLANCE -------------------------\n");
    printf("==============================================================\n");
    printf("1.Laporan Customer\n2.Laporan Seller\n3.Kembali\n");
    printf("pilih menu (1/2/3) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
    case 1:
        lihat_laporan_customer();
        break;
    case 2:
        lihat_laporan_seller();
        break;
    case 3:
        menuadmin();
        break;
    default:
        printf("Pilihan anda tidak tersedia");
        break;
    }
}

void lihat_laporan_customer()
{
    FILE *file;
    struct customer data;

    file = fopen("laporan_customer.dat", "rb");
    printf("==============================================================\n");
    printf("-------------------------- INDOLANCE -------------------------\n");
    printf("==============================================================\n");

    while (fread(&data, sizeof(data), 1, file))
    {
        printf("Nama               : %s\n", data.username);
        printf("Akun yang di lapor : %s\n", data.seller);
        printf("Laporan            : %s\n", data.laporan);
        printf("-------------------------\n");
    }

    fclose(file);
    system("pause");
    system("cls");
    menuadmin();
}

void lihat_laporan_seller()
{
    FILE *file;
    struct seller data_seller;

    file = fopen("laporan_seller.dat", "rb");
    printf("==============================================================\n");
    printf("-------------------------- INDOLANCE -------------------------\n");
    printf("==============================================================\n");

    while (fread(&data_seller, sizeof(data_seller), 1, file))
    {
        printf("Nama Pelapor       : %s\n", data_seller.username);
        printf("Akun yang di lapor : %s\n", data_seller.customer);
        printf("Laporan            : %s\n", data_seller.laporan);
        printf("-------------------------\n");
    }

    fclose(file);
    system("pause");
    system("cls");
    menuadmin();
}
