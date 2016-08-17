---
title: "Tk-Conclusions"
permalink: /paper/tk/
excerpt: "Some conclusions about tkinter."
modified: 2016-8-17 10:49:48
---

# TK()

[Fishc详解](http://bbs.fishc.com/forum.php?mod=forumdisplay&fid=243&filter=typeid&typeid=604)

---

>root = thinter.Tk() #root 即为根窗口
>......
>mainloop()

1. frame
2. Label
3. IntVar-StringVar
   **TK()中的显示，输入的内容如果是变量，需要以如上方式声明成对象**

## 位置管理 pack,grid,place

没有确定位置就储存在内存中，不会显示出来。

1.  pack()
    1.  padx,pady.
        **与X,Y边框的距离**。
    2.  fill——**是否填充=Y or X or BOTH**
    3.  anchor——**E W S N NW等8个位置（即上下左右对齐）**
    4.  expand是否随外框改变尺寸
2.  grid()
                  **以网格方式排列，以row,column表示坐标(从0起) 。sticky =默认居中（e,w,s,n）**
3.  place()
    1.  relx,rely **对齐点相对位置**
    2.  relwidth,relheight **相对父组件的宽度和高度**
    3.  ​

## button and LabelFrame

```python
Button(root,text="标签上的内容",command=点击标签的行为(function形式)\
.width=10).grid(row=1,column=1,sticky=w)
```



## Checkbutton

b = Checkbutton(root,text='girl',variable=一个IntVar()——不是0就默认打勾)

## Radiobutton

Radiobutton(root,text='girl',variable=IntVar(),value=1)

**选择后将value赋给variable**
**拥有相同value的会同时被选中，同时不同的value会自动反选**

### indicatoron = False

### 输入框 Entry

```python 
e = Entry(root,textvariable=v1[,state="readonly"])
e.delete(0,END)
e.insert(0,"默认文本")
```

- show = "\*"  : 输入的会以\*显示
- v1为输入的变量，获取方法为v1.get()

### Listbox

Lb = Listbox(root)

**用于多个选项**
Lb.insert(position,item)
**position 从0最后一个位置是END**


~~~python
for item in ['a','b','c']:
	Lb.insert(END,item)
~~~
Lb.delete()提供确定位置，或是起始位置，结束位置。
Lb.delete(ACTIVE)表示当前选中的

height属性，规定显示的行数（默认是10）

#### 添加滚动条

支持的滚动条的对象有x,yscrollcommand对象
首先创建一个滚动条

~~~python
sb = Scroballbar(root)
sb.pack(side=RIGHT,fill=Y)
~~~

再将滚动条添加
~~~python
Lb  = Listbox(root,yscrollcommand=sb.set)#Listbox跟着Scrollbar动
sb.config(command=Lb.yview)#Scrollbar动Listbar也动
~~~

#### 另一种滚动条Scale
Scale滚动可以调节精度
~~~python
s = Scale(root,from_=0,to=10,orient=HORIZONTAL,\
tickinterval=5,\ # 每隔5格显示一个刻度
resolution=5,\ #向下挪一下走5格
length=200 #长度200个像素
)
~~~

### Text

创建一个可以修改的文本框。可以插入组件，可以插入windows对象，还可以插入图片。

```python
text = Text(root,width=30,hright=2)
text.pack()

text.insert(INSERT,'content') #INSERT即为光标位置
text.insert(END,'content')
```

~~~python
b1 = button(text,text='点我点我',command=commmand)
#在text中插入button，button的root要换为text
text.window_create(INSERT,window=b1)
~~~

~~~python
#插入一张图片
photo = PhotoImage(file='file_name')
text.image_create(END,image=photo)
~~~

##### mark and tag

#### canvas
~~~puyhon
c = Canvas(root,width,height)
c.create_line(0,0,100,100,fill='colour',width=宽度)
c.create_rectangle()
c.create_oval() #为相同参数矩形的内切椭圆
c.create_polygon(points,outline='color',fill='color')#points为点元组
~~~
#### 空字符串表示透明

### Menu

1. 菜单栏
   1. 下拉菜单#root.confjg(menu=menubar)
   2. 分割线 #filemenu.add_separator()
   3. 级联菜单 #filemenu.add_cascade(label='name',menu=submenu)

2. 弹出菜单

   实现方式：将Menu.post()与'<Button-1>'用bind绑定

### Message > Label

###  Spinbox>Entry

**一个范围让用户进行选择**

### PanedWindow

### Toplevel

**显示一个额外的，独立的窗口。**
**源自于root，root一关闭就全关闭了。**

### messagebox #是一个子包#

1.  messagebox.askokcancel('title','text',default,icon,parent)

2.  askretrycancel()

3.  askyesno()

              **以上按下确定返回True,Otherwise False**

4.  askquestion()

              **返回yes or no**、

5.  showerror(),showinfo(),showwarning()

              **返回ok表示用户点击了是**

### filedialog #也是一个子包

filedialog.askopenfilename()会打开一个选择文件对话框
选中时返回文件的完整路径

filedialog.asksaveasfilename()打开保存对话框

colorchooser.askcolor()打开颜色选择对话框，返回RGU，和16进制颜色