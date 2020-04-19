//
//  ClassInfo.h
//  TimeTableHelper
//
//  Created by 김건영 on 2020/04/03.
//  Copyright © 2020 김건영. All rights reserved.
//

#ifndef ClassInfo_h
#define ClassInfo_h

#include "common.h"

#define NAME_LEN 50

enum{Mon=1,TUE,WED,THU,FRI};

typedef struct _timeinfo
{
    int day;
    int starttime;
    int endtime;
}timeInfo;

typedef struct _classinfo
{
    char class_name[NAME_LEN];
    int class_credit;
    timeInfo classtime[5];
    int numoftime;
}classInfo;

int IsThereClass(char * classname,classInfo ** dp_class);
void StoreClassInfo(void);

#endif /* ClassInfo_h */
