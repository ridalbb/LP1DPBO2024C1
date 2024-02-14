<?php 

// Inisialisasi kelas.
class DPR
{
    // Private attribute:
    private $id = '';
    private $nama = '';
    private $bidang = '';
    private $partai = '';
    private $gambar = '';

    // Konstruktor.
    public function __construct($id = '',$nama = '',  $bidang = '', $partai = '', $gambar = '')
    {
        $this->id = $id;
        $this->nama = $nama;
        $this->bidang = $bidang;
        $this->partai = $partai;
        $this->gambar = $gambar;
    }

    // Setter.
    // id.
    public function set_id($id)
    {
        $this->id = $id;
    }
    // Nama DPR.
    public function set_nama($nama)
    {
        $this->nama = $nama;
    }
    // Bidang.
    public function set_bidang($bidang)
    {
        $this->bidang = $bidang;
    }
    // partai.
    public function set_partai($partai)
    {
        $this->partai = $partai;
    }
    // Gambar.
    public function set_gambar($gambar)
    {
        $this->gambar = $gambar;
    }

    // Getter.
    // id.
    public function get_id()
    {
        return $this->id;
    }
    // Nama DPR.
    public function get_nama()
    {
        return $this->nama;
    }
    // Bidang
    public function get_bidang()
    {
        return $this->bidang;
    }
    // partai
    public function get_partai()
    {
        return $this->partai;
    }
    // Gambar
    public function get_gambar()
    {
        return $this->gambar;
    }

    // Destruktor.
    function __destruct()
    {
    }
}

?>