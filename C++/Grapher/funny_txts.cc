#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include "grapher.hpp"

using namespace std;

string quote(){

string quoteBank[15] = {"        	                   Little help from a little friend        	         		 ",
			"        		               Leave your tangent to me!				         ",
			" 	                 	       Smarter than you think :)					 ",
			"   'We cannot solve our problems with the same thinking we used when we created them.' ~ A.Einstein     ",
			"                       ?emem a fo edis rehto eht no eb ot leef ti seod woH                              ", 
			"                      'We need to be strong and face the example.' ~ me B)                              ",
			"                                 Brace yourselves! Modulus is coming.                                   ",
			"                                           'Jeszcze jak!'                                               ",
			"                               Quadratic equation? Nothing easier bruv!                                 ",
			"     I hate when someone talks about integrals. Why are you so prejudiced about discrete charts??       ",
			"                             Taylor series? Meh. Never heard of that lol                                ",
			"                   I'm an alien. I'm a legal alien. I'm a math artist in ur Debian.                     ",
			"                                  HAH! @ed! Watch out before i # u!                                     ",
			"                                     Right there at your command!                                       ",
			"                                 What shall I draw for You today sir?                                   "};

	srand (time(NULL));
	int i = rand() % 15;

	return quoteBank[i];

}
