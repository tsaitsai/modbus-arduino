/*
    ModbusUDP2.h - Header for Modbus UDP2 Library
    Copyright (C) 2016 wvengen
    Copyright (C) 2015 André Sarmento Barbosa
*/
#include <Arduino.h>
#include <Modbus.h>
#include <SPI.h>
#include <Ethernet2.h>

#ifndef MODBUSUDP2_H
#define MODBUSUDP2_H

#ifndef MODBUSIP_PORT
  #define MODBUSIP_PORT     502
#endif
#ifndef MODBUSIP_MAXFRAME
  #define MODBUSIP_MAXFRAME 200
#endif

class ModbusUDP : public Modbus {
    private:
        EthernetUDP _udp;
        byte _MBAP[7];

    public:
        ModbusUDP();
        void config(uint8_t *mac);
        void config(uint8_t *mac, IPAddress ip);
        void config(uint8_t *mac, IPAddress ip, IPAddress dns);
        void config(uint8_t *mac, IPAddress ip, IPAddress dns, IPAddress gateway);
        void config(uint8_t *mac, IPAddress ip, IPAddress dns, IPAddress gateway, IPAddress subnet);
        void task();
};

#endif /* MODBUSUDP2_H */

