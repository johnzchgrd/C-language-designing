# Just a MEMO
## 1、相互包含问题（https://bbs.csdn.net/topics/20196917）
互相包含是允许的，为了防止编译时的错误，所以有#pragma once这样的声明，
无论头文件被包含多少次，都只编译1次，
只要在头文件中加上这一行就可以随意互相包含了，
其实在一定的情况下互相包含可以让你的工作更简单，什么东西都是视情况而定
，就像goto语句，很多书上已经把它扁得一文不值了，但是假如遇到内联汇编的时候，
goto也可以做一些巧妙的工作，看你懂不懂得灵活运用了。
如果你仔细观察由VC自动生成的头文件，那如天书一般的条件宏其实就是为了避免在相互引用的时候重复编译。
## 常用数学函数prototype
  double __cdecl sin(double _X);
  double __cdecl cos(double _X);
  double __cdecl tan(double _X);
  double __cdecl sinh(double _X);
  double __cdecl cosh(double _X);
  double __cdecl tanh(double _X);
  double __cdecl asin(double _X);
  double __cdecl acos(double _X);
  double __cdecl atan(double _X);
  double __cdecl atan2(double _Y,double _X);
  double __cdecl exp(double _X);
  double __cdecl log(double _X);
  double __cdecl log10(double _X);
  double __cdecl pow(double _X,double _Y);
  double __cdecl sqrt(double _X);
  double __cdecl ceil(double _X);
  double __cdecl floor(double _X);
/* 7.12.7.2 The fabs functions: Double in C89 */
  extern  float __cdecl fabsf (float x);
  extern long double __cdecl fabsl (long double);
  extern double __cdecl fabs (double _X);
