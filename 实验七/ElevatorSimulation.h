//
//  ElevatorSimulation.h
//  实验七
//
//  Created by 吴芳谷 on 2017/5/16.
//  Copyright © 2017年 Zhy. All rights reserved.
//
#pragma once
#ifndef ElevatorSimulation_h
#define ElevatorSimulation_h
#include<stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "DataModel.h"
#include <math.h>
int SystemInit(int argc,char *argv[]);
void ShowMenu(int menu_flag);//显示系统菜单函数
void  FullSimulate() ;//动画仿真模块函数
void  ShowMovieAndImport() ;//显示动画仿真过程并输出结果文件的函数
void  HistorySimulate() ;//历史仿真文件回放函数
void  ShowMovieAndImport() ;//显示动画仿真过程并输出结果文件的函数

#endif /* ElevatorSimulation_h */
