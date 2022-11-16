# SIMULASI PIN KUNCI PINTU DENGAN ARDUINO DAN PROTEUS
Project ini merupakan tugas dari matakuliah microprocessing. Secara garis besar project ini membahas mengenai cara kerja microcontroller(Arduino) melakukan verifikasi password PIN dari keypad dan indikator validasi PIN tersebut menggunakan bantuan LCD dan 2 buah lampu LED
## Prerequisites
* PROTEUS 8
* ARDUINO IDE
 ## Installing
1. Unduh project dengan perintah
```sh
git clone https://github.com/Kalveir/Simulasi-Pin-Kunci-Pintue
```
2. Pindahkan semua file library Arduiono proteus ke **...\Libcenter Electronic\DATA\LIBRARY**
3.  Install Libary Arduino dengan menu **Sketch > add .ZIP Library...**
## Running the tests 
* Buka Arduino IDE dan buka project file yang berekstensi .ino
* Tekan tombol **Verfy** untuk proses compile. Jika tidak ada error, pilih menu **Sketch > Export compiled Binarry**
* Buka file **Kunci_pintu.pdsprj** dengan software Proteus
* klik 2x pada microcontroller, kemudian pilih file hasil compile dari Arduino tadi
* Klik play dan selesai

## Problem record
Apabila saat melakukan proses compile, kemudian anda menemukan error sebagai berikut :
> warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]

Silahkan edit code pada line 6 dan 7 dengan code berikut :
```sh
char psw[]="12345";
Password password = Password(psw);
```
