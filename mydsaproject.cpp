#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>  //-->library for malloc & realloc...
using namespace std;
bool register_student(struct student *stud,struct list *ls);
double calculate_aggregiate(struct student *);
void addToList(struct student *stud, struct list *l);
void showList(struct student *stud, struct list *l);
struct student
{
    char name[20];
    int metric_marks, fsc_marks, entryTest_marks;
    student *next;
    //--> 10 % weightage to metric, 50% to fsc, 40% to entry test...
};
struct list
{
    char name[20];
    double aggr;
    list *next;
};
int main()
{
    cout<<"\t\t\n\n\n|************************************************|";
    cout<<"\t\t\n|           WELCOME   TO   STUDENT               |";
    cout<<"\t\t\n|             SELECTION  PROCESS                 |";
    cout<<"\t\t\n|************************************************|\n\n\n";
    student *s;     //--> creates an object of student...
    s = (struct student *) malloc(sizeof(struct student));
    struct list *ls;
    ls = (struct list *) malloc(sizeof(struct list));
    strcpy(ls->name, "");
    ls->aggr = 0;
    ls->next= NULL;
    do
    {
        cout<<" 1 >to register a new student\n";
        cout<<" 2> to display lists of students registered\n";
        cout<<" 3> to quit\n";
        int input;
        cin>>input;
        if (input == 1)
        {
            register_student(s, ls);
        }
        else if (input == 2)
        {
            showList(s, ls);
        }
        else if (input == 3)
        exit(0);
        cout<<"\n";
    } while(1);

}
bool register_student(struct student *stud,struct list *ls)
{
    student *s = stud;
    char m[20];
    cin.getline(m,20);
    cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout<<"Write name of student\n";
    cin.getline(s->name,50);
    cout<<"\n----------------------------------------------------\n";
    cout<<"Enter metric percentage\n";
    cin>>s->metric_marks;
    cout<<"\n----------------------------------------------------\n";
    cout<<"Enter Hsc percentage\n";
    cin>>s->fsc_marks;
    cout<<"\n----------------------------------------------------\n";
    cout<<"Enter entry test percentage\n";
    cin>>s->entryTest_marks;
    cout<<"\n----------------------------------------------------\n";
    double aggregiate;
    aggregiate = calculate_aggregiate(s);   //-->call to function below...
    cout<<"aggregiate percentage is "<< aggregiate<<"\n";
    cout<<"\n----------------------------------------------------";
    if (aggregiate >= 70)
    {
        cout<<"\n***************************CONGRATULATIONS****************************\n";
        cout<<"\n**************Student registered in COMPUTER ENGINEERING**************\n";
        addToList(s,ls);
        return true;
    }
    else if (aggregiate >= 60)
    {
        cout<<"\n***************************CONGRATULATIONS****************************\n";
        cout<<"\n*************Student registered in MECHANICAL ENGINEERING*************\n";
        addToList(s,ls);
        return true;
    }
    else if (aggregiate >=50)
    {
        cout<<"\n***************************CONGRATULATIONS****************************\n";
        cout<<"\n************Student registered in CIVIL ENGINEERING*******************\n";
        addToList(s,ls);
        return true;
    }
    else
    {
        cout<<"\n**********Sorry, the student can't be registered in engineering********\n";
        return false;
    }
    cout<<"\n *******************  THANK  YOU***************************\n";
}
double calculate_aggregiate(struct student *stud)
{
    student *s = stud;
    double aggr;
    aggr = s->metric_marks * 10/100  + s->fsc_marks * 50/100 +
        s->entryTest_marks * 40/100;
    return aggr;
}
void addToList(struct student *stud, struct list *l)
{
    list *pointer = l;
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }
    pointer->next = (struct list *) malloc(sizeof(struct list));
    pointer = pointer->next;
    strcpy(pointer->name , stud->name);
    pointer->aggr = calculate_aggregiate(stud);
    pointer->next = NULL;
}
void showList(struct student *stud, struct list *l)
{
    list *pointer = l;
    if (pointer->next == NULL)
        cout<<"No student registered yet!\n";
    else
    {
        cout<<"Students statistics are: \n";
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
            cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
            cout<<"Name of student is: "<<pointer->name<<"\n";
            cout<<"\n---------------------------------------------\n";
            cout<<"Aggregiate of student is: "<<pointer->aggr<<"\n";
            cout<<"\n----------------------------------------------\n";
            if (pointer->aggr >= 70)
            {
                cout<<"Student registered in COMPUTER ENGINEERING\n";
                cout<<"\n------------------------------------------\n";

            }
            else if(pointer->aggr >=60&&pointer->aggr<70)
            {
                cout<<"Student registered in MECHANICAL ENGINEERING\n";
                cout<<"\n------------------------------------------\n";
            }

            else
            {
                cout<<"Student registered in CIVIL ENGINEERING\n";
                cout<<"\n--------------------------------------------";

            }
                cout<<"\n*******------*******-------******--------******";
            }
        }
    }
