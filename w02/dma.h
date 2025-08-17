/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)

Full Name  : Sahil Hareshbhai Patel
Student ID#: 173793225
Email      : shpatel27@myseneca.ca
Section    : NDD
Date       : 18-09-2024

 Authenticity Declaration:

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_DMA_H
#define SENECA_DMA_H
namespace seneca {
    struct Contact {
        char
            m_name[21],
            m_lastname[31];
        long long
            m_phoneNumber;
    };

    /// <summary>
    /// Receives an unknown number of double numbers from the console and prints them in reverse order.
    /// </summary>
    void reverse();

    /// <summary>
    /// Creates a Contact compound type dynamically and gets its content from the console, then returns its address.
    /// </summary>
    /// <returns>Contact*: The address of the dynamically allocated Contact</returns>
    Contact* getContact();

    /// <summary>
    /// Prints a Contact in a line
    /// </summary>
    /// <param name="C">const reference of the Contact to be printed</param>
    void display(const Contact& C);

    /// <summary>
    /// Receives the address of a dynamically allocated Contact and removes it from memory.
    /// </summary>
    /// <param name="C">Contact*: The address of the Contact to be deallocated</param>
    void deallocate(Contact* C);

    /// <summary>
    /// Empties the content of the Contact received by reference by setting the name and last name to empty strings and the phone number to zero.
    /// </summary>
    /// <param name="C">Contact&: Reference of a Contact to be emptied</param>
    void setEmpty(Contact& C);
}
#endif // !SENECA_DMA_H

