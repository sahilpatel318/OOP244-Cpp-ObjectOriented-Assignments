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

#ifndef SENECA_MOVIE_H_   // If not defined, define the header guard to prevent multiple inclusion of this file
#define SENECA_MOVIES_H_  // Define the header guard for SENECA_MOVIES_H_

#ifndef NAMESPACE_MOVIE_H  // Another header guard for the namespace section
#define NAMESPACE_MOVIE_H  // Define the header guard for NAMESPACE_MOVIE_H

// Start of the 'seneca' namespace
namespace seneca {

    // Definition of the Movie structure that holds information about a movie
    struct Movie {
        char m_title[128];         // Movie title (up to 128 characters)
        int m_year;                // Release year of the movie
        char m_rating[6];          // Movie rating (up to 5 characters)
        int m_duration;            // Duration of the movie in minutes
        char m_genres[10][11];     // Array to store up to 10 genres, each genre having up to 10 characters
        float m_consumerRating;    // Consumer rating of the movie 
    };

    // Function to load movie data (likely from a file or database)
    // Returns true if loading is successful, false otherwise
    bool loadMovies();

    // Function to check if a movie contains a specific genre
    // Takes a pointer to a Movie structure and the genre to check as arguments
    // Returns true if the movie has the given genre, false otherwise
    bool hasGenre(const Movie* mvp, const char genre[]);

    // Function to display a movie's information
    // Takes a pointer to a Movie structure as an argument
    void displayMovie(const Movie* mvp);

    // Function to display all movies that match a given genre
    // Takes the genre to search for as an argument
    void displayMoviesWithGenre(const char genre[]);

}  // End of the 'seneca' namespace

#endif  // End of NAMESPACE_MOVIE_H header guard
#endif  // End of SENECA_MOVIES_H_ header guard
