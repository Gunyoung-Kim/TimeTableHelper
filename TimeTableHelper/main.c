//
//  main.c
//  TimeTableHelper
//
//  Created by 김건영 on 2020/04/03.
//  Copyright © 2020 김건영. All rights reserved.
//

#include "common.h"
#include "CreditManager.h"
#include "ClassInfo.h"
#include "PrintThings.h"
#include "WishList.h"
#include "MakeTimeTable.h"

#define MAX_CLASS_LEN 50

enum {MAkE_TIMETABLE=1,ENTER_CLASS};

int main(void)
{
    int maxc,minc;
    int selection;
    int wayofmaking;
    char wishclass[MAX_CLASS_LEN];
    classInfo * p_class;
    
    ShowMenu();
    scanf("%d",&selection);
    fflush(stdin);
    
    switch(selection) {
        case MAkE_TIMETABLE:
            /* 사용자가 줘야되는 정보들 받는 과정 */
            fputs("최소, 최대 이수학점: ", stdout);
            scanf("%d %d",&minc,&maxc);
            fflush(stdin);
            TakeMaxMinCredit(minc, maxc);          //최소 및 최대 이수학점
            
            while(1) {
                fputs("듣고 싶은 과목 입력: ", stdout);
                gets(wishclass);
                if(IsThereClass(wishclass,&p_class)) {
                    AddWishList(p_class);
                }
                else {
                    puts("해당 수업은 존재하지 않습니다...");
                }
                fputs("계속 하시겠습니까?(Yes 1 No 0) ", stdout);
                while(1) {
                    scanf("%d",&selection);
                    fflush(stdin);
                    if(selection == 1 || selection == 0)
                        break;
                }
                if(selection == 0)
                    break;
            }
            
            ShowWayOfMakingSelection();
            scanf("%d",&wayofmaking);
            fflush(stdin);
            switch(wayofmaking) {
                case 1:
                    MakeTimeTableRandomly();
                    break;
                default:
                    break;
            }
            
            break;
        case ENTER_CLASS:
            StoreClassInfo();
            break;
        default:
            break;
    }
    
    return 0;
}
