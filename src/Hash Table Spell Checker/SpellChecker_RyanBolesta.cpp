/****************************************************************************
   Author:               Ryan Bolesta
   Due Date:             November 1, 2016
   Course:               CSC402
   Professor Name:       Dr. Zhang
   Assignment:           #3
   File Name:            SpellChecker_RyanBolesta.cpp
   Purpose:              Program adds all of words.dat to a hash table and
                         then prompts for a word to spell check. application
                         then spell checks the word and finds possible
                         corrections.
*****************************************************************************/

#include <iostream>
#include <cstdlib>
#include "QuadraticProbing_RyanBolesta.h"
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

/* Spell check the word */
void spellCheck(HashTable<string>& H);

/* If word is incorrect, find any possible corrections */
void findCorrections(HashTable<string>& H, string word);

int main(){
         HashTable<string> H;
         int oldSize = 0;
         int newSize = 0;
         int elts = 0;
         string word;
         ifstream infile;
         infile.open("words.dat");

         while(infile>>word)
         {
                oldSize = H.getSize();
                H.insert(word);
                newSize = H.getSize();

                if(newSize != oldSize)
                        cout<<"Rehashing... new size is "<<newSize<<endl;
                elts++;
         }
         float loadFactor = (float(elts) / float(newSize));
         cout<<endl<<endl<<"The load factor is: "<<loadFactor<<endl;
         cout<<"There were "<<H.getCollisions()<<" collisions."<<endl;
         cout<<"Done!"<<endl<<endl;

         for(;;){
                spellCheck(H);
         }

         return 0;

}

/* Spell check the word */
void spellCheck(HashTable<string>& H){
        string word;
        cout<<"Enter a word for spell checking (enter done to exit):    ";
        cin>>word;
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        if(word == "done")
                exit(0);

        if(H.contains(word))
                cout<<"Correct! "<<H.getData(word)<<endl<<endl;
        else{
                cout<<"Wrong! ";
                findCorrections(H, word);
        }
}

/* If word is incorrect, find any possible corrections */
void findCorrections(HashTable<string>& H, string word){
        int suggestions = 0;
        string alteration = word;
        string mostRecent = " ";
        bool found = false;
        cout<<"Possible corrections: ";

        for(unsigned x = 0; x < word.length()+1; ++x)
        {
                for(char c = 'a'; c <= '{'; ++c)
        		{
                		//alteration
                                if(c == '{')
                                        c = '\'';

                                alteration = word;
                		alteration[x] = c;
                		if(H.contains(alteration) && alteration != mostRecent)
                		{
                			cout<<alteration<<", ";
                                        mostRecent = alteration;

                		}

                                string missing = word.substr(0, x) + c + word.substr(x);
        			if(H.contains(missing) && missing != mostRecent)
        			{
        				cout<<missing<<", ";
                                        mostRecent = missing;
        			}

                                if(c == '\'')
                                        c = '{';
                        }
        }

        for(unsigned x = 0; x < word.length(); ++x)
        {
                string extra = word.substr(0, x)+ word.substr(x + 1);
                if(H.contains(extra)&& extra != mostRecent)
                {
                        cout<<extra<<", ";
                        mostRecent = extra;
                }

        }
        if(mostRecent == " ")
                cout<<"***None Found***"<<endl;
        cout<<endl<<endl;
}
