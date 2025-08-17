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
#include "movie.h"  // Include movie-related function and structure declarations
#include "file.h"   // Include file-handling functions for loading movie data
#include "utils.h"  // Include utility functions like `toLowerCase`
#include <iostream> // For input/output operations
#include <cstring>  // For string manipulation functions like `strstr`
#include <cstdio>   // Standard C I/O functions

using namespace std;

namespace seneca {
    Movie movies[50];  // Array to store up to 50 movies

    // Loads movies from the data file into the movies array
    bool loadMovies() {
        Movie mv;       // Temporary variable to hold movie data while reading from the file
        int mnum = 0;   // Counter for the number of movies read
        bool ok = true; // Flag to check if reading is successful
        if (openFile("movies.dat")) {  // Open the data file
            while (ok && mnum < 50) {  // Loop until either reading fails or 50 movies are loaded
                ok = readTitle(mv.m_title) &&
                    readYear(&mv.m_year) &&
                    readMovieRating(mv.m_rating) &&
                    readDuration(&mv.m_duration) &&
                    readGenres(mv.m_genres) &&
                    readConsumerRating(&mv.m_consumerRating);  // Read movie data step by step
                if (ok) movies[mnum++] = mv;  // If reading is successful, add movie to the array
            }
            closeFile();  // Close the file after reading
        }
        return mnum == 50;  // Return true if 50 movies were successfully loaded
    }

    // returns true if the genre arg is substring of any of the
    // genres of the target of the mvp (Movie*) argument
    bool hasGenre(const Movie* mvp, const char genre[]) {
        int i = 0;
        char userGenre[11] = {};  // Array to store the user's genre in lowercase
        char movieGenre[11] = {}; // Array to store the movie's genre in lowercase
        bool found = false;
        while (!found && mvp->m_genres[i][0]) {  // Loop through the movie's genres until a match is found
            toLowerCase(userGenre, genre);       // Convert the user's genre to lowercase
            toLowerCase(movieGenre, mvp->m_genres[i]);  // Convert the movie's genre to lowercase
            if (strstr(movieGenre, userGenre)) {  // Check if user's genre is a substring of the movie's genre
                found = true;  // If a match is found, set found to true
            }
            i++;  // Move to the next genre in the movie's genre array
        }
        return found;  // Return whether a matching genre was found
    }

    // displays the movie info
    void displayMovie(const Movie* mvp) {
        int i = 1;  // Start with the second genre, as the first is displayed directly
        cout << mvp->m_title << " [" << mvp->m_year << "], "  // Display title and year
            << mvp->m_rating << ", duration: " << mvp->m_duration << " minutes, Rating: " << mvp->m_consumerRating << "/10"
            << endl << "    (" << mvp->m_genres[0];  // Display the first genre
        while (mvp->m_genres[i][0]) {  // Continue displaying genres as long as they are non-empty
            cout << ", " << mvp->m_genres[i++];  // Display each genre, separated by commas
        }
        cout << ")" << endl;  // Close the genre list
    }

    // displays all the movies containing the genre arg
    void displayMoviesWithGenre(const char genre[]) {
        int i, j;
        for (i = 0, j = 1; i < 50; i++) {  // Iterate through all 50 movies
            if (hasGenre(&movies[i], genre)) {  // If the movie has the specified genre
                cout << j++ << "- ";  // Number the movie in the list
                displayMovie(&movies[i]);  // Display the movie's details
            }
        }
        if (j == 1) {  // If no movies matched the genre
            cout << "No match found for: " << genre << endl;  // Display a "no match" message
        }
    }
}
