﻿# ECBM库

#### 介绍
该GIT仓库为ECBM的发行版，ECBM库能帮助你更快更简单地实现你的电子创意。  
ECBM寓意为：**E***verything* **C***an* **B***e* **M***odule*，即：***一切都可以模块化***  
造轮子一时爽，一直造一直爽。编程即是思想，不同的人有着不同的思想模式，就会有不同的编程风格。   
我也使用过很多库，发现可以分为两种：   
* 一种是简单封装成函数，没有一个好的体系。 这类库一般由DIY爱好者编写，由于是用到什么写什么，所以很容易出现一套库不同风格的问题。甚至库的发布者本身就是搜罗网上其他人写的库，导致库之间冲突严重，风格混乱。   
* 一种是按某种风格和规则封装，但是复杂的文件结构和代码规则让新手望而却步。这类库一般由工程师编写，有很好的框架，但是英文注释、英文文档和复杂的结构成为学习的难点。  

这两种都不符合我的需求，于是我便自己造轮子，这才有了ECBM项目。  
ECBM分为两部分：**软件** 和 **硬件**  

ECBM的软件经过了近两年多的迭代，现在终于进化到了3.0.0版本！（2020年11月22日发布）

#### 3.0.0版本特性  

* 基于C语言，并按照统一的风格编写，方便记忆。当你理解之后，甚至可以不用看说明就能立即使用新加入的库。  
* 利用KEIL的特性，使得在KEIL环境下可以使用**图形化编辑工具**，这极大地方便了我们配置外设！  
* 大幅度的优化代码运行速度，大数据量读写的驱动如OLED驱动速度快了5倍。
* 低速外设驱动代码采用类似于面向对象结构，并支持**多器件复用**、**任意IO**都可以驱动。
* 一键新建工程，繁琐的事情原来可以这么简单。
* **全中文注释**，更符合国人习惯。
* 自带例程，有一点基础就能学会。没基础也可以去[知乎专栏](https://www.zhihu.com/column/c_1103988350364495872)学习学习。
* 可剪裁的代码增加，能装进更小的单片机型号。
* 支持STC8全系列单片机！只要有手册上能查得到都能支持。
* 增加虚拟指令层，未来可以支持STC16单片机！

#### 硬件特性   

ECBM项目的使用者定位是单片机新手和电子DIY爱好者。这一点和arduino一致，因此也提供一些板子供新手和爱好者使用。如果你有一定的硬件基础，也可以使用任意一款STC8开发板。   
* 为何使用51单片机？  
    * 51是很老的单片机了，但是确实很简单。对比stm32单片机来说，不需要那么多的初始化，拿来就能用。对比PIC和AVR来说，8051的编译环境易搭建、资料丰富，甚至很多大学都开设有8051的课程。上过类似课程的同学可以迅速入门ECBM。  
    * 另外，在STM32CubeMX的加持下，stm32单片机也变得很简单了，所以下一步ECBM将会有stm32的板子出现。
* 为何是STC8单片机？  
    * 库要求要有通用性，为了保证通用性就不能为了运行速度而优化。这就要求使用一款运行速度快的51单片机。  
    * STC8在整型计算略低于stm32f030（同等运行频率下），在浮点计算中略高于stm32f030（也是同等运行频率下）。所以STC8的性能值得肯定。  
* ECBM板子有何特点？  
    * ECBM有四个主系列：智能、实用、学习、极致。  
        * 智能：即插即用，搭积木式编程。硬件统一、通信统一，将精力集中在**实现功能**上，而不是**如何实现功能**上。    
        * 实用：标准接口小板，标准的2.54排针，方便使用面包板或杜邦线来实现创意，随心所欲。最大程度集成化，只需一条USB即可开始创作。  
        * 学习：中型板子，外设丰富。适合对电路一窍不通、未来想发展软件的同学。  
        * 极致：各种奇葩（褒义）板子，刷新你对开发板的刻板印象。  
* ECBM板子是否开源？  
    * 板子的电路就是基本的最小系统+一定的外设。自己去打板、焊接所花的钱和时间还不如购入一款STC8开发板。由于任意STC8开发板都能使用ECBM库，所以硬件不开源。但肯定只有官方出的板子兼容性最好，而且也不算太贵(ノ￣▽￣)。这是[购买地址](https://shop179570892.taobao.com/index.htm?spm=2013.1.w5002-21430097888.2.54374be8ul78Pw)，您的一份支持便是对我的极大鼓励。

#### 参与贡献

1. 加入QQ群778916610。
2. 提交建议或者BUG。
3. 等待确认。
4. 代码库升级。


#### 注解

1. 版本号按照[框架版本].[文件版本].[代码版本]-[驱动版本]排列。
* 框架版本，在整个库的调用关系，编写方式或者结构层级发生变化的时候，该版本加一。同时清零文件版本和代码版本。此版本变动说明改动很大，更新ECBM库时请多多留意。
* 文件版本，当LIB文件夹发生文件增减时，该版本加一。STC8目前还在发展当中，所以未来还是会加入很多外设。所以此版本变动的话，尝鲜党都可以更新ECBM来玩玩。
* 代码版本，当修改了某些代码或者修复了BUG时，该版本加一。有些极客可能喜欢某些版本，不喜欢频繁的更新。或者已经将某个版本用在产品上了。那么在只有该版本号增加的情况下，可以酌情不更新ECBM库。
* 驱动版本，这是当device文件夹里的模块驱动文件增减时，该版本加一。因此在不使用模块的情况下，只有该版本升级时可以忽略不更新ECBM。