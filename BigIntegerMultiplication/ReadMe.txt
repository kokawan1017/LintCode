========================================================================
    控制台应用程序：BigIntegerMultiplication 项目概述
========================================================================

原题链接：
http://www.lintcode.com/en/problem/big-integer-multiplication/

大致思路：
主要实现3个方法：
1、实现string和char类型相乘
2、实现string与string相加
3、在1和2的基础上，遍历其中一个乘数，用每个char逐个和string相乘，再将结果相加