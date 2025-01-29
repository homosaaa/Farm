# Farm
Documentation::

1- made the methods STATIC in the validation to call the methods directly without calling an object from the class
     also made the ID counter static so it can increase the value of ID by 1 whenever we create an object from classes that       
     has an id in it's attributes. (i think it needs improvements later)

2- used "const" in most functions (methods/setters/getters) for best practices and to avoid any errors or any changing
   variables in functions by mistake.
   this means if we called any const function we have t.........
   
3- used '&' to make functions like transferto work correctly and in general to make the code more optimized and fast
   as we are calling by reference instead of copying the data in memory.
   

4- used <stdexcept> library instead of <exception> as it has more specific exception types like invalid_argument we used
   and easier than manually create modified exception classes.

5- used <cctype> library to use the function isalpha() to check for alphabetic characters in strings

6- Name Validation method:
	 - made it validate the name length and throw error if it's less than 5 characters or more than 20 characters
	 - made it validate the alphabetic characters in the name, and throw errors if there non alphabetic characters
	 - after some errors in testing i modified the validation to include spaces in names as it was throwing exceptions
	   when names had spaces

7- Min Balance Validation method:
	 - made it validate the value entered, if balance less than 1500 it throws error
	 - needs more improvement as after testing it reads any characters as less 1500.
	   should i make the validation reads direct input or make two validation methods
	   for balance one for calling the object directly and one for user input???????

8- Min Salary Validation method:
	 - made it validate the value entered, if salary less than 5000 it throws error
	 - needs more improvement as after testing it has the same issue as min balance
	   validation
--------------------------------------------------------------------------------------------------------------------
					(((((((((((Update!!!!!))))))))))))))
		 Removed deposit & withdrawl & transferto validations to the validation class
		 instead of Client class
--------------------------------------------------------------------------------------------------------------------
9- Added Validate Deposit method:
	  - made it validate deposit value and make sure that it's not zero or negative

10- Added validate withdrawl method:
	  - made it validate withdrawl value and make sure it's positive and does not exceed balance

11- Added validate transferto method:
	  - same as the last two methods!

12- //Added Comments for readibility and understanding the code :D


---------------------------------------------
{{{{{ Code used for testing is below }}}}}}}}
---------------------------------------------

int main(){

//Testing Validation Class:

//1- Testing Name Validation

cout << "Testing Name Validation" << endl;

string name1, name2, name3;

cout << "Enter First Name: ";
getline(cin, name1);

cout << "Enter Second Name: ";
getline(cin, name2);

cout << "Enter Third Name: ";
getline(cin, name3);

// First try block for name1
try {
    Validation::validateName(name1);
    cout << "First Name is valid: " << name1 << endl;
}
catch (invalid_argument& e) {
    cout << "Error for First Name: " << e.what() << endl;
}

// Second try block for name2
try {
    Validation::validateName(name2);
    cout << "Second Name is valid: " << name2 << endl;
}
catch (invalid_argument& e) {
    cout << "Error for Second Name: " << e.what() << endl;
}

// Third try block for name3
try {
    Validation::validateName(name3);
    cout << "Third Name is valid: " << name3 << endl;
}
catch (invalid_argument& e) {
    cout << "Error for Third Name: " << e.what() << endl;
}

cout << "=========================================" << endl;

  // ==========================================================

  // 2- Testing Password validation

  cout << "Testing Password validation" << endl;

  cout << "Enter first Password: ";

  string pass1,pass2;

  getline(cin, pass1);

  cout << "Enter second Password: ";

  getline(cin, pass2);

  // first try block for pass1 (right password length)
  try { 
      Validation::validatePassword(pass1);
      cout << "Password 1 is valid: " << pass1 << endl;
  }
  catch (invalid_argument& p) {
      cout << "Error for password 1: " << p.what() << endl;
  }
  // second try block for pass2 (wrong password length)
  try {
      Validation::validatePassword(pass2);
      cout << "Password 2 is valid: " << pass2 << endl;
  }
  catch (invalid_argument& p) {
      cout << "Error for password 2: " << p.what() << endl;
  }

  cout << "=========================================" << endl;
//===========================================================

   // 3- Testing Balance Validation

   cout << "Testing Balance Validation" << endl;

   double bal1, bal2;

   cout << "Enter Balance 1: ";

   cin >> bal1;

   cout << "Enter Balance 2: ";

   cin >> bal2;
 
   // try block for balance 1
   try {
       Validation::validateMinBalance(bal1);
       cout << "Balance 1 = " << bal1 << " is correct and equals or above 1500 egp" << endl;
   }
   catch (invalid_argument& b) {
       cout << "Error for Balance 1: " << b.what() << endl;
   }
   // try block for balance 2
   try {
       Validation::validateMinBalance(bal2);
       cout << "Balance 2 = " << bal2 << " is correct and equals or above 1500 egp" << endl;
   }
   catch (invalid_argument& b) {
       cout << "Error for Balance 2: " << b.what() << endl;
   }

   cout << "=========================================" << endl;
   //===============================================================

 // 4- Testing Salary Validation

 cout << "Testing Salary Validation" << endl;

 double sal1, sal2;

 cout << "Enter Salary 1: ";

 cin >> sal1;

 cout << "Enter Salary 2: ";

 cin >> sal2;

 // try block for Salary 1
 try {
     Validation::validateMinSalary(sal1);
     cout << "Salary 1 = " << sal1 << " is correct and equals or above 5000 egp" << endl;
 }
 catch (invalid_argument& s) {
     cout << "Error for Salary 1: " << s.what() << endl;
 }
 // try block for Sakary 2
 try {
     Validation::validateMinSalary(sal2);
     cout << "Salary 1 = " << sal2 << " is correct and equals or above 5000 egp" << endl;
 }
 catch (invalid_argument& s) {
     cout << "Error for Salary 2: " << s.what() << endl;
 }

 cout << "=========================================" << endl;
 //===============================================================

    Client c1(22, "Mohamed", "password123", 3000.0);
    Client c2(12, "Mai", "password456", 1000.0);

    cout << "Clients data before any changes" << endl;
    c1.displayInfo();
    cout << "========================" << endl;
    c2.displayInfo();
    cout << "========================" << endl;

    try {
        cout << "Mohamed data after 500 deposit amount" << endl;
        // Testing deposit
        c1.deposit(500);
        c1.displayInfo();  
        cout << "========================" << endl;

        cout << "Mohamed data after 1000 withdrawl amount" << endl;
        // Testing withdrawal
        c1.withdraw(1000);
        c1.displayInfo();  
        cout << "========================" << endl;

        cout << "Mohamed and Mai data after 500 amount transfered to bob" << endl;

        // Testing transfer
        c1.transferTo(500, c2);
        c1.displayInfo(); 
        cout << "========================" << endl;
        c2.displayInfo(); 
        cout << "========================" << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "=========================================" << endl;
    //===============================================================

Person p("Hamadaa", "password123", 2000);
Client c("Rozana Abbas", "password123", 2000);
Admin a("Amr Maged", "password123", 2000,6000);
Employee e("Mohamed mahmoud", "password123", 2000, 5000);

cout << "Person ID: " << p.getId() << endl;
cout << "Client ID: " << c.getId() << endl;
cout << "Admin ID: " << a.getId() << endl;
cout << "Employee ID: " << e.getId() << endl;
cout << "=========================================" << endl;
//===============================================================

}


