---
title: "RE-Instructions"
permalink: /paper/re/
excerpt: "Some conclusions and menu."
modified: 2016-7-29 16:29:36
---

# 元字符 matacharacter
[元字符用法查询](http://bbs.fishc.com/forum.php?mod=viewthread&tid=57691&extra=page%3D1%26filter%3Dtypeid%26typeid%3D403)

. ^ $ * + ? {} [] \ | ()

## 方括号  [] 
制定一个字符类用于存放需要匹配的字符集合

[abc] = [a-c] 表示匹配a,b,c其中的一个字母。顺序按照ASCⅡ排列
PS.元字符在方括号中不会触发特殊功能

'\'会剥夺元字符的特殊作用

\d = [0-9] \d\d\d 匹配一个三位数

\D

\s 匹配任何空白字符

\S

\w 匹配任何单词

\W

\b 匹配单词开始或结束

\B

## {}重复次数：
 .{2,9} 表示匹配任意字符二到九次

> (([01]?\d?\d|25[0-5]|2[0-4]\d)\.){3}([01]?\d?\d|25[0-5]|2[0-4]\d)'

#### * = [0-+∞] = [0,]

#### + = [1-+∞] = [1,]

#### ? = [0,1]

PS. 后面接?即表示非贪婪的限制符 *? +? ?? {m,n}?

[Part-1](http://bbs.fishc.com/forum.php?mod=viewthread&tid=57073&extra=page%3D1%26filter%3Dtypeid%26typeid%3D403)

### ^  $

'^From'匹配以From开头的字符串

‘\.$’匹配以.结尾的字符串

### \b \A \Z 位置符

\b 单词边界匹配符

- '\bclass\b'只能匹配 a class a

- 不能匹配 aclassa 和 aclass a 

### 对象化方法

a = re.compile(pattern = r'写入待匹配内容'，flags=0)

- a.match()
- a.search()
- a.findall()
- a.finditer()

上述四个方法返回一个对象，包含4个关键方法。
- group() 返回匹配的字符串 = group(0) 其中的值代表第几个值组捕获的内容
- groups()
- start() 起始位置
- end()   结束位置
- span()  (起始位置，结束位置)

flag：
- ASCII,A         只匹配ASCII字符
- DOTALL,S        使.匹配一切符号（包括换行符）
- IGNORECASE,I    不区分大小写
- LOCALE,L        支持当前语言区域
- MUTILINE,M      多行匹配，影响（^ $）
- VERBOSE,X       启用详细的正则表达式

[Part-2](http://bbs.fishc.com/thread-57188-1-1.html)

[Part-3](http://bbs.fishc.com/thread-57207-1-1.html)

### 非捕获组，命名组及向前断言

[Part-5](http://bbs.fishc.com/thread-57317-1-1.html)

非捕获组

'''python
m = re.match("([abc])+", "abc")
m.groups()
('c',)
m = re.match("(?:[abc])+", "abc")
m.groups()
()
'''

命名组

'''python
>>> p = re.compile(r'(?P<word>\b\w+\b)')
>>> m = p.search( '(((( Lots of punctuation )))' )
>>> m.group('word')
'Lots'
>>> m.group(1)
'Lots'
'''

我们要讲解的另一个零宽断言是前向断言，前向断言可以分为前向肯定断言和前向否定断言两种形式。

(?=...)前向肯定断言。如果当前包含的正则表达式（这里以 ... 表示）在当前位置成功匹配，则代表成功，否则失败。一旦该部分正则表达式被匹配引擎尝试过，就不会继续进行匹配了；剩下的模式在此断言开始的地方继续尝试。

(?!...)<p style="line-height:30px;text-indent:2em;text-align:left">前向否定断言。这跟前向肯定断言相反（不匹配则表示成功，匹配表示失败）。</p>

### re.split() re.sub()的用法
[Part-6](http://bbs.fishc.com/thread-57362-1-1.html)

'''python
p = re.compile( '(blue|white|red)')

p.sub( 'colour', 'blue socks and red shoes')

'colour socks and colour shoes'

p.sub( 'colour', 'blue socks and red shoes', count=1)

'colour socks and red shoes'
'''

'''python
p = re.compile(r'\W+')

p.split('This is a test, short and sweet, of split().')

['This', 'is', 'a', 'test', 'short', 'and', 'sweet', 'of', 'split', '']

p.split('This is a test, short and sweet, of split().', 3)

['This', 'is', 'a', 'test, short and sweet, of split().']

p = re.compile(r'\W+')

p2 = re.compile(r'(\W+)')

p.split('This... is a test.')

['This', 'is', 'a', 'test', '']

p2.split('This... is a test.')

['This', '... ', 'is', ' ', 'a', ' ', 'test', '.', '']

re.split('[\W]+', 'Words, words, words.')

['Words', 'words', 'words', '']

re.split('([\W]+)', 'Words, words, words.')

['Words', ', ', 'words', ', ', 'words', '.', ''] 

re.split('[\W]+', 'Words, words, words.', 1)

['Words', 'words, words.']
'''

- \ backslash
- ` backtick
- * asterisk
- _ underscore
- {} curly braces
- [] square brackets
- () parentheses
- # hash mark
- + plus sign
- - minus sign (hyphen)
- . dot
- ! exclamation mark
