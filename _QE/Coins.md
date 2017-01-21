---
title: "Coin Problem"
permalink: /QE/coin
excerpt: "Coin problem."
modified: 2017-01-21 19:40:28
---

In England, the currency is made up of pound £, and pence p, and there are eight coins in general circulation:

​	1p 2p 5p 10p 20p 50p £1(100p) £2(200p)

It's possible to make £2 pounds in the following way:

​	1£ + 50p + 2*20p + 5p + 2p + 1p

How many different ways can £2 be made using any number of coins?



```python
def CS():
    number = 0
    money = 200
    for a in range(3):
        A = money = 200 - 100*a
        for b in range(A//50+1):
            money = A
            B = money = money - 50*b
            for c in range(B//20+1):
                money = B
                money  = C =money - c*20
                for d in range(C//5+1):
                    money = C
                    money = D =money - 5*d
                    for e in range(D//2+1):
                        money = D
                        if 100*a+50*b+20*c+5*d+2*e<=200:
                            number += 1
    return number+1

# CS() 14699
```



[Further Info](/solution_coin_sums.pdf)