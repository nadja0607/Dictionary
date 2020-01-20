#include "functions.h"




//function definitions
	int count_star_occurence(string str) 
	{
  		
  		int count = 0;
  		for (int i = 0; i < str.size(); i++)
    	if (str[i] == '*')
    	count++;
  		return count;
  	}

  	int count_questionmark_occurence(string str) 
	{
  		
  		int count = 0;
  		for (int i = 0; i < str.size(); i++)
    	if (str[i] == '?')
    	count++;
  		return count;
  	}
	
  	//binary search function for full words
	vector <string> binary_search_full_word(vector<string>& arr,  int l, int r, string x, int& cntr) 
	{ 
		
		if (r >= l) { 
	        int mid = l + (r - l) / 2; //find middle element
	  
	        // If the element is present at the middle 
	        
	        cntr++; // increment counter because comparison was made
	        if (arr[mid] == x)
	        {	
	        	vector <string> results_vector;
	        	results_vector.push_back(arr[mid]);
	            return results_vector; //return vector with the word searched
			}	  
	        // If element is smaller than mid, then it can only be present in left subarray 
	        //increment counter because comparison was made
	        cntr++;
	        if (arr[mid] > x) 
	            return binary_search_full_word(arr, l, mid - 1, x, cntr); 
	  
	        // Else the element can only be present in right subarray 
	        return binary_search_full_word(arr, mid + 1, r, x, cntr); 
       	}
		vector <string> results_vector; //return empty vector
		return results_vector;
	}

	//binary search function for words with star
		vector <string> binarySearch(vector<string>& arr,  int l, int r, string x, int& cntr, int star_pos) 
	{ 
		
		if (r >= l) { 
	        int mid = l + (r - l) / 2; //find middle element
	        // If the element is present at the middle 
	        // itself
	        
	        cntr++;
	        if (arr[mid].substr(0,star_pos) == x.substr(0,star_pos)) 
	        {
	            vector<string> results_vector;
	        
	        	int i_upper = mid;

	        	while (arr[i_upper].substr(0,star_pos) == arr[mid].substr(0,star_pos))
	        	{
	        		i_upper--;
	        		cntr++;
	        	} 

		        i_upper = i_upper+1; // to get the correct index of upper bound

		        int i_lower = mid;

		        	while (arr[i_lower].substr(0,star_pos) == arr[mid].substr(0,star_pos))
		        	{
		        		i_lower++;
		        		cntr++;
		        	} 

		        i_lower = i_lower-1; // to get the correct index of upper bound

		        for(int e = i_upper; e <= i_lower; e++)
			        {
			        	results_vector.push_back(arr[e]);
			        	cntr++;
			        }

		        return results_vector; 
	  		}
	        // If element is smaller than mid, then 
	        // it can only be present in left subarray 
	        cntr++;
	        if (arr[mid].substr(0,star_pos) > x.substr(0,star_pos)) 
	            return binarySearch(arr, l, mid - 1, x, cntr, star_pos); 
	  
	        // Else the element can only be present 
	        // in right subarray 
	        return binarySearch(arr, mid + 1, r, x, cntr, star_pos); 
       	}
		vector<string> results_vector;
		return results_vector; 
	} 

//function that gets as input sorted vector with desirable prefixes
//it runs loop over each element and returns a vector with matching sufixes
	vector <string> search_suffixes(vector<string>& arr, string x, int star_pos,int vect_len, int& cntr) 
	{ 
		vector<string> results_vector;
		for (int i=0; i < vect_len; i++)
			{
				
				cntr++;
				
				if (arr[i].substr(star_pos+1) == x.substr(star_pos+1))
				{

					cntr++;
					results_vector.push_back(arr[i]);
					
				}
			}

		return results_vector; 
	}