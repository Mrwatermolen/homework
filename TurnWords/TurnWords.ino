#include <morse.h>


String turn = "";
Morse m(13);
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    while (Serial.available() > 0)  
    {
        turn += char(Serial.read());
        delay(2);
    }
    for(int i = 0; i < turn.length(); i++)
    {
      switch(turn[i])
      {
        case 'a': m.dot();m.dash();m.c_time();break; //a *-
        case 'b': m.dash();m.dot();m.dot();m.dot();m.c_time();break; // b -***
        case 'c': m.dot();m.dash();m.dot();m.dash();m.c_time();break; // c -*-*
        case 'd': m.dash();m.dot();m.dot();m.c_time();break; // d -**
        case 'e': m.dot();m.c_time();break; // e *
        case 'f': m.dot();m.dot();m.dash();m.dot();m.c_time();break; // f **-*
        case 'g': m.dash();m.dash();m.dot();m.c_time();break; // g --*
        case 'h': m.dot();m.dot();m.dot();m.dot();m.c_time();break; // h ****
        case 'i': m.dot();m.dot();m.c_time();break; // i **
        case 'j': m.dot();m.dash();m.dash();m.dash();m.c_time();break; //j *---
        case 'k': m.dash();m.dot();m.dash();m.c_time();break; // k -*-
        case 'l': m.dot();m.dash();m.dot();m.dot();m.c_time();break; // l *-**
        case 'm': m.dash();m.dash();m.c_time();break; // m --
        case 'n': m.dash();m.dot();m.c_time();break; // n -*
        case 'o': m.dash();m.dash();m.dash();m.c_time();break; // o ---
        case 'p': ;m.dot();m.dash();m.dash();m.dot();m.c_time();break; // p *--*
        case 'q': m.dash();m.dash();m.dot();m.dash();m.c_time();break; // q --*-
        case 'r': m.dot();m.dash();m.dot();m.c_time();break; // r *-*
        case 's': m.dot();m.dot();m.dot();m.c_time();break; // s ***
        case 't': m.dash();m.c_time();break; // t -
        case 'u': m.dot();m.dot();m.dash();m.c_time();break; // u **-
        case 'v': m.dot();m.dot();m.dot();m.dash();m.c_time();break; // v ***-
        case 'w': m.dot();m.dash();m.dash();m.c_time();break; // w *--
        case 'x': m.dash();m.dot();m.dot();m.dash();m.c_time();break; // x -**-
        case 'y': m.dash();m.dot();m.dash();m.dash();m.c_time();break; // y -*--
        case 'z': m.dash();m.dash();m.dot();m.dot();m.c_time();break; // z --**
        default:m.w_time();break; // word interval
      }
    }
    delay(3000);
}
