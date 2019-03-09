#ifndef MORSECODERS_CONNECTION_H
#define MORSECODERS_CONNECTION_H

#include <SoftwareSerial.h>
#include <HardwareSerial.h>

#define HC12_SPEED 9600
#define SERIAL_SPEED 9600


class Connection {
    private:
        SoftwareSerial HC12;
        const char id = 'a';
        bool handshakeSuccess = false;

        void handshake() {

        }

    public:
        explicit Connection(const SoftwareSerial &HC12) : HC12(HC12) {}

        void begin () {
            HC12.begin(HC12_SPEED);
            Serial.begin(SERIAL_SPEED);
            handshake();
        }

        void loop() {

        }

        void write (char * x){
            Serial.write(x);
            HC12.write(x);
        }

        int read() {
            if (Serial.available()){
                return Serial.read();
            }
            if (HC12.available()){
                return HC12.read();
            }
            return -1;
        }

};

#endif
