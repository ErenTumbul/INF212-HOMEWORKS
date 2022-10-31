#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

class med
{
private:
    int med_id;
    int num_med;
    double med_price;
    string drug_name;
public:

   med()
   {
       med_id=0;
       num_med=0;
       med_price=0;
       drug_name=" ";
   }


    void set_med()
    {


       cout<<"enter id: ";
       cin>>med_id;
       cout<<"enter number of drugs: ";
       cin>>num_med;
       cout<<"enter price: ";
       cin>>med_price;
       cout<<"enter name: ";
       cin>>drug_name;

    }

    void get_med()
    {
       cout<<"id: "<<med_id<<endl
           <<"piece: "<<num_med<<endl
           <<"price: "<<med_price<<endl
           <<"name: "<<drug_name<<endl;

    }

    med(const med& other)
    {
        med_id=other.med_id;
        num_med=other.num_med;
        med_price=other.med_price;
        drug_name=other.drug_name;
    }

    med& operator=(const med& other)
    {
        med_id=other.med_id;
        num_med=other.num_med;
        med_price=other.med_price;
        drug_name=other.drug_name;

        return (*this);
    }





    int get_med_id()
    {
        return med_id;
    }
    int get_piece()
    {
        return num_med;
    }
    double get_price()
    {
        return med_price;
    }
    string get_med_name()
    {
        return drug_name;
    }


    void edit_med();
    void view_store();
    void ilac_ekle();
    void search_med();

    friend class pharmacy;

};


class pharmacy
{
private:
    int ecz_id;
    string name;
    string adress;
public:



    pharmacy()
    {
        ecz_id=0;
        name="NULL";
        adress=" NULL";
    }


    void set_ph()
    {
        cout<<"enter id: ";
        cin>>ecz_id;
        cout<<"enter name: ";
        cin>>name;
        cout<<"enter adress: ";
        cin>>adress;
    }

    pharmacy(const pharmacy& other)
    {
        ecz_id=other.ecz_id;
        name=other.name;
        adress=other.adress;

    }

    pharmacy& operator=(const pharmacy& other)
    {
        ecz_id=other.ecz_id;
        name=other.name;
        adress=other.adress;

        return (*this);

    }

    void info_pha()
    {
        cout<<ecz_id<<" "<<name<<" "<<adress<<endl;
    }

    int get_ecz_id()
    {
        return ecz_id;
    }

    string get_ecz_name()
    {
        return name;
    }

    string get_adress()
    {
        return adress;
    }

    void eczane_bul();
//    void eczane_göster();
    void open_file();
    void list_phar();
    void eczane_ols(int id,string n,string a);
    void view_store();
    void create_list2();


    void customer_menu();

    friend class med;


};

void med::search_med()
{

    system("cls");
    system("color 4");
    k:

    fstream file1,file2;
    int counter=0;

    pharmacy p;
    med m;

    int ecz_id = p.get_ecz_id();
    string ecz_name=p.get_ecz_name();
    string ecz_adress=p.get_adress();

    string name;

    cout<<"\t\n\n ilac ismi girin: ";
    cin>>name;

    file1.open("eczane_listesi.dat", ios::in);

    while(file1>>ecz_id)
    {

        file1>>ecz_name;
        file1>>ecz_adress;

        file2.open(ecz_name + "_ilac"+".dat", ios::in);

        while(file2>>m.med_id)
        {

            file2>>m.num_med;
            file2>>m.med_price;
            file2>>m.drug_name;

            string mname=m.get_med_name();



            if(strcmp(name.c_str(),mname.c_str())==0)
            {
                cout<<ecz_name<<" eczanesi: "<<endl;

                cout<<"Ilac bilgileri: "<<endl;
                cout<<setw(15)<<"id: "<<m.med_id<<setw(15)<<"name: "<<m.drug_name<<setw(15)<<"piece: "<<m.num_med<<setw(15)<<"price: "<<m.med_price<<endl;

                counter++;
            }

        }


        file2.close();


    }
    file1.close();
     if(counter==0)
        {
                cout<<"\n\t hicbir eczanede bu ilac bulunmamakta..."<<endl;

        }

    cout<<"\t\n\n 1.baska ilac ara"<<endl
        <<"2.customer menu"<<endl
        <<"3.exit"
        <<endl;





}






void pharmacy::open_file()
{

    fstream file2;
    file2.open(name +"_ilac" + ".dat", ios::out | ios::in | ios::app);
    file2.close();

}





void pharmacy::eczane_bul()
{

    system("cls");
    system("color 4");


    fstream file;

    pharmacy p;
    string name;
    int counter=0;

    cout<<"eczane ismi girin: ";
    cin>>name;

    file.open("eczane_listesi.dat",ios::in | ios::out);

    while( file>>p.ecz_id)
    {

        file>>p.name;
        file>>p.adress;

        if(p.name.compare(name)==0)
        {

            p.info_pha();
            counter++;
        }
    }
    if(counter==0)
    {
            cout<<"\t\n eczane bulunmamakta"<<endl;
    }


}


void pharmacy::list_phar()
{

    fstream file;
    pharmacy p;
    file.open("eczane_listesi.dat",ios::in | ios::out);

    while(file>>p.ecz_id)
    {

        file>>p.name;
        file>>p.adress;

        p.info_pha();

    }



}

void pharmacy::view_store()
{

    fstream file;

    string name;

    cout<<"\t\n eczane ismi giriniz; ";
    cin>>name;

    med m;


    file.open(name+"_isim"+".dat",ios::in | ios::out | ios::ate);


    while(file>>m.med_id)
    {


        file>>m.num_med;
        file>>m.med_price;
        file>>m.drug_name;

        m.get_med();

    }
    file.close();


}




void customer_menu()
{
    k:
    system("cls");
    system("color 4");

    cout<<"\t\n\n welcome!!"<<endl;

    int ch,ch2;

    pharmacy p;
    med m;

    cout<<"\t\n 1.search medicine "<<endl
        <<" 2.list pharmacies "<<endl
        <<" 3.store info "<<endl
        <<" 4.view a store "<<endl;

    cin>>ch;

    if(ch==1)
    {
        m.search_med();
    }
    else if(ch==2)
    {
        p.list_phar();
    }
    else if(ch==3)
    {
        p.eczane_bul();
    }
    else if(ch==4)
    {
        p.view_store();
    }
    else
    {
        cout<<"\t invalid entry!! "<<endl
            <<"\t 1.exit 2.return  "<<endl;
        cin>>ch2;

        if(ch2==1)
        {
            exit(0);
        }
        else if(ch2==2)
        {
            goto k;
        }
        else if(ch2==3)
        {
            //main_menu();
        }

    }


}

void create_list1()
{
    system("cls");
    system("color 4");

    fstream file;
    file.open("eczane_listesi.dat",ios::in | ios::out);
    int ch;

    if(file)
    {
        cout<<"\t\n dosya mevcut"<<endl;
    }
    else
    {
        cout<<"\t\n dosya oluþturuluyor..."<<endl;
        file.open("eczane_listesi.dat",ios::in | ios::out | ios::app);
        cout<<"\t\n dosya oluþturuldu!!"<<endl;
    }

    cout<<"press 1 to retuen: "<<endl;
    cin>>ch;

    if(ch==1)
    {
        //owner_menu();
    }


}

void pharmacy::create_list2()
{

    system("cls");
    system("color 4");

    fstream file;

    cout.setf(ios::left);

    cout<<setw(15)<<"eczane id: ";
    cin>>ecz_id;
    cout<<setw(15)<<"eczane ismi: ";
    cin>>name;
    cout<<setw(15)<<"eczane adres: ";
    cin>>adress;

    eczane_ols(ecz_id,name,adress);
    open_file();


}

void pharmacy::eczane_ols(int id,string n,string a)
{

    fstream file;

    file.open("eczane_listesi.dat",ios::in | ios::out | ios::app);

    file<<setw(18)<<id
        <<setw(18)<<n
        <<setw(18)<<a
        <<endl;

}


void med::ilac_ekle()
{

    system("cls");
    system("color 4");
    k:



    fstream file1,file2;
    int counter=0;
    pharmacy p;
    med m;
    int ecz_id=p.get_ecz_id();
    string ecz_name=p.get_ecz_name();
    string ecz_adress=p.get_adress();

    p.list_phar();

    string name;

    cout<<"eczane ismi giriniz: "<<endl;
    cin>>name;

    file1.open("eczane_listesi.dat", ios::in);

    while(file1>>p.ecz_id)
    {
        file1>>p.name;
        file1>>p.adress;





        if(p.name.compare(name)==0)
        {
            file2.open(name + "_ilac" + ".dat",ios::in | ios::out | ios::app);

            m.set_med();

             file2<<setw(15)<<m.med_id
                <<setw(15)<<m.num_med
                <<setw(15)<<m.med_price
                <<setw(15)<<m.drug_name
                <<endl;

                counter++;
        }

    }

    if(counter==0)
        {
            cout<<"eczane yok!?!"<<endl;
        }

    file1.close();
    file2.close();

    cout<<"1.main menu"<<endl
        <<"2.baska ilac ekle"
        <<endl;

    int ch;

    cin>>ch;

    if(ch==1)
    {
        //main_menu();
    }
    else if(ch==2)
    {
        goto k;
    }


}









void owner_menu()
{
    k:
    system("cls");
    system("color 4 ");

    double password=1901022030;
    double pa;
    int ch1,ch2;
    pharmacy p;
    med m;

    cout<<" enter password: ";
    cin>>pa;

    if(password==pa)
    {
        system("cls");

        cout<<"\t\n\n 1.create list "<<endl
            <<" 2.add pharmacy "<<endl
            <<" 3.add medicine "<<endl
            <<" 4.edit medicine"<<endl;

        cout<<"\t\n choice: ";
        cin>>ch1;

        if(ch1==1)
        {
            create_list1();
        }
        else if(ch1==2)
        {
            p.create_list2();
        }
        else if(ch1==3)
        {
            m.ilac_ekle();
        }
        else if(ch1==4)
        {
            m.edit_med();
        }
        else
        {
            cout<<"\t\n invalid entry!! "<<endl
                <<"\t 1.exit 2.return"<<endl;
            cin>>ch2;

            if(ch2==1)
            {
                exit(0);
            }
            else if(ch2==2)
            {
                goto k;
            }
        }
    }

    else
    {
        cout<<"\t\n invalid entry!! "<<endl
            <<"\t 1.exit 2.main menu"<<endl;
        cin>>ch2;

        if(ch2==1)
        {
            exit(0);
        }
        else if(ch2==2)
        {
            //main_menu();
        }
    }

}

void med::edit_med()
{

    system("cls");
    system("color 4");
    k:
    fstream file1, file2, file3;
    med m;
    pharmacy p;
    int id2;
    int counter=0;
    string name;


   // int ecz_id=p.get_ecz_id();
    //string name1=p.get_ecz_name();
    //string adress=p.get_adress();

    p.list_phar();

    file1.open("eczane_listesi.dat",ios::in | ios::out);

    cout<<"\t\n eczane isim: ";
    cin>>name;

    while(file1>>p.ecz_id)
    {
        file1>>p.name;
        file1>>p.adress;

        if(p.name.compare(name)==0)
        {
            counter++;

            file2.open(name + "_ilac" + ".dat",ios::in | ios::out);
            file3.open("temp.dat",ios::in | ios::out | ios::app);

            cout<<"t\n degistirmek istediginiz ilac id: ";
            cin>>id2;

            while(file2>>m.med_id)
            {

                file2>>m.num_med;
                file2>>m.med_price;
                file2>>m.drug_name;

                if(id2==m.med_id)
                {
                    cout.setf(ios::left);
                    cout<<"\n Yeni ilac id: ";
                    cin>>m.med_id;
                    cout<<"\n Yeni ilac isim: ";
                    cin>>m.drug_name;
                    cout<<"\n Yeni ilac fiyat: ";
                    cin>>m.med_price;
                    cout<<"\n Yeni ilac adet; ";
                    cin>>m.num_med;


                     file3<<setw(15)<<m.med_id
                         <<setw(15)<<m.num_med
                         <<setw(15)<<m.med_price
                         <<setw(15)<<m.drug_name
                         <<endl;




                }
                else
                {

                    file3<<setw(15)<<m.med_id
                         <<setw(15)<<m.num_med
                         <<setw(15)<<m.med_price
                         <<setw(15)<<m.drug_name
                         <<endl;

                }

                file2.close();
                file3.close();
                remove((name+"_ilac"+".dat").c_str());
                rename("temp.dat",(name+"_ilac"+".dat").c_str());
            }

            }

        }

        if(counter==0)
        {
            cout<<"eczane yok?!?!?"<<endl;
        }



    file1.close();


    cout<<"1.edit another"
        <<"2.exit"
        <<endl;

        int ch;
        cin>>ch;

        if(ch==1)
        {
            goto k;
        }
        else if(ch==2)
        {
            exit(0);
        }

}














void main_menu()
{
    system("cls");
    system("color 4");

    cout<<"\t\t\n\n Welcome to Pharmacy Interface \n"<<endl;

    cout<<"\t\n 1.owner menu"<<endl;
    cout<<"\t\n 2.customer menu"<<endl;
    int ch;
    cin>>ch;

    if(ch==1)
    {
        owner_menu();
    }
    else if(ch==2)
    {
        customer_menu();
    }
    else{
        cout<<"INVALID ENTRY!!!";
        exit(0);
    }

}







int main() {


    main_menu();


}
