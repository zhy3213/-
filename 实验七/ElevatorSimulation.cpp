//
//  ElevatorSimulation.cpp
//  实验七
//
//  Created by 吴芳谷 on 2017/5/16.
//  Copyright © 2017年 Zhy. All rights reserved.
//

#include "ElevatorSimulation.h"
#include "ResponseCalculate.hpp"
//#include "DataModel.h"
#include "ScreenSimulation.hpp"
int SystemInit(int argc,char *argv[]){
    int num,i=0;
    double a;
    if (access("/Users/wufanggu/Documents/Lab7/SysConf", F_OK)!=0) {
        return 0;
    }
    if (access("/Users/wufanggu/Documents/Lab7/SysConf/SysParam.txt", F_OK)!=0) {
        return -1;
    }
    FILE *fp;
    fp=fopen("/Users/wufanggu/Documents/Lab7/SysConf/SysParam.txt", "r");
    if (fp==NULL) {
        return -2;
    }
    fclose(fp);
    freopen("/Users/wufanggu/Documents/Lab7/SysConf/SysParam.txt", "r", stdin);
    if(scanf("%d",&num)==EOF){
        freopen("/dev/consle", "r", stdin);//not sure
        return -8;
    }
    for (; i<num; i++) {
        if (scanf("%s=%s",ParamArray[i].param_name,ParamArray[i].param_value)==EOF) {
            freopen("/dev/consle", "r", stdin);//not sure
            return -7;
        }
    }
    freopen("/dev/consle", "r", stdin);//not sure
    if (access(ParamArray[0].param_value, F_OK)!=0) {
        return -3;
    }
    if (access(ParamArray[1].param_value, F_OK)!=0) {
        return -4;
    }
    a=atoi(ParamArray[2].param_value);
    if (a<=2||a!=floor(a)) {
        return -5;
    }
    a=atof(ParamArray[3].param_value);
    if (a<=0||a!=floor(a)) {
        return -6;
    }
    return 1;
}

void ShowMenu(int menu_flag){
    int flag;
    printf("本程序为一个电梯仿真程序，仿真两部电梯的联动运行，提供如下功能\n1. 指定用户指令文件，静默仿真（只输出仿真结果文件）\n2. 指定用户指令文件，动画仿真（不输出仿真结果文件）\n3. 指定用户指令文件，全面仿真（即显示动画，又输出结果文件）\n4.指定历史仿真文件，动画形式回放\n5.修改系统参数\n0. 退出\n请输入您要执行的功能序号：");
    scanf("%d",&flag);
    //while (1) {
    switch (flag) {
        case 1:
            printf("您当前处于“静默仿真”模块，请选择要进行的操作：\n1. 输入用户指令文件名称，开始静默仿真\n0. 返回上级菜单\n请输入您需要进行的操作序号：");
            scanf("%d",&flag);
            switch (flag) {
                case 1:
                    //scanf("%s",UserFileName);
                    SilenceSimulate();
                    break;
                case 0:
                    break;
                default:
                    break;
            }
            break;
        case 2:
            printf("您当前处于“动画仿真”模块，请选择要进行的操作：\n1. 输入用户指令文件名称，开始动画仿真\n0. 返回上级菜单\n请输入您需要进行的操作序号：");
            scanf("%d",&flag);
            switch (flag) {
                case 1:
                    scanf("%s",UserFileName);
                    MovieSimulate();
                    break;
                case 0:
                    break;
                default:
                    break;
            }
        case 3:
            printf("您当前处于“全面仿真”模块，请选择要进行的操作：\n1. 输入用户指令文件名称，开始全面仿真\n0. 返回上级菜单\n请输入您需要进行的操作序号：\n");
            scanf("%d",&flag);
            switch (flag) {
                case 1:
                    scanf("%s",UserFileName);
                    FullSimulate();
                    break;
                case 0:
                    break;
                default:
                    break;
            }
        case 4:
            printf("您当前处于“历史仿真文件回放”模块，请选择要进行的操作：\n1. 输入历史仿真文件名称，开始仿真回放\n0. 返回上级菜单\n请输入您需要进行的操作序号：\n");
            scanf("%d",&flag);
            switch (flag) {
                case 1:
                    scanf("%s",UserFileName);
                    HistorySimulate();
                    break;
                case 0:
                    break;
                default:
                    break;
            }
        case 5:
            printf("您当前处于“系统参数配置”模块，请选择要配置的参数：\n1. 配置用户指令文件存放目录\n2. 配置历史仿真文件存放目录\n3. 配置电梯总层数\n4. 配置电梯动画仿真时的延迟系数\n0. 返回上级菜单\n请输入您需要重新配置的参数序号：");
            scanf("%d",&flag);
            switch (flag) {
                case 1:
                    printf("waiting for coding...");
                    break;
                    
                default:
                    break;
            }
        default:
            printf("Fuck!\n");
            break;
    }
    //}
}

