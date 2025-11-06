// This program allows user enter a number of student,a numvber of tests and stores their results
// in a two-dimensional array. Lets user search and see a student and their corresponding
// test scores, average, letter grade and student's name (each in a parallel array)
// Name: Alexander Allan

# include <iomanip>
# include <iostream>
# include <string>

using namespace std;

// constant declarations for maximum number of students and tests.
const int MAX_STUDENTS = 30;
const int MAX_TESTS = 10;

// function prototypes
void ReadScores(int[][MAX_TESTS],int& ,int&, int[],string[]);
void PrintScores(const int[][MAX_TESTS], int, int);
void avg_scores(const int[][MAX_TESTS], int, int, double[]);
int linear_search(const int[],int, int);
void letter_grade_assign(const double [],char[],int);
void input_validation(int&, int);

int main()
{
    // array of test scores
    int scores[MAX_STUDENTS][MAX_TESTS];
    int student_ids[MAX_STUDENTS];
    double student_avgs[MAX_TESTS];
    char letter_grades[MAX_STUDENTS];
    string student_names[MAX_STUDENTS];

    // number of students in class and number of tests written
    int number_students, number_tests, search_id, index;

    cout << "==============================================================================================" << endl;
    cout << "This program lets you enter any number of students up to 30 and their corresponding test scores" << endl;
    cout << "Then it will show each student and their test scores, their average, student id, name and average letter grade" << endl;
    cout << "==============================================================================================" << endl;

    // Function calls
    ReadScores(scores,number_students,number_tests,student_ids,student_names);
    PrintScores(scores,number_students,number_tests);
    avg_scores(scores,number_students,number_tests,student_avgs);
    letter_grade_assign(student_avgs,letter_grades,number_students);
    
    cout << "\nWhat student id are you looking for?" << endl;
    cin >> search_id;
    // Input validation of search id
    input_validation(search_id,number_students);
    // Search for the student id and store it's location
    index = linear_search(student_ids,number_students,search_id);
    // Output all of searched student's info and test results
    cout << "\nStudent name: " << setw(3) << student_names[index] << endl;
    cout << "The test scores for student # " << index+1 << " are : " << endl; 
    for (int tests=0 ; tests < number_tests; tests++)
    {
       cout << "Test # " << tests+1 << setw(3) << scores[index][tests] << endl;
    }
    cout << "Average Test score: " << setw(3) << student_avgs[index] << endl;
    cout << "Average Letter Grade: " << setw(3) << letter_grades[index] << endl;

    // My name and student id
    cout << "===================================================" << endl;
    cout << "Alexander Allan" << "\nStudent ID: 100478940" << endl;
    return 0;
}

//***********************************************************************************
// Definition of ReadScore function                                                 *
// This function reads a number of students and number of tests entered by the user *
// Then stores it in a 2-d array to be used in the PrintScores function             *
//***********************************************************************************
void ReadScores(int scores[][MAX_TESTS], int& number_students, int& number_tests, int student_ids[], string student_names[])
{
    // Local variables
    int temp;

    cout << "Enter the number of students (up to 30)" << endl;
    cin >> number_students;
    // Check for valid number of students
    input_validation(number_students,30);

    cout << "Enter the number of tests (up to 10)" << endl;
    cin >> number_tests;
    // Check for valid number of tests
    input_validation(number_tests,10);

    // Iterate through array
    for (int student = 0; student < number_students; student++)
    {
        // Add student id to the id's parallel array
        student_ids[student] = student+1; //+1 so no student is #0
        cout << "What is student " << student+1 << "'s name?" << endl;
        // Resets the keyboard from previous inputs
        cin.ignore();
        // Get full length of name until \n or enter
        getline(cin,student_names[student]); // [student] not student+1 since we already incremented it before input
        cout << "Enter the " << number_tests << " test scores (0 to 100) for student # " <<(student+1) << endl;
        
        // Next step of iteration, grabbing test scores for the 2-d array
        for(int test = 0; test < number_tests; test++)
        {
            // Temperaily stores input before it is stored in the array
            cin >> temp;
            // Checks for valid test score inputs
            input_validation(temp,100);
            // Once a valid test score has been giving it is entered into the array
            scores[student][test] = temp;
        }
            
    }
}

//*********************************************************************************
// Definition for PrintScores function                                            *
// Function takes the 2-d array and uses number of students and number of tests   *
// to print out each student and their corresponding test scores                  *
//*********************************************************************************
void PrintScores(const int scores[][MAX_TESTS],int num_students, int num_tests)
{
    for (int student = 0; student < num_students; student++)
    {
        // Get each student
        cout << "The test scores for student # " << (student+1) << " are: ";

        // Get each test result for each student
        for (int test = 0; test < num_tests; test++)
            cout << setw(3) << scores[student][test];
        cout << endl;
    }
}    

//****************************************************************************************
// Definition for avg_scores function                                                    *
// Function takes the 2-d array scores and uses number of students and number of tests   *
// to calculate the average of their test scores and store it in a parallel array        *
//****************************************************************************************
void avg_scores(const int scores[][MAX_TESTS],int num_students, int num_tests, double student_avgs[])
{
    for (int student = 0; student < num_students; student++)
    {
        // Local vairables for holding sum and the average of grades
        double avg;
        int sum=0; 
        // Iterate through array and sum all tests
        for (int test = 0; test < num_tests; test++)
            sum += scores[student][test];
        
        // Once sum has been totaled use number of tests to calculate the average score
        avg = sum/num_tests;
        // Add average into new parallel array
        student_avgs[student] = avg;
    //Return averages for all students
    cout << "The average score for student: " << student+1 << " is : " << setprecision(2) << fixed << student_avgs[student] << endl;
    }
}

//*****************************************************************************************************
// Definition for linear_search function                                                              *
// Function takes the array for student ids and uses number of students to perform a search           *
// iterating through the array until it finds the id it's looking for and returns its index location  *
//*****************************************************************************************************
int linear_search(const int student_ids[], int num_students, int search_id)
{
    // Local variables for indexing and positional location return
    int index=0, position = -1;
    // While loop boolean flag
    bool found = false;
    
    while (found == false && index < num_students)
    {
        // Loop iterates through array until it finds a true position
        if (student_ids[index] == search_id)
        {
            found = true;
            position = index;
        }
        index++;
    }
    // If loop finishes the entire array without flag turning true it must mean the id is not in the array
    if (found == false)
        cout << "Unable to find a student with that id" << endl;
    return position;
}
//******************************************************************************************************************
// Definition for letter_grade_assign function                                                                     *
// Function takes the array for student averages and uses number of students with a for loop                       *
// to iterate through the average test scores array and assign a letter grade version to a new parellel array      *
//******************************************************************************************************************
void letter_grade_assign(const double student_avg[], char letter_grade[], int num_students)
{
    // Since average can be a float/double grade placeholder needs to be doubler as well.
    double grade;
    // Iterate through student_avg array and add coresponding letter grade into a new parallel array
    for (int index=0; index < num_students; index++)
    {   
        grade = student_avg[index];
        if (grade >= 85)
            letter_grade[index] = 'A';
        else if (grade < 85 && grade >= 75)
            letter_grade[index] = 'B';
        else if (grade < 75 && grade >= 65)
            letter_grade[index] = 'C';
        else if (grade < 65 && grade >= 55)
            letter_grade[index] = 'D';
        else
            letter_grade[index] = 'F';
    }
}
//******************************************************************************************************************
// Definition for input_validation function                                                                        *
// Function takes an int parameter in which is the input from user to check for invalid inputs and prompts         *
// user to enter a valid input in. Uses an int parameter 'max' to set the valid range of inputs.                   *
//******************************************************************************************************************
void input_validation(int& number, int max)
{
    while(number > max || number < 1 || cin.fail())
    {
        if (cin.fail()) // Check if input has failed from character input
        {
        cin.clear(); // Clear the input and ignore a number of characters
        cin.ignore(10000,'\n');
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "You entered a character not a number, Please try again" << setw(6) << endl;
        // Get user to re enter the input
        cout << "Enter a number up to " << max << endl;
        cin >> number;
        }
        else
        {
            // If input hasn't failed it is a number, if loop is triggered it is outside the range
            cout << number << " is not valid, please try again" << endl;
            // Get user to enter a valid number
            cout << "Enter a new number up to " << max << endl;
            cin >> number;
        }
    }
}
