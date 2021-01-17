#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// This function calculates the employee's gross pay, total tax and net pay.
void CalcPay (double Hours, string name) 
{
    float rate =18.00;
    double tax = 0.12;
    double grosspay, totaltax, netpay;
    
    grosspay= (Hours*rate);
    totaltax= (grosspay * tax);
    netpay= (grosspay - totaltax);
    
    cout << setprecision(2) << fixed << showpoint; //Format the numbers
    
    cout << "Employee: " << name << "\t\t\t";
    cout << "Total Hours: "<< Hours << ", Gross Pay: $"<< grosspay << ", Tax: $" << totaltax;
    cout << ", Net Pay: $"<< netpay<< "\n";
}


int main()
{
    // this functions open the file
    // then identifies each employee 
    // and accumulate the total hours worked.
    ifstream inputFile;
    string filename;
    string datarecord;
    string datahour;
    string empname;
    
    string jimname= "Jimmy Bucket", johnname= "John Doe", annname= "Ann Doe";
    string maryname= "Mary Jones", bobname= "Bob Hu";

    
    double jimhour = 0,johnhour=0, annhour=0, maryhour=0, bobhour=0;
        double emphour;
   
   // Open the file.
   inputFile.open("C:\\Users\\TashPC\\Desktop\\hw4.txt");

   // If the file successfully opened, process it.
   if (inputFile)// Open the file.
   {
       // Determine the employee names and accumulate the hours worked.
       while (getline (inputFile , datarecord))
       {
           empname=datarecord.substr(0,3);  //Set which column needs to be read for employee verification
           datahour= datarecord.substr(31,2);// Set which column needs to be read for employee's hours worked
           emphour = stod(datahour);// Convert the numerical data from file to double to use in calculations.
           
         if (empname=="Jim")                // the following if-statments skim through
         {                                  // the data from the file and
             jimhour= jimhour+emphour;      // accumulate the hours for each employee
         }                                  // using the first three letters of their name. 
         else if (empname=="Joh")
         {
             johnhour= johnhour+emphour;
         }
         else if (empname== "Ann")
         {
             annhour= annhour+emphour;
         }
         else if (empname == "Mar")
         {
             maryhour= maryhour + emphour;
         }
         else if (empname == "Bob")
         {
             bobhour= bobhour + emphour;
         }
         
       }
       
   CalcPay (jimhour, jimname);      //Call the CalPay function in order to use 
   CalcPay (johnhour,johnname);     // the total hours worked to determine the 
   CalcPay (annhour, annname);      // Gross Pay, Taxes, and NetPay for each employee. 
   CalcPay (maryhour, maryname);
   CalcPay (bobhour, bobname);
        
        // Close the file.
        inputFile.close();   
    
   }
   else 
   {
        // Display an error message.
	   cout << "Error opening the file.\n";
   }
   return 0;
   
}

