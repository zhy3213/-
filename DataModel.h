//
//  DataModel.h
//  实验七
//
//  Created by 吴芳谷 on 2017/5/9.
//  Copyright © 2017年 Zhy. All rights reserved.
//
#pragma once
#ifndef DataModel_h
#define DataModel_h
#define MAX_PARAM_VALUE_LEN 200
#define MAX_PARAM_NAME_LEN 200
typedef  struct  UserCall{
    int  user_floor ;     	//用户所在楼层
    int  user_target ;     //用户目标楼层
    int  call_time ;         //用户请求时刻
    char  call_type ;       //用户指令类型，´U´表示上行指令，´D´表示下行指令
}USERCALL;

typedef  struct  SysParam{
    char  param_name[MAX_PARAM_NAME_LEN] ;     	//参数名
    char  param_value[MAX_PARAM_VALUE_LEN] ;     //参数值
}SYSPARAM;

typedef  struct  ServeListNode{
    char  serve_state ;       //电梯服务状态
    USERCALL  *user_call ;//电梯当前响应用户指令时，指向指令数组的某一个元素
    struct ServeListNode  *next_node ;//存储下一个结点的地址
}SERVELISTNODE;

typedef  struct  elevatorstate{
    int  current_floor ;     	//电梯当前所处楼层
    char  run_state ;          //电梯运行状态
    SERVELISTNODE  *serve_list ;//电梯响应的用户指令队列
}ELEVATORSTATE;

typedef  struct  ResponseListNode{
    int  usercall_index;       //用户指令在指令数组中对应的序号
    struct  ResponseListNode  *next_node;//存储下一个结点的地址
}RESPONSELISTNODE;

typedef  struct  ResponseListHeadNode{
    int  list_num ;       //待响应用户指令链表中数据结点的个数
    RESPONSELISTNODE  *head ;//链表中第一个数据结点的指针
    RESPONSELISTNODE  *tail ;//链表中最后一个数据结点的指针
}RESPONSELISTHEADNODE;

extern USERCALL *UserCallList;
extern int UserCallListLen;
extern SYSPARAM ParamArray[200];
extern ELEVATORSTATE ElevatorA;
extern ELEVATORSTATE ElevatorB;
extern RESPONSELISTHEADNODE *ResponseList;
extern char UserFileName[512];
extern int FinishCallNum;
extern int time;
extern int StatusChangeFlag;

#endif /* DataModel_h */
