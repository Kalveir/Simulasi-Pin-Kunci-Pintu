#include <Password.h>         //library untuk Password
#include <Keypad.h>           //library untuk Keypad
#include <LiquidCrystal.h>    //library untuk LCD
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);  //inisialisai pin untuk LCD

//char psw[]="12345";
Password password = Password("12345");   //isi dengan password kalian sendiri

int ledHijau = 10;    //inisialisasi pin untuk led hijau
int ledMerah = 11;    //inisialisasi pin untuk led merah

const byte baris = 4;   //konstanta jumlah baris pada keypad
const byte kolom = 3;   //konstanta jumlah kolom pada keypad
char keys[baris][kolom] =   //pemetaan baris dan kolom ke karakter
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte barisPin[baris] = { 9, 8, 7, 6 };    //inisialisasi pin untuk baris keypad
byte kolomPin[kolom] = { 5, 4, 3 };       //inisialisasi pin untuk kolom keypad

//membuat objek keypad
Keypad keypad = Keypad( makeKeymap(keys), barisPin, kolomPin, baris, kolom );


void setup()
{
  Serial.begin(9600);             //mengatur baud rate ke 9600
  lcd.begin(16, 2);               //inisialisasi jumlah baris dan kolom pada LCD
  pinMode(ledHijau, OUTPUT);      //mengkonfigurasi led hijau sebagai output
  pinMode(ledMerah, OUTPUT);      //mengkonfigurasi led merah sebagai output
  digitalWrite(ledMerah, HIGH);   //kondisi awal led merah bernilai HIGH   

  keypad.addEventListener(keypadEvent);

  //menulis tampilan awal pada LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Password:");
}


void loop()
{
  char key = keypad.getKey();
  if(key)
  {
    if((key != '*')&&(key != '#'))    //jika karakter yang masuk tidak sama dengan bintang dan pagar
    {
      lcd.print("*");   //password yang di inputkan akan diganti menjadi bintang
    }

    if(key == '#')    //jika karakter yang masuk sama dengan pagar LCD akan mengapus nilai inputan yang ada di LCD
    {
      lcd.clear();
      lcd.print("Password:");
    }
  }
}


void keypadEvent(KeypadEvent eKey)
{
  switch (keypad.getState())
  {
    case PRESSED:
    Serial.println(eKey);
    delay(10);

    switch (eKey)
    {
      case '*': login(); delay(1); break;   //tombol bintang berfungsi sebagai Enter

      case '#': password.reset(); delay(1); break;    //tombol pagar berfungsi untuk menghapus nilai inputan di LCD sekaligus untuk mereset password

      default: password.append(eKey); delay(1);
    }
  }
}



void login()
{
  if (password.evaluate())    
  {
    //jika password benar maka selenoid door akan bernilai LOW dan dan pintu akan terbuka
    digitalWrite(ledMerah, LOW);    //led merah mati
    digitalWrite(ledHijau, HIGH);   //led hijau menyala
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Password benar");    //tampilan LCD ketika password benar
    lcd.setCursor(0,1);
    lcd.print("Pintu terbuka");     //tampilan LCD ketika password benar
    delay(3000);

    //setelah 3 detik seleoid door akan bernilai HIGH dan dan pintu akan terkunci kembali
    digitalWrite(ledMerah, HIGH);   //led merah menyala
    digitalWrite(ledHijau, LOW);    //led hijau mati
    lcd.clear();
    lcd.print("Password:");
    password.reset();   //password akan di reset secara otomatis
  }
  else
  {
    //jika password salah maka selenoid door akan bernilai HIGH dan pintu akan tetap terkunci
    digitalWrite(ledMerah, HIGH);   //led merah menyala
    digitalWrite(ledHijau, LOW);    //led hijau mati
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Password salah");    //tampilan LCD ketika password salah
    delay(3000);

    //setelah 3 detik lcd akan di bersihkan dan password akan di reset kembali
    lcd.clear();
    lcd.print("Password:");
    password.reset();
  }
}
