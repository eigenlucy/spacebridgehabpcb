#include <Arduino.h>
#include <SX126x-Arduino.h>
#include <SPI.h>
#include <TinyGPSPlus.h>
#include "SparkFun_I2C_GPS_Arduino_Library.h" //Use Library Manager or download here: https://github.com/sparkfun/SparkFun_I2C_GPS_Arduino_Library

I2CGPS myI2CGPS; //Hook object to the library
hw_config hwConfig;

// ESP32 - SX126x pin configuration
// int PIN_LORA_RESET = 4;	 // LORA RESET
// int PIN_LORA_DIO_1 = 21; // LORA DIO_1
// int PIN_LORA_BUSY = 22;	 // LORA SPI BUSY
int PIN_LORA_NSS = 10;	 // LORA SPI CS ~ uc.spi2_cs.line
int PIN_LORA_SCLK = 12;	 // LORA SPI CLK ~ uc.ic.IO12
int PIN_LORA_MISO = 13;	 // LORA SPI MISO ~ uc.ic.IO13
int PIN_LORA_MOSI = 11;	 // LORA SPI MOSI ~ uc.ic.IO11
// int RADIO_TXEN = 26;	 // LORA ANTENNA TX ENABLE
// int RADIO_RXEN = 27;	 // LORA ANTENNA RX ENABLE

#define PORT Serial
//#define PORT SerialUSB

void setup()
{
  PORT.begin(115200);
  PORT.println("GTOP Read Example");

  while (myI2CGPS.begin() == false)
  {
    PORT.println("Module failed to respond. Please check wiring.");
    delay(500);
  }
  PORT.println("GPS module found!");
}

void loop()
{
  while (myI2CGPS.available()) //available() returns the number of new bytes available from the GPS module
  {
    byte incoming = myI2CGPS.read(); //Read the latest byte from Qwiic GPS

    if(incoming == '$') PORT.println(); //Break the sentences onto new lines
    PORT.write(incoming); //Print this character
  }
}

