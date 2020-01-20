
#include <cstdlib>
#include<bits/stdc++.h> 
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include "functions.h"
using namespace std;

int main(int numArg, char *args[])
{
	string fileName;
	int numberOfWords;
	

	if (numArg != 5) // checking for correct input when opening file
	{
		cerr << "Insufficient Arguments." << endl;
		cerr<<"Usage: ./mydictionary -d <dictionaryfile> -l <numberOfWords>"<<endl; //used to tell the user the proper invocation pattern
		return EXIT_SUCCESS;
	}
	else // checking for correct input when opening file
	{	
		for (int i=1; i<numArg; i++)
		{
			if (string(args[i])=="-d" && i+1<numArg) //before accessing the next location we have to check if it's valid 
				fileName=args[i+1];
			
			if (string(args[i])=="-l" && i+1<numArg){
				numberOfWords=stoi(args[i+1]);} 
		}
		// display this
		cout<<"This is the file used / Filename: "<<fileName<<endl;
		cout<<"Number of output words: "<<numberOfWords<<endl;

	}


	// opening file
	ifstream fin(fileName);
	//if the file is not open, the program terminates
	if(not fin.is_open())
	{
		cout<<"Can't open the file"<<fileName<<endl;
		return EXIT_FAILURE;
	}
	
	//reading from the file and storing in vector
	//create vector containg all words from dicitonary file 
	vector<string> words; 
	
	do
	{
		string readWord;
		fin>>readWord;
		words.push_back(readWord);
	}
	while(fin); //while file is open
	
	//creating the INFINITE LOOP so the program keeps asking for the input until "exit" is typed
	
	while(true)
	{
		//variable for the user inputter word
		string search_word;
		//asking the user for the word 
		cout<<"Enter the word you want to search: ";
		cin>>search_word;
		
		//if the user writes "exit" the program terminates
		if (search_word=="exit")
			{ 
				cout<< "exited the program"<< endl;
				return EXIT_SUCCESS;
			}
		
		bool word_found = false;
		bool star_is_there = false;
		bool questionmark_is_there = false;
		bool full_word_is_there = false;
		int star_pos, questionmark_pos;
		int num_of_stars, num_of_questionmarks;
		string prefix, suffix;

		
		//error checking of user input
		if (search_word.find("*") != std::string::npos ) // searching for occurence of star in the searched word
			{ 
				star_is_there = true;
				star_pos = search_word.find("*");
				
				if (star_pos == 0) // check if first element is a star, if yes then ask for imput again
				{
					cout << "" << endl;
					cout<< "invalid input: you should not start search with a star"<< endl;
					cout << "" << endl;
					continue; // if input is invalid, skip everything else in the while 
					//loop and ask for input again, this will also reset our booliean varaibles such as word found
				}
				
				num_of_stars = count_star_occurence(search_word); //if there are more than one star, ask again fo input
				if (num_of_stars > 1)
				{
					cout << "" << endl;
					cout<< "invalid input:you should not enter more than one star"<< endl;
					cout << "" << endl;
					continue;
				}

				string prefix = search_word.substr(0,star_pos); 
				string suffix = search_word.substr(star_pos+1);
				
				if (suffix != "") //check if the star is the last character
				{
					cout << "" << endl;
					cout<< "invalid input: a star needs to be the last element"<< endl;
					cout << "" << endl;
					continue;
				}
				

			}

		if (search_word.find("?") != std::string::npos) // searching for occurence of "?"" in the searched word
			{ 
				questionmark_is_there = true;
				questionmark_pos = search_word.find("?");
				

				if (questionmark_pos == 0) // check if first element is a star, if yes then ask for imput again
				{
					cout << "" << endl;
					cout<< "you should not start search with a questionmark"<< endl;
					cout << "" << endl;
					continue;
				}
				
				num_of_questionmarks = count_questionmark_occurence(search_word); //if there are more than one star, ask for imput again
				if (num_of_questionmarks > 1)
				{
					cout << "" << endl;
					cout<< "you should not enter more than one questionmark"<< endl;
					cout << "" << endl;
					continue;
				}
			}

		if (star_is_there && questionmark_is_there) //there cannot be both ? and *
		{
			cout << "" << endl;
			cout<< "you cannot enter both ? and a * in one search"<< endl;
			cout << "" << endl;
			continue;
		}

		if (not star_is_there && not questionmark_is_there)
		{
			full_word_is_there = true;
		}

		//we have three cases of input 
		/* first case is input is only word
		second case is input contains star
		third case is input contains quesiton mark*/
		if (full_word_is_there)
		{
					string x = search_word; //x is just another name for user inputted word
					int n = words.size(); //size of the word vector
					int cntr = 0; // counter for num of comparisons, this will be passed by reference into binary search functions
					// declare vector called results vector, run binary search for FULL WORDS
					vector <string> results_vector = binary_search_full_word(words, 0, n-1, x, cntr); 
					//print results
					cout << " Number of comparisons: " << cntr << endl;
					if (results_vector.size()== 0) 
						cout << (" Element not present") <<  endl; 
					else
					{
						cout << (" Number of matches:") << results_vector.size() << endl;

						cout << (" The program found the following word(s) that match your search:") <<  endl;
						cout << endl;
						//print desired number of words or less (in case there are less matches than the desired number)
						int num_to_display = numberOfWords;
						if (results_vector.size() < numberOfWords) 
						{
							num_to_display = results_vector.size();
						}
						for (int i=0; i < num_to_display; i++)
						{
							cout << results_vector[i] << endl;
						}
					}
		}
		if (star_is_there)
		{
				string x = search_word; //x is just another name for user inputted word
				int n = words.size(); //size of the word vector
				int cntr = 0; // counter for num of comparisons, this will be passed by reference into binary search functions
				// we already know star_pos from before

				//run biary search according to prefix
				vector <string> results_vector = binarySearch(words, 0, n-1, x, cntr, star_pos); 
				//prints output
				cout << " Number of comparisons: " << cntr << endl;
					if (results_vector.size()== 0) 
						cout << (" Element not present") <<  endl; 
					else
					{
						cout << (" Number of matches:") << results_vector.size() << endl;

						cout << (" The program found the following word(s) that match your search:") <<  endl;
						cout << endl;
						//print desired number of words or less (in case there are less matches than the desired number)
						int num_to_display = numberOfWords;
						if (results_vector.size() < numberOfWords) 
						{
							num_to_display = results_vector.size();
						}

						for (int i=0; i < num_to_display ; i++)
						{
							cout << results_vector[i] << endl;
						}
					}
						
		}

		if (questionmark_is_there)
		{
				string x = search_word; //x is just another name for user inputted word
				int n = words.size(); //size of the word vector
				int cntr = 0; // counter for num of comparisons, this will be passed by reference into binary search functions
			//using questionmark_pos from before 
			// run binary search for prefixes
			vector <string> results_vector1 = binarySearch(words, 0, n-1, x, cntr, questionmark_pos); 
	
			//with the output vector of binary search for prefixes, use this as input for linear search of suffixes
			vector <string> results_vector = search_suffixes(results_vector1, x, questionmark_pos,results_vector1.size() , cntr); 
			
			cout << " Number of comparisons: " << cntr << endl;
					if (results_vector.size()== 0) 
						cout << (" Element not present") <<  endl; 
					else
					{
						cout << (" Number of matches:") << results_vector.size() << endl;

						cout << (" The program found the following word(s) that match your search:") <<  endl;
						cout << endl;
						//print desired number of words or less (in case there are less matches than the desired number)
						int num_to_display = numberOfWords;
						if (results_vector.size() < numberOfWords) 
						{
							num_to_display = results_vector.size();
						}

						for (int i=0; i < num_to_display ; i++)
						{
							cout << results_vector[i] << endl;
						}
					}
		}

	}
	


} 