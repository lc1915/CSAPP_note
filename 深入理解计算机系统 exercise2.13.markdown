# 深入理解计算机系统 exercise2.13

标签（空格分隔）： 深入理解计算机系统 

---

## Practice Problem 2.13
The Digital Equipment VAX computer was a very popular machine from the late 1970s until the late 1980s. Rather than instructions for Boolean operations And and Or, it had instructions bis (bit set) and bic (bit clear). Both instructions take a data word x and a mask word m. They generate a result z consisting of the bits of x modified according to the bits of m. With bis, the modification involves setting z to 1 at each bit position where m is 1. With bic, the modification involves setting z to 0 at each bit position where m is 1. To see how these operations relate to the C bit-level operations, assume we have functions bis and bic implementing the bit set and bit clear operations, and that we want to use these to implement functions computing bit-wise operations | and ^, without using any other C operations. Fill in the missing code below.

Hint: Write C expressions for the operations bis and bic.

``` c
/* Declarations of functions implementing operations bis and bic */
int bis(int x, int m);
int bic(int x, int m);

/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, int y) {
    int result =  ___________ ;
    return result;
}

/* Compute x^y using only calls to functions bis and bic */
int bool_xor(int x, int y) {
    int result = ____________ ;
    return result;
}

```

## 解决思路

用书中的方法 用集合表示二进制数值 按位从右至左 写成集合
如 二进制数 0b101101 可以用集合 { 0, 2, 3, 5} 来表示，表明第 0, 2, 3, 5 位（从右往左，从低往高，位置从0开始）上 bit 为 1。

用集合图表示，两圆圈交叉地方代表交集 即x&y，并集即为x|y，x^y是两个圆圈没有交叉的两个部分。
这样一来，问题就变得直观了。

下面来看一下题目中关键句子。

> With bis, the modification involves setting z to 1 at each bit position where m is 1. 

意思是`bis(x, m) == x | m` 在集合图中为两个圆圈所占据的所有部分

> With bic, the modification involves setting z to 0 at each bit position where m is 1.

意思是`bic(x, m) == x & (~m)` 在集合图中为x所在圆圈的不交叉部分

第一个result要求Or，直接`bis(x, y)`即可。

下面我们来看第二个result 要求异或。
直接分析的话无从下手，我们从集合图来看。
异或，是求集合图中两个圆圈拥有但不相交的部分，我们可以视作左右两个圆圈独有部分的和。这样一来，就变为求bis（左，右）。而左，右两部分分别为x,y和y,x的bic函数值。
可解。

**答案** `bis(bic(x, y), bic(y, x))`