#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
int i = 0;
int check = 7416;
class book_var{
    public:
        int bookid,price,pages;
        string name,aut,pub;
        book_var(){
            bookid = 0;
            name = "";
            aut = "";
            pub = "";
            price = 0;
            pages = 0;
        }
        friend void disp(int k);
}b[100];


class bookfun: public book_var{
    private:
        void addcall();
        void Delete();
        void update();
    public:
        void menu();
        void Search();
        void show();
        void purchase();
        void Return();
};

void bookfun::menu(){
    choose:
    system("cls");
    int choice;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------------Book Store Management---------------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"\n\t\t\t\t[1]. Add a New Book";
    cout<<"\n\t\t\t\t[2]. Search a Book";
    cout<<"\n\t\t\t\t[3]. Update a Book";
    cout<<"\n\t\t\t\t[4]. Delete a Book";
    cout<<"\n\t\t\t\t[5]. Show all Book";
    cout<<"\n\t\t\t\t[6]. Purchase a Book";
    cout<<"\n\t\t\t\t[7]. Return a Book";
    cout<<"\n\t\t\t\t[8]. Exit";
    cout<<endl;
    cout<<"\n\t\t\t\tChoose an Option --> ";
    cin>>choice;
    switch(choice){
        case 1:
            addcall();
            break;
        case 2:
            Search();
            break;
        case 3:
            update();
            break;
        case 4:
            Delete();
            break;
        case 5:
            show();
            break;
        case 6:
            //purchase();
            break;
        case 7:
            //Return();
            break;
        case 8:
            system("cls");
            cout<<"\nExiting the application....";
            exit(0);
        default:
            cout<<"\n\t\t\t---Enter the VALID option---";

    }
    getch();
    goto choose;
}


void disp(int k){
    cout<<"\n\n Book Id : "<<b[k].bookid;
    cout<<"\n\n Book Name : "<<b[k].name;
    cout<<"\n\n Author Name : "<<b[k].aut;
    cout<<"\n\n Publisher Name : "<<b[k].pub;
    cout<<"\n\n Price of the book "<<b[k].name<<" : "<<b[k].price;
    cout<<"\n\n No.of Pages : "<<b[k].pages;
    cout<<"\n\n========================================================================================"<<endl;
}

void bookfun::addcall(){
    again:
    system("cls");
    cout<<"...This is ADMINISTRATORS ONLY..."<<endl;

    cout<<"\n\nEnter the ADMIN only pin to continue: ";
    int a;
    cin>>a;
    system("cls");
    if(a==check){
        p:
        char o;
        cout<<"\nLoading.....";
        system("cls");
        cout<<"---------------------------------------------------------------------------------------"<<endl;
        cout<<"---------------------------------Book Store Management---------------------------------"<<endl;
        cout<<"---------------------------------------------------------------------------------------"<<endl;
        cout<<"\nEnter the Book-id: ";
        cin>>b[i].bookid;
        for(int f=0;f<i;f++){
            if(b[i].bookid==b[f].bookid){
                cout<<"\n\nBook-id already exists..";
                getch();
                goto p;
                }
        }

        cout<<"\n\nEnter the Book Name: ";
        cin>>b[i].name;
        cout<<"Enter the Author Name: ";
        cin>>b[i].aut;
        cout<<"Enter the Publisher Name: ";
        cin>>b[i].pub;
        cout<<"Enter the no.of pages: ";
        cin>>b[i].pages;
        cout<<"Enter the price of "<<b[i].name<<" book: ";
        cin>>b[i].price;
        system("cls");
        cout<<"\n\n\n\t\t SUCCESSFUL!!!";
        cout<<"\n\n\n\t\t New Book added successfully";
        i++;
        cout<<"\n\n\n\t\t Add more?[y/n]: ";
        cin>>o;
        if(o =='y'){
            goto p;
        }
        else{
            menu();
        }

    }
    else{
        cout<<"\nEntered wrong password :( ";
        cout<<"\nTry again? [y/n]";
        char s;
        cin>>s;
        if(s == 'y'){
            goto again;
        }
        else{
            menu();
        }
    }
}

void bookfun::Search(){
    system("cls");
    int id,found=0,choice;
    string name;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------------Book Store Management---------------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    if(i==0){
        cout<<"\n\nDatabase is empty...";
        getch();
        menu();
    }
    else{
        cout<<"\n\n 1. According to book-id.";
        cout<<"\n\n 2. According to book name.";
        cout<<"\n\n 3. According to author name.";
        cout<<"\n\n\n\nSelect the option: ";
        cin>>choice;
        if (choice== 1){
            cout<<"\n\nEnter the book-id: ";
            cin>>id;
            for(int a=0;a<i;a++){
                if(id == b[a].bookid){
                    disp(a);
                    found++;
                }
            }

        }

        else if(choice==2){
            cout<<"\n\nEnter the Book name: ";
            cin>>name;
            for(int a=0;a<i;a++){
                if(name==b[a].name){
                    disp(a);
                    found++;
                }
            }
        }

        else if(choice==3){
            cout<<"\n\nEnter the Author Name: ";
            cin>>name;
            for(int a=0;a<i;a++){
                if(name==b[a].aut){
                        disp(a);
                        found++;
                }
            }
        }

        else{
            system("cls");
            cout<<"\n\nBOOK NOT FOUND...";
        }
    }

}

void bookfun::show(){
    system("cls");
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------------Book Store Management---------------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    char g;
    if(i==0){
        cout<<"\n\nDatabase is empty...";
        getch();
        menu();
    }
    else{
        for(int a=0;a<i;a++){
            disp(a);
        }
    }

    cout<<"\n\nReturn to the main menu : [y/n]";
    cin>>g;
    if(g=='y')
        menu();
    else
        exit(0);
}

void bookfun::update(){
    system("cls");

    int id,found=0;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------------Book Store Management---------------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    again:
    system("cls");
    cout<<"...This is ADMINISTRATORS ONLY..."<<endl;

    cout<<"\n\nEnter the ADMIN only pin to continue: ";
    int a;
    cin>>a;
    system("cls");
    if(a==check){
        if(i==0){
            cout<<"\n\nDatabase is empty...";
            getch();
            menu();
        }
        else{
            doit:
            cout<<"\n\nEnter the Book-id you want to update: ";
            cin>>id;
            for(int a=0;a<i;a++){
                if(id==b[a].bookid){
                    char g;
                    cout<<"\n\nEnter the Book Name: ";
                    cin>>b[a].name;
                    cout<<"Enter the Author Name: ";
                    cin>>b[a].aut;
                    cout<<"Enter the Publisher Name: ";
                    cin>>b[a].pub;
                    cout<<"Enter the no.of pages: ";
                    cin>>b[a].pages;
                    cout<<"Enter the price of "<<b[i].name<<" book: ";
                    cin>>b[a].price;
                    system("cls");
                    getch();
                    cout<<"\n\n\n\t\t SUCCESSFULLY UPDATED!!!";
                    found++;
                    system("cls");
                    cout<<"Want to update more: [y/n]";
                    if (g=='y')
                        goto doit;
                    else
                        menu();
                }
            }
            if(found==0){
                char g;
                cout<<"\n\nBook-ID NOT FOUND...";
                cout<<"\n\nTry again? [y/n]";
                if (g=='y')
                    goto doit;
                else
                    menu();
            }
        }
    }
    else{
        cout<<"\nEntered wrong password :( ";
        cout<<"\nTry again? [y/n]";
        char s;
        cin>>s;
        if(s == 'y'){
            goto again;
        }
        else{
            menu();
        }
    }
}

void bookfun::Delete(){
    system("cls");
    int id,found=0;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------------Book Store Management---------------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    again:
    system("cls");
    cout<<"...This is ADMINISTRATORS ONLY..."<<endl;

    cout<<"\n\nEnter the ADMIN only pin to continue: ";
    int a;
    cin>>a;
    system("cls");
    if(a==check){
        if(i==0){
            cout<<"\n\nDatabase is empty...";
            getch();
            menu();
        }
        else{
            doit:
            cout<<"\n\n Enter book-ID to delete: ";
            cin>>id;
            string temp;
            for(int a=0;a<i;a++){
                temp = b[a].name;
                if(id == b[a].bookid){
                    for(int k=a;k<i;k++){
                        b[k].bookid = b[k+1].bookid;
                        b[k].name = b[k+1].name;
                        b[k].aut = b[k+1].aut;
                        b[k].pub = b[k+1].pub;
                        b[k].pages = b[k+1].pages;
                        b[k].price = b[k+1].price;
                    }
                    cout<<"\n\nDeleted "<<temp<<" Successfully...";
                    i--;
                    found++;
                }

            }
            if(found==0){
                char g;
                cout<<"\n\nBook-ID NOT FOUND...";
                cout<<"\n\nTry again? [y/n]";
                if (g=='y')
                    goto doit;
                else
                    menu();
            }
        }
    }

    else{
        cout<<"\nEntered wrong password :( ";
        cout<<"\nTry again? [y/n]";
        char s;
        cin>>s;
        if(s == 'y'){
            goto again;
        }
        else{
            menu();
        }
    }
}




int main(){
    class bookfun book;
    book.menu();
    return 0;
}
