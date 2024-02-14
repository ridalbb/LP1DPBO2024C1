<?php

// Mengimpor file.
require("DPR.php");

// Memulai session.
session_start();

// Mengecek apakah session sudah dibuat atau belum.
if (!isset($_SESSION["data_DPR"])) {
  $_SESSION["data_DPR"] = array();
}

// Mengambil nilai dari session yang ada.
$data_DPR = $_SESSION["data_DPR"];

// MENU
echo '<form method="post">';
  echo '<input type="submit" name="create" value="Add Data"> | ';
  echo '<input type="submit" name="read" value="Show Data"> | ';
  echo '<input type="submit" name="update" value="Update Data"> | ';
  echo '<input type="submit" name="delete" value="Delete Data">';
echo '</form>';

// Flag function CRUD.
$flag = 0;
// Create data.
if(isset($_POST['create']))
{
  $flag = 1;
}
// Read data.
elseif(isset($_POST['read']))
{
  $flag = 2;
}
// Update data.
elseif(isset($_POST['update']))
{
  $flag = 3;
}
// Delete data.
elseif(isset($_POST['delete']))
{
  $flag = 4;
}

// Form input data.
if($flag == 1 || $flag == 3 || $flag == 4)
{
  echo '<form action="main.php" method="post" enctype="multipart/form-data">';
    // Untuk modifikasi data (Update dan Delete). 
    // => diminta data id DPR yang akan dimodifikasi.
    if($flag == 4 || $flag == 3)
    {
      echo '<label for="id_modif">id DPR yang Ingin Dimodifikasi:</label><br>';
      echo '<input type="text" name="id_modif", id="id"><br><br>';
    }
    // Form set nilai data DPR
    if($flag == 1 || $flag == 3)
    {
      echo '<label for="id">id</label><br>';
      echo '<input type="text" name="id", id="id"><br>';
      echo '<label for="nama">Nama</label><br>';
      echo '<input type="text" name="nama" id="nama"><br>';
      echo '<label for="bidang">Bidang</label><br>';
      echo '<input type="text" name="bidang" id="bidang"><br>';
      echo '<label for="partai">partai</label><br>';
      echo '<input type="text" name="partai" id="partai"><br><br>';
      echo '<input type="file" name="gambar" id="gambar"><br><br>';
    }
    // Button dibedakan tiap function agar memudahkan saat pengecekan penekanan button.
    if($flag == 1)
    {
      echo '<input type="submit" name="submitC" value="Submit">';
      // echo '<input type="submit" name="end" value="Reset">';
    }
    if($flag == 3)
    {
      echo '<input type="submit" name="submitU" value="Submit">';
    }
    if($flag == 4)
    {
      echo '<input type="submit" name="submitD" value="Submit">';
    }
  echo '</form>';
}

// Menambah data (Create).
if (isset($_POST['submitC'])) {
  // Mengambil data dari form dan menyimpan ke variabel.
  $id = $_POST["id"];
  $nama = $_POST["nama"];
  $bidang = $_POST["bidang"];
  $partai = $_POST["partai"];

  // Setup gambar dan penyimpanan gambar ke suatu dir.
  $target_dir = "gambar/";
  $target_file = $target_dir . basename($_FILES["gambar"]["name"]);
  $imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));
  move_uploaded_file($_FILES["gambar"]["tmp_name"], $target_file);
  
  // Instansiasi object.
  $DPR = new DPR($nama, $id, $bidang, $partai, basename($_FILES["gambar"]["name"]));
  // Push object ke array.
  array_push($data_DPR, $DPR);
  echo 'Data Berhasil Ditambahkan...';
}

// Menampilkan data (Read).
if($flag == 2)
{
  $flagBerhasil = 0;
  $i = 1;

  // Proses menampilin data DPR.
  echo '<b>DATA DPR:</b><br>(id - Nama - bidang - partai)<br>';
  foreach($data_DPR as $DPR)
  {
    $flagBerhasil = 1;
    echo '<br><img src="gambar/' . $DPR->get_gambar() . '" alt="Foto DPR" style="width: 100px; height: auto;"><br>';
    echo $i . '. ' . $DPR->get_id() . ' | ' . $DPR->get_nama() . ' | ' . $DPR->get_bidang() . ' | ' . $DPR->get_partai() . '<br>';
    $i = $i + 1;
  }
  if($flagBerhasil == 0)
  {
    echo 'Belum Terdapat Data DPR...';
  }
}

// Mengupdate data (Update).
if(isset($_POST['submitU']))
{
  $flagBerhasil = 0;
  foreach($data_DPR as $DPR)
  {
    // Pencarian id yang sama dengan id yang mau diubah.
    if($DPR->get_id() == $_POST['id_modif'])
    {
      // Unlink gambar.
      unlink('gambar/' . $DPR->get_gambar());
      // Setup dan menyimpan gambar di suatu dir.
      $target_dir = "gambar/";
      $target_file = $target_dir . basename($_FILES["gambar"]["name"]);
      $imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));
      move_uploaded_file($_FILES["gambar"]["tmp_name"], $target_file);

      // Re-assign nilai pada atribut.
      echo 'Data Berhasil Diubah...';
      $DPR->set_nama($_POST['nama']);
      $DPR->set_id($_POST['id']);
      $DPR->set_bidang($_POST['bidang']);
      $DPR->set_partai($_POST['partai']);
      $DPR->set_gambar(basename($_FILES["gambar"]["name"]));
      $flagBerhasil = 1;
    }
  }
  if($flagBerhasil == 0)
  {
    echo 'Data Tidak Tersedia...';
  }
}

// Menghapus data (Delete).
if(isset($_POST['submitD']))
{
  $flagBerhasil = 0;
  $index = 0;
  foreach($data_DPR as $DPR)
  {
    // Pencarian id yang sama dengan id yang mau dihapus.
    if($DPR->get_id() == $_POST['id_modif'])
    {
      echo 'Data Berhasil Dihapus...';
      // Menghapus objek dari array.
      unset($data_DPR[$index]);
      // Menghapus gambar dari folder.
      unlink('gambar/' . $DPR->get_gambar());
      // Reset index array.
      $data_DPR = array_values($data_DPR);
      $flagBerhasil = 1;
      break;
    }
    else
    {
      $index = $index + 1;
    }
  }  
  if($flagBerhasil == 0)
  {
    echo 'Data Tidak Tersedia...';
  }
}

// Set nilai session yang terbaru.
$_SESSION["data_DPR"] = $data_DPR;

// if(isset($_POST['end']))
// {
//    session_destroy();
//    header("Location: main.php");
// }

?>