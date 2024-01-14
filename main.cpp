/*
A simple console based cpp code to perform vending machine logic as per the given requirements. 
The code continue to run infinite times and ask user input, return output with feedback including denominaitons.
*/


#include <iostream>

using namespace std;

/*
Class machine, which consists of core vending machine private methods and variables.
*/

struct Machine{
  short amount, extraMoney, cost = 2;                                           //short members for money computation 
  Machine(){
    cout << "\nDrinks Available are Cola, Lemonade and Water, Consider Denominations 1, 2, 5 and 10 Euro Only" << endl;
    cin >> amount;

    if(checkDenomination(amount)){
      cout << "\nOUTPUT: " << "\nAmount Returned: " << amount << endl;
    }
    else{
      if(amount < 2){
        cout << "\nMinimum Cost is 2 Euro, Consider adding more Money"  << endl;
        cin >> extraMoney;
        if(!checkDenomination(extraMoney)){
          amount += extraMoney;
        }
        else{
          cout  <<  "\nOUTPUT: " << "Denomination Not Supported"
                <<  "Returning Amount:  " <<  amount + extraMoney <<  endl;
        }
     }
      chooseDrink();
    }
  }

  ~Machine(){
    cout  << "\nTerminated, Starting Again" << endl;
  }


private:

/*
Method to output the money along with denominations. No informal parameters required
*/

  void remainingBalance(void){
    
    cout << "\n"  <<  (amount - cost) / 2 << " - 2 Euro Denomination Out \n"
         << (amount - cost) % 2 << " - 1 Euro Denomination Out" <<  endl;
     
  }

/* 
Method to check the validity of input money. Only one informal parameter
@param1:  Input amount 
*/

  int checkDenomination(short amount){
    int denom[] = {1, 2, 5, 10};                                    //int array for checking input denominations validity
    bool  denm = 0;
    for(short i = 0; i < 4 ; ++i){
      if (denom[i] == amount) {
        denm = 1;
      }else continue; 
    }
    if(!denm){
      cout << "\nEntered Denomination is not supported" << endl;
      return 1;
    }
    else return 0;
  }

/*
Method to display drinks and get user input. No informal parameters required. 
*/

  void chooseDrink(void){
    char drink;                                                       //char member to store user drink type
    cout << "\nEnter the Drink Required \n" <<
            "c for Cola \n"  <<
            "w for water \n" <<
            "l for Lemonade \n" << 
            "x for Cancel"  <<  endl;
    
    cin >> drink;                                                    //Standard Input for drink
    
    switch(drink){
      case('c'):  cout << "\nCola Selected"    
                       << "\nOUTPUT:  Cola Out"  <<  endl;
                  remainingBalance();
                  break;

      case('l'):  cout << "\nLemonade Selected"
                       << "\nOUTPUT:  Lemonade Out"  <<  endl;
                  remainingBalance();
                  break;
  
      case('w'):  cout << "\nWater Selected"
                       << "\nOUTPUT:  Water Out" <<  endl;
                  remainingBalance();
                  break;

      case('x'):  cout << "Cancelled" <<  endl;
                  break;

      default:    
                  break;
    }
  }
};

int main(){
  while(1){
    Machine obj;
  }
  return 0;
}
