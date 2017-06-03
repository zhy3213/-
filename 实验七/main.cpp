//
//  main.cpp
//  实验七
//
//  Created by 吴芳谷 on 2017/5/9.
//  Copyright © 2017年 Zhy. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include "DataModel.h"
#include "ElevatorSimulation.h"
#include "DataImport.h"
#include "ResponseCalculate.hpp"
#include "ScreenSimulation.hpp"
//extern int SystemInit(int argc,char *argv[]);
//extern void ShowMenu(int menu_flag);
int main(int argc,char * argv[]) {
    strcpy(UserFileName, "/Users/Wufanggu/Documents/Lab7");
    printf("%d",SystemInit(argc, argv));
    ShowMenu(argc);
    Draw(&argc, argv);
    return 0;
}
