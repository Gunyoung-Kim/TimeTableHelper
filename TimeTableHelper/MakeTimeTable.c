//
//  MakeTimeTable.c
//  TimeTableHelper
//
//  Created by 김건영 on 2020/04/06.
//  Copyright © 2020 김건영. All rights reserved.
//

#include <time.h>
#include "common.h"
#include "MakeTimeTable.h"
#include "WishList.h"
#include "CreditManager.h"
#include "ClassInfo.h"
#include "TimeTable.h"
#include "PrintThings.h"

#define RANDOM_REPEAT_MIN 20
#define RECOMMEND_TIME 4

int * MakeRandomArr(int length,int rtime)
{
    int * arr = (int *)malloc(sizeof(int)*length);
    srand((unsigned int)time(NULL)*rtime);
    int temp,num1,num2;
    int repeat_time;
    
    repeat_time = rand()%RANDOM_REPEAT_MIN + RANDOM_REPEAT_MIN;
    
    for(int i=0;i<length;i++)
        arr[i] = i;

    for(int i=0;i<repeat_time;i++) {
        num1 = rand()%length;
        while(1) {
            num2 = rand()%length;
            if(num2 != num1)
                break;
        }
        
        temp = arr[num1];
        arr[num1] = arr[num2];
        arr[num2] = temp;
    }
    return arr;
}

/* 배열의 순서를 막 섞은다음에 순서대로 쫙 뽑아서 배치한다 */
void MakeTimeTableRandomly(void)
{
    classInfo ** wishlist = GetWishList();
    int list_length = GetWishListNum();
    int * arr;
    int i,isclear,rcase;
    
    for(rcase=0;rcase<RECOMMEND_TIME;rcase++) {
        arr= MakeRandomArr(list_length,rcase);
        printf("\n\n            (( CASE %d ))         \n",rcase+1);
        for(i=0;i<list_length;i++) {
            if(IsCreditProper(wishlist[arr[i]]->class_credit)== -1)
                break;
            isclear = FillTimeTable(wishlist[arr[i]]);
            if(isclear ==1) {
                CreditIncrement(wishlist[arr[i]]->class_credit);
                ShowClassInfo(wishlist[arr[i]]);
            }
        }
        InitCredit();
        InitTimeTable();
        free(arr);
    }
}
