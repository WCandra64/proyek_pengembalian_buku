langkah2 bikin repository
1. masuk ke folder tempat mau naro proyeknya
2. klik kanan di windownya, klik **git bash here**, copas di bawah (buat paste di gitbash tinggal klik kanan)
3. _git clone https://github.com/WCandra64/proyek_pengembalian_buku.git_
4. _git remote add origin https://github.com/WCandra64/proyek_pengembalian_buku.git_
5. _git checkout -b nama_klen(misal fadel) *_
<br/>
tiap mau update repositori lokal disamain sama repo remote, pake _git pull_
<br/>langkah 5 buat ganti branch, branch utama tu master, fungsi branch biar file yang ada di branch satu sama laen ga kecampur, jadi misal di master ada file main.cpp, terus di branch fadel ada file main.cpp, 2 file itu isinya beda<br/>
buat pindah branch pake _git checkout -b nama_branch_


langkah2 upload file (upload cpp nya doang aja)
1. _git add namafile.ekstensi_ (kalo mau add semua file pake) _git add *_
2. _git commit -m "pesan upload (diisi perubahan yang diupload)"_
3. _git push origin nama_brach_

buat hapus file yang udah di add/stage pake command _git reset head --_<br/>
buat cek file yang udah di add/stage pake command _git status_
