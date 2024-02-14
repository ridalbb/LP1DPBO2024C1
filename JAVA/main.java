// Import library:
import java.util.Scanner;
import java.util.ArrayList;

class main
{
    public static void main(String[] args)
    {
        // Inisialisasi list.
        ArrayList<DPR> dataDPR = new ArrayList<>();

        // Inisialisasi scanner.
        Scanner sc = new Scanner(System.in);

        int fungsi = 0, i;
        String nama, bidang, partai, id, id_ubah;

        do 
        {
            // Clear console.
            System.out.print("\033[H\033[2J");
            System.out.flush();

            // Menampilkan menu.
            System.out.print("[");
            for(i = 0; i < 35 ; i++)
            {
                System.out.print("-");
            }
            System.out.print("MENU");
            for(i = 0; i < 35 ; i++)
            {
                System.out.print("-");
            }
            System.out.println("]");
            System.out.println("\n(1) Tambah Data | (2) Ubah Data | (3) Hapus Data | (4) Tampil Data | (5) END\n");
            System.out.print("[");
            for(i = 0; i < 74 ; i++)
            {
                System.out.print("-");
            }
            System.out.println("]\n");

            // Meminta masukkan user untuk menjalankan suatu fungsi
            System.out.print("Masukkan Angka Perintah: ");
            fungsi = sc.nextInt();
            System.out.println("---");
            
            // Menambah data.
            if(fungsi == 1)
            {
                System.out.print("Masukkan id DPR           : ");
                id = sc.next();
                System.out.print("Masukkan nama DPR         : ");
                nama = sc.next();
                System.out.print("Masukkan bidang DPR       : ");   
                bidang = sc.next();
                System.out.print("Masukkan partai DPR       : ");
                partai = sc.next();

                // Object buat menyimpan nilai sementara sebelum dimasukkan ke list.
                DPR temp = new DPR();
                temp.setNama(nama); temp.setid(id); temp.setbidang(bidang); temp.setpartai(partai);
                dataDPR.add(temp);
            }
            // Mengubah data.
            else if(fungsi == 2)
            {
                // Meminta id DPR yang ingin diubah datanya.
                System.out.print("Masukkan id DPR yang Ingin Diubah: ");
                id_ubah = sc.next();
                System.out.println("---");

                // Meminta inputan data DPR baru.
                System.out.print("Masukkan id DPR           : ");
                id = sc.next();
                System.out.print("Masukkan nama DPR         : ");
                nama = sc.next();
                System.out.print("Masukkan bidang DPR       : ");   
                bidang = sc.next();
                System.out.print("Masukkan partai DPR       : ");
                partai = sc.next();

                // Mencari data yang ingin diubah
                for(i = 0; i < dataDPR.size(); i++)
                {
                    // Proses pengubahan data.
                    if(dataDPR.get(i).getid().equals(id_ubah))
                    {
                        dataDPR.get(i).setNama(nama);
                        dataDPR.get(i).setid(id);
                        dataDPR.get(i).setbidang(bidang);
                        dataDPR.get(i).setpartai(partai);
                        break;
                    }
                }
            }
            // Hapus data DPR.
            else if(fungsi == 3)
            {
                // Meminta id DPR yang ingin dihapus datanya.
                System.out.print("Masukkan id DPR yang Ingin Dihapus: ");
                id_ubah = sc.next();

                // Mencari data yang ingin dihapus.
                for(i = 0; i < dataDPR.size(); i++)
                {
                    // Proses penghapusan data.
                    if(dataDPR.get(i).getid().equals(id_ubah))
                    {
                        dataDPR.remove(i);
                    }
                }
            }
            // Selesai.
            else if(fungsi == 5)
            {
                System.out.println("Terima Kasih...");
            }
            // Nampilin data DPR.
            else if(fungsi == 4)
            {
                if(dataDPR.isEmpty())
                {
                    System.out.println("Belum Terdapat Data DPR...");
                }
                else
                {
                    System.out.println("Press Enter to Continue...\n---\n(id - Nama - Program Studi - partai)\n\n[-----------DATA DPR------------]\n");
                    for(i = 0; i < dataDPR.size(); i++)
                    {
                        System.out.println((i + 1) + ". " + dataDPR.get(i).getid() + " - " + dataDPR.get(i).getNama() + " - " + dataDPR.get(i).getbidang() + " - " + dataDPR.get(i).getpartai());
                    }
                }
                sc.nextLine();
                sc.nextLine();
            }
            else
            {
                System.out.println("Angka Di luar Jangkauan...");
            }
        } while (fungsi != 5);
    }
}