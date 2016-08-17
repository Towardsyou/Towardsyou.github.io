---
title: "Conclusion-1"
permalink: /paper/cc1/
excerpt: "Note with python3."
modified: 2016-7-30 13:35:15
---

## 字符串的格式化
%d| 整数 
%f| 浮点数
%s| 字符串
%f | 十六进制整数

如果你不太确定应该用什么， %s 永远起作用，它会把任何数据类型转换为字符串

## 字典的有关方法

```python
d = {'Micael':95}
为了避免key不存在的情况
-  key in dict
- dict.get(key,return = -1)
```

## *args 与 **kw
在Python中定义函数，可以用必选参数、默认参数、可变参数和关键字参数，这4种参数都可以一起使用，或者只用
其中某些，但是请注意，参数定义的顺序必须是：必选参数、默认参数、可变参数和关键字参数。

*args 代表可变参数   **kw 代表关键字参数

既可以直接pp(1,2,3,4,5) 输入*args
pp(x=99,y=100) 输入*kw

也可以先定义a=[1,2,3,4,5] b={'x':99,'y':100} 再pp(*a,**b)

默认参数一定要是不可改变的，否则就会不断改变
## enumerate
Python内置的enumerate 函数可以把一个list变成索引-元素对

## Generator
- (x**2 for i in range(100))就是一个生成器
- 或者要把函数变成generator，只需要把print b 改为yield b 就可以了。每次next()，就会输出b

## map()和reduce()
我们先看map。map() 函数接收两个参数，一个是函数，一个是序列， map 将传入的函数依次作用到序列的每个元素，并把结果作为新的list返回。

```python
map(str, [1, 2, 3, 4, 5, 6, 7, 8, 9])
['1', '2', '3', '4', '5', '6', '7', '8', '9']
```

再看reduce的用法。reduce把一个函数作用在一个序列[x1, x2, x3...]上，这个函数必须接收两个参数，reduce把结果继续和序列的下一个元素做累积计算，其效果就是：

```python
>>> def add(x, y):
... return x + y
...
>>> reduce(add, [1, 3, 5, 7, 9])
25
```

## filter
Python内建的filter() 函数用于过滤序列。

和map() 类似， filter() 也接收一个函数和一个序列。和map() 不同的时， filter() 把传入的函数依次作用于每个元素，然后根据返回值是True 还是False 决定保留还是丢弃该元素。

## 排序
通常规定，对于两个元素x 和y ，如果认为x < y ，则返回‐1 ，如果认为x == y ，则返回0 ，如果认为x > y ，则返回1 ，这样，排序算法就不用关心具体的比较过程，而是根据比较结果直接排序。

Python内置的sorted() 函数就可以对list进行排序：

## Something Trivial
isinstance(dict1,dict) = type(dict1) == dict

### Page1-71 廖学峰python3教程