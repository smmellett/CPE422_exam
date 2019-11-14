/* A Simple GPIO application
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2018
* ISBN 9781119533160. Please see the file README.md in the repository root
* directory for copyright and GNU GPLv3 license information.            */

#include<iostream>
#include<unistd.h> //for usleep
#include"GPIO.h"
#include"derek_LED.h"
using namespace exploringBB;
using namespace std;

int main(){
   GPIO outGPIO(49), inGPIOA(26), inGPIOB(46);

   outGPIO.setDirection(OUTPUT);
   LED led(3);

   if (inGPIOA.getValue() == 0){
      outGPIO.setValue(HIGH);
   }
   else if (inGPIOB.getValue() == 0){
      led.turnOn();
   }
   else{
      led.turnOff();
      outGPIO.setValue(LOW);
   }

   return 0;
}
