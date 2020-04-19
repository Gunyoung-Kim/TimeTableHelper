//
//  ClassInfo.c
//  TimeTableHelper
//
//  Created by 김건영 on 2020/04/03.
//  Copyright © 2020 김건영. All rights reserved.
//

#include "common.h"
#include "ClassInfo.h"

#define FILE_NAME "classInfo.dat"

/* 존재하는 수업이면 1 반환 없는 수업이면 0 반환*/
int IsThereClass(char * classname,classInfo ** dp_class)
{
    FILE * fp = fopen(FILE_NAME,"r");
    char name[NAME_LEN];
    int credit,numoftime;
    classInfo * ptr;
    timeInfo time[5];
    
    while(1) {
        fread(name, sizeof(char), NAME_LEN, fp);
        if(feof(fp)) {
            break;
        }
        
        fread(&credit, sizeof(int), 1, fp);
        fread(&numoftime,sizeof(int),1,fp);
        for(int i=0;i<numoftime;i++) {
            fread(&(time[i].day), sizeof(int), 1, fp);
            fread(&(time[i].starttime), sizeof(int), 1, fp);
            fread(&(time[i].endtime),sizeof(int),1,fp);
        }
        
        if(!strcmp(classname, name)) {                                  //존재하는 수업이면 포인터에 복사?
            ptr = (classInfo *)malloc(sizeof(classInfo));
            ptr->class_credit = credit;
            strcpy(ptr->class_name, name);
            ptr->numoftime = numoftime;
            for(int i=0;i<numoftime;i++) {
                ptr->classtime[i].day = time[i].day;
                ptr->classtime[i].starttime = time[i].starttime;
                ptr->classtime[i].endtime = time[i].endtime;
            }
            *dp_class = ptr;
            fclose(fp);
            return 1;
        }
    }
    
    fclose(fp);
    return 0;
}

void StoreClassInfo(void)
{
    FILE * fp = fopen(FILE_NAME, "w");
    int sel;
    classInfo class;
    
    while(1) {
        printf("수업 이름 입력: ");
        gets(class.class_name);
        fflush(stdin);
        
        printf("이수 학점 입력: ");
        scanf("%d",&(class.class_credit));
        fflush(stdin);
        
        printf("주 수업횟수 입력: ");
        scanf("%d",&(class.numoftime));
        fflush(stdin);
        
        for(int i=0;i<class.numoftime;i++) {
            printf("수업 시간대 입력(요일 시작교시 종료교시): ");         //아직은 요일 입력시 숫자를 요구-> 나중에 고쳐야될 부분입니다.
            scanf("%d %d %d",&(class.classtime[i].day),&(class.classtime[i].starttime),&(class.classtime[i].endtime));
        }
        
        /* 이제 여기에 파일에 데이터 입력하는 부분 넣어야됨*/
        fwrite(class.class_name, sizeof(char), sizeof(class.class_name), fp);
        fwrite(&(class.class_credit), sizeof(int), 1, fp);
        fwrite(&(class.numoftime), sizeof(int), 1, fp);
        
        for(int i=0;i<class.numoftime;i++) {
            fwrite(&(class.classtime[i].day), sizeof(int), 1, fp);
            fwrite(&(class.classtime[i].starttime), sizeof(int), 1, fp);
            fwrite(&(class.classtime[i].endtime), sizeof(int), 1, fp);
        }
        
        fputs("계속 입력하시갰습니까?(Yes 1, No 0)", stdout);
        scanf("%d",&sel);
        fflush(stdin);
        if(sel == 0)
            break;
    }
    
    fclose(fp);
}
