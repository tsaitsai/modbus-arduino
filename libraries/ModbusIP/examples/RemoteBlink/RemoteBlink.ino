/*
  Modbus-Arduino Example - RemoteBlink (Modbus IP)
  Copyright 2016 by wvengen
  http://github.com/wvengen/modbus-arduino

  This example shows how to control a remote Modbus IP device. it works
  together with the Lamp example, blinking it every second. To see it in
  reality, you'll need two Ethernet-enabled Arduinos: one running the
  Lamp example, the other running this sketch.
*/
 
#include <SPI.h>
#include <Ethernet.h>
#include <Modbus.h>
#include <ModbusIP.h>

// ip address we're going to send to
byte dst[] = { 192, 168, 1, 220 };
// coil we're going to switch on and off
const int LAMP_COIL = 100; 

ModbusMasterIP mbm;

void setup() {
    // Ethernet address of this shield
    byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE };
    // IP address for this shield
    byte ip[] = { 192, 168, 1, 221 };
    Ethernet.begin(mac, ip);
}

void loop() {
    // blink lamp every second
    mbm.sendCoil(dst, LAMP_COIL, 1);
    delay(500);
    mbm.sendCoil(dst, LAMP_COIL, 0);
    delay(500);
}
