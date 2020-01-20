
#include <cstdlib>
#include<bits/stdc++.h> 
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
using namespace std; 

int count_star_occurence(string str);
int count_questionmark_occurence(string str);
vector <string> binary_search_full_word(vector<string>& arr,  int l, int r, string x, int& cntr);
vector <string> binarySearch(vector<string>& arr,  int l, int r, string x, int& cntr, int star_pos);
vector <string> search_suffixes(vector<string>& arr, string x, int star_pos,int vect_len, int& cntr);
