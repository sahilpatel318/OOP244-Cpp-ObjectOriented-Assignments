/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #1 (P1)

Full Name  : Sahil Hareshbhai Patel
Student ID#: 173793225
Email      : shpatel27@myseneca.ca
Section    : NDD
Date       : 11-09-2024

 Authenticity Declaration:

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS  // Disables warnings for unsafe functions in Visual Studio

#include <iostream>  // For input and output operations
#include <cstring>   // For string manipulation functions (like `strcmp`)
#include <cstdio>    // For C standard input/output functions

#include "movie.h"   // Include custom header file for handling movie-related functionalities
#include "utils.h"   // Include custom utility functions (like flushing keys, user prompts, etc.)

using namespace std;  // Allows usage of standard library without prefixing `std::`
using namespace seneca;  // Allows usage of `seneca` namespace (likely contains movie-related functions)

// Main function
int main() {
    bool done = false;         // Flag to control the loop, starts with `false`
    char genre[128];           // Array to store the genre entered by the user (128 characters max)

    loadMovies();              // Load movies from a file or database at the beginning of the program

    cout << "Welcome to 50 top movies of all times \"genre\" search." << endl << endl;  // Welcome message

    // Main loop to keep searching until the user wants to stop
    while (!done) {
        cout << "Enter the movie genre to start the search: ";  // Prompt the user for a movie genre
        cin >> genre;                                           // Read the user's input (genre)
        flushkeys();                                            // Clears extra input from the input buffer

        displayMoviesWithGenre(genre);  // Calls the function to display movies with the entered genre

        // Ask if the user wants to perform another search
        cout << "Do another search? (Y)es: ";
        done = !yes();  // Calls `yes()` function; loop continues if user responds 'Y'
        cout << endl;   // Prints a new line for better output formatting
    }

    cout << "Goodbye!" << endl;  // Exit message
    return 0;  // Return 0 to indicate successful program execution
}
