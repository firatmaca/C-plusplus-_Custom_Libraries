#include "fstring.h"
#include <stdio.h>
#include "QDebug"
fstring fappend;
fstring fprepend;
fstring  temp;
fstring::fstring()
{

    data=0;
    length=0;

}

fstring::fstring(const char * item){
    data=new char ();
    length=strlen(item);

    for(int i=0;i<length;i++){
        data[i]=item[i];
    }
    data[length]='\0';

}

fstring fstring::operator=(const char *item)
{

    length=strlen(item);
    data=new char ();
    for(int i=0;i<length;i++){
        data[i]=item[i];
    }
    data[length]='\0';
}

fstring::fstring(fstring &item)
{

    length=strlen(item.data);
    data=new char ();
    for(int i=0;i<length;i++){
        data[i]=item.data[i];
    }
    data[length]='\0';
    temp.data=data;
    temp.length=length;
}

fstring fstring::operator=(fstring &item)
{

    data=new char ();
    data=item.data;
    length=strlen(item.data);
    for(int i=0;i<length;i++){
        data[i]=item.data[i];
    }
    data[length]='\0';

}

fstring& fstring::operator+=(fstring const &item)
{


    int a=strlen(item.data);
    int tr=temp.length+strlen(item.data);

    for(int i=0;i< tr;i++){
        temp.data[i+a]+=item.data[i];
    }
    temp.data[ tr]='\0';

    return  temp;
}

bool flag=0;
fstring &fstring::append(fstring &item)
{   fappend.data=data;
    fappend.length=length;
    length  =strlen(fappend.data);
    if(flag==0){
        fappend.length=strlen(item.data);
        fappend.data=item.data;
        flag=1;
        return fappend;
    }
    int b=strlen(item.data);
    int toplam=0;
    toplam=length+b;
    for(int i=length;i< toplam;i++){
        fappend.data[i]=item.data[i-length ];
    }
    fappend.data[toplam]='\0';
    return fappend;
}
bool flag1=0;

fstring &fstring::prepend(fstring &item)
{
    fprepend .data=data;
    fprepend.length=length;
    length =strlen(fprepend.data);
    if(flag1==0){
        fprepend.length=strlen(item.data);
        fprepend.data=item.data;
        flag1=1;
        return fprepend;
    }
    int b=strlen(item.data);
    int toplam1=0;
    toplam1=length+b;
    data=new char ();
    for(int i=0;i< length;i++){
        data[i]=fprepend.data[i];
    }
    for(int i=0;i< b;i++){
        fprepend.data[i]=item.data[i];
    }
    for(int i=b;i< toplam1;i++){
        fprepend.data[i]=data[i-b];

    }
    fprepend.data[toplam1]='\0';
    return fprepend;
}

istream & operator>>(istream &output, fstring &item)
{
    char *d = new char () ;
    output >> d;
    int a=strlen(d);
    item.length=a;
    item.data= d;
    return output;
}

int fstring::fsize(fstring &item)
{
    int len=strlen(item.data);
    return len;
}

void fstring::clear()
{

    data="";
    length=0;

}

bool fstring::isEmpty(fstring &item)
{
    if(fsize(item)>0)
        return 0;

    return 1;
}

int fstring::indexOf(fstring &item, char *c)
{
    int a=strlen(item.data);
    int b= strlen(c);
    char *d= new char();
    for(int i =0;i<a;i++){
        if(c[0]==item.data[i]){
            for(int j=i;j<j+b;j++){
                d[j-i]=item.data[j];
                if(*d=*c){
                    return i;
                }
            }
        }

    }
    return -1;
}

ostream& operator << (ostream &input, fstring  &item)
{

    int a=strlen(item.data);
    char *d = new char () ;
    for(int i=0;i<a;i++){
        d[i]=item.data[i];
    }
    d[a]='\0';
    input <<d;
    return input;
}


