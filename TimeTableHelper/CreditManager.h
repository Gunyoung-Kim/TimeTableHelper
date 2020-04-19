//
//  CreditManager.h
//  TimeTableHelper
//
//  Created by 김건영 on 2020/04/03.
//  Copyright © 2020 김건영. All rights reserved.
//

#ifndef CreditManager_h
#define CreditManager_h

int GetCredit(void);
void TakeMaxMinCredit(int min,int max);
void InitCredit(void);
void CreditIncrement(int add);
int IsCreditProper(int add);

#endif /* CreditManager_h */
