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

#ifndef SENECA_FILE_H_  // Include guard to prevent multiple inclusions of this header file
#define SENECA_FILE_H_  // Define the guard

#ifndef NAMESPACE_FILE_H  // Secondary include guard to ensure that the namespace is defined only once
#define NAMESPACE_FILE_H

namespace seneca {  // Start of the seneca namespace, which contains all file-related functions

    // Opens the file with the given filename in read mode.
    // Returns true if the file opens successfully, otherwise false.
    bool openFile(const char filename[]);

    // Closes the file that was opened by openFile().
    void closeFile();

    // Reads the title of the movie from the file.
    // Takes a char array (title) as an argument and stores the title.
    // Returns true if reading is successful, otherwise false.
    bool readTitle(char title[]);

    // Reads the release year of the movie from the file.
    // Takes a pointer to an integer (year) and stores the year.
    // Returns true if reading is successful, otherwise false.
    bool readYear(int* year);

    // Reads the movie rating from the file.
    // Takes a char array (rating) to store the movie's rating.
    // Returns true if reading is successful, otherwise false.
    bool readMovieRating(char rating[]);

    // Reads the movie's duration from the file.
    // Takes a pointer to an integer (duration) and stores the duration.
    // Returns true if reading is successful, otherwise false.
    bool readDuration(int* duration);

    // Reads the genres of the movie from the file.
    // Takes a 2D char array (genres) to store up to 10 genres, each up to 10 characters.
    // Returns true if reading is successful, otherwise false.
    bool readGenres(char genres[][11]);

    // Reads the consumer rating of the movie from the file.
    // Takes a pointer to a float (rating) and stores the consumer rating.
    // Returns true if reading is successful, otherwise false.
    bool readConsumerRating(float* rating);

}  // End of the seneca namespace

#endif  // End of the secondary include guard
#endif  // End of the main include guard (SENECA_FILE_H_)
