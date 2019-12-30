const byte numeral[10] = {
  // 0 = led dalam seven segment yang tidak diberikan tagangan
  // 1 = led dalam seven segment yang diberikan tagangan masukan
  B11111100, // angka 0
  B01100000, // angka 1
  B11011010, // angka 2
  B11110010, // angka 3
  B01100110, // angka 4
  B10110110, // angka 5
  B10111111, // angka 6
  B11100000, // angka 7
  B11111110, // angka 8
  B11100110, // angka 9
};
 
// pin dari segment dp,G,F,E,D,C,B,A
const int segmentPins[8] = { 10, 11, 8, 7, 6, 4, 3, 2};
 
 
void setup()
{
  for(int i=0; i < 8; i++)
  {
    pinMode(segmentPins[i], OUTPUT);
  }
}
 
void loop()
{
  //Seven segment akan memulai dari 0 sampai 10
  //Cara kerjanya sistem ditambah 1 dengan delay 1 detik dan ditambah 1 dengan delay 1 detik sampai batas nilai 9.
  //Setelah 7 segment menunjukkan angka 9, maka 7 segment akan mereset ke angka 0 kembali
  for(int i=0; i <= 10; i++){
    showDigit(i);
    delay(1000);
    }
   delay(2000);
  }
 
void showDigit( int number){
  boolean isBitSet;
  for(int segment = 1; segment < 8; segment++){
    if( number < 0 || number > 9){
      isBitSet = 0; //isBitSet akan membuat semua display pada 7 segment mati (LOW)
      }else{
    isBitSet = bitRead(numeral[number], segment);
    }
  isBitSet = !isBitSet; //
  digitalWrite( segmentPins[segment], isBitSet);
  }
}
