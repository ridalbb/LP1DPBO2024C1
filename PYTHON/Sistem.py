# Import class
from DPR import DPR

# Inisialisasi class
class Sistem:
    # Method menambah data atribut ke dalam objek list
    def add_data(dataDPR):
        # Input data atribut DPR
        id =        str(input("Masukkan id DPR          : "))
        nama =      str(input("Masukkan Nama anggota DPR: "))
        bidang =    str(input("Masukkan bidang DPR      : "))
        partai =    str(input("Masukkan partai DPR      : "))
        # Memasukkan data DPR ke dalam objek list
        dataDPR.append(DPR(id, nama, bidang, partai))

    # Method mengubah data atribut ke dalam objek list
    def ubah_data(dataDPR):
        # Input data atribut id DPR yang ingin diubah
        id_ubah = str(input("Masukkan id DPR yang Ingin Diubah  : "))
        i = 0
        flag = 0
        # Looping mencari index data atribut DPR berdasarkan id inputan user
        while flag == 0:
            if dataDPR[i].get_id() == id_ubah:
                index = i
                flag = 1
            i += 1
        # Input data atribut DPR kembali
        id =        str(input("Masukkan id DPR          : "))
        nama =      str(input("Masukkan Nama anggota DPR: "))
        bidang =    str(input("Masukkan bidang DPR      : "))
        partai =    str(input("Masukkan partai DPR      : "))
        # Re-Assign nilai pada objek list
        dataDPR[index].set_id(id)
        dataDPR[index].set_nama(nama)
        dataDPR[index].set_bidang(bidang)
        dataDPR[index].set_partai(partai)

    # Method menghapus data atribut DPR
    def hapus_data(dataDPR):
        # Input data atribut id DPR yang ingin dihapus
        id_hapus = str(input("Masukkan id DPR yang Ingin Dihapus    : "))
        flag = 0
        i = 0
        # Looping mencari index data atribut DPR berdasarkan id inputan user
        while flag == 0:
            if dataDPR[i].get_id() == id_hapus:
                index = i
                flag = 1
            i += 1
        # Menghapus data atribut DPR dari objek list
        dataDPR.pop(index)

    # Method untuk menampilkan data DPR
    def tampilkan_data(dataDPR):
        print("Press Enter to Continue...\n---")

        # Mencari String Terpanjang
        if len(dataDPR) == 0:
            print("Belum Ada Data DPR yang Terekam...")
        else:
            print("Data DPR:")
            panjang = [3, 4, 13, 8]
            for pembelajar in dataDPR:
                # String id terpanjang
                if len(pembelajar.get_id()) > panjang[0]:
                    panjang[0] = len(pembelajar.get_id())
                # String Nama terpanjang
                if len(pembelajar.get_nama()) > panjang[1]:
                    panjang[1] = len(pembelajar.get_nama())
                # String bidang terpanjang
                if len(pembelajar.get_bidang()) > panjang[2]:
                    panjang[2] = len(pembelajar.get_bidang())
                # String partai terpanjang
                if len(pembelajar.get_partai()) > panjang[3]:
                    panjang[3] = len(pembelajar.get_partai())
            
            # Menampilkan Header Tabel
            # Bagian Atas
            print("+", end="")
            # id
            for i in range(panjang[0] + 2):
                print("-", end="")
            print("+", end="")
            # Nama
            for i in range(panjang[1] + 2):
                print("-", end="")
            print("+", end="")
            # bidang
            for i in range(panjang[2] + 2):
                print("-", end="")
            print("+", end="")
            # partai
            for i in range(panjang[3] + 2):
                print("-", end="")
            print("+")

            # Bagian Tengah
            print("| id ",end="")
            for i in range(panjang[0]-2):
                print(" ", end="")
            print("| Nama", end="")
            for i in range(panjang[1]-3):
                print(" ", end="")
            print("| bidang", end="")
            for i in range(panjang[2]-5):
                print(" ", end="")
            print("| partai", end="")
            for i in range(panjang[3]-5):
                print(" ", end="")
            print("|")

            # Bagian Bawah
            print("+", end="")
            # id
            for i in range(panjang[0] + 2):
                print("-", end="")
            print("+", end="")
            # Nama
            for i in range(panjang[1] + 2):
                print("-", end="")
            print("+", end="")
            # bidang
            for i in range(panjang[2] + 2):
                print("-", end="")
            print("+", end="")
            # partai
            for i in range(panjang[3] + 2):
                print("-", end="")
            print("+")

            # Mengeluarkan Output Data DPR
            i = 1
            for pembelajar in dataDPR:
                # id
                print(f"| {pembelajar.get_id()}", end="")
                for i in range(panjang[0]-len(pembelajar.get_id())+1):
                    print(" ", end="")
                # Nama
                print(f"| {pembelajar.get_nama()}", end="")
                for i in range(panjang[1]-len(pembelajar.get_nama())+1):
                    print(" ", end="")
                # bidang
                print(f"| {pembelajar.get_bidang()}", end="")
                for i in range(panjang[2]-len(pembelajar.get_bidang())+1):
                    print(" ", end="")
                # partai
                print(f"| {pembelajar.get_partai()}", end="")
                for i in range(panjang[3]-len(pembelajar.get_partai())+1):
                    print(" ", end="")
                print("|")
                i += 1

            # Mengeluarkan Output Footer Tabel
            print("+", end="")
            # id
            for i in range(panjang[0] + 2):
                print("-", end="")
            print("+", end="")
            # Nama
            for i in range(panjang[1] + 2):
                print("-", end="")
            print("+", end="")
            # bidang
            for i in range(panjang[2] + 2):
                print("-", end="")
            print("+", end="")
            # partai
            for i in range(panjang[3] + 2):
                print("-", end="")
            print("+")

        # Agar tidak langsung ke menu setelah nge-print tabel
        input()