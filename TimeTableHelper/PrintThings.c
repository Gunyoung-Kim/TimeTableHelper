//
//  PrintThings.c
//  TimeTableHelper
//
//  Created by 김건영 on 2020/04/05.
//  Copyright © 2020 김건영. All rights reserved.
//

#include "common.h"
#include "ClassInfo.h"

void ShowMenu(void)
{
    system("clear");
    
    printf("--------- MENU -------------- \n");
    printf("1. 시간표짜기 \n");
    printf("2. 수업 입력하기 \n");
    printf("선택>> ");
}

void ShowWayOfMakingSelection(void)
{
    printf("-------- How To Make ----------- \n");
    printf("1. Random \n");
    printf("선택>> ");
}

void ShowClassInfo(classInfo * class)
{
    printf("-------------------------------------\n");
    printf("과목명: %s, %d학점 \n",class->class_name,class->class_credit);
    for(int i=0;i<class->numoftime;i++) {
        switch(class->classtime[i].day) {
            case Mon:
                printf("Mon ");
                break;
            case TUE:
                printf("TUE ");
                break;
            case WED:
                printf("WED ");
                break;
            case THU:
                printf("THU ");
                break;
            case FRI:
                printf("FRI ");
                break;
            default:
                break;
        }
        printf("%d ~ %d 교시 \n",class->classtime[i].starttime,class->classtime[i].endtime);
    }
    printf("-------------------------------------\n");
}


