// Deklarasi kelas.
public class DPR 
{
    // Private atribut
    private String id;
    private String nama;
    private String bidang;
    private String partai;

    // Konstruktor.
    public DPR()
    {
        this.id = "";
        this.nama = "";
        this.bidang = "";
        this.partai = "";
    }

    public DPR(String nama, String bidang, String partai, String id)
    {
        this.id = id;
        this.nama = nama;
        this.bidang = bidang;
        this.partai = partai;
    }

    // Getter dan Setter.
    // Setter.
    public void setid(String id)
    {
        this.id = id;
    }
    public void setNama(String nama)
    {
        this.nama = nama;
    }
    public void setbidang(String bidang)
    {
        this.bidang = bidang;
    }
    public void setpartai(String partai)
    {
        this.partai = partai;
    }

    // Getter.
    public String getid()
    {
        return this.id;
    }
    public String getNama()
    {
        return this.nama;
    }
    public String getbidang()
    {
        return this.bidang;
    } 
    public String getpartai()
    {
        return this.partai;
    }
}