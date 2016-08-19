/*
    ModbusUDP.h - Header for Modbus UDP Library
    Copyright (C) 2016 wvengen
    Copyright (C) 2015 André Sarmento Barbosa
*/
#include <Arduino.h>
#include <Modbus.h>
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

#ifndef MODBUSUDP_H
#define MODBUSUDP_H

#define MODBUSIP_PORT 	  502
#define MODBUSIP_MAXFRAME 200

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

#endif /* MODBUSUDP_H */

