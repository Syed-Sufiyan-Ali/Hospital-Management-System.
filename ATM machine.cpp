<<<<<<< HEAD
#include <iostream>
using namespace std;
 int main (){

     char acc_type ;
     int Current_balance = 1000;
     int Savings_balance = 15000;
 	int opt = {0};
    int withdraw = {0} ;
    int deposit = {0};
	cout << "which account do you want to open press " << endl <<"1 for Savings "<< endl <<"2 for Current ";

	cin >> acc_type ;
  
   

 	switch (acc_type){
        
 		case '1':
 	    cout << "savings acccont opened\n 1 - Withdraw\n 2 - check balance\n 3 - Deposit funds\n";
	    
 			cin >> opt ; 
 			   switch (opt) {
 			    case 1:
				
 			     cout << "enter the amount you want to with draw\n " ; 
 				 cin >> withdraw ; 
 			     if (withdraw > Savings_balance){
 			         	cout << "Balance not Sufficient!";
 			         	return 1 ;
 					 }
				 
 				cout << "You withdrawed " << withdraw << "PKR " << "your current amount is: " << Savings_balance - withdraw << "PKR";
 		        break ;
		        
 				case 2:
 		    	 cout << "you current balance is " << Current_balance;
 		         break ;  
		        
 		        case 3: 
 				cout << "Ente the ammount you want to deposit ";
 				cin >> deposit ;
 		        cout << "You have successfully deposited an amount of "; 
 				cout << deposit << "PKR " ;
 				cout << "your balance is not "; 
 				cout << deposit + Savings_balance ;
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
 			         	cout << "Balance not Sufficient!";
 			         	return 1 ;
 					 }
 			     cout << "You withdrawed " << withdraw << "PKR " << "your current amount is: " << Current_balance - withdraw << "PKR";
 		         break ;
		        
 				case 2:
 		    	 cout << "you current balance is " << Current_balance;
 		         break ;  
		        
 		        case 3: 
 				cout << "Ente the ammount you want to deposit ";
 				cin >>  deposit ;
 		        cout << "You have successfully deposited an amount of "; 
 				cout << deposit << "PKR " ;
 				cout << "your balance is "; 
 				cout << deposit + Current_balance ;
 		         break ;
		        
 		        default:
                 cout << "Invalid option selected!";
                 break;
 		}
 		break; 
		
 	default:
     cout << "Invalid account type selected!";
     break;
 	}
	
 }

=======
#include <iostream>
using namespace std;
 int main (){

     char acc_type ;
     int Current_balance = 1000;
     int Savings_balance = 15000;
 	int opt = {0};
    int withdraw = {0} ;
    int deposit = {0};
	cout << "which account do you want to open press " << endl <<"1 for Savings "<< endl <<"2 for Current ";

	cin >> acc_type ;
  
   

 	switch (acc_type){
        
 		case '1':
 	    cout << "savings acccont opened\n 1 - Withdraw\n 2 - check balance\n 3 - Deposit funds\n";
	    
 			cin >> opt ; 
 			   switch (opt) {
 			    case 1:
				
 			     cout << "enter the amount you want to with draw\n " ; 
 				 cin >> withdraw ; 
 			     if (withdraw > Savings_balance){
 			         	cout << "Balance not Sufficient!";
 			         	return 1 ;
 					 }
				 
 				cout << "You withdrawed " << withdraw << "PKR " << "your current amount is: " << Savings_balance - withdraw << "PKR";
 		        break ;
		        
 				case 2:
 		    	 cout << "you current balance is " << Current_balance;
 		         break ;  
		        
 		        case 3: 
 				cout << "Ente the ammount you want to deposit ";
 				cin >> deposit ;
 		        cout << "You have successfully deposited an amount of "; 
 				cout << deposit << "PKR " ;
 				cout << "your balance is not "; 
 				cout << deposit + Savings_balance ;
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
 			         	cout << "Balance not Sufficient!";
 			         	return 1 ;
 					 }
 			     cout << "You withdrawed " << withdraw << "PKR " << "your current amount is: " << Current_balance - withdraw << "PKR";
 		         break ;
		        
 				case 2:
 		    	 cout << "you current balance is " << Current_balance;
 		         break ;  
		        
 		        case 3: 
 				cout << "Ente the ammount you want to deposit ";
 				cin >>  deposit ;
 		        cout << "You have successfully deposited an amount of "; 
 				cout << deposit << "PKR " ;
 				cout << "your balance is "; 
 				cout << deposit + Current_balance ;
 		         break ;
		        
 		        default:
                 cout << "Invalid option selected!";
                 break;
 		}
 		break; 
		
 	default:
     cout << "Invalid account type selected!";
     break;
 	}
	
 }

>>>>>>> ec8f6941f6b74be2681c34c63f314e37a58fbbd5
