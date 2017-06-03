//
//  ResponseCalculate.hpp
//  实验七
//
//  Created by 吴芳谷 on 2017/5/16.
//  Copyright © 2017年 Zhy. All rights reserved.
//

#ifndef ResponseCalculate_hpp
#define ResponseCalculate_hpp

#include <stdio.h>
#include "DataModel.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void  SilenceSimulate() ;//静默仿真模块函数
void  InitSimulation() ;//初始化仿真变量函数
void  InitElevator(ELEVATORSTATE   *elevator) ;//初始化电梯状态变量函数
int  LoadUserCallArray(FILE  *fp) ;//用户指令数组加载数据函数
int  OutputSimulationResult() ;//计算仿真结果并输出为结果文件的函数
void  ImportUserCall(FILE  *fp) ;//将用户指令写入仿真结果文件的函数
void  ImportSimulateParam(FILE  *fp) ;//将仿真参数写入仿真结果文件的函数
void  GetNextTimeStatus(ELEVATORSTATE  *elevator) ;//计算电梯下一时刻状态的函数
void  ImportSimulateResult(FILE *fp) ;//将电梯当前时刻状态写入仿真结果文件的函数
void  FindUserCallCanServe(ELEVATORSTATE  *elevator , char r_state) ;//处理当前电梯是否可以同时响应其它用户指令的函数
char  GetElevatorDirection(ELEVATORSTATE  *elevator) ;//电梯在服务过程中处于停止状态时判断其上下行状态的函数
void  SetElevatorState(ELEVATORSTATE  *elevator) ;//将电梯状态修改为下一时刻状态的函数

#endif /* ResponseCalculate_hpp */
