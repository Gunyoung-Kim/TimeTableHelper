//
//  TimeTable.c
//  TimeTableHelper
//
//  Created by 김건영 on 2020/04/03.
//  Copyright © 2020 김건영. All rights reserved.
//

#include "common.h"
#include "TimeTable.h"
#include "ClassInfo.h"

static int timetable[15][5] ={EMPTY,};

/* 시간표에 수업 들어가면 1 반환 안들어가지면 -1 반환 */
int FillTimeTable(classInfo * class)
{
    int i;
    
    for(i=0;i<class->numoftime;i++) {
        for(int j=class->classtime[i].starttime;j<=class->classtime[i].endtime;j++) {
            if(timetable[j-1][class->classtime[i].day-1] == FILLED)
                return -1;
        }
    }
    
    for(i=0;i<class->numoftime;i++) {
        for(int j=class->classtime[i].starttime;j<=class->classtime[i].endtime;j++)
            timetable[j-1][class->classtime[i].day-1] = FILLED;
    }
    
    return 1;
}

void InitTimeTable(void)
{
    int i,j;
    
    for(i=0;i<15;i++) {
        for(j=0;j<5;j++) {
            timetable[i][j] = EMPTY;
        }
    }
}
