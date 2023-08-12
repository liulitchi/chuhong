/******************************************************************************
 * Copyright (C) 2023 Nymph <Academy of Artemis>
 * Copyright (C) 2023 liulitchi <kz-xy@163.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 *
 * Ακαδημία της Αρτέμιδος(Academy of Artemis) is a loosely connected 
 * network of math learning group, whose members share a common interest 
 * in mathematics and statistics and often exchange their learning 
 * experiences with one another.
 *  
 * main.c 
 * Last edited: 2023/8/12
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "book.h"

int cmpfunc (const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {

    int value = 0;
    srand((unsigned)time(NULL));


    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    int die3 = rand() % 6 + 1;
    int die4 = rand() % 6 + 1;
    printf("骰子： %d %d %d %d\n", die1, die2, die3, die4); // 显示盘面点
    int display[4] = {die1, die2, die3, die4}; 
    
    // 最小化排序
    qsort(display, 4, sizeof(int), cmpfunc); 

    // 
    value = 1000 * display[0] + 100 * display[1] + 10 * display[2] + display[3];
    
  /*printf("value = %d\n", value);
    printf("display[0] = %d\n", display[0]);
    printf("display[1] = %d\n", display[1]);
    printf("display[2] = %d\n", display[2]);
    printf("display[3] = %d\n", display[3]); */
    int meet = 0; // 判断盘面点是否属于六十二谱
    for (int i = 0; i < sizeof(points) / sizeof(points[0]); i++) {
        
        if (points[i] == value) {
            meet = 1; 
            printf("名称： %s\n", name[i]);            
            printf("雅名： %s\n", alias[i]);
            printf("归类： %s\n", category[i]);            
            //printf("赏罚： %s\n", reward[i]);
            return 0;
        }
    }
    
    if (meet == 0) {
        puts("无赏罚色，请重新掷骰子！");
        return 0;
    }    
 
    return 0;
}
