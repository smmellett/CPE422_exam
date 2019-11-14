#include <iostream>
#include <sstream>
#include <fstream>
#include <unistd.h>
using namespace std;

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#define ADC 0

float getTemperature(int adc_value) {     // from the TMP36 datasheet
   float cur_voltage = adc_value * (1.80f/4096.0f); // Vcc = 1.8V, 12-bit
   float diff_degreesC = (cur_voltage-0.75f)/0.01f;
   return (25.0f + diff_degreesC);
}

int readAnalog(int number){
   stringstream ss;
   ss << ADC_PATH << number << "_raw";
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> number;
   fs.close();
   return number;
}

int main(){
   int i = 0;   
   
   fstream fs;
   fs.open("temperatures.txt", fstream::out);
   for(i=0; i<10; i++)
   {
      float temp = getTemperature(readAnalog(ADC));
      float fahr = 32 + ((temp * 9)/5);    // convert deg. C to deg. F
      fs << temp << endl;
      sleep(1);
   }
   fs.close();
}

