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
