#include <stdio.h>

/*Functions used in code*/
void info(char *x, char *y, char *z);
void pyramid(char a, char b, char c);

/*Main function*/
void main (void)
{
	char opt1, opt2, opt3;			/*Declares the chars that the users options are assigned to*/
	
	info(&opt1, &opt2, &opt3);		/*Calls the info function*/
	pyramid(opt1, opt2, opt3);		/*Calls the pyramid function*/
}

/*This function prints instructions to the user, gets the options from the user and then outputs the options*/
void info(char *x, char *y, char *z)
{
	/*Prints instruction to the user and gets the input*/
	char opt[2];
	printf("Enter 3 characters: ");
	scanf("%s", opt);
	
	/*This changes the value at the memory address. Pointers have been used so that multiple characters can be returned*/
	*x = opt[0];
	*y = opt[1];
	*z = opt[2];
}

/*Functions takes the characters as input and uses them to print pyramid*/
void pyramid(char a, char b, char c)
{
	
	printf("\n     %c", a);
	printf("\n    %c%c%c", a, b, a);
	printf("\n   %c%c%c%c%c", a, b, c, b, a);
	printf("\n  %c%c%c%c%c%c%c", a, b, c, c, c, b, a);
	printf("\n %c%c%c%c%c%c%c%c%c", a, b, c, c, c, c, c, b, a);
	printf("\n%c%c%c%c%c%c%c%c%c%c%c", a, b, c, c, c, c, c, c, c, b, a);
}
