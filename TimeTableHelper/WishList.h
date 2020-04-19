//
//  WishList.h
//  TimeTableHelper
//
//  Created by 김건영 on 2020/04/05.
//  Copyright © 2020 김건영. All rights reserved.
//

#ifndef WishList_h
#define WishList_h

#include "ClassInfo.h"

void AddWishList(classInfo * p_class);
classInfo ** GetWishList(void);
int GetWishListNum(void);

#endif /* WishList_h */
