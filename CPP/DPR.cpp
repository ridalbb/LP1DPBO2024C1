// Import library.
#include <iostream>
#include <string>

// Standard namespace.
using namespace std;

// Inisialisasi class.
class DPR
{
    // Atribut Private.
    private:
        string nama;
        string id;
        string bidang;
        string partai;

    // Atribut Public.
    public:
        // Konstruktor.
        DPR()
        {
            // Set default nilai atribut.
            this->id = "";
            this->nama = "";
            this->bidang = "";
            this->partai = "";
        }

        DPR(string nama, string id, string bidang, string partai)
        {
            // Set nilai atribut.
            this->id = id;
            this->nama = nama;
            this->bidang = bidang;
            this->partai = partai;
        }

        // Getter dan Setter.
        // Setter.
        void set_id(string id)
        {
            this->id = id;
        }
        void set_nama(string nama)
        {
            this->nama = nama;
        }
        void set_bidang(string bidang)
        {
            this->bidang = bidang;
        }
        void set_partai(string partai)
        {
            this->partai = partai;
        }

        // Getter.
        string get_id()
        {
            return this->id;
        }
        string get_nama()
        {
            return this->nama;
        }
        string get_bidang()
        {
            return this->bidang;
        }
        string get_partai()
        {
            return this->partai;
        }
        
        // Method Remove Attribute.
        void hapusDataDPR()
        {
            this->id = "";
            this->nama = "";
            this->bidang = "";
            this->partai = "";
        }

        // Destruktor
        ~DPR()
        {
            
        }
};