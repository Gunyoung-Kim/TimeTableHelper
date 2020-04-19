//
//  CreditManager.c
//  TimeTableHelper
//
//  Created by 김건영 on 2020/04/03.
//  Copyright © 2020 김건영. All rights reserved.
//

#include "CreditManager.h"

static int credit=0;   // 이건 굳이 필요 없을거 같은데?
static int min_credit;
static int max_credit;

void TakeMaxMinCredit(int min,int max)
{
    min_credit = min;
    max_credit = max;
}

int GetCredit(void)
{
    return credit;
}

void InitCredit(void)
{
    credit = 0;
}

void CreditIncrement(int add)
{
    credit +=add;
}

/* 더이상 안되면 -1 반환 괜찮으면 1 반환 */
int IsCreditProper(int add)
{
    if(max_credit < credit + add)
        return -1;
    else
        return 1;
}
