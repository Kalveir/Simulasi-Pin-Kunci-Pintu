# SIMULASI PIN KUNCI PINTU DENGAN ARDUINO DAN PROTEUS
<p align = "center">
  <img src= "https://github.com/Kalveir/Simulasi-Pin-Kunci-Pintu/blob/main/screenshoot/SS.PNG">
</p>

Project ini merupakan tugas dari matakuliah microprocessing. Secara garis besar project ini membahas mengenai cara kerja microcontroller(Arduino) melakukan verifikasi password PIN dari keypad dan indikator validasi PIN tersebut menggunakan bantuan LCD dan 2 buah lampu LED
## Prerequisites
* PROTEUS 8
* ARDUINO IDE
 ## Installing
1. Unduh project dengan perintah
```sh
git clone https://github.com/Kalveir/Simulasi-Pin-Kunci-Pintu.git
```
2. Pindahkan semua file [library Arduino proteus](https://github.com/Kalveir/Simulasi-Pin-Kunci-Pintu/tree/main/Arduino-Library-for-Proteus) ke **...\Libcenter Electronic\Proteus 8 Profesional\DATA\LIBRARY**
3.  Install [Libary Arduino](https://github.com/Kalveir/Simulasi-Pin-Kunci-Pintu/tree/main/library_arduino) dengan menu **Sketch > add .ZIP Library...**
## Running the tests 
* Buka Arduino IDE dan buka project file yang berekstensi [.ino](https://github.com/Kalveir/Simulasi-Pin-Kunci-Pintu/blob/main/kunci_pintu_dengan_arduino/kunci_pintu_dengan_arduino.ino)
* Tekan tombol **Verfy** untuk proses compile. Jika tidak ada error, pilih menu **Sketch > Export compiled Binarry**
* Buka file project **Kunci_pintu.pdsprj** dengan software Proteus
* klik 2x pada microcontroller, kemudian pilih file [hasil compile](https://github.com/Kalveir/Simulasi-Pin-Kunci-Pintu/blob/main/kunci_pintu_dengan_arduino/kunci_pintu_dengan_arduino.ino.standard.hex) dari Arduino tadi
* Klik play dan selesai

## Problem solving
Apabila saat melakukan proses compile, kemudian anda menemukan error seperti berikut :
> warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]

Silahkan edit code pada line 6 dan 7 dengan code berikut :
```C
char psw[]="12345";
Password password = Password(psw);
```
