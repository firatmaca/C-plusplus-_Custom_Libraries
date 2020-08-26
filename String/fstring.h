#ifndef FSTRING_H
#define FSTRING_H
#include <iostream>
using namespace std;
class fstring
{
public:
    fstring();
    fstring(const char *item);
    fstring operator=(const char *item);
    fstring(fstring &item);
    fstring operator=(fstring &item);
    fstring& operator+=(fstring const &item);
    fstring& append (fstring &item);
    fstring& prepend (fstring &item);
    friend ostream& operator<<( ostream  &input, fstring &item );
    friend istream & operator>>(istream &output, fstring &item);
    int fsize(fstring &item);
    void clear();
    bool isEmpty(fstring &item);
    int indexOf(fstring &item , char *c);

private:
    char *data;
    int length;

};

#endif // FSTRING_H
