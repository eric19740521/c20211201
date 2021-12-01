

用VS Code2019遠端控制樹梅派(raspberry pi).開發C語言程式(remote ssh linux c)  控制周邊
參考資料:
https://atceiling.blogspot.com/2014/02/raspberry-pi-wiringpi-gpio.html
http://cheng-min-i-taiwan.blogspot.com/2013/04/raspberry-pi-c.html


1.安裝WiringPi套件
git clone https://github.com/WiringPi/WiringPi.git

2.編譯安裝
cd WiringPi
sudo ./build

3.GPIO測試
gpio -v
sudo gpio readall

4.gcc -o led01 led01.c -lwiringPi
./led01

5.程式碼
//wiringPiSetup () -- 檢查是否有WiringPi並允需程式使用它。
//pinMode() -- 指定Pin腳為輸入/輸出狀態。
//digitalWrite() -- 輸出或偵測輸入一個值( 0 或 1)  到 pin腳。


#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

#define LED     1         //wiringPi pin 1 is BCM_GPIO 18.
#define BUTTON  6  //wiringPi pin 6 is BCM_GPIO 22 25.

int main (void)
{
  printf ("樹梅派LED01 燈 閃爍 \n") ;

  if (wiringPiSetup () == -1)
    return 1 ;

  pinMode (LED, OUTPUT) ;         // aka BCM_GPIO pin 17

  for (;;)
  {
    digitalWrite (LED, 1) ;       // On
    delay (500) ;               // mS
    digitalWrite (LED, 0) ;       // Off
    delay (500) ;
  }
  return 0 ;
}
