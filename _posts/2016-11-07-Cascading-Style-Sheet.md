---
title: "CSS Note"
permalink: /paper/cssNote/
excerpt: "Note about CSS."
modified: 2016-11-23 09:27:39
---
* things added

  * css should be added to the head tag by `<link href="styles/style.css" rel="stylesheet" type="text/css">`
  * head tag to add font`<link href='http://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet' type='text/css'>`
  * main.js should be added before the end of body tags

* we can select multiple elements to apply a single rule `p,h1,h3 {color:red;}`

* Pseudo class selector `a:hover` :Selects <a>, but only when the mouse pointer is hovering over the link.

* <img> is a inline element so we need `display:block` to make it take up space and have margin

* color

  * HSL 接受**色相**，**饱和度**和**亮度**值
    1. **色调**：颜色的基色光。这需要0和360之间的值，呈现的角度轮色轮。
    2. **饱和度**：怎么饱和是什么颜色？这需要一个值从0到100％，其中0表示无颜色（这将显示为灰色阴影），和100％充满色彩饱和度
    3. **亮度**：光线如何，或明亮的颜色？这从0-100％，其中0表示没有光取一个值（它会出现全黑）和100％充满光明（它会出现全白）

  * RGB和HSL都有相应的模式- RGBA和HSLA -这让你不仅要显示什么颜色设置，还能有什么**透明度，**你想要的颜色有。对应的功能采取同样的参数，加上在0-1范围内的第四个价值-它设定了透明度或**alpha通道**。0是完全透明，1是完全不透明的。

* overflow:auto; ==>  the overflowing content is hidden and scroll bars are shown to let the user scroll to see all the content.
* Background clip display
  * ```
    .default     { background-clip: border-box;  }
    .padding-box { background-clip: padding-box; }
    .content-box { background-clip: content-box; }
    ```

  * ```
    .inline       { display: inline;       }
    .block        { display: block;        }
    .inline-block { display: inline-block; }
    ```
