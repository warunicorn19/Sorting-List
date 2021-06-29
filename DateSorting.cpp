#include<iostream>
using namespace std;
struct date{
   int day;
   int month;
   int year;
   int valid = 1;
};
int datevalidate(int dd, int mm, int yy){
   if(yy>=100 && yy<=9999){
      if(mm>=1 && mm<=12){
         if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12));
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11));
               else if((dd>=1 && dd<=28) && (mm==2));
                  else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)));
            else
               return 0;
            } else{
            return 0;
         }
      } else {
      return 0;
   }
}
int main(){
   cout<<"Enter 5 dates to be sorted:\n";
   struct date input[5];
   for(int i=0; i<5; i++){
      cout<<"Enter Date "<<(i+1)<<" : ";
      cin>>input[i].day;
      cin>>input[i].month;
      cin>>input[i].year;
      input[i].valid = datevalidate(input[i].day, input[i].month, input[i].year);
      if(input[i].valid){
         cout<<"Date is invalid";
         exit(0);
      }
   }
   for (int i=0; i<4; i++){
      for (int j=i+1; j<5; j++){
         if (input[i].year > input[j].year){
            struct date temp = input[i];
            input[i] = input[j];
            input[j] = temp;
         }
         else if (input[i].year == input[j].year && input[i].month > input[j].month){
            struct date temp = input[i];
            input[i] = input[j];
            input[j] = temp;
         }
         else if (input[i].year == input[j].year && input[i].month == input[j].month && input[i].day > input[j].day){
            struct date temp = input[i];
            input[i] = input[j];
            input[j] = temp;
         }
      }
   }
   cout<<"Sorted dates are : \n";
   for(int i=0; i<5; i++){
      cout<<input[i].day<<" "<<input[i].month<<" "<<input[i].year;
      cout<<endl;
   }
}