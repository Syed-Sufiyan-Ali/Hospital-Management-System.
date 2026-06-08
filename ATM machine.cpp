#include <iostream>
using namespace std;
 int main (){

    char acc_type ;
    int Current_balance = 1000;
    int Savings_balance = 15000;
 	int opt = {0};
    int withdraw = {0} ;
    int deposit = {0};
while (true){


<<<<<<< HEAD
	cout << "Which account do you want to open press " << endl <<"1 for Savings "<< endl <<"2 for Current ";
=======
	cout << "<======================================================================> \nWhich account do you want to open press " << endl <<"1 for Savings "<< endl <<"2 for Current ";
>>>>>>> 26a06bc764e8263622ceb73f2dc2eeeaaefc809a

	cin >> acc_type ;
    if (acc_type == 0){
    	break;
	}
 
 	switch (acc_type){
        
 		case '1':
 	    cout << "savings acccont opened\n 1 - Withdraw\n 2 - check balance\n 3 - Deposit funds\n";
	    
 			cin >> opt ; 
 			   switch (opt) {
 			    case 1:
				
 			     cout << "enter the amount you want to with draw\n " ; 
 				 cin >> withdraw ; 
 			     if (withdraw > Savings_balance){
 			         	cout << "Balance not Sufficient! \n " ;
 			         	return 1 ;
 					 }
				 
 				cout << "You withdrawed " << withdraw << "PKR " << "your current amount is: " << Savings_balance - withdraw << "PKR \n";
 		        break ;
		        
 				case 2:
 		    	 cout << "you current balance is \n " << Current_balance;
 		         break ;  
		        
 		        case 3: 
 				cout << "Enter the ammount you want to deposit \n ";
 				cin >> deposit ;
 		        cout << "You have successfully deposited an amount of "; 
 				cout << deposit << "PKR " ;
 				cout << "your balance is now "; 
 				cout << deposit + Savings_balance << endl ;
 		         break ;
		        
 		        default:
                 cout << "Invalid option selected!";
                 break;
	           
 		}
 		break ;


         case '2':
 	    	cout << "Current acccont opened\n 1 - Withdraw\n 2 - check balance\n 3 - Deposit funds ";
 	        cin >> opt ; 
 			   switch (opt) {
 			    case 1:
				
 			     cout << "enter the amount you want to with draw\n " ; 
 				 cin >> withdraw ; 
 				 if (withdraw > Current_balance){
 			         	cout << "Balance not Sufficient! \n ";
 			         	return 1 ;
 					 }
 			     cout << "You withdrawed " << withdraw << "PKR " << "your current amount is: " << Current_balance - withdraw << "PKR \n ";
 		         break ;
		        
 				case 2:
 		    	 cout << "you current balance is " << Current_balance << endl;
 		         break ;  
		        
 		        case 3: 
 				cout << "Ente the ammount you want to deposit ";
 				cin >>  deposit ;
 		        cout << "You have successfully deposited an amount of "; 
 				cout << deposit << "PKR " ;
 				cout << "your balance is now "; 
 				cout << deposit + Current_balance << endl ;
 		         break ;
		        
 		        default:
                 cout << "Invalid option selected! \n";
                 break;
 		}
 		break; 
		
 	default:
     cout << "Invalid account type selected! \n";
     break;
		} 
		
    }
    	
 }
 
<<<<<<< HEAD
=======



>>>>>>> 26a06bc764e8263622ceb73f2dc2eeeaaefc809a

