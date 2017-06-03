//
//  DataModel.cpp
//  实验七
//
//  Created by 吴芳谷 on 2017/5/18.
//  Copyright © 2017年 Zhy. All rights reserved.

#include "DataModel.h"
USERCALL *UserCallList;
int UserCallListLen;
SYSPARAM ParamArray[200];
ELEVATORSTATE ElevatorA;
ELEVATORSTATE ElevatorB;
RESPONSELISTHEADNODE *ResponseList;
char UserFileName[512];
int FinishCallNum;
int time;
int StatusChangeFlag;
