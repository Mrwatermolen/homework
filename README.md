# work
 开源硬件课程学习

## 第一天
 ·github的使用
 ·Arduino的安装
  ![Arduino](F:\学校\开源硬件\arduino.png)
  ·Fritzing的安装
  ![](F:\学校\开源硬件\fritzing.png)  
  ·processing的安装
  ![](F:\学校\开源硬件\processing.png)
  ·Linux的安装

## 第二天
·Arduino 语法的学习
示例为Morse的转化
morse.h
```
#ifndef _MORSE_H
#define _MORSE_H
class Morse
{
  public:
    Morse(int pin); //构造函数
    void dot(); //方法 构造点
    void dash(); //方法 构造划
    void c_time(); //方法 字符
    void w_time(); //方法 单词
  private:
    int _pin;//
    int _time;//点的时间
};
#endif

```
morse.cpp
```
#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
	_time=250;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(_time);
	digitalWrite(_pin,LOW);
	delay(_time);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(_time*4);
	digitalWrite(_pin,LOW);
	delay(_time);
}

void Morse::c_time()
{
	digitalWrite(_pin,LOW);
	delay(_time*3);
}

void Morse::w_time()
{
	digitalWrite(_pin,LOW);
	delay(_time*7);
}

```
TurnWord.ino
```
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

```

## 第三天

·硬件连接与软件的配合使用

·示例为小车行驶方向的控制

电路图
   ![](F:\学校\开源硬件\work\7.4课堂作业car\car.png)
car.ino
```
// f 前进 b后退 l左转 r右转 s停止

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

int data = 0;
void loop()
{
  if(Serial.available() > 0)
  {
    data = Serial.read();
    switch(data)
    {
      case 'f':forward();break;
      case 'b':backward();break;
      case 'l':left();break;
      case 'r':right();break;
	  case 's':stop();break;
    }
  }

}

void backward()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
}


void left()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
}


void right()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}


void forward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}


void stop()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}

```  
·示例为七段显示器使用

电路图
   ![](F:\学校\开源硬件\work\7.4七段显示器\2019.png)

code.ino
```
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

int data = 0;
int code[10][4] = {
  {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,1}, {0,1,0,0}, {0,1,0,1},
  {0,1,1,0}, {0,1,1,1}, {1,0,0,0}, {1,0,0,1}
};

void loop()
{
  if(Serial.available() > 0)
  {
    data = Serial.read() - 48;
    for(int i = 0; i < 4; i++)
    {
      if(code[data][i] == 0)
        digitalWrite(5 - i,LOW);
      else
        digitalWrite(5 - i,HIGH);
    }
  }

}

```   


##第四天
·多位数的显示
电路图
   ![](F:\学校\开源硬件\work\7.5多位数显示\2019.png)
code.ino
```
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
int count = 0;
int data[4] = {0, 0, 0, 0};
int code[10][4] = {
  {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,1}, {0,1,0,0}, {0,1,0,1},
  {0,1,1,0}, {0,1,1,1}, {1,0,0,0}, {1,0,0,1}
};

void loop()
{
  if(count > 3)
    count = 0;
  for(int j = 0; j < 4; j++)
    digitalWrite(13 - j,HIGH);
  if(Serial.available() > 0)
  {
    digitalWrite(13 - count,LOW);
    data[count] = Serial.read() - 48;
    for(int i = 0; i < 4; i++)
    {
      if(code[data[count]][i] == 0)
        digitalWrite(5 - i,LOW);
      else
        digitalWrite(5 - i,HIGH);
    }
    digitalWrite(13 - count,HIGH);
    count++;
  }

}
```
Shiny Bruticus-Jofo.brd为模型文件


#课程总结
第一次接触开源硬件 从一开始啥也不懂到现在能够模拟出数学显示也是收获颇多
<p>我从这一节课里获得最多的能力就是自我学习能力，一开始很多东西都不知道，只能去硬翻英语资料，
或者通过中文论坛查找知识。尤其是七段显示器，有些复杂，却也提升了我对开源硬件的理解</p>
<em>最后 感谢老师的教导！</em>
