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

#define _CRT_SECURE_NO_WARNINGS  // Disable warnings for unsafe functions in Visual Studio
#include "file.h"  // Include the file that contains function prototypes related to file operations
#include <stdio.h>  // Standard I/O library for file handling

namespace seneca {
    FILE* fptr;  // File pointer to handle the file operations globally within the namespace

    // opens the data file and returns true is successful
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");  // Open the file in read mode
        return fptr != NULL;  // Return true if the file opened successfully, otherwise false
    }

    // closes the data file
    void closeFile() {
        if (fptr) fclose(fptr);  // Close the file if it was successfully opened
    }

    // reads the title of the movie from the global fptr File pointer
    // returns true if successful
    bool readTitle(char title[]) {
        return fscanf(fptr, "%[^(](", title) == 1;  // Read characters until '(' is encountered and store in title
    }

    // reads the year of the movie from the global fptr File pointer
    // returns true if successful
    bool readYear(int* year) {
        return fscanf(fptr, "%d)", year) == 1;  // Read the year as an integer until ')' is encountered
    }

    // reads the rating of the movie from the global fptr File pointer
    // returns true if successful
    bool readMovieRating(char rating[]) {
        return fscanf(fptr, " %[^|]|", rating) == 1;  // Read characters until '|' is encountered and store in rating
    }

    // reads the duration of the movie from the global fptr File pointer
    // returns true if successful
    bool readDuration(int* duration) {
        return fscanf(fptr, "%d|", duration) == 1;  // Read the movie duration as an integer until '|' is encountered
    }

    // reads the genres of the movie from the global fptr File pointer
    // returns true if successful
    bool readGenres(char genre[][11]) {
        char genres[256];  // Temporary array to store the entire genre string from the file
        int gi = 0;  // Index for genres array
        int i = 0;   // Index for genre rows
        int j = 0;   // Index for genre columns
        bool res = fscanf(fptr, " %[^|]|", genres);  // Read the genre string until '|' is encountered

        if (res) {  // If reading was successful, process the genre string
            res = false;  // Reset the result flag
            while (genres[gi]) {  // Loop through the genre string
                if (genres[gi] != ',') {  // If the character is not a comma, copy it to the current genre
                    genre[i][j++] = genres[gi++];
                    res = true;  // Set the result flag to true since we are copying valid data
                }
                else {
                    genre[i][j] = '\0';  // End the current genre string
                    i++;  // Move to the next genre
                    gi++;  // Skip the comma
                    j = 0;  // Reset the column index for the next genre
                }
            }
        }
        genre[i++][j] = '\0';  // End the last genre string
        genre[i][0] = '\0';    // NULL terminate the array of genre strings
        return res;  // Return whether genres were successfully read
    }

    // reads the consumerRating of the movie from the global fptr File pointer
    // returns true if successful
    bool readConsumerRating(float* rating) {
        return fscanf(fptr, "%f\n", rating) == 1;  // Read the consumer rating as a floating-point number
    }
}
