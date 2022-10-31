#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include "library.h"




void set_CustomerInfo(nodec *r, nodec *customer_info)
{

    int i=1;

    r->Id=customer_info[0].Id;
    strcpy(r->name,customer_info[0].name);
    r->type=customer_info[0].type;
    r->x_coord=customer_info[0].x_coord;
    r->y_coord=customer_info[0].y_coord;

        nodec *temp = (nodec *)malloc(sizeof(nodec));

        nodec *ptr;
        nodec *mptr;


        mptr=temp;
        ptr=temp;


        while(i<5)

        {
            temp->Id=customer_info[i].Id;
            strcpy(temp->name,customer_info[i].name);
            temp->type=customer_info[i].type;
            temp->x_coord=customer_info[i].x_coord;
            temp->y_coord=customer_info[i].y_coord;

            temp=malloc(sizeof(nodec));

            ptr->nextCusPtr = temp;
            ptr=ptr->nextCusPtr;
            i++;
        }
        ptr->nextCusPtr = NULL;

        r->nextCusPtr = mptr;

}






void set_ProductInfo(nodeP *r, nodeP *product_info){

    int i=1;

    r->Id=product_info[0].Id;
    strcpy(r->name,product_info[0].name);
    r->type=product_info[0].type;
    r->price=product_info[0].price;


        nodeP *temp = (nodeP *)malloc(sizeof(nodeP));

        nodeP *ptr;
        nodeP *mptr;

        mptr=temp;
        ptr=temp;


        while(i<7)
        {
            temp->Id=product_info[i].Id;
            strcpy(temp->name,product_info[i].name);
            temp->type=product_info[i].type;
            temp->price=product_info[i].price;
            temp->nextProPtr=NULL;
            temp=malloc(sizeof(nodeP));
            ptr->nextProPtr = temp;
            ptr=ptr->nextProPtr;
            i++;
        }

        ptr->nextProPtr = NULL;

        r->nextProPtr = mptr;

}








void set_customer(nodec* c)
{

    nodec *iter;
    iter=c;

    system("color 11");
    while(iter->nextCusPtr != NULL)
    {
     iter=iter->nextCusPtr;
    }
    iter->nextCusPtr=(nodec*)malloc(sizeof(nodec));
   printf("\t\n\n Enter Customer Info: \n");
   printf("\t\n 1.Id: ");
   scanf("%d",&iter->nextCusPtr->Id);
   printf("\t\n 2.Name: ");
   scanf("%s",iter->nextCusPtr->name);
   printf("\t\n 3.Type: ");
   scanf("%d",&iter->nextCusPtr->type);
   printf("\t\n 4.X_Coord: ");
   scanf("%lf",&iter->nextCusPtr->x_coord);
   printf("\t\n 5.Y_Coord: ");
   scanf("%lf",&iter->nextCusPtr->y_coord);
   iter->nextCusPtr->nextCusPtr=NULL;
}


void print_customerall(nodec* c)
{
    system("cls");
    system("color 13");
    nodec* iter;
    iter=c;

    while(iter!=NULL)
    {
        printf("\t\n Id:%d   Name:%s   Type:%u   X_Coord:% lf    Y_Coord%lf \n",iter->Id,iter->name,iter->type,iter->x_coord,iter->y_coord);
        iter=iter->nextCusPtr;
    }
}

void set_purchased(nodep* p,double cost,int id_item,int id_user,int invoice,int piece,int type,int id)
{

    nodep* iter;
    iter=p;

    while(iter->nextPurPtr!=NULL)
    {
        iter=iter->nextPurPtr;
    }

    iter->nextPurPtr=(nodep*)malloc(sizeof(nodep));

    iter->nextPurPtr->Id=id;
    iter->nextPurPtr->product_id=id_item;
    iter->nextPurPtr->customer_id=id_user;
    iter->nextPurPtr->invoice_id=invoice;
    iter->nextPurPtr->cost=cost;
    iter->nextPurPtr->piece=piece;
    iter->nextPurPtr->type=type;


    iter->nextPurPtr->nextPurPtr=NULL;

}

void set_ship(shipp* s,int invoice,double fee,int id)
{

        shipp* iter;
        iter=s;

        while(iter->nextShpPtr!=NULL)
        {
            iter=iter->nextShpPtr;
        }

        iter->nextShpPtr=(shipp*)malloc(sizeof(shipp));
        iter->nextShpPtr->invoice=invoice;
        iter->nextShpPtr->fee=fee;
        iter->nextShpPtr->customer_id=id;
        iter->nextShpPtr->nextShpPtr=NULL;
}



void set_product(nodeP* p)
{
    system("cls");
    system("color 13");

    nodeP* iter;
    iter=p;

    while(iter->nextProPtr != NULL)
    {
        iter=iter->nextProPtr;
    }
    iter->nextProPtr=(nodeP*)malloc(sizeof(nodeP));
    printf("\t\n\n Enter Product Info: \n");
    printf("\t\n 1.Id: ");
    scanf("%d",&iter->nextProPtr->Id);
    printf("\t\n 2.Name: ");
    scanf("%s",iter->nextProPtr->name);
    printf("\t\n 3.Type: ");
    scanf("%d",&iter->nextProPtr->type);
    printf("\t\n 4.Price: ");
    scanf("%lf",&iter->nextProPtr->price);
    iter->nextProPtr->nextProPtr=NULL;

}

void print_productall(nodeP* p)
{

    system("color 4");

    nodeP* iter;
    iter=p;

    while(iter!=NULL)
    {
        printf("\t\n Id:%d  Name:%s  Type:%u  Price:%lf \n",iter->Id,iter->name,iter->type,iter->price);
        iter=iter->nextProPtr;


    }

}



void Main_Menu(nodec* c,nodep* p,nodeP *P,shipp* s){

    system("cls");
    system("color 5");
    int option,ch;
    k:
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME Hanabi \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\t\n\n 1.Sale: \n");
    printf("\t\n 2.Customer Info: \n");
    printf("\t\n 3.Product Info: \n");
    puts("\t\n 4.Customer Analysis: ");
    puts("\t\n 5.Product Analysis: ");
    puts("\t\n\n Choose Menu ");
    scanf("%d",&option);

    if(option==1){
        sale_menu(c,p,P,s);

    }
    else if(option==2){

        customerinfo_menu(c,p,P,s);
    }
    else if(option==3){

        productinfo_menu(P,c,p,s);
    }
    else if(option==4){

        customer_analyses(c,p,P,s);
    }
    else if(option==5){

        product_analyses(c,p,P,s);

    }
    else{
        system("cls");
        system("color 4");

        puts("\t\n\nTHERE IS NO SUCH MENU!!!???");
        puts("\t\n 1:Go Back \t\n 2:Exit  ");
        scanf("%d",&ch);

        if(ch==1){
            goto k;
        }
        else if(ch==2){
            exit(0);
        }

    }


}

void sale_menu(nodec* c,nodep* p,nodeP* P,shipp* s)
{
    system("cls");
    system("color 4");

    int id,x=0;


    puts("\t\t\n\n\n\n Welcome Sale Menu \n");
    puts("\t\n\n Please Login ");
    printf("Enter Your Ýd: ");
    scanf("%d",&id);

    nodec* iter;
    iter=c;

    while(iter!=NULL)
    {
        if(iter->Id==id)
        {
            x=1;

        }
        iter=iter->nextCusPtr;

    }

    if(x==1)
    {
        last_bill(p,id);
        sale_interface(c,P,p,s,id);
    }
    else if(x==0)
    {
        printf("\t\n There is no such user!!!");
        printf("\t\n Please Sign Up");
        set_customer(c);
    }


}

void last_bill(nodep* p,int id)
{
    system("color 4");
    int last=0;

    nodep* iter;
    iter=p;

        while(iter!=NULL)
        {
            if(id==iter->Id)
            {
                if(iter->invoice_id>last)
                {
                    last=iter->invoice_id;
                    iter=iter->nextPurPtr;
                }
            }
            else
            {
                iter=iter->nextPurPtr;
            }
        }

        iter=p;

        printf("\n LAST BILL!!!!!");

        while(iter!=NULL)
        {
            if(iter->invoice_id==last)
            {
                printf("\t\n\n Id:%d  invoice id:%d  customer id:%d  product id:%d  cost:%lf \n",iter->Id,iter->invoice_id,iter->customer_id,iter->product_id,iter->cost);
                iter=iter->nextPurPtr;

            }
            else
            {
                iter=iter->nextPurPtr;
            }
        }



}

void sale_interface(nodec* c,nodeP* p,nodep* n,shipp* s,int id)
{

    system("color 4");
    puts("\t\n\n Products: ");

    int choice,piece;
    int invoice,ch,e;
    double cost,ship,total;
    nodeP* iter;
    iter=p;
    nodep* iter1;
    iter1=n;
    int type;
    int pr_id;

    print_productall(p);
    get_invoice(n);
    invoice=get_invoice(n);

    k:

    printf("\t\n Enter the id of the product you want to buy: ");
    scanf("%d",&choice);
    printf("\t\n Enter how much you want to buy: ");
    scanf("%d",&piece);

    while(iter->nextProPtr!=NULL)
    {
       if(iter->Id==choice)
       {
           cost=(iter->price*piece);
           type=iter->type;
           iter=iter->nextProPtr;
       }
       else{
           iter=iter->nextProPtr;
       }
    }



    while(iter1->nextPurPtr!=NULL)
    {
        if(iter1->nextPurPtr==NULL)
        {
            break;
        }
        else{
            iter1=iter1->nextPurPtr;
        }

    }
    pr_id=iter1->Id+1;

    set_purchased(n,cost,choice,id,invoice,piece,type,pr_id);




    puts("\t\n 1.Continue \n 2.End");
    scanf("%d",&ch);


    if(ch==1)
    {
        goto k;
    }
    else if(ch==2)
    {
        ship=shippingx(c,id);
        total=total_cost(n,invoice,ship);
        get_bill(n,c,p,s,invoice,total,ship,choice);
        set_ship(s,invoice,ship,id);

        printf("\t\n Press 0 for exit: ");
        scanf("%d",&e);
        if(e==0){
            exit(0);
        }
    }
}

int get_invoice(nodep* p)
{
    int invoice;
    nodep* iter;
    iter=p;


    while(iter->nextPurPtr!=NULL)
    {
        iter->nextPurPtr;
    }
    invoice=iter->invoice_id+1;

    return invoice;
}

double shippingx(nodec* c,int id)
{
    //5 dolar per 100km
    double shipping,distance,p;
    nodec* iter;
    iter=c;
    while(iter!=NULL)
    {
        if(iter->Id==id)
        {
            break;
        }
        else {
            iter = iter->nextCusPtr;
        }
    }

    distance=pow(c->x_coord,2)+pow(c->y_coord,2);
    distance=sqrt(distance);
    p=distance/10;
    shipping=p*5;

    return shipping;

}

double total_cost(nodep* p,int invoice,double ship)
{
    double cost;
    nodep* iter;
    iter=p;
    while(iter!=NULL)
    {
        if(iter->invoice_id==invoice)
        {
            cost=cost+iter->cost;
            iter=iter->nextPurPtr;
        }
        else
        {
            iter=iter->nextPurPtr;
        }

    }

    cost=cost+ship;

    return cost;
}

void get_bill(nodep* p,nodec* c,nodeP* P,shipp* s,int invoice,double total,double ship,int choice)
{
    system("cls");
    system("color 4");

    nodep* iter;
    iter=p;

    while(iter!=NULL)
    {
        if(iter->invoice_id==invoice)
        {
            printf("\t\n\n Id:%d  invoice Id:%d  Customer_Id:%d  product_id:%d quantity:%d cost:%lf \n",iter->Id,iter->invoice_id,iter->customer_id,iter->product_id,iter->piece,iter->cost);
            iter=iter->nextPurPtr;
        }
        else
        {
            iter=iter->nextPurPtr;
        }
    }
    printf("\t\n\n Shipping Cost: %lf\n",ship);
    printf("\t Total Cost: %lf\n",total);

    printf("\t\n\n press 0 to main_menu");
    int a;
    scanf("%d",&a);
    if(a==0){
        Main_Menu(c,p,P,s);
    }

}

void customerinfo_menu(nodec* c,nodep* n,nodeP* p,shipp* s)
{

    system("cls");
    system("color 13");
    k:



    puts("\t\n\n\n\n\n\n\n\t Customer Info Menu\n");
    puts("\t\n 1.View All Customers");
    puts("\t\n 2.According to the Customer Type");
    puts("\t\n 3.Single Customer Info");
    printf("\t\n\n Choice: ");

    int x,id,t;
    nodec* iter;
    iter=c;

    scanf("%d", &x);

    if(x==1)
    {
        system("cls");
        system("color 11");
        print_customerall(c);
    }
    else if(x==2)
    {
        system("cls");
        system("color 11");

        puts("\t\n\n\n Choose Type\n");
        puts("\t\n 0.Business");
        puts("\t\n 1.Individual");
        printf("\t Choose: ");
        scanf("%d",&t);

        if(t==0)
        {
            system("cls");
            system("color 4");

            while(iter!=NULL){

                if(iter->type==0){
                    printf("\t\n Id:%d   Name:%s   Type:%u   X_Coord:% lf    Y_Coord%lf ",iter->Id,iter->name,iter->type,iter->x_coord,iter->y_coord);
                    iter=iter->nextCusPtr;
                }
                else{
                    iter=iter->nextCusPtr;
                }
            }
        }
        else if(t==1)
        {
            system("cls");
            system("color 4");

            while(iter!=NULL){

                if(iter->type==1){
                    printf("\t\n Id:%d   Name:%s   Type:%u   X_Coord:% lf    Y_Coord%lf ",iter->Id,iter->name,iter->type,iter->x_coord,iter->y_coord);
                    iter=iter->nextCusPtr;

                }
                else{
                    iter=iter->nextCusPtr;
                }
            }
        }
    }
    else if(x==3)
    {
        system("cls");
        system("color 4");

        puts("\t\n\n Enter a Customer Id:");
        scanf("%d",&id);

        while(iter!=NULL){
            if(iter->Id==id){
                printf("\t\n Id:%d   Name:%s   Type:%u   X_Coord:% lf    Y_Coord%lf ",iter->Id,iter->name,iter->type,iter->x_coord,iter->y_coord);
                iter=iter->nextCusPtr;
            }
            else{
                iter=iter->nextCusPtr;
            }
        }
    }
    else{
        puts("\n 1:Go Back! \n 2:Exit \n Main Menu \n");
        scanf("%d",&t);

        if(t==1){
            system("cls");
            goto k;
        }
        else if(t==2){
            exit(0);
        }
        else if(t==3){
            Main_Menu(c,n,p,s);
        }
    }
}

void productinfo_menu(nodeP* p,nodec* c,nodep* n,shipp* s)
{
    system("cls");
    system("color 5");

    k:
    puts("\t\t\n\n\n\n\n\n Product Info Menu \n");
    puts("\t\n 1.View All Products ");
    puts("\t\n 2.According to the Product Type ");
    puts("\t\n 3.ingle Product Info ");

    int ch,id,x;
    nodeP* iter;
    iter=p;

    printf("\t\n Choose: ");
    scanf("%d",&ch);

    if(ch==1)
    {
        system("cls");
        system("color 4");

        print_productall(p);
    }
    else if(ch==2)
    {
        system("cls");
        system("color 4");

        puts("\t\n\n 1.Fruit ");
        puts("\t\n 2.Vegetable ");
        puts("\t\n 3.Meat Products ");
        printf("\t\n Choose : ");
        scanf("%d",&x);

        if(x==1){
            while(iter!=NULL)
            {
                if(iter->type==1){
                    printf("\t\n Id:%d  Name:%s  Type:%u  Price:%lf \n",iter->Id,iter->name,iter->type,iter->price);
                    iter=iter->nextProPtr;
                }
                else{
                    iter=iter->nextProPtr;
                }
            }
        }
        else if(x==2)
        {
            while(iter!=NULL)
            {
                if(iter->type==2){
                    printf("\t\n Id:%d  Name:%s  Type:%u  Price:%lf \n",iter->Id,iter->name,iter->type,iter->price);
                    iter=iter->nextProPtr;
                }
                else{
                    iter=iter->nextProPtr;
                }
            }
        }
        else if(x==3)
        {
            while(iter!=NULL)
            {
                if(iter->type==3)
                {
                    printf("\t\n Id:%d  Name:%s  Type:%u  Price:%lf \n",iter->Id,iter->name,iter->type,iter->price);
                    iter=iter->nextProPtr;
                }
                else{
                    iter=iter->nextProPtr;
                }
            }
        }

    }
    else if(ch==3)
    {
        system("cls");
        system("color 4");

        printf("\t\n\n Enter a Product Id:");
        scanf("%d",&id);

        while(iter!=NULL)
        {
            if(iter->Id==id)
            {
                printf("\t\n Id:%d  Name:%s  Type:%u  Price:%lf \n",iter->Id,iter->name,iter->type,iter->price);
            }
            else
            {
                iter=iter->nextProPtr;
            }
        }

    }
    else{
        puts("\n 1.Go Back!! \n 2.Exit \n 3.Main Menu \n");
        scanf("%d",&x);

        if(x==1){
            goto k;
        }
        else if(x==2){
            exit(0);
        }
        else if(x==3){
            Main_Menu(c,n,p,s);
        }

    }
}

void customer_analyses(nodec* c,nodep* n,nodeP* p,shipp* s)
{
    k:
    system("cls");
    system("color 4");

    puts("\t\t\n\n\n\n Customer Analyses \n");
    puts("\t\n\n 1.Items purchased by a single specific user");
    puts("\t\n\n 2.Total amount of items purchased by a user");
    puts("\t\n\n 3.Total amount of products purchased by all customer");
    puts("\t\n\n 4.Users shipping fees\n");

    int ch,v;

    printf("\t Choice: ");
    scanf("%d",&ch);


    if(ch==1)
    {
        single_userinfo(c,n,p);
    }
    else if(ch==2)
    {
        ca_2(c,n,p);
    }
    else if(ch==3)
    {
        ca_3(c,n,p);
    }
    else if(ch==4)
    {
        ca_4(s);
    }
    else
    {
        printf("\t\n Invalid Option\n");
        printf("\n 1.Go Back!! \n 2.Exit\n 3.Main Menu\n");
        scanf("%d",&v);

        if(v==1)
        {
            goto k;
        }
        else if(v==2)
        {
            exit(0);
        }
        else if(v==3){
            Main_Menu(c,n,p,s);
        }
    }
}

void single_userinfo(nodec* c,nodep* n,nodeP* p)
{
    system("cls");
    system("color 11");

    int id;
    nodeP* iter2;
    iter2=p;
    nodep* iter;
    iter=n;

    print_customerall(c);


    printf("\t\n\n Enter Id:");
    scanf("%d",&id);

    while(iter->nextPurPtr!=NULL)
    {
        if(iter->customer_id==id)
        {
          while(iter2!=NULL)
          {
              if(iter->product_id==iter2->Id)
              {
                  printf("\t\n Id:%d  Name:%s",iter->Id,iter2->name);
                  iter2=iter2->nextProPtr;


              }
              else{
                  iter2=iter2->nextProPtr;
              }
          }

        }
        else{
            iter=iter->nextPurPtr;
        }
    }

    iter=n;
    int most=0,least=0,i=0;
    int items[15]={0};

    while(iter!=NULL)
    {
        if(iter->customer_id==id)
        {
            items[iter->product_id]=iter->piece+items[iter->product_id];
            iter=iter->nextPurPtr;
        }
        else
        {
            iter=iter->nextPurPtr;
        }

    }



    least=items[0];

    for(i=0;i<15;++i)
    {
        if(most<items[i])
        {
            most=i;
        }
        else if(least<items[i])
        {
            least=i;
        }
    }

    printf("\t\n This User bought mostly item: %d and least: %d .\n",most,least+1);


}

void ca_2(nodec* c,nodep* n,nodeP* p)
{
    system("cls");
    system("color 4");

    int id;
    double total;
    nodep* iter;
    iter=n;

    print_customerall(c);

    printf("\t\n\n Enter Id: ");
    scanf("%d",&id);

    while(iter!=NULL)
    {
        if(iter->customer_id==id)
        {
            total=total+iter->cost;
            iter=iter->nextPurPtr;
        }
        else
        {
            iter=iter->nextPurPtr;
        }
    }

    printf("\t\n\n This User spend %lf dolars in his/her all shoppings.\n",total);

}

void ca_3(nodec* c,nodep* n,nodeP* p)
{

    nodep* iter;
    iter=n;
    double users[100];
    nodec* iter2;
    iter2=c;

    while(iter!=NULL)
    {
        users[iter->customer_id]=users[iter->customer_id]+iter->cost;
        iter=iter->nextPurPtr;
    }

    while (iter2!=NULL)
    {
        printf("\t\n User:%d spent %lf dolars.",iter2->Id,users[iter2->Id]);
        iter2=iter2->Id;

    }

}

void ca_4(shipp* s)
{
    system("color 13");

    shipp* iter;
    iter=s;
    double total=0;
    int a,id;

    printf("\t\n\n Enter Id: ");
    scanf("%d",&id);

    while(iter!=NULL)
    {
        if(iter->customer_id==id)
        {
            total=total+iter->fee;
            iter=iter->nextShpPtr;
        }
        else{
            iter=iter->nextShpPtr;
        }

    }

    printf("\t\n\n this user spent %lf dolars for shipping by far.\n",total);



}

void product_analyses(nodec* c,nodep* n,nodeP* p,shipp* s)
{
    system("cls");
    system("color 4");
    k:
    printf("\t\n\n\n\n\n Product Analyses \n");
    printf("\t\n\n 1.Total Cost of a single product.");
    printf("\t\n\n 2.Total Cost of a single type.");
    printf("\t\n\n 3.Total Cost of every product.\n");

    int ch,x;

    printf("\t\n\n Choice:");
    scanf("%d",&ch);

    if(ch==1)
    {
        pa_1(c,n,p,s);
    }
    else if(ch==2)
    {
        pa_2(c,n,p,s);
    }
    else if(ch==3)
    {
        pa_3(c,n,p,s);
    }

    else
    {

        printf("\t\n Invalid Option!!\n");
        printf("\t\n 1.Go Back 2.main manu 3.Exit\n");
        scanf("%d",&x);

        if(x==1)
        {
            goto k;
        }
        else if(x==2)
        {
            Main_Menu(c,n,p,s);
        }
        else if(x==3)
        {
            exit(0);
        }
    }
}


void pa_1(nodec* c,nodep* n,nodeP* p,shipp* s)
{
    system("cls");
    system("color 4");

    k:
    printf("\t\n Enter Product Id:");
    nodep* iter;
    iter=n;
    int id,i,a;
    double total=0;
    scanf("%d",&id);

    while(iter!=NULL)
    {
        if(iter->product_id==id)
        {
            total=total+iter->cost;
            iter=iter->nextPurPtr;
        }
        else{
            iter=iter->nextPurPtr;
        }
    }

    printf("\t\n Product you have choosen had sold for %lf dolars by far.\n",total);

    printf("press 0 to return!");
    scanf("%d",&a);
    if(a==0){
        product_analyses(c,n,p,s);
    }


}

void pa_2(nodec* c,nodep* n,nodeP* p,shipp* s)
{

    system("cls");
    system("color 4");

    k:

    printf("\t\n Enter Product Type:");
    int type,a;
    double total=0;
    nodep* iter;
    iter=n;
    nodeP* iter2;
    iter2=p;
    scanf("%d",&type);

    while(iter2!=NULL)
    {
        if(iter2->type==type)
        {
            while(iter!=NULL)
            {
                if(iter2->Id==iter->product_id)
                {
                    total=total+iter->cost;
                }
                iter=iter->nextPurPtr;
            }
        }
            iter2=iter2->nextProPtr;

    }

    printf("\t\n this type of pruduct had sold for %lf dolars by far.\n",total);

    printf("press 0 to return!");
    scanf("%d",&a);
    if(a==0){
        product_analyses(c,n,p,s);
    }


}

void pa_3(nodec* c,nodep* n,nodeP* p,shipp* s)
{
    system("cls");
    system("color 4");
    nodep* iter;


    k:
        iter=n;

    printf("\t\n\n Total Cost\n");

    double total;
    int a;
    while(iter!=NULL)
    {
        total=total+iter->cost;
        iter=iter->nextPurPtr;
    }
    printf("\t\n total cost is : %lf dolars.\n",total);
    printf("\t\n press o to return!!!\n");
    scanf("%d",&a);
    if(a==0){
        product_analyses(c,n,p,s);
    }

}

