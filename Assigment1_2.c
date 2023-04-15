#include <stdio.h>

/*Functions included in program*/
void getinfo(char *getvehicle, float *getbuiltup, float *getsingle, float *getdual);
float fuel_a(float builtupcalc, float singlecalc, float dualcalc);
float fuel_b(float builtupcalc, float singlecalc, float dualcalc);
float calc_salary(float total_fuel_cost);
void calc_total(float total_fuel_cost, float get_salary);

int main(void)
{
	/*Declares the variables*/
	char vehicle, a, b;
	float builtup, single, dual, total_fuel, salary;
	
	/*Step 1: Runs function to get the information from user*/
	getinfo(&vehicle, &builtup, &single, &dual);
	
	/*Step 2 (If option A selected): If statement that if true
	runs function to calculate total cost of fuel*/
	if(vehicle == 'A')
	{
		total_fuel = fuel_a(builtup, single, dual);
	}
	
	/*Step 2 (If option B chosen): If statement that if true
	runs function to calculate total cost of fuel*/
	if(vehicle == 'B')
	{
		total_fuel = fuel_b(builtup, single, dual);
	}
	
	/*Step 3: Runs function to calculate the salary*/
	salary = calc_salary(total_fuel);
	
	/*Step 4: Calculates the total cost overall*/
	calc_total(total_fuel, salary);
}

	/*This function is intended to get the input from the user and
	then return them to the main function. Uses pointers so
	that multiple values could be returned.*/
void getinfo(char *getvehicle, float *getbuiltup, float *getsingle, float *getdual)
{
	/*Gets the vehicle type from the user and flushes so that future use of
	scanf works correctly*/
	printf("Enter A or B car type: ");
	scanf("%s", *&getvehicle);
	fflush(stdin);
	
	/*Makes program more robust. Converts incorrect case to uppercase*/
	if(*getvehicle == 'a')
	{
		*getvehicle = 'A';
	}
	
	if(*getvehicle == 'b')
	{
		*getvehicle = 'B';
	}
	
	/*Gets distances from user in miles*/
	printf("Enter distance traveled in built up areas in miles: ");
	scanf("%f", *&getbuiltup);
	fflush(stdin);
	printf("Enter distance traveled in single cariageway: ");
	scanf("%f", *&getsingle);
	fflush(stdin);
	printf("Enter distance traveled in dual cariageway or motorway: ");
	scanf("%f", *&getdual);
	fflush(stdin);
}

/*Function to calculate total cost of fuel if vehicle A has been selected and
return result*/
float fuel_a(float builtupcalc, float singlecalc, float dualcalc)
{
	float final;
	
	/*These floats contain how many miles per gallon for vehicle A.
	They are also used later in the function*/
	float a = 40;			/*Shows how many miles per gallon in built up areas*/
	float b = 50;			/*Shows how many miles per gallon in single carriageway*/
	float c = 60;			/*Shows how many miles per gallon in built up dual carriageway*/
	float litre = 4.54609;	/*Conversion from mile to litre*/
	float price = 1.5;		/*Price in GBP for 1 litre*/
	
	/*Calculates the final cost of the fuel*/
	builtupcalc = (builtupcalc * (1/a));
	singlecalc = (singlecalc * (1/b));
	dualcalc = (dualcalc * (1/c));
	
	final = builtupcalc + singlecalc +dualcalc;
	final = final * litre;
	final = final * price;
	
	/*Prints result. Return result to main function*/
	printf("The total cost of fuel for the journey is: %.2f GBP\n", final);
	return final;		// Return ends the function
}

/*Function to calculate total cost of fuel if vehicle B has been selected
and return result*/
float fuel_b(float builtupcalc, float singlecalc, float dualcalc)
{
	float final;
	
	/*These floats contain how many miles per gallon for vehicle B. They are also used later
	in the function*/
	float a = 45;			/*Shows how many miles per gallon in built up areas*/
	float b = 55;			/*Shows how many miles per gallon in single carriageways*/
	float c = 65;			/*Shows how many miles per gallon in dual carriageways*/
	float litre = 4.54609;	/*Conversion from mile to litre*/
	float price = 1.3;		/*Price in GBP for 1 litre*/
	
	/*Calculates the final cost of the fuel*/
	builtupcalc = (builtupcalc * (1/a));
	singlecalc = (singlecalc * (1/b));
	dualcalc = (dualcalc * (1/c));
	
	final = builtupcalc + singlecalc +dualcalc;
	final = final * litre;
	final = final * price;
	
	/*Prints result. Return result to main function*/
	printf("The total cost of fuel for the journey is: %.2f GBP\n", final);
	return final;		// Return ends the function
}

/*Function to calculate the salary*/
float calc_salary(float total_fuel_cost)
{
	float salary;
	
	/*If statements determines how much they would have earned from work
	up to their current level of pay and then calcualtes everything after that*/
	if(total_fuel_cost >= 60)
	{
		total_fuel_cost = total_fuel_cost - 60;
		salary = 140;
		salary = salary + (5 * total_fuel_cost);
		total_fuel_cost = 0;		/*Prevents it from causeing following if statements to become true*/
	}
	
	if(total_fuel_cost >= 30)
	{
		total_fuel_cost = total_fuel_cost - 30;
		salary = 50;
		salary = salary + (3 * total_fuel_cost);
		total_fuel_cost = 0;		/*Prevents it from causeing following if statements to become true*/
	}
	
	if(total_fuel_cost >= 10)
	{
		total_fuel_cost = total_fuel_cost - 10;
		salary = 10;
		salary = salary + (2 * total_fuel_cost);
		total_fuel_cost = 0;		/*Prevents it from causeing following if statements to become true*/
	}
	
	if(total_fuel_cost > 0)
	{
		salary = total_fuel_cost;
	}
	
	/*Prints result to user and returns to main function*/
	printf("The total salary is: %.2f GBP\n", salary);
	return salary;
}

/*Function takes the total costs of fuel and salary and outputs total to user*/
void calc_total(float total_fuel_cost, float get_salary)
{
	float overall_cost = total_fuel_cost + get_salary;
	printf("The total cost of the journey is: %.2f GBP", overall_cost);
}
