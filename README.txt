Data Structures
CS-UH 1050 – Spring 2019
Date:February 26th 2019
---------------------------------------------------------------------------------------------------------------------
Project Name: 
	My Dictionary
---------------------------------------------------------------------------------------------------------------------
Tech/framework used:
	Sublime Text Editor
---------------------------------------------------------------------------------------------------------------------
Prerequisites:
	Linux/FreeBSD C++ environment
---------------------------------------------------------------------------------------------------------------------
Description: 
	In this project, I developed a speller application named My Dictionary, that can help a user lookup
	English words in the provided dictionaries. 
	The program takes the name of the dictionary to be used as a parameter in its command line.
	The application is invoked as follows:
	
			mymachine-promt >> ./mydictionary -d <dictionaryFile> -l <numOfWordsInOutput>

		*flag -d indicates that the lexeme that follows is the file name of the dictionary to be used 
		*flag -l indicates the number that follows is the maximum number of results printed for the output

	Once the program starts, it presents the user with a prompt. 
	Every time, the user types in a query, the application generates and 
	prints out the result(s)and it expects the next query. 
	*The program terminates once the user types "exit" at the prompt.

	The user can search for specific word(s). 
	The program provides three key functionalities:
		• tell whether a user-provided word is included in the dictionary used
		• list all the words of the dictionary that commence with a user-provided prefix
			prefix chosen by entering *
		• list all the words of the dictionary that match the input up to one character.
			missing letter replaced with ?
---------------------------------------------------------------------------------------------------------------------


	
