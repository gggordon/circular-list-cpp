#include <iostream>
#include <string>

using namespace std;

int main(){
   string a ="test";
   string* temp = new string(a);
   cout << "Value in string : " << temp << endl;
   if(temp == NULL){
      cout << "Strings can store NULL in CPP" << endl;
   }else{
      cout << "Strings can NOT store NULL in CPP" << endl;
   }
   return 0;
}
