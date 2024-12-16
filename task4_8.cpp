// task4_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string> 
#include <iostream>
using namespace std;


char english[] = { ' ', 'A', 'B', 'C', 'D',
                  'E', 'F', 'G', 'H',
                  'I', 'J','K', 'L', 'M', 'N',
                  'O', 'P', 'Q', 'R',
                  'S', 'T', 'U', 'V',
                  'W','X','Y','Z', 0};


char english_extended[] = { ' ', 'A', 'B', 'C', 'D',
                            'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                            'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                            ',', '.', '!', '?', ':', ';', '-', '_', '(', ')', '"', '\'',
                            0 };


// bey3ed the number of characters in an array
int size_of(char arr[]) {
    int size = 0;
    for (int i = 0; arr[i] != 0; i++) { //le8ayet ma el terminator yeb2a be-zero
        size++;
    }
    return size;
}

int findNo(char c, char arr[]) {
    for (int i = 0; i < size_of(arr); i++) {
        if (arr[i] == c) return i; //returns the index i where the match is found
    }
}

// el bey decipher
string decipher(string& word, int a, int b, char arr[]) {
    int n = size_of(arr);
    string collect; // stores the decrypted text
    int a_inv;
    int found;
    for (int i = 0; i < 27; i++)
    {
        found = (a * i) % 27; // (a * a^-1) % n 

        if (found == 1)
            a_inv = i; // a inverse found, a_inv = 4

    }


    for (char letter : word) { // beylef 3ala kol 7arf fe word, and word is the inputted text
        collect += arr[a_inv * (findNo(letter, arr) - b) % n]; //affine decypher formula
    }
    return collect;
}


int main()
{
    string word;
    int a, b;

    cout << "Enter the text to decipher: ";
    getline(cin, word);

    cout << "Enter key a: ";
    cin >> a;

    cout << "Enter key b: ";
    cin >> b;

    cout << decipher(word, a, b, english);
    return 0;
}