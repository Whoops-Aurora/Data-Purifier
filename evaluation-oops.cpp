#include <iostream>
#include <string>
using namespace std;
class Publication
{
    protected:
    int price;
    string title;
    int year_of_publish;
    string publication_type;
    public:
    virtual void discount()=0;
    virtual void print_publication()=0;
    virtual void add()=0;
};
class Video:public Publication
{
private:
    int time;
    public:
    Video()
    {
        this->price=0;
        this->publication_type="Video";
        this->title="NULL";
        this->year_of_publish=2020;
        time=0;
    }
    Video(int p,string t,int y,int pg)
    {
        this->price=p;
        this->publication_type="Video";
        this->title=t;
        this->year_of_publish=y;
        time=pg;
    }
    void discount()
    {
        cout<<"\n can't discount video"<<endl;
    }
    void add(int p,string t,int y,int pg)
    {
        this->price=p;
        this->publication_type="Video";
        this->title=t;
        this->year_of_publish=y;
        time=pg;
        cout<<"changes made successfully"<<endl;
    }
    void print_publication()
    {
        cout<<"Title:"<<this->title<<" Price:"<<this->price<<" Year of publication:"<<this->year_of_publish<<" Time:"<<time<<"\nType:"<<this->publication_type<<endl;
    }
};
class ebooks:public Publication
{
protected:
    int pages;
public:
    ebooks()
    {
        this->price=0;
        this->publication_type="ebook";
        this->title="NULL";
        this->year_of_publish=2020;
        pages=0;
    }
    ebooks(int p,string t,int y,int pg)
    {
        this->price=p;
        this->publication_type="ebook";
        this->title=t;
        this->year_of_publish=y;
        pages=pg;
    }
    void add(int p,string t,int y,int pg)
    {
        this->price=p;
        this->publication_type="Video";
        this->title=t;
        this->year_of_publish=y;
        pages=pg;
        cout<<"changes made successfully"<<endl;
    }
    void discount()
    {
        cout<<"applying discount,current price:"<<this->price<<endl;
        this->price=this->price-(this->price*0.1);
        cout<<"New price:"<<this->price<<endl;
    }
    void print_publication()
    {
        cout<<"Title:"<<this->title<<" Price:"<<this->price<<" Year of publication:"<<this->year_of_publish<<" Pages:"<<pages<<"\nType:"<<this->publication_type<<endl;
    }
};
int main()
{
    int price;
    string title;
    int year_of_publish;
    int ch,i=1,position,pgs,vids,ebookss;
    ebooks obj(214,"KLE tech",2019,35),obj1,obj2;
    Video obj3(),obj4(),obj5(),obj6(),obj7(),obj8(),obj9();
    Publication *ptr[2];
    ptr[0]=&obj;
    ptr[1]=&obj1;
    //ptr[2]=&obj2;
    //ptr[3]=&obj3;
   /* ptr[4]=&obj4;
    ptr[5]=&obj5;
    ptr[6]=&obj6;
    ptr[7]=&obj7;
    ptr[8]=&obj8;
    ptr[9]=&obj9;*/

    /*
    ptr[1]->print_publication();
    ptr[1]->discount();
    ptr[1]->print_publication();
    */
    while(1)
    {
        cout<<"\nMENU"<<endl;
        cout<<"1)edit a publication\n2)display all publication\n3)apply discount to ebooks\n"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter data as price:";
            cin>>price;
            cout<<"Enter data as Title:";
            cin>>title;
            cout<<"Enter data as year of publish:";
            cin>>year_of_publish;
            cout<<"Enter total pages/minutes";
            cin>>pgs;
            cout<<"Enter position to change:";
            cin>>position;
            ptr[position]->add(price,title,year_of_publish,pgs);
            break;
        case 2:
            for(i=0;i<10;i++)
            {
                ptr[i]->print_publication();
            }
            cout<<"Printing complerte"<<endl;
            break;
        case 3:
            for(i=0;i<10;i++)
            {
                ptr[i]->discount();
            }
        case 4:
            cout<<"Number of videos:"<<vids<<"\nNumber of eBooks:"<<ebookss<<endl;
            break;
        default:
            cout<<"Wrong input"<<endl;
        }
    }
}