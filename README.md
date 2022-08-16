# linux-6.0 内核学习


![20220816_152143_70](image/20220816_152143_70.png)

```
Something I hope you know before go into the coding~
First, please watch or star this repo, I'll be more happy if you follow me.
Bug report, questions and discussion are welcome, you can post an issue or pull a request.
```


## 目录

* [版本特性概述](docs/版本特性概述.md)
* [编译错误告警汇总](docs/编译错误告警汇总.md)
* [内核启动错误告警汇总](docs/内核启动错误告警汇总.md)
* [发行版错误告警汇总](docs/发行版错误告警汇总.md)
* [环境搭建](docs/环境搭建.md)
    * [x86_64](docs/环境搭建/x86_64.md)
    * [arm64](docs/环境搭建/arm64.md)
    * [arm](docs/环境搭建/arm.md)
    * [i386](docs/环境搭建/i386.md)
* [带着问题读内核](docs/带着问题读内核.md)





## 图示









## 代码量

```
[root@Rocky /data/linux-6.0.git]# cloc .
   77966 text files.
   77419 unique files.                                          
   14414 files ignored.

github.com/AlDanial/cloc v 1.70  T=378.16 s (168.1 files/s, 85934.5 lines/s)
---------------------------------------------------------------------------------------
Language                             files          blank        comment           code
---------------------------------------------------------------------------------------
C                                    31794        3219507        2542279       16503034
C/C++ Header                         23218         697022        1331018        6832903
JSON                                   452              2              0         371620
YAML                                  2869          51981          13128         237025
Assembly                              1311          46791          99738         226033
Bourne Shell                           853          25858          17624         100612
make                                  2753          10628          11625          48615
Perl                                    66           7373           5026          36470
Python                                 151           6426           5875          32250
yacc                                     9            698            409           4912
lex                                      9            346            309           2110
C++                                      8            353             91           1957
Bourne Again Shell                      54            355            314           1476
awk                                     13            217            157           1323
NAnt script                              2            148              0            509
TeX                                      1              6             73            147
Windows Module Definition                2             15              0            109
m4                                       1             15              1             95
CSS                                      2             35             37             90
XSLT                                     5             13             26             61
MATLAB                                   1             17             37             35
vim script                               1              3             12             27
Ruby                                     1              4              0             25
Markdown                                 6             34              0             24
INI                                      1              1              0              6
sed                                      1              2              5              5
---------------------------------------------------------------------------------------
SUM:                                 63584        4067850        4027784       24401473
---------------------------------------------------------------------------------------
```















----
