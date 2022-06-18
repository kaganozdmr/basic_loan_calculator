
#include <stdio.h>
#include <stdlib.h>

void chooseLoanSpec();
int chooseOption();
void func(int loan, int month);
void fileOperation(int loan, double paid, int month, double monthly_payment, double firstmonthly);

int main(int argc, char *argv[])
{	
	chooseLoanSpec();
	return 0;
}

void chooseLoanSpec(){
	int loan, month;
	printf("How much credit do you want to use? \n");
	scanf(" %d", &loan);
	printf("How many months will you pay back? \n");
	scanf(" %d", &month);
	func(loan, month);
}

int chooseOption(){
	int option;
	printf("6 months insurance fee is 100. \n 12 months insurance fee is 200.\n 24 months insurance fee is 400. \n The insurance cost for 36 months or more is 1200.");
	printf("Choose interest rate \n 1-You will be insured(0.10) \n 2-You will not be insured(0.17) \n Your choice :  ");
	scanf(" %d", &option);
	if(option == 1 ) return 1;
	else if (option == 2 ) return 2;
	else { 
		printf("Please enter 1 or 2, the program is running from the beginning. \n \n");
		chooseOption();
	}	
}

void func(int loan, int month){
	int todaydate;
	double monthly_payment, paid, firstmonthly, lastpayment;
	int option = chooseOption();
	if (option == 1)
	{	
		paid = loan * (1 + (((float)month / 12) * 0.1));
		if (month >= 6 && month <12) paid = paid + 100;
		else if (month >= 12 && month < 24 ) paid = paid + 200;
		else if (month >= 24 && month < 36) paid = paid + 400;
		else if (month < 6 ) paid = paid;
		else paid = paid + 1200;
		int i;
		
		monthly_payment = paid / month;
		printf("\n Amount of credit you use: %.2d \n Loan amount you will pay: %.2f \n", loan , paid);
		printf("What date is today ? ");
		scanf("%d", &todaydate);
		firstmonthly = (monthly_payment / 30)*(30-todaydate);
		printf("1 .month amount to be paid  :>> %.2f \n", firstmonthly);
		for (i = 2; i <= month-1 ; i++)
		{
			printf("%d .month amount to be paid  :>> %.2f \n", i, monthly_payment);
		}
		lastpayment = paid - (monthly_payment * (month-2)) - firstmonthly;
		printf("%d .month amount to be paid  :>> %.2f \n",month ,lastpayment);
	}
	else
	{

		int i;
		paid = loan * (1 + (((float)month / 12) * 0.17));
		printf("Total amount payable %.2f \n", paid);
		monthly_payment = paid / month;
		printf(" \n Amount of credit you use: %d \n Loan amount you will pay:  %.2f \n", loan , paid);
		printf("What date is today ? ");
		scanf("%d", &todaydate);
		firstmonthly = (monthly_payment / 30)*(30-todaydate);
		printf("1 .month amount to be paid  :>> %.2f \n", firstmonthly);
		for (i = 2; i <= month-1 ; i++)
		{
			printf("%d . month amount to be paid  :>> %.2f \n", i, monthly_payment);
		}
		lastpayment = paid - (monthly_payment * (month-2)) - firstmonthly;
		printf("%d .month amount to be paid  :>> %.2f \n",month ,lastpayment);
	}
	fileOperation(loan, paid, month, monthly_payment, firstmonthly);
}

void fileOperation(int loan, double paid, int month, double monthly_payment, double firstmonthly){
	int s, j;
	double lastpayment;
	printf("Would you like to save the installment table to your computer? : \n 1-Save \n 2-Not save ?\n Your choice :  ");
	scanf("%d",&s);
	if(s==1){
		FILE *file = fopen("file.txt", "w");
		fprintf(file,"Amount of loan received: %.2d \nLoan amount to be paid %.2f \n" , loan, paid);
		fprintf(file,"1 .month amount to be paid  :>> %.2f \n", firstmonthly);
		for (j = 2; j <= month-1; j++)
		{
			fprintf(file,"%d . month amount to be paid  :>> %.2f \n", j, monthly_payment);
		}
		lastpayment = paid - (monthly_payment * (month-2)) - firstmonthly;
		fprintf(file,"%d .month amount to be paid  :>> %.2f \n",month ,lastpayment);
		printf("File saved. \nThe program has ended.");
		fclose(file);
	}
	else if (s =! 1) {
		printf("The program has ended.");
	}
}
