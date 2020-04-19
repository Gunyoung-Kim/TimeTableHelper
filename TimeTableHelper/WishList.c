//
//  WishList.c
//  TimeTableHelper
//
//  Created by 김건영 on 2020/04/05.
//  Copyright © 2020 김건영. All rights reserved.
//

#include "WishList.h"
#include "ClassInfo.h"

#define MAX_LIST_NUM 10

static classInfo * wishlist[MAX_LIST_NUM];
static int wishlistnum =0;

void AddWishList(classInfo * p_class)
{
    wishlist[wishlistnum++] = p_class;
}

classInfo** GetWishList(void)
{
    return wishlist;
}

int GetWishListNum(void)
{
    return wishlistnum;
}
