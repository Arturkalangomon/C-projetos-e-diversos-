#include <iostream>
#include <String>

 using namespace std;

 class Person 
 {
   String name; 
   int height;
 };

 void setValues(Person&);
 void getValues(const Person&);

 int main ()
 {
   Person p1;
   setValues(p1);  
   cout << "Informando dados sobre a pessoa:\n";
   cout << "================================\n";
   getValues(p1);
   return 0;
 }

 void setValues(Person& pers)
 {
   cout << "Informe o nome da pessoa: ";
   getline(cin, pers.name);
   cout << "Informe a altura em milímetros: ";
   cin >> pers.height; 
   cin.ignore();
 }

 void getValues(const Person& pers)
 {
   cout << "Nome da pessoa: " << pers.name << endl; 
   cout << "A altura da pessoa em milímetros é: " << pers.height << endl;
 }
 
 //via link https://pt.wikibooks.org/wiki/Programar_em_C%2B%2B/Classes...
