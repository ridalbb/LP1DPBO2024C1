// Import library dan file.
#include <bits/stdc++.h>
#include "DPR.cpp"
#include <cstdio>

// Standard namespace.
using namespace std;

int main()
{
    int i, fungsi = 0;
    string nama, bidang, partai, id, id_ubah;
    DPR temp;

    // List kumpulan data DPR.
    list<DPR> dataDPR;

    do
    {
        system("cls");
        // Nampilin menu.
        cout << "[";
        for(i = 0; i < 35; i++)
        {
            cout << "-";
        }
        cout << "MENU";
        for(i = 0; i < 35; i++)
        {
            cout << "-";
        }
        cout << "]\n";
        cout << "\n(1) Tambah Data | (2) Ubah Data | (3) Hapus Data | (4) Tampil Data | (5) END\n";
        cout << "\n[";
        for(i = 0; i< 74; i++)
        {
            cout << "-";
        }
        cout << "]\n\nMasukkan Angka Perintah: ";
        // Meminta user untuk menjalankan suatu perintah.
        cin >> fungsi;
        cout << "---\n";
        // Tambah Data.
        if (fungsi == 1)
        {
            // Input atribut.
            cout << "Masukkan id anggota DPR    : ";
            cin >> id;
            cout << "Masukkan Nama anggota DPR  : ";
            cin >> nama;
            cout << "Masukkan bidang anggota DPR: ";
            cin >> bidang;
            cout << "Masukkan partai anggota DPR: ";
            cin >> partai;

            // Assign attribut.
            temp.set_id(id);
            temp.set_nama(nama);
            temp.set_bidang(bidang);
            temp.set_partai(partai);
       

            // Push ke list.
            dataDPR.push_back(temp);
        }
        // Ubah data.
        else if (fungsi == 2)
        {
            // Input id data atribut DPR yang ingin diubah datanya.
            cout << "Masukkan id DPR yang Ingin Diubah: ";
            cin >> id_ubah;

            // Input data atribut DPR yang baru.
            cout << "Masukkan id DPR    : ";
            cin >> id;
            cout << "Masukkan Nama DPR  : ";
            cin >> nama;
            cout << "Masukkan bidang DPR: ";
            cin >> bidang;
            cout << "Masukkan partai DPR: ";
            cin >> partai;

            // Proses pengubahand data atribut DPR.
            for (list<DPR>::iterator it = dataDPR.begin(); it != dataDPR.end(); it++)
            {
                if (it->get_id() == id_ubah)
                {
                    it->set_id(id);
                    it->set_nama(nama);
                    it->set_bidang(bidang);
                    it->set_partai(partai);
                }
            }
        }
        // Hapus Data.
        else if (fungsi == 3)
        {
            // Input data id DPR yang ingin dihapus datanya.
            cout << "Masukkan id DPR yang Ingin Dihapus: ";
            cin >> id_ubah;

            for (list<DPR>::iterator it = dataDPR.begin(); it != dataDPR.end(); it++)
            {
                if (it->get_id() == id_ubah)
                {
                    it = dataDPR.erase(it);
                }
            }
        }
        // Menampilkan Data
        else if (fungsi == 4)
        {
            cout << "Press Enter to Continue...\n---\n";

            if(dataDPR.empty())
            {
                cout << "Belum Terdapat Data DPR\n";
            }
            else
            {
                cout << "Data DPR\n";
                // Mencari String Terpanjang
                int panjang[4] = {3, 4, 13, 8};
                for(list<DPR>::iterator it = dataDPR.begin(); it != dataDPR.end(); it++)
                {
                    if(it->get_id().length() > panjang[0])
                    {
                        panjang[0] = it->get_id().length();
                    }
                    if(it->get_nama().length() > panjang[1])
                    {
                        panjang[1] = it->get_nama().length();
                    }
                    if(it->get_bidang().length() > panjang[2])
                    {
                        panjang[2] = it->get_bidang().length();
                    }
                    if(it->get_partai().length() > panjang[3])
                    {
                        panjang[3] = it->get_partai().length();
                    }
                }

                // Menampilkan Header Tabel.
                // Bagian Atas.
                cout << "+";
                // Header id.
                for(i = 0; i < panjang[0]+2; i++)
                {
                    cout << "-";
                }
                cout << "+";
                // Header nama.
                for(i = 0; i < panjang[1]+2; i++)
                {
                    cout << "-";
                }
                cout << "+";
                // Header bidang.
                for(i = 0; i < panjang[2]+2; i++)
                {
                    cout << "-";
                }
                cout << "+";
                // Header bidang.
                for(i = 0; i < panjang[3]+2; i++)
                {
                    cout << "-";
                }
                cout << "+\n";

                // Bagian tengah.
                cout << "| id ";
                for(i = 0; i < panjang[0]-2; i++)
                {
                    cout << " ";
                }
                cout << "| Nama";
                for(i = 0; i < panjang[1]-3; i++)
                {
                    cout << " ";
                }
                cout << "| Bidang ";
                for(i = 0; i < panjang[2]-6; i++)
                {
                    cout << " ";
                }
                cout << "| partai";
                for(i = 0; i < panjang[3]-5; i++)
                {
                    cout << " ";
                }
                cout << "|\n";

                // Bagian bawah.
                cout << "+";
                // Header id.
                for(i = 0; i < panjang[0]+2; i++)
                {
                    cout << "-";
                }
                cout << "+";
                // Header nama.
                for(i = 0; i < panjang[1]+2; i++)
                {
                    cout << "-";
                }
                cout << "+";
                // Header bidang.
                for(i = 0; i < panjang[2]+2; i++)
                {
                    cout << "-";
                }
                cout << "+";
                // Header bidang.
                for(i = 0; i < panjang[3]+2; i++)
                {
                    cout << "-";
                }
                cout << "+\n";

                // Output data DPR.
                for (list<DPR>::iterator it = dataDPR.begin(); it != dataDPR.end(); it++)
                {
                    cout << "| " << it->get_id();
                    for(i = 0; i < panjang[0]-it->get_id().length()+1; i++)
                    {
                        cout << " ";
                    }
                    cout << "| " << it->get_nama();
                    for(i = 0; i < panjang[1]-it->get_nama().length()+1; i++)
                    {
                        cout << " ";
                    }
                    cout << "| " << it->get_bidang();
                    for(i = 0; i < panjang[2]-it->get_bidang().length()+1; i++)
                    {
                        cout << " ";
                    }
                    cout << "| " << it->get_partai();
                    for(i = 0; i < panjang[3]-it->get_partai().length()+1; i++)
                    {
                        cout << " ";
                    }
                    cout << "|\n";
                }

                // Bagian footer.
                cout << "+";
                // Header id.
                for(i = 0; i < panjang[0]+2; i++)
                {
                    cout << "-";
                }
                cout << "+";
                // Header nama.
                for(i = 0; i < panjang[1]+2; i++)
                {
                    cout << "-";
                }
                cout << "+";
                // Header bidang.
                for(i = 0; i < panjang[2]+2; i++)
                {
                    cout << "-";
                }
                cout << "+";
                // Header bidang.
                for(i = 0; i < panjang[3]+2; i++)
                {
                    cout << "-";
                }
                cout << "+\n";
            }
            fflush(stdin);
            getchar();
        }
        else if(fungsi == 5)
        {
            cout << "Terima Kasih...\n";
        }

    } while (fungsi != 5);

    return 0;
}