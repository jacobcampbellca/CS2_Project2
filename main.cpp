//  PROGRAM FILE NAME: Project 2.cpp        ASSIGNMENT #: 2
//
//  PROGRAM AUTHOR: Jacob Campbell
//
//  COURSE: CSC 24400     SEMESTER: FALL 2018     PROFESSOR: Dr. Miller
//
//  DUE DATE: Sept. 24th, 2018
//
//  DESCRIPTION: Prompt for an integer n, and the generate output
//               to simulate Sisyphus’ eternal toil in the underworld
//               until Hercules rescues him from his fate, after n
//               rounds have elapsed. Each time Sisyphus must push the
//               boulder up the hill, he must move it a total distance
//               of 100 feet. Each push of the boulder will move it a
//               random distance between 0 and 3 feet. Once the top of
//               the hill is reached, the total number of pushes needed
//               to reach the top should be printed out.
//
//  FUNCTIONS: header()
//             footer()
//             intro()
//             iMustToil()
//             push(double thisDistance)
//             reachedTop(int pushes, int length)
//             startOver()
//             rescued()
//             main()

#include <iostream>     // Includes IO stream
#include <iomanip>      // Provides parametric manipulators
#include <cmath>        // Allows use of srand()
using namespace std;    // Uses namespace STD across entire program

// Program header
void header() {
    cout << endl;
    cout << " --------------------------------- " << endl;
    cout << "|     START OF PROGRAM OUTPUT     |" << endl;
    cout << " --------------------------------- " << endl;
    return;
}

// Program footer
void footer() {
    cout << " --------------------------------- " << endl;
    cout << "|      END OF PROGRAM OUTPUT      |" << endl;
    cout << " --------------------------------- " << endl;
    cout << endl;
    return;
}

// Describes the scenario to the program user
void intro(){
    cout << "               Hello Cruel UnderWorld" << endl;
    cout << "               ======================" << endl;
    cout << endl;
    cout << "Hello Sisyphus!" << endl;
    cout << "I am Hades! God of the Underworld!" << endl;
    cout << endl;
    cout << "You have offended the gods!  Your punishment, for all eternity, will be to roll" << endl;
    cout << "this 200 pound boulder up that 100 foot high hill, whereupon reaching the top," << endl;
    cout << "you will watch it roll back down to the bottom again, only to begin again to roll" << endl;
    cout << "it up that hill!" << endl;
    cout << endl;
}

// Sisyphus dialogue, describing his punishment
void iMustToil() {
    cout << "I must forever toil to roll this boulder up the hill" << endl;
}

// Displays the distance of each push using one argument of type double
// called "thisDistance". Displays "thisDistance" right justified
// using 13 spaces.
double push(double thisDistance) {
    cout << "   Push -";
    cout << right << setw(13) << thisDistance << " feet" << endl;
    return 0;
}

// Displays how many times Sisyphus has pushed the rock to the top of the hill,
// and the number of pushes it took him to get it to the top that particular
// time. Uses two arguments called "pushed" (number of pushes to the top), and
// "length" (number of times the top has been reached)
void reachedTop(int pushes, int length) {
    cout << endl;
    cout << "Success! I reached the top of the hill for the " << length << "th time!";
    cout << "  It only took " << pushes << " pushes to get the boulder to the top" << endl;
    cout << endl;
}

// Displayed once Sisyphus has pushed to the rock to the top of the hill but has not
// completed his punishment
void startOver() {
    cout << "Oh No!  The rock rolled back down the hill!" << endl;
    cout << "I have to walk down the hill and start all over." << endl;
    cout << "I have reached the bottom of the hill." << endl;
    cout << endl;
}

// Displayed when Sisyphus has completed his punishment
void rescued() {
    cout << endl;
    cout << "I have been rescued by Hercules - I am freed from this eternal punishment!" << endl;
    cout << endl;
    cout << endl;
}

int main() {
    
    header();   // Show header
    
    double seedValue;                                   // Variable "seedValue" of type double
    cout << "Enter a non-negative seed value" << endl;  // Prompts user to input non negative value
    cin >> seedValue;                                   // Stores user input on variable "seedValue"
    srand(seedValue);                                   // Generates a random number using "seedValue"
    
    int length;                                         // Variable "length" of type int
    int timesToTop = 1;                                 // Variable "timesToTop" int initialized with a value of one
    cout << "How long (enter an integer): " << endl;    // Prompts user to enter how long Sisyphus must endure his punishment
    cin >> length;                                      // Stores user input in variable "length"
    cout << endl;
    
    intro();    // Show intro
    
    // For the value stored in length, while length is greater than zero,
    // decrement length by one each time the loop is completed
    for(int i = length; i > 0; i--) {
        iMustToil();    // Calls iMustToil()
        
        double distanceMoved = 0;   // Initialize variable "distanceMoved" of type double to zero
        double numberOfPushes = 0;  // Initialize variable "numberOfPushes" of type double to zero
        
        // While variable "distanceMoved"is less than 100...
        while(distanceMoved < 100) {
            // Generate a random number between zero and three and
            // store it in variable "randomNumber" of type float
            float randomNumber = (float) (rand() / ((float) RAND_MAX / 3.0));
            
            // If "distanceMoved" plus "randomNumber" is greater than 100...
            if((distanceMoved + randomNumber) > 100){
                randomNumber = abs(distanceMoved - 100);    // Store the absolute value of "distanceMoved" minus 100 in "randomNumber"
                distanceMoved = 100.0;                      // Set "distanceMoved" to 100
            }
            // Else...
            else {
                distanceMoved = distanceMoved + randomNumber;   // Set "distanceMoved" to "distanceMoved" plus "randomNumber"
            }
            
            numberOfPushes++;   // Increment "numberOfPushes" by one
            
            push(randomNumber); // Display distance of push (value of "randomNumber")
        }
        
        reachedTop(numberOfPushes, timesToTop); // Display "numberOfPushes" and "timesToTop"
        timesToTop++;                           // Increment "timesToTop" by one
        
        distanceMoved = 0;  // Reset "distanceMoved" to zero
        numberOfPushes = 0; // Reset "numberOfPitches" to zero
        
        if(timesToTop <= length) {
            startOver();        // Display startOver()
        }
        else {
            break;
        }
        
    }
    
    rescued();  // Display rescued()
    footer();   // Display footer()
    return 0;   // End program
    
}

