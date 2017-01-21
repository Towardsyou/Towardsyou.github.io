---
title: "Numpy note"
permalink: /QE/npNote
excerpt: "Numpy note."
modified: 2017-01-21 22:36:11
---

# Numpy Note

```python
import numpy as np
```

## Creating Arrays

### The most important of these dtypes are:
- float64: 64 bit floating point number
- float32: 32 bit floating point number
- int64: 64 bit integer
- int32: 32 bit integer
- bool: 8 bit True or False


```python
z = np.empty(3,dtype = int) # intergers

z = np.zeros(3,dtype=float) #float => float64

z = np.ones(3)
```


```python
z = np.linspace(2,4,5) # From 2 to 4 with 5 numbers
z = np.arrange(2,4,0.5)
```


```python
z = np.identity(2) #an identity matrix with 2 dimension
```

* From python list tuples using np.array()


```python
z = np.array([[10,20],[12,21]])

z = np.array((10,20)
```

*Do not copy Numpy array*

## Array Methods


```python
z.sort()

z.sum()

z.mean()

z.max()

z.argmax() ## Returns the index of the maximal element
```


```python
z.cumsum()

z.cumprod()

z.var()

z.std()

z.T <=> z.transpose()
```


```python
z.searchsorted(a)
#if z is nondecreasing array then it return index of first element such that z>=a
```

## Algebra Operations


```python
a + b

a + 10

a * 10

a ** 2
# element by element
```

## Matrix Multiplication


```python
np.dot(a,b) # for the inner product
```

* As a rule, comparisions on array are done elementwise


```python
z == y
>>array([ True,  True], dtype=bool)
```


```python
z[z>3] # leave the element such that > 3

=> b = z>3 # b = array[False ... True ...]
   z[b]
```

## Other common use


```python
np.linalg.inv(A) # calculate the inverse
```


```python
np.linalg.det(A) # calculate the determinant
```
