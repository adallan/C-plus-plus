// Budget.cpp is a  monthly budget analysis program that takes in user budget and expense
// Then reports if they are over, under or on budget.

// File name: Budget.cpp
// Name: Alexander Allan


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Define while loop variable 
    char loop_sentinel='Y';

    //Define variables for budget, running total, number of expenses and num
    double budget, running_total, expense_holder;
    int num_expenses, num; // num_expenses and num is for a for loop

    while (loop_sentinel == 'Y' || loop_sentinel == 'y') //start while loop
    {
        // Get user to enter budget
        cout << "Please enter your monthly budget (1 to 10,000)" << endl;
        cin >> budget;
        while (budget <= 0 || budget >= 10000) //check proper input
        {
            if (cin.fail()) // Check if fail from char to double conversion
            {
                cin.clear(); // Clear the input and ignore a number of characters
                cin.ignore(10000,'\n');
            }
            else // Make user input new input. Will always occur because char value got cleared
            {
                cout << "Please enter a proper budget in numbers (1 to 10,000)" << endl;
                cin >> budget;
            }
        } 
        // Get user to enter how many expenses they have
        cout << "How many expenses do you have each month?(1 to 10)" << endl;
        cin >> num_expenses;
        while (num_expenses <= 0 || num_expenses >= 10) //check proper input
        {
            if (cin.fail()) // Clear the failure loop again
            {
                cin.clear(); 
                cin.ignore(10000,'\n'); // Clear input and ignore characters
            }
            else // Get user to fix their expense input
            {
                cout << "Please enter number of expenses again, must be greater than 0." << endl;
                cin >> num_expenses;
            }
        }
        // Get user to enter the cost of each expense
        for (num = 1; num <= num_expenses; num++) 
        //to loop until we reach or pass number of expenses entered
        {
            if (num == 1) // check if 1st expense
            {
                cout << "Please enter the cost of first expense (Above 0, Less than 10000)" << endl;
                cin >> running_total; //gather 1st expense
                while (running_total <= 0 || running_total >= 10000) //input validation
                {
                    if (cin.fail()) // Same as above
                    {
                        cin.clear(); 
                        cin.ignore(10000,'\n');
                    }
                    else
                    {
                        cout << "Please enter a valid cost for first expense, greater than 0 and less than 10000" <<
                        endl;
                        cin >> running_total; //Set the first value for running total
                    }  
                }
                cout << "Total expenses: " << setw(6) << setprecision(2) << fixed
                << running_total << endl;
            
            }
            else
            {
                cout << "Please enter the cost of next expense (Above 0, Less than 10000)" << endl;
                cin >> expense_holder; // Hold the value for next expense without overriding running total
                while (expense_holder <= 0 || expense_holder >= 10000) //input validation
                {
                    if (cin.fail()) // Again check for char input into the double
                    {
                        cin.clear(); 
                        cin.ignore(10000,'\n');
                    }
                    else
                    {
                        cout << "Please enter a valid cost for next expense, greater than 0 and less than 10000" <<
                        endl;
                        cin >> expense_holder;
                        cout << "Total expenses: " << setw(6) << setprecision(2) << fixed 
                        << running_total << endl; 
                        // Current running total
                    }
                }
                running_total = running_total+expense_holder; //Start to accumulate the running total
                cout << "Total expenses: " << setw(6) << setprecision(2) << fixed 
                << running_total << endl;
            }
        }
        if (running_total>budget) //Check for if user is over budget
        {
            cout << "You are over your budget" << endl;
            cout << "==========================" << endl;
            cout << "Budget: " << setw(6) << setprecision(2) << fixed << budget << endl;
            cout << "Total Expenses: " << setw(6) << setprecision(2) << fixed << running_total 
            << endl;
            cout << "You are over budget by: " << setw(6) << setprecision(2) << fixed
            << running_total-budget << endl; //Calculation for amount over budget
        }
        else if (running_total==budget) //Check if user is on budget
        {
            cout << "You are right on budget" << endl;
            cout << "==========================" << endl;
            cout << "Budget: " << setw(6) << setprecision(2) << fixed << budget << endl;
            cout << "Total Expenses: " << setw(6) << setprecision(2) << fixed << running_total 
            << endl;
            cout << "Your leftover budget: " << setw(6) << setprecision(2) << fixed
            <<running_total-budget << endl; //Calculation and show that user is directly on budget
        }
        else //If user if not on or over they must be under budget.
        {
            cout << "You are under budget" << endl;
            cout << "==========================" << endl;
            cout << "Budget: " << setw(6) << setprecision(2) << fixed << budget << endl;
            cout << "Total Expenses: " << setw(6) << setprecision(2) << fixed << running_total 
            << endl;
            cout << "Your leftover budget: " << setw(6) << setprecision(2) << fixed
            << budget-running_total << endl; //Calculation for leftover budget
        }
        //Check if user wants to run program again, if not exit loop
        cout << "Do you wish to run another budget analysis? Please enter Y or y to continue" << endl;
        cin >> loop_sentinel;
    }

return 0;
}
