#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include "library.h"
int main()
{



    nodec *customer=(nodec *)malloc(sizeof(nodec));
    customer->nextCusPtr = NULL;

    nodeP *product=(nodeP *)malloc(sizeof(nodeP));
    product->nextProPtr = NULL;

    nodep *purchased=(nodep *)malloc(sizeof(nodep));
    purchased->nextPurPtr = NULL;


    shipp *shipping=(shipp *)malloc(sizeof(shipp));
    shipping->nextShpPtr = NULL;

    nodec customer_info[5] =
    {
    {1, "Ali Karaman",  1, 16.8, 10},
    {2,    "Zehra Cilek",  0, 12.4, 6.9},
    {3,    "Mehmet Derin",    0, 10.55, 15.4},
    {4,    "Veli Ortanca",    1, 5.1,    1.2},
    {5,    "Menekse Serin",1,    2, 7.9}
    };

    nodeP product_info[7] =
    {
    {1,"Portakal",1, 5.99},
    {2,"Muz",1, 12.95},
    {3,"Sogan",2, 7.45},
    {4,"Pirasa",2, 3.95},
    {5,"Lahana",2, 5.95},
    {6,"Limon",1, 7.45},
    {7,"Hamsi",3, 15}
    };

    purchased->Id=1;
    purchased->invoice_id=1;
    purchased->customer_id=1;
    purchased->product_id=7;
    purchased->piece=7;
    purchased->type=3;
    purchased->cost=105;


    shipping->invoice=1;
    shipping->customer_id=1;
    shipping->fee=15;

    set_CustomerInfo(customer, customer_info);
    set_ProductInfo(product, product_info);

    Main_Menu(customer,purchased,product,shipping);





}

