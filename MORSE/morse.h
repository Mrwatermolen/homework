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