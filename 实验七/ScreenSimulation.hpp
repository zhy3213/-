//
//  ScreenSimulation.hpp
//  实验七
//
//  Created by 吴芳谷 on 2017/5/16.
//  Copyright © 2017年 Zhy. All rights reserved.
//

#ifndef ScreenSimulation_hpp
#define ScreenSimulation_hpp

#include <stdio.h>
#include <GLUT/GLUT.h>

void Draw(int *argc,char * argv[]);
void renderScene(void);
void  MovieSimulate() ;//动画仿真模块函数
void  ShowMovie() ;//显示动画仿真过程函数
void  PaintPicture() ;//将当前时刻电梯状态绘制成图形的函数

#endif /* ScreenSimulation_hpp */
