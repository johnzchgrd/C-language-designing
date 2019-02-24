# Just a MEMO
## 1、相互包含问题（https://bbs.csdn.net/topics/20196917）
互相包含是允许的，为了防止编译时的错误，所以有#pragma once这样的声明，
无论头文件被包含多少次，都只编译1次，
只要在头文件中加上这一行就可以随意互相包含了，
其实在一定的情况下互相包含可以让你的工作更简单，什么东西都是视情况而定
，就像goto语句，很多书上已经把它扁得一文不值了，但是假如遇到内联汇编的时候，
goto也可以做一些巧妙的工作，看你懂不懂得灵活运用了。
如果你仔细观察由VC自动生成的头文件，那如天书一般的条件宏其实就是为了避免在相互引用的时候重复编译。
## 2、常用数学函数prototype

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
   
## 3、Quoted-printable编码方法（ http://blog.chacuo.net/494.html ）

    任何一个8位的字节值可编码为3个字符：一个等号”=”后跟随两个十六进制数字(0–9或A–F)表示该字节的数值.
例如，ASCII码换页符（十进制值为12）可以表示为”=0C”, 等号”=”（十进制值为61）必须表示为”=3D”. 除了
可打印ASCII字符与换行符以外，所有字符必须表示为这种格式.
    所有可打印ASCII字符(十进制值的范围为33到126)可用ASCII字符编码来直接表示, 但是等号”=”(十进制值为61)
不可以这样直接表示.ASCII的水平制表符(tab)与空格符, 十进制为9和32, 如果不出现在行尾则可以用其ASCII字符
编码直接表示。如果这两个字符出现在行尾，必须QP编码表示为”=09″ (tab)或”=20″ (space).
    如果数据中包含有意义的行结束标志，必须转换为ASCII回车(CR)换行(LF)序列，既不能用原来的ASCII字符也不能用
QP编码的”=”转义字符序列。 相反，如果字节值13与10有其它的不是行结束的含义，它们必须QP编码为=0D与=0A.
    quoted-printable编码的数据的每行长度不能超过76个字符. 为满足此要求又不改变被编码文本，在QP编码结果的每
行末尾加上软换行(soft line break). 即在每行末尾加上一个”=”, 但并不会出现在解码得到的文本中.
