#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct a_type
{
  string type;
  string name;
  string _value;
  int value;
  double d_value;
}type[50];


int foo(string,int);
double d_foo(string,int);
string _foo( string,int);

int main()
{
string str;
int i = 0 ;
string C$$ = "myFile.txt";
ifstream fin;
fin.open(C$$);
if (!fin.is_open())
{cout<<"ERROR"<<endl;}
else
{
 while(!fin.eof())
{
   str = "";
   fin >> str;
   ++i;
   
   if(str == "10")
   {
   type[i].type = "int";
   fin >> str;
   type[i].name = str;
   fin >> str;
   if( str == "-")
   {
    fin >> str;
    type[i].value = stoi(str);
   }
   else { continue; }
   }

   if(str == "10.0")
   {
   type[i].type = "double";
   fin >> str;
   type[i].name = str;
   fin >> str;
   if( str == "-")
   {
    fin >> str;
    type[i].d_value = stod(str);
    }
   else {continue;}
   }
   if(str == "bul")
   {
   type[i].type = "bool";
   fin >> str;
   type[i].name = str;
   fin >> str;
   if( str == "-")
   {
    fin >> str;
    if ( str == "0"  ){ type[i]._value = "false"; }
    else{ type[i]._value = "true"; }
   }
   else
   {continue;}
   }
   if(str == "abc")
   {
   type[i].type = "string";
   fin >> str;
   type[i].name = str;
   fin >> str;
   if( str == "-")
   {
    fin >> str;
    type[i]._value = str;
   }
   else
   {continue;}
   }
   if(str == "print")
   { 
      fin >> str;
      for(int j = 0; j <= i; ++j )
      if (str == type[j].name )
      { 
       fin >> str;
       if( str == ":")
       {
        if( type[j].type == "int"){ cout << type[j].value <<endl; }
        if( type[j].type == "double"){ cout << type[j].d_value <<endl; }
        if( type[j].type == "string"){ cout << type[j]._value <<endl; }
        if( type[j].type == "bool"){ cout << type[j]._value <<endl; }
       }
       if( str == "^")
       {
         if( type[j].type == "int")
            {fin >> str; cout << type[j].value + foo( str, i)<<endl ; fin >> str; continue;}
         if( type[j].type == "double")
            {fin >> str; cout << type[j].d_value + d_foo( str, i)<<endl ;fin >> str; continue;}
         if( type[j].type ==  "string")
            {fin >> str;cout << type[j]._value + _foo( str, i)<<endl ;fin >> str; continue;}
         if( type[j].type ==  "bool")
            {
              fin >> str;
              string bul = _foo(str,i);
              if( bul == "true")
              {
                if( type[j]._value == "true"  )
                 {cout<< "true" << endl ;}
                else{cout << "false" << endl;}
              }
              else {cout << "false" << endl; }
              fin >> str; continue;
            }
                
       }
       if( str == "~")
       {
         if( type[j].type == "int")
            {fin >> str; cout << type[j].value - foo( str, i)<<endl ; fin >> str; continue;}
         if( type[j].type == "double")
            {fin >> str; cout << type[j].d_value - d_foo( str, i)<<endl ; fin >> str; continue;}
         if( type[j].type ==  "string")
            {cout << "ERROR" <<endl ;fin >> str; continue;}
         if( type[j].type ==  "bool")
            {cout << "ERROR" <<endl ;fin >> str; continue;}
       }
       if( str == "$")
       {
         if( type[j].type == "int")
            {fin >> str; cout << type[j].value * foo( str, i)<<endl ;fin >> str; continue;}
         if( type[j].type == "double")
            {fin >> str; cout << type[j].d_value * d_foo( str, i)<<endl ; fin >> str; continue;}
         if( type[j].type ==  "string")
            {cout << "ERROR" <<endl ;fin >> str; continue;}
         if( type[j].type ==  "bool")
            {cout << "ERROR" <<endl ;fin >> str; continue;}
       }
       if( str == "%")
       {
         if( type[j].type == "int")
            {fin >> str; cout << type[j].value / foo( str, i)<<endl ;fin >> str; continue;}
         if( type[j].type == "double")
            {fin >> str; cout << type[j].d_value / d_foo( str, i)<<endl ; fin >> str; continue;}
         if( type[j].type ==  "string")
             {cout << "ERROR" <<endl ;fin >> str; continue;}
         if( type[j].type ==  "bool")
             {cout << "ERROR" <<endl ;fin >> str; continue;}
       }
      }
   }
   if( str == "enter")
   {
    fin >> str;
    for(int j = 0; j <= i; ++j )
      if (str == type[j].name )
      {
        
        if( type[j].type == "int" )   {cin >> type[j].value ;fin >> str; continue;}
        if( type[j].type == "double" ){cin >> type[j].d_value ;fin >> str; continue;}
        if( type[j].type == "string" ){cin >> type[j]._value ;fin >> str; continue;}
        if( type[j].type == "bool" )
        {
          int a;
          cin >> a; 
          if ( a != 0 ){ type[i]._value = "true";fin >> str; continue;}
          else{ type[i]._value = "false";fin >> str; continue; }
        }
        }
      }
    if( str == "rot")
    {
      fin >> str;if(str != "10"){cout << "ERROR:" << endl;}
      else
      {
       fin >> str;
       type[i].name = str;
       fin >> str; if(str != "-"){cout << "ERROR" << endl;}
       else
       {
         fin >> str;
         type[i].value = stoi(str);
         fin >> str; if(str != ":"){cout << "ERROR" << endl;}
         else
         {
           fin >> str;
           fin >> str;
           if(str == "<<")
           {
             fin >> str;
             int y = foo(str,i);
             fin >> str;if(str != ":"){cout << "ERROR" << endl;}
             else
             {
               fin >> str;
               if(str == "+")
               {
                 fin >> str;
                 fin >> str;if(str != "<"){cout << "ERROR" << endl;}
                 else
                 {
                   fin >> str;
                   if(str == "print" )
                   {
                     fin >> str;
                     int z = foo(str,i);
                     fin >> str;if(str == ">")
                     {
                       for(int j = type[i].value; j < y; ++j){cout << z << endl;}
                     }
                   }
                   else if(str == "con")
                   {
                     fin >> str;
                     string w = str;
                     fin >> str;if(str != "="){cout<<"ERROR"<<endl;break;}
                     else
                     {
                      fin >> str;
                      int k = 0;
                      k = stoi(str);
                      fin >> str; if(str != "<"){cout<<"ERROR" <<endl;break;}
                      else
                      {
                        fin >> str;
                        if(str == "print")
                        {
                          fin >> str;
                          int t = foo(str,i);
                          fin >> str;
                          if(str == ">")
                          {
                            for(int j = type[i].value; j < y; ++j)
                            {
                              type[i].name = w;
                              if(j == k){cout << t <<endl;}
                              
                            }
                          }
                        }
                      }
                     }
                   }
                   }
                   }
                 }
                }
             
           if(str == "<=")
           {
             fin >> str;
             int y = foo(str,i);
             fin >> str;if(str != ":"){cout << "ERROR" << endl;}
             else
             {
               fin >> str;
               if(str == "+")
               {
                 fin >> str;
                 fin >> str;if(str != "<"){cout << "ERROR" << endl;}
                 else
                 {
                   fin >> str;
                   if(str == "print" )
                   {
                     fin >> str;
                     int z = foo(str,i);
                     fin >> str;if(str == ">")
                     {
                       for(int j = type[i].value; j <= y; ++j){cout << z << endl;}
                     }
                   }
                   else if(str == "con")
                   {
                     fin >> str;
                     string w = str;
                     fin >> str;if(str != "="){cout<<"ERROR"<<endl;break;}
                     else
                     {
                      fin >> str;
                      int k = 0;
                      k = stoi(str);
                      fin >> str; if(str != "<"){cout<<"ERROR" <<endl;break;}
                      else
                      {
                        fin >> str;
                        if(str == "print")
                        {
                          fin >> str;
                          int t = foo(str,i);
                          fin >> str;
                          if(str == ">")
                          {
                            for(int j = type[i].value; j <= y; ++j)
                            {
                              type[i].name = w;
                              if(j == k){cout << t <<endl;}
                              
                            }
                          }
                        }
                      }
                     }
                     
                     
                   }
                 }
               }

             }
           }
           if(str == ">>")
           {
             fin >> str;
             int y = foo(str,i);
             fin >> str;if(str != ":"){cout << "ERROR" << endl;}
             else
             {
               fin >> str;
               if(str == "-")
               {
                 fin >> str;
                 fin >> str;if(str != "<"){cout << "ERROR" << endl;}
                 else
                 {
                   fin >> str;
                   if(str == "print" )
                   {
                     fin >> str;
                     int z = foo(str,i);
                     fin >> str;if(str == ">")
                     {
                       for(int j = type[i].value; j > y; --j){cout << z << endl;}
                     }
                   }
                   else if(str == "con")
                   {
                     fin >> str;
                     string w = str;
                     fin >> str;if(str != "="){cout<<"ERROR"<<endl;break;}
                     else
                     {
                      fin >> str;
                      int k = 0;
                      k = stoi(str);
                      fin >> str; if(str != "<"){cout<<"ERROR" <<endl;break;}
                      else
                      {
                        fin >> str;
                        if(str == "print")
                        {
                          fin >> str;
                          int t = foo(str,i);
                          fin >> str;
                          if(str == ">")
                          {
                            for(int j = type[i].value; j > y; --j)
                            {
                              type[i].name = w;
                              if(j == k){cout << t <<endl;}
                              
                            }
                          }
                        }
                      }
                     }
                   }
                   }
                   }
                 }
           }
           if(str == ">=")
           {
                          fin >> str;
             int y = foo(str,i);
             fin >> str;if(str != ":"){cout << "ERROR" << endl;}
             else
             {
               fin >> str;
               if(str == "-")
               {
                 fin >> str;
                 fin >> str;if(str != "<"){cout << "ERROR" << endl;}
                 else
                 {
                   fin >> str;
                   if(str == "print" )
                   {
                     fin >> str;
                     int z = foo(str,i);
                     fin >> str;if(str == ">")
                     {
                       for(int j = type[i].value; j >= y; --j){cout << z << endl;}
                     }
                   }
                   else if(str == "con")
                   {
                     fin >> str;
                     string w = str;
                     fin >> str;if(str != "="){cout<<"ERROR"<<endl;break;}
                     else
                     {
                      fin >> str;
                      int k = 0;
                      k = stoi(str);
                      fin >> str; if(str != "<"){cout<<"ERROR" <<endl;break;}
                      else
                      {
                        fin >> str;
                        if(str == "print")
                        {
                          fin >> str;
                          int t = foo(str,i);
                          fin >> str;
                          if(str == ">")
                          {
                            for(int j = type[i].value; j >= y; --j)
                            {
                              type[i].name = w;
                              if(j == k){cout << t <<endl;}
                            }
                           }
                         }
                       }
                      }
                     }
                   }
                 }
               }
             }
            }
           }
         }
        }

  for( int j = 0 ;j <= i ; ++j)
      {
        if (str == type[j].name) 
        {
        if( type[j].type == "int")
        { 
           fin >> str;
           fin >> str;
           int k = foo(str,i);
           fin >> str;
           if(str == ":"){type[j].value = k;}
           else
          {
             if( str == "^")
               {
                fin >> str;
                type[j].value = k + foo(str,i);
                break;
               }
             if( str == "~")
               {
                fin >> str;
                type[j].value = k - foo(str,i);
                break;
               }
             if( str == "$")
               {
                fin >> str;
                type[j].value = k * foo(str,i);
                break;
               }
             if( str == "%")
                {
                 fin >> str;
                 type[j].value = k / foo(str,i);
                 break;
                }          
          }
        }
         if( type[j].type == "double")
        {
           fin >> str;
           fin >> str;
           double k = d_foo(str,i);
           fin >> str;
           if(str == ":"){type[j].d_value = k;}
           else
          {
             if( str == "^")
               {
                fin >> str;
                type[j].d_value = k + d_foo(str,i);
                break;
               }
             if( str == "~")
               {
                fin >> str;
                type[j].d_value = k - d_foo(str,i);
                break;
               }
             if( str == "$")
               {
                fin >> str;
                type[j].d_value = k * d_foo(str,i);
                break;
               }
             if( str == "%")
                {
                 fin >> str;
                 type[j].d_value = k / d_foo(str,i);
                 break;
                }          
          }
        }
        if( type[j].type == "string")
        {
           fin >> str;
           fin >> str;
           string k = _foo(str,i);
           fin >> str;
           if(str == ":"){type[j]._value = k;}
           else
          {
             if( str == "^")
               {
                fin >> str;
                type[j]._value = k + _foo(str,i);
                break;
               }
             if( str == "~")
               {
                cout<< "ERROR" << endl;
               }
             if( str == "$")
               {
                cout<< "ERROR" << endl;
               }
             if( str == "%")
                {
                 cout<< "ERROR" << endl;
                }          
          }
        }
                if( type[j].type == "bool")
        {
           fin >> str;
           fin >> str;
           string k = _foo(str,i);
           fin >> str;
           if(str == ":"){type[j]._value = k;}
           else
          {
             if( str == "^")
               {
                fin >> str;
                if( _foo(str,i) != "0" || "false" )
                {if( k != "0" || "false")
                {type[j]._value = "true";}
                else{type[j]._value = "false";}
                }
               }
             if( str == "~")
               {
                cout<< "ERROR" << endl;
               }
             if( str == "$")
               {
                cout<< "ERROR" << endl;
               }
             if( str == "%")
                {
                cout<< "ERROR" << endl;
                }          
          }
        }
       }
      
   }
 }
}

fin.close();
 return 0;
}

int foo(string str, int i)
{
  for( int j = 1; j <= i ;++j)
  {
   if (str == type[j].name){return type[j].value;}
  }

  int tmp ;
  istringstream is (str);
  is >> tmp;
  return tmp;
}

string _foo(string str,int i)
{
  for( int j = 1; j <= i ;++j)
  {
   if (str == type[j].name){return type[j]._value;}
  }
  return str;
}

double d_foo(string str , int i)
{
   for( int j = 1; j <= i ;++j)
  {
   if (str == type[j].name) {return type[j].d_value;}
  }
  double tmp;
  istringstream iss (str) ;
  iss >> tmp;
  return tmp;
}