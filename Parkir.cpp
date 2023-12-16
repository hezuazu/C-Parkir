#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

struct Parkir {
    string nomorPlat;
    int jm_masuk;
    int jm_keluar;
    int biaya;
    int uang;
    int kembalian;
};

const int MAX_PARKIR = 100;
Parkir dataParkir[MAX_PARKIR];

// Deklarasi Variable Global
int tot_biaya, pilih, jm_masuk, jm_keluar, durasi, biaya, harga_kendaraan, uang, kembalian, jumlahParkir = 0, selc_mobil, selc_motor, selc_bus, selc_truck;
string nomorPlat, jenis_kendaraan[4] = {"Motor \t Rp.2000", "Mobil \t Rp.4000", "Truck \t Rp.6000", "Bus   \t Rp.8000"};
char* waktu;

bool compareByTime(const Parkir& a, const Parkir& b) {
    return a.jm_masuk < b.jm_masuk;
}

bool compareByPlat(const Parkir& a, const Parkir& b) {
    return a.nomorPlat < b.nomorPlat;
}

// Membuat function kendaraan
void kendaraan() {
    // Menampilkan Array jenis_kendaraan
    for (int i = 0; i <= 3; i++) {
        cout << "[" << i + 1 << "]" << jenis_kendaraan[i] << endl;
    }
}

void tanggal() {
    time_t now = time(0);
    waktu = ctime(&now);
    cout << "|         " << waktu;
}

void menghitung_biaya() {
    cout << "Nomor Plat Kendaraan \t: ";
    cin >> nomorPlat;

    cout << "Jam Masuk Kendaraan  \t: ";
    cin >> jm_masuk;

    cout << "Jam Keluar Kendaraan \t: ";
    cin >> jm_keluar;

    if (jm_masuk > 0 && jm_keluar <= 24) {
        durasi = jm_keluar - jm_masuk;
        biaya = durasi * harga_kendaraan;

        cout << "Biaya Parkir \t\t: Rp." << biaya << endl;
        cout << "Masukan Nominal Uang \t: ";
        cin >> uang;
        kembalian = uang - biaya;
        tot_biaya += biaya;

        dataParkir[jumlahParkir++] = {nomorPlat, jm_masuk, jm_keluar, biaya, uang, kembalian};

        cout << "-----------------------------------------------\n";
        cout << "|             Struk Karcis Parkir             |\n";
        tanggal();
        cout << "-----------------------------------------------\n";
        cout << "|Nomor Plat      : " << left << setw(27) << nomorPlat << "|\n";
        cout << "|Jam Masuk       : " << left << setw(27) << jm_masuk << "|\n";
        cout << "|Jam Keluar      : " << left << setw(27) << jm_keluar << "|\n";
        cout << "-----------------------------------------------\n";
        cout << "|Biaya Parkir    : Rp." << left << setw(24) << biaya << "|\n";
        cout << "-----------------------------------------------\n";
        cout << "|Bayar           : " << left << setw(27) << uang << "|\n";
        cout << "|Kembalian       : " << left << setw(27) << kembalian << "|\n";
        cout << "-----------------------------------------------\n";

        if (biaya > uang) {
            cout << "Uang Kurang\n";
            menghitung_biaya();
        }

        // Tambahkan pengurutan dataParkir secara otomatis berdasarkan waktu masuk
        sort(dataParkir, dataParkir + jumlahParkir, compareByTime);

    } else {
        cout << "Masukan Waktu 1 - 24\n";
        menghitung_biaya();
    }
}

void pembayaranKarcis() {
    cout << "=========================================\n";
    kendaraan();
    cout << "=========================================\n";
    cout << "Pilih Kendaraan : ";
    cin >> pilih;

    switch (pilih) {
        case 1:
            jenis_kendaraan[0];
            selc_motor += 1;
            harga_kendaraan = 2000;
            break;
        case 2:
            jenis_kendaraan[1];
            selc_mobil += 1;
            harga_kendaraan = 4000;
            break;
        case 3:
            jenis_kendaraan[2];
            selc_truck += 1;
            harga_kendaraan = 6000;
            break;
        case 4:
            jenis_kendaraan[3];
            selc_bus += 1;
            harga_kendaraan = 8000;
            break;
        default:
            cout << "Opsi Kendaraan tidak Valid\n";
            pembayaranKarcis();
    }
    menghitung_biaya();
}

void pencarianNomorKendaraan() {
    string searchPlat;
    cout << "Masukkan Plat Kendaraan yang Dicari: ";
    cin >> searchPlat;

    int platDitemukan = 0; // 0 menunjukkan plat tidak ditemukan

    for (int i = 0; i < jumlahParkir; ++i) {
        if (dataParkir[i].nomorPlat.find(searchPlat) != string::npos) {
            cout << "-----------------------------------------------\n";
            cout << "|             Struk Karcis Parkir             |\n";
            tanggal();
            cout << "-----------------------------------------------\n";
            cout << "|Nomor Plat      : " << left << setw(27) << nomorPlat << "|\n";
            cout << "|Jam Masuk       : " << left << setw(27) << jm_masuk << "|\n";
            cout << "|Jam Keluar      : " << left << setw(27) << jm_keluar << "|\n";
            cout << "-----------------------------------------------\n";
            cout << "|Biaya Parkir    : Rp." << left << setw(24) << biaya << "|\n";
            cout << "-----------------------------------------------\n";
            cout << "|Bayar           : " << left << setw(27) << uang << "|\n";
            cout << "|Kembalian       : " << left << setw(27) << kembalian << "|\n";
            cout << "-----------------------------------------------\n";
        }
    }
    if (platDitemukan == 0) {
        cout << "Plat kendaraan tidak ditemukan!.\n";
    }
}

void struct_parkir() {
    for (int i = 0; i < jumlahParkir; ++i) {
        cout << "-----------------------------------------------\n";
        cout << "|             Struk Karcis Parkir             |\n";
        tanggal();
        cout << "-----------------------------------------------\n";
        cout << "|Nomor Plat      : " << left << setw(27) << dataParkir[i].nomorPlat << "|\n";
        cout << "|Jam Masuk       : " << left << setw(27) << dataParkir[i].jm_masuk << "|\n";
        cout << "|Jam Keluar      : " << left << setw(27) << dataParkir[i].jm_keluar << "|\n";
        cout << "-----------------------------------------------\n";
        cout << "|Biaya Parkir    : Rp." << left << setw(24) << dataParkir[i].biaya << "|\n";
        cout << "-----------------------------------------------\n";
        cout << "|Bayar           : " << left << setw(27) << dataParkir[i].uang << "|\n";
        cout << "|Kembalian       : " << left << setw(27) << dataParkir[i].kembalian << "|\n";
        cout << "-----------------------------------------------\n";
    }
}

void tampilkanDataParkir() {
    int pilihan;
    cout << "[1] Default \n";
    cout << "[2] Waktu \n";
    cout << "[3] Plat \n";
    cout << "Pilih tampilan data : ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            struct_parkir();
            break;
        case 2:
            sort(dataParkir, dataParkir + jumlahParkir, compareByTime);
            struct_parkir();
            break;
        case 3:
            sort(dataParkir, dataParkir + jumlahParkir, compareByPlat);
            struct_parkir();
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            break;
    }
}

void totalhariini() {
    cout << "-----------------------------------------------\n";
    cout << "|            Total Parkir Hari Ini            |\n";
    tanggal();
    cout << "-----------------------------------------------\n";
    cout << "|Motor : " << left << setw(37) << selc_motor << "|\n";
    cout << "|Mobil : " << left << setw(37) << selc_mobil << "|\n";
    cout << "|Bus : " << left << setw(39) << selc_bus << "|\n";
    cout << "|Truck : " << left << setw(37) << selc_truck << "|\n";
    cout << "|Total Parkir    : Rp." << left << setw(24) << tot_biaya << "|\n";
    cout << "-----------------------------------------------\n";
}

int main() {
    int menu;

    do {
        cout << "\nMenu:\n";
        cout << "1. Pembayaran Karcis Parkir\n";
        cout << "2. Pencarian Nomor Kendaraan\n";
        cout << "3. Tampilkan Data Parkir\n";
        cout << "4. Total Parkir Hari Ini\n";
        cout << "5. Keluar\n";
        cout << "\n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1:
                pembayaranKarcis();
                break;
            case 2:
                pencarianNomorKendaraan();
                break;
            case 3:
                tampilkanDataParkir();
                break;
            case 4:
                totalhariini();
                break;
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (menu != 5);

    return 0;
}

