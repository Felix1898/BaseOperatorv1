/* A Program for Basic Base Operations in C++ */
/* By Felix 1898 */
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
vector <long> mem; //For keeping memory of non hex stuff
vector <char*> s; //For keeping memory of hex stuff
enum bases {    //For making it more realistic
    BIN=2,
    HEXAD = 6,
    OCTA = 8,
    DECIMAL=10
};
class base //FATHER CLASS
{

    public:
int b;
char sign;
    void conv(int);
    void show(void);
    long dat;
  long cvt;
  char*str= NULL;
  base()
  {
      dat=0;
      cvt=0;
      sign='+';
      }
~base()
{
    delete str;
}
};
void base::conv(int b1)
{
    if(b1==16)
    {
        str=new char;
    }
    long tmp=(long)dat;
 //   cout<<"Tmpo:"<<tmp<<endl;
    int q=1;
    int i;
    int k=0;
      long sum=0;
    while(tmp!=0)
    {
    i=tmp%b1;
  if(b1==16)
  {
      if(i<10)
      str[k]=(char)(i+48);
  else if(i>=10)
    str[k]=(char)(i+55);
  k++;
  }
        sum=(sum)+(i*q);

        q=q*b;
    tmp=tmp/b1;

}
if(b1==16)
{
str[k]='\0';
/*show()l*/
}
    cvt=sum;
}
void base::show()
{
    for(int i=strlen(str)-1;i>=0;i--)
        cout<<str[i];
}
class deci : public base //DECIMAL
{
            public:

    deci()
    {b=10;}

    deci operator+(const deci&x){
    deci a;
    a.dat=(this->dat)+x.dat;
    a.cvt=(this->cvt)+x.cvt;
    return a;
    }
    deci operator*(const deci&x)
    {
         deci a;
    a.dat=(this->dat)*(x.dat);
    a.cvt=(this->cvt)*(x.cvt);
    return a;
    }
      deci operator-(const deci&x)
    {
         deci a;
    a.dat=fabs((this->dat)-(x.dat));
    a.cvt=fabs((this->cvt)-(x.cvt));
    if((this->dat)>(x.dat))
    {
        a.sign='+';
    }
    else
        a.sign='-';
    return a;
    }
};
class bin: public base //BINARY
{
    public:
    bin()
    { (b)=2; }
        bin operator+( bin& x)
        {
        bin a;
        (*this).conv(10);
        x.conv(10);
        deci b;
        b.dat=(x.cvt)+(this->cvt);
        b.conv(2);
        a.dat=b.cvt;
        return a;
        }
  bin operator*( bin& x)
        {
        bin a;
        (*this).conv(10);
        x.conv(10);
        deci b;
        b.dat=(x.cvt)*(this->cvt);
        b.conv(2);
        a.dat=b.cvt;
        return a;
        }
 bin operator-( bin& x)
        {
        bin a;
        (*this).conv(10);
        x.conv(10);
        deci b;
        b.dat=fabs((x.cvt)-(this->cvt));
        if(x.cvt>this->cvt)
            a.sign='+';
        else
            a.sign='-';
        b.conv(2);
        a.dat=b.cvt;
        return a;
        }

};
class octa: public base //OCTAL
{
    public:
    octa()
    { b=8; }
        octa operator+( octa& x)
        {
        octa a;
        (*this).conv(10);
        x.conv(10);
        deci b;

        b.dat=(x.cvt)+(this->cvt);
        b.conv(8);
        a.dat=b.cvt;
        return a;
        }
     octa operator*( octa& x)
        {
        octa a;
        (*this).conv(10);
        x.conv(10);
        deci b;
        b.dat=(x.cvt)*(this->cvt);
        b.conv(8);
        a.dat=b.cvt;
        return a;
        }
         octa operator-( octa& x)
        {
        octa a;
        (*this).conv(10);
        x.conv(10);
        deci b;
        b.dat=fabs((x.cvt)-(this->cvt));
        b.conv(8);
        if(x.cvt>this->cvt)
            sign='+';
        else
            sign='-';
        a.dat=b.cvt;
        return a;
        }
};
class hexa: public base //HEXADECIMAL
{
    public:
    hexa()
    { b=16; }
      hexa operator+( hexa& a)
        {
        hexa x;
        (*this).conv(10);
        a.conv(10);
        deci b;
          long res=0,res2=0;
int k=0;

         for(int i=strlen(this->str)-1;i>=0;i--)
         {
             if((this->str[i]>='A')&&(this->str[i]<='F'))
             {
              res=res+((int)this->str[i]-55)*(pow(16,k));
k++;
}
else
{

 res=res+(long)((int)(this->str[i])-48)*(pow(16,k));
k++;
}
         }
         k=0;
        for(int i=strlen(a.str)-1;i>=0;i--)
         {
             if((a.str[i]>='A')&&(a.str[i]<='F'))
             {
              res2=res2+(long)((int)a.str[i]-55)*(pow(16,k));
k++;
}
else
{

 res2=res2+(long)((int)(a.str[i])-48)*pow(16,k);
k++;
}

      }
b.dat=res+res2;
b.conv(16);
   long l=strlen(b.str);
        cout<<l<<endl;
        char s[l];


int i;
for(i=0;i<l;i++)
        {
            s[l-i-1]=b.str[i];
        }
        s[l]='\0';
        x.str=new char;
strcpy(x.str,s);
        return x;
        }
             hexa operator*( hexa& a)
        {
               hexa x;
        (*this).conv(10);
        a.conv(10);
        deci b;
          long res=0,res2=0;
int k=0;

         for(int i=strlen(this->str)-1;i>=0;i--)
         {
             if((this->str[i]>='A')&&(this->str[i]<='F'))
             {
              res=res+((int)this->str[i]-55)*(pow(16,k));
k++;
}
else
{

 res=res+(long)((int)this->str[i]-48)*(pow(16,k));
k++;
}
         }
         k=0;
        for(int i=strlen(a.str)-1;i>=0;i--)
         {
             if((a.str[i]>='A')&&(a.str[i]<='F'))
             {
              res2=res2+(long)((int)a.str[i]-55)*(pow(16,k));
k++;
}
else
{

 res2=res2+(long)((int)a.str[i]-48)*(pow(16,k));
k++;
}

      }
b.dat=res*res2;
b.conv(16);
   long l=strlen(b.str);
        cout<<l<<endl;
        char s[l];


int i;
for(i=0;i<l;i++)
        {
            s[l-i-1]=b.str[i];
        }
        s[l]='\0';
        x.str=new char;
strcpy(x.str,s);
        return x;
        }

             hexa operator-( hexa& a)
        {
               hexa x;
        (*this).conv(10);
        a.conv(10);
        deci b;
          long res=0,res2=0;
int k=0;

         for(int i=strlen(this->str)-1;i>=0;i--)
         {
             if((this->str[i]>='A')&&(this->str[i]<='F'))
             {
              res=res+((int)this->str[i]-55)*(pow(16,k));
k++;
}
else
{

 res=res+(long)((int)this->str[i]-48)*(pow(16,k));
k++;
}
         }
         k=0;
        for(int i=strlen(a.str)-1;i>=0;i--)
         {
             if((a.str[i]>='A')&&(a.str[i]<='F'))
             {
              res2=res2+(long)((int)a.str[i]-55)*(pow(16,k));
k++;
}
else
{

 res2=res2+(long)((int)a.str[i]-48)*(pow(16,k));
k++;
}

      }
b.dat=fabs(res-res2);
if(res>res2)
    x.sign='+';
else
    x.sign='-';
b.conv(16);
   long l=strlen(b.str);
        cout<<l<<endl;
        char s[l];


int i;
for(i=0;i<l;i++)
        {
            s[l-i-1]=b.str[i];
        }
        s[l]='\0';
        x.str=new char;
strcpy(x.str,s);
        return x;
        }
};
class Run
{
public:
void menu(void);
Run()
{
    menu();
}
};
void Run::menu()
{
    int k;
    cout<<"\n Welcome To Base Operator  ! Enter any key to continue \n";
    char ch=getchar();
system("cls");

cout<<"LOADING"<<endl;
for(int i=0;i<3700;i++)
    cout<<"-";
system("cls");
     bases x;
      char x1;
    cout<<"What do you want to do ? \n Base Conversion(Enter 0) or Enter symbol of Operation(Add + or Multiply * or \n Difference - (gives abs difference) ):"<<endl;
      cin>>x1;
     if(x1=='+'||x1=='*'||x1=='-')
{
    cout<<"\n Enter the Base : "<<endl;
    cin>>k;
     if(k==2)
        x=BIN;
     else if(k==8)
        x=OCTA;
     else if(k==10)
        x=DECIMAL;
     else if(k==16)
        x=HEXAD;

      if(x==BIN)
      {

        bin X,Y,Z; cout<<"Enter the number :";
        cin>>X.dat;
        cout<<"\n Enter the second number :";
        cin>>Y.dat;
        if(x1=='+')
        Z=X+Y;
            else if(x1=='*')
            Z=X*Y;
            else
                Z=X-Y;
        cout<<"Result: "<<Z.sign<<Z.dat;
        mem.push_back(Z.dat);
      }
     else if(x==DECIMAL)
   {
       deci X,Y,Z; cout<<"Enter the number :";
   cin>>X.dat;
    cout<<"\n Enter the second number :";
        cin>>Y.dat;
        if(x1=='+')
        Z=X+Y;
        else if(x1=='*')
            Z=X*Y;
            else
                Z=X-Y;
        cout<<"Result: "<<Z.sign<<Z.dat;
mem.push_back(Z.dat);

   }
     else if(x==OCTA)
        {octa X,Y,Z; cout<<"Enter the number :";
     cin>>X.dat;
      cout<<"\n Enter the second number :";
        cin>>Y.dat;
        if(x1=='+')
        Z=X+Y;
        else if(x1=='*')
            Z=X*Y;
            else
                Z=X-Y;
        cout<<"Result: "<<Z.sign<<Z.dat;
mem.push_back(Z.dat);
        }
     else if(x==HEXAD)
     {
        hexa X,Y,Z;

       cout<<"Enter the number :";
X.str=new char;
fflush(stdin);
gets(X.str);
                cout<<"Enter other number :";
Y.str=new char;

gets(Y.str);

if(x1=='+')
Z=X+Y;
else if(x1=='*')
Z=X*Y;
else
    Z=X-Y;
cout<<"\n Result:";
cout<<Z.sign;
puts(Z.str);
s.push_back(Z.str);
}
}
else if(x1=='0')
{
    int f;
cout<<"\n Enter the Base : "<<endl;
    cin>>f;
     if(f==2)
        x=BIN;
     else if(f==8)
        x=OCTA;
     else if(f==10)
        x=DECIMAL;
     else if(f==16)
        x=HEXAD;
    if(x==BIN)
    {
        bin X;
        cout<<"Enter the number in binary (ignore trailing zeroes) : "<<endl;
        cin>>X.dat;
        cout<<"Convert to? Enter base ... \n ";
        cin>>f;
        if(f==8||f==10||f==16)
        X.conv(f);
        if(f!=16)
         {

            cout<<"Result:"<<X.dat<<endl;
        mem.push_back(X.dat);
         }
        else
        {
            cout<<"Result :";
    strrev(X.str);
    puts(X.str);
        s.push_back(X.str);

    }
    }
   else if(x==OCTA)
    {
        octa X;
        cout<<"Enter the number in octal : "<<endl;
        cin>>X.dat;
        cout<<"Convert to? Enter base ... \n ";
        cin>>f;
        if(f==2||f==10||f==16)
        X.conv(f);
        if(f!=16)
           {
               cout<<"Result:"<<X.dat<<endl;
        mem.push_back(X.dat);
           }
        else
        {
            cout<<"Result :";
    strrev(X.str);
    puts(X.str);
    s.push_back(X.str);
    }
    }
  else  if(x==DECIMAL)
    {
        deci X;
        cout<<"Enter the number in decimal: "<<endl;
        cin>>X.dat;
        cout<<"Convert to? Enter base ... \n ";
        cin>>f;
        if(f==2||f==8||f==16)
        X.conv(f);
        if(f!=16)
        {

            cout<<"Result:"<<X.dat<<endl;
        mem.push_back(X.dat);
        }
        else
        {
            cout<<"Result :";
    strrev(X.str);
    puts(X.str);
        s.push_back(X.str);

    }
    }
   else if(x==HEXAD)
    {
        hexa X;
        long res=0;
                cout<<"Enter the number in hexadecimal : "<<endl;
        X.str=new char;
        fflush(stdin);
        gets(X.str);
        int k=0;
        for(int i=strlen(X.str)-1;i>=0;i--)
         {
             if((X.str[i]>='A')&&(X.str[i]<='F'))
             {
              res=res+((int)X.str[i]-55)*(pow(16,k));
k++;
}
else
{

 res=res+(long)((int)(X.str[i])-48)*(pow(16,k));
k++;
}
         }
         deci X1;
         X1.dat=res;
        cout<<"Convert to? Enter base ... \n ";
        cin>>f;

        if(f==2||f==8)
        X1.conv(f);
        if(f!=10&&f!=16)
            {cout<<"Result:"<<X1.dat<<endl;
            mem.push_back(X1.dat);}
    else if(f!=16)
        {cout<<"Result:"<<X1.dat<<endl;
        mem.push_back(X1.dat);
        }
        else
        {
            puts(X.str);
                s.push_back(X.str);

    }

}
}
}
int main()
{
    char ch='y';
    char c;
    do
    {
        Run X;
    c=getchar();
    c=getchar();
    system("cls");

    cout<<"Press S(see result log) else Press any key?"<<endl;
    fflush(stdin);
    cin>>ch;
    if(ch=='S')
    {
    for(int i=0;i<mem.size();i++)
        cout<<mem[i]<<endl;
        for(int i=0;i<s.size();i++)
            puts(s[i]);
    }
    c=getchar();
    c=getchar();
    cout<<"Continue ??? Y or N(stop) ?"<<endl;
    fflush(stdin);
    cin>>ch;
    }while(ch!='N'&&ch!='n');
    return 0;
}
