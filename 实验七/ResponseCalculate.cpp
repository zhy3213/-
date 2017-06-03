//
//  ResponseCalculate.cpp
//  实验七
//
//  Created by 吴芳谷 on 2017/5/16.
//  Copyright © 2017年 Zhy. All rights reserved.
//

#include "ResponseCalculate.hpp"
void  SilenceSimulate(){
    char temp[512];
    FILE *fp;
    bool flag=1;
    while (1) {
        scanf("%s",temp);
        if (strcmp(temp, "*")!=0) {
            strcpy(UserFileName, temp);
        }
        if (access(UserFileName, F_OK)!=0) {
            continue;
        }
        InitSimulation();
        fp=fopen(UserFileName, "r");
        if (fp==NULL) {
            continue;
        }
        if(!LoadUserCallArray(fp)){
            continue;
        }
        if (OutputSimulationResult()) {
            continue;
        }
        break;
    }
    
    
}

void InitSimulation(){
    RESPONSELISTNODE *p;
    if (UserCallList!=NULL) {
        free(UserCallList);
        UserCallList=NULL;
    }
    UserCallListLen=0;
    FinishCallNum=0;
    if (ResponseList!=NULL) {
        while (ResponseList->head!=NULL) {
            p=ResponseList->head;
            ResponseList->head=ResponseList->head->next_node;
            free(p);
            p=NULL;
        }
    }
    else{
        ResponseList=(RESPONSELISTHEADNODE*)malloc(sizeof(RESPONSELISTHEADNODE));
    }
    ResponseList->head=NULL;
    ResponseList->tail=NULL;
    ResponseList->list_num=0;
    InitElevator(&ElevatorA);
    InitElevator(&ElevatorB);
}

void InitElevator(ELEVATORSTATE   *elevator){
    elevator->current_floor=1;
    elevator->run_state='S';
    SERVELISTNODE *p;
    while (elevator->serve_list!=NULL) {
        p=elevator->serve_list;
        if (elevator->serve_list->next_node!=NULL) {
            elevator->serve_list=elevator->serve_list->next_node;
        }
        else{
            elevator->serve_list=NULL;
        }
        free(p);
    }
}

int LoadUserCallArray(FILE  *fp) {
    fscanf(fp, "%d",&UserCallListLen);
    int ItemNum=0;
    UserCallList=(USERCALL*)malloc(UserCallListLen*sizeof(USERCALL));
    while (fscanf(fp, "%d,%d,%d",&UserCallList[ItemNum].call_time,&UserCallList[ItemNum].user_floor,&UserCallList[ItemNum].user_target)!=EOF) {
        if (UserCallList[ItemNum].user_floor<UserCallList[ItemNum].user_target) {
            UserCallList[ItemNum].call_type='U';
        }
        else if(UserCallList[ItemNum].user_floor>UserCallList[ItemNum].user_target){
            UserCallList[ItemNum].call_type='D';
        }
        else{
            UserCallList[ItemNum].call_type='H';
        }
        ItemNum++;
    }
    if (ItemNum==UserCallListLen) {
        return 1;
    }
    return 0;
}

void  FindUserCallCanServe(ELEVATORSTATE  *elevator , char r_state) {
    int uf=elevator->serve_list->user_call->user_floor;
    char us=elevator->serve_list->user_call->call_type,ue=elevator->run_state,s;
    bool flag=0;
    if (ResponseList->head==NULL) {
        return;
    }
    RESPONSELISTNODE *r,*k,*p=ResponseList->head;
    SERVELISTNODE *q;
    r=p;
    k=p;
    int m=elevator->current_floor,i,f,t;
    do {
        i=p->usercall_index;
        f=UserCallList[i].user_floor;
        t=UserCallList[i].user_target;
        s=UserCallList[i].call_type;
        if (us==r_state) {
            if ((r_state=='U'&&s=='U'&&f>m)||(r_state=='d'&&s=='D'&&f<m)) {
                flag=1;
            }
        }
        else{
            if ((r_state=='U'&&s=='U'&&f>=m&&t<=uf)||(r_state=='D'&&s=='D'&&f<=m&&t<=uf)||(ue=='S'&&f==m&&r_state=='U'&&t<=uf)||(ue=='S'&&f==m&&r_state=='D'&&t>=uf)) {
                flag=1;
            }
        }
        if (flag) {
            q=(SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
            q->user_call=UserCallList+i;
            q->next_node=NULL;
            if (f==m) {
                q->serve_state='E';
            }
            else{
                q->serve_state='P';
            }
            elevator->serve_list->next_node=q;
            
        }
    } while (p!=NULL);
}
