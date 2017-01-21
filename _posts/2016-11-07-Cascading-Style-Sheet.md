---
title: "CSS Note"
permalink: /paper/cssNote/
excerpt: "Note about CSS."
modified: 2016-11-23 09:27:39
---
## Css Note

### Over all Settings
- we can select multiple elements to apply a single rule `p,h1,h3 {color:red;}`
- \<img\> is a inline element so we need `display:block` to make it take up space and have margin

**选择器

```css
[attribute]	用于选取带有指定属性的元素。
[attribute=value]	用于选取带有指定属性和值的元素。
[attribute~=value]	用于选取属性值中包含指定词汇的元素。
[attribute|=value]	用于选取带有以指定值开头的属性值的元素，该值必须是整个单词。
[attribute^=value]	匹配属性值以指定值开头的每个元素。
[attribute$=value]	匹配属性值以指定值结尾的每个元素。
[attribute*=value]	匹配属性值中包含指定值的每个元素。
```
### 边框
```css
padding: //内边距
margin: //外边框
border-style:
border-width:
border-color:transparent
border-radius:
```
### Position
- CSS 定位机制
  CSS 有三种基本的定位机制：普通流、浮动和绝对定位。
  除非专门指定，否则所有框都在普通流中定位。也就是说，普通流中的元素的位置由元素在 (X)HTML 中的位置决定。
  块级框从上到下一个接一个地排列，框之间的垂直距离是由框的垂直外边距计算出来。
  行内框在一行中水平布置。可以使用水平内边距、边框和外边距调整它们的间距。但是，垂直内边距、边框和外边距不影响行内框的高度。由一行形成的水平框称为行框（Line Box），行框的高度总是足以容纳它包含的所有行内框。不过，设置行高可以增加这个框的高度。

- CSS position 属性
  通过使用 position 属性，我们可以选择 4 种不同类型的定位，这会影响元素框生成的方式。
  position 属性值的含义：

  - static

  元素框正常生成。块级元素生成一个矩形框，作为文档流的一部分，行内元素则会创建一个或多个行框，置于其父元素中。

  - relative

  元素框偏移某个距离。元素仍保持其未定位前的形状，它原本所占的空间仍保留。因此，移动元素会导致它覆盖其它框。

  - absolute

  元素框从文档流完全删除。绝对定位的元素的位置相对于最近的已定位祖先元素。元素定位后生成一个块级框。(z-index 属性设置元素的堆叠顺序。拥有更高堆叠顺序的元素总是会处于堆叠顺序较低的元素的前面。and z-index can be negative.)

  - fixed

  元素框的表现类似于将 position 设置为 absolute，不过其包含块是视窗本身。
  提示：相对定位实际上被看作普通流定位模型的一部分，因为元素的位置相对于它在普通流中的位置。

- Float

  [Float](http://www.w3school.com.cn/css/css_positioning_floating.asp)

```css
#example {
  position:relative/absolute;
  left:20px;
  top:20px;
}
```









* color

  * HSL 接受**色相**，**饱和度**和**亮度**值
    1. **色调**：颜色的基色光。这需要0和360之间的值，呈现的角度轮色轮。
    2. **饱和度**：怎么饱和是什么颜色？这需要一个值从0到100％，其中0表示无颜色（这将显示为灰色阴影），和100％充满色彩饱和度
    3. **亮度**：光线如何，或明亮的颜色？这从0-100％，其中0表示没有光取一个值（它会出现全黑）和100％充满光明（它会出现全白）

  * RGB和HSL都有相应的模式- RGBA和HSLA -这让你不仅要显示什么颜色设置，还能有什么**透明度，**你想要的颜色有。对应的功能采取同样的参数，加上在0-1范围内的第四个价值-它设定了透明度或**alpha通道**。0是完全透明，1是完全不透明的。

* overflow:auto; ==>  the overflowing content is hidden and scroll bars are shown to let the user scroll to see all the content.
* Background clip display
```CSS
.default     { background-clip: border-box;  }
.padding-box { background-clip: padding-box; }
.content-box { background-clip: content-box; }
```

```CSS
.inline       { display: inline;       }
.block        { display: block;        }
.inline-block { display: inline-block; }
```

### Common use
inline>id>class
align="center"
body background="/i/a.jpg"