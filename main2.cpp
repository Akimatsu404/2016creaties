//
//  main2.cpp
//  hanoi
//
//  Created by 土肥　佑綺 on 2016/06/03.
//  Copyright © 2016年 土肥　佑綺. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <list>

struct iList
{
    std::string name;
    std::list<int> data;
};

int N;
iList A, B, C;

void hanoi(int n, iList *from, iList *work, iList* dest);
void move(int n, iList* from, iList* dest);
void print(iList *data);

int main()
{

    N = 3;
    int i;
    for(i = N; i > 0; --i)
    {
        A.data.push_back(i);
    }
    
    A.name = "A";
    B.name = "B";
    C.name = "C";
    
    hanoi(N, &A, &B, &C);
    
    print(&A);
    print(&B);
    print(&C);
    return 0;
}

void hanoi(int n, iList *from, iList *work, iList* dest)
{
    
    if(n>1){hanoi(n-1, from, dest, work);}
    print(&A);
    print(&B);
    print(&C);
    printf("\n");
    move(n, from, dest);

    if(n>1){hanoi(n-1, work, from, dest);}
    
}

void move(int n, iList* from, iList* dest)
{

    int fromSize = from->data.size();
    
    std::list<int>::iterator itr = from->data.end();
    itr--;
    
    auto i = (*itr);
    
    dest->data.push_back((*itr));
    from->data.pop_back();
    
}

void print(iList *data)
{
    printf("%s : ", data->name.c_str());
    int size = data->data.size();
    std::list<int>::iterator itr = data->data.begin();
    
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", (*itr));
        itr++;
    }
    printf("\n");
    
}


/*
 N = 2
 
 1.AからB
 2.AからC
 3.BからC
 

 */

