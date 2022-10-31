#ifndef library_h_
#define library_h_


struct customer{
    int Id;
    char name[50];
     int type  ;
    double x_coord;
    double y_coord;
    struct customer* nextCusPtr;
};
typedef struct customer nodec;
typedef nodec* customer;


struct purchased{
    int Id;
    int invoice_id;
    int customer_id;
    int product_id;
    double cost;
    int piece;
    int type;
    struct purchased* nextPurPtr;

};
typedef struct purchased nodep;
typedef nodep* purchased;

struct shipping{

    int invoice;
    double fee;
    int customer_id;
    struct shipping* nextShpPtr;

};
typedef struct shipping shipp;
typedef shipp* shipping;


struct product{
    int Id;
    char name[50];
    int type;
    double price;
    struct product* nextProPtr;
};
typedef struct product nodeP;
typedef nodeP* product;


void set_customer(nodec* c);
void print_customerall(nodec* c);
void set_purchased(nodep* p,double cost,int id_item,int id_user,int invoice,int piece,int type,int id);
void set_ship(shipp* s,int invoice,double fee,int id);
void set_product(nodeP* p);
void print_productall(nodeP* p);
void Main_Menu(nodec* c,nodep* p,nodeP *P,shipp* s);
void sale_menu(nodec* c,nodep* p,nodeP* P,shipp* s);
void last_bill(nodep* p,int id);
void sale_interface(nodec* c,nodeP* p,nodep* n,shipp* s,int id);
int get_invoice(nodep* p);
double shippingx(nodec* c,int id);
double total_cost(nodep* p,int invoice,double ship);
void get_bill(nodep* p,nodec* c,nodeP* P,shipp* s,int invoice,double total,double ship,int choice);
void customerinfo_menu(nodec* c,nodep* n,nodeP* p,shipp* s);
void productinfo_menu(nodeP* p,nodec* c,nodep* n,shipp* s);
void customer_analyses(nodec* c,nodep* n,nodeP* p,shipp* s);
void single_userinfo(nodec* c,nodep* n,nodeP* p);
void ca_2(nodec* c,nodep* n,nodeP* p);
void ca_3(nodec* c,nodep* n,nodeP* p);
void ca_4(shipp* s);
void product_analyses(nodec* c,nodep* n,nodeP* p,shipp* s);
void pa_1(nodec* c,nodep* n,nodeP* p,shipp* s);
void pa_2(nodec* c,nodep* n,nodeP* p,shipp* s);
void pa_3(nodec* c,nodep* n,nodeP* p,shipp* s);





#endif // library_h_

