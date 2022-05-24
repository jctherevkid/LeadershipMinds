//Including stdio.h and Authors.h since both are required to run this code
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Authors.h"

/*
* These functions will be called by the main function. Most of these split off to lower
* the number of decisions per function, so as to make the program more understandable. 
*/

int questions(int numQuestions);
int oneThrough4Val(int validate);
char aThroughDVal(char answer);
char tOrFVal(char answer);
void exportAnswer(char aValue[100]);
/* 
The below functions use the answer input to assign the appropriated weighted values to the author. 
*/
int question1Values(int* authors, char answer);
int question2Values(int* authors, char answer);
int question3Values(int* authors, char answer);
int question4Values(int* authors, char answer);
/*
Final calc will assign a number, 0-3, to be the final answer. Here are the value assignments to each author:
Stephen Covey  = 0
Dale Carnegie  = 1
Jocko Willink  = 2
Alexis Ohanian = 3
*/
int finalCalc(int* summary);
int repeatQuiz();

typedef struct QandA
{
	char question[100];
	char answerA[100];
	char answerB[100];
	char answerC[100];
	char answerD[100];
}quiz;

//Define questions and answers
struct QandA Question1;
struct QandA Question2;
struct QandA Question3;
struct QandA Question4;

//Begin main function

int main(int argc, char** argv)
{
	//Variable initialization
	int numberOfQuestions;
	int finalAnswer = 0;
	int	goAgain = 1;
	
	//Introduce the application
	printf("Welcome to Leadership Minds. This is an interactive quiz program that will help pair you with an author that matches your style.");
	
	//This goto option allows me to come back to the top rather than just exit when the error handling hit
	while (goAgain) {
		printf("You get to choose how in depth this quiz is. How many questions would you like asked?\n(Choose a number between 1 and 4)\n");
		scanf_s(" %d", &numberOfQuestions);
		//while loop to error handle user input
		numberOfQuestions = oneThrough4Val(numberOfQuestions);
		//now call the function that asks the questions, and assigns the author's value to the finalAnswer
		finalAnswer = questions(numberOfQuestions);

		//now the functions have asked the questions and calculated the result and returned it here into final answer
		//Have 4 different endings, one for each author
		if (finalAnswer == 0) {
			printf("%s\n", SCOVEY);
			//For the users records - write to an exterior file
			exportAnswer(SCOVEY);
		}
		else if (finalAnswer == 1) {
			printf("%s\n", DCARNEGIE);
			//For the users records - write to an exterior file
			exportAnswer(DCARNEGIE);
		}
		else if (finalAnswer == 2) {
			printf("%s\n", JWILLINK);
			//For the users records - write to an exterior file
			exportAnswer(JWILLINK);
		}
		else {
			printf("%s\n", AOHANIAN);
			//For the users records - write to an exterior file
			exportAnswer(AOHANIAN);
		}
		
		//next invite the user to go again
		goAgain = repeatQuiz();
		
	}

	printf("Thanks for taking the time to go through the quiz! Ending....\n");
	
	return 0;
}

//Filling out the functions so they work when they are called

int questions(int numQuestions)
{
	//local variable declaration
	char answer;
	int authors[4] = { 0, 0, 0, 0 };
	int name;
	//question definitions
	strcpy_s(Question1.question,100, "Choose 1: What kind of leader best describes what kind of leader you want to be?\n");
	strcpy_s(Question2.question,100, "I think that the team members I manage: \n");
	strcpy_s(Question3.question, 100, "True(T) or False(F): Employees and team members should be almost entirely autonomous: \n");
	strcpy_s(Question4.question,10, "I am: \n");
	//define answers for question 1
	strcpy_s(Question1.answerA,50, "A: A principled leader\n");
	strcpy_s(Question1.answerB,50, "B: A well liked leader\n");
	strcpy_s(Question1.answerC,50, "C: A no-nonsense get-to-the-point leader\n");
	strcpy_s(Question1.answerD,50, "D: A breakthrough and innovative leader\n");
	//Define answers for question 2
	strcpy_s(Question2.answerA, 80,"A: Need guidance and a larger perspective\n");
	strcpy_s(Question2.answerB,80, "B: Have great potential if they are given the right, positive nudge\n");
	strcpy_s(Question2.answerC,80, "C: Should rise up to the task and take it as if it was their own\n");
	strcpy_s(Question2.answerD,80, "D: Are only the right team members if they think a little differently\n");
	/*No answers defined as it's true of false for question 3
	/ Define answers for question 4 */
	strcpy_s(Question4.answerA,80, "A: New to the workforce, but want to be a manager soon\n");
	strcpy_s(Question4.answerB,80, "B: Want to lead well not only at work but at home and in other situations\n");
	strcpy_s(Question4.answerC,80, "C: A leader who wants his team to self direct\n");
	strcpy_s(Question4.answerD,80, "D: Focused on coming in with a new style in leadership\n");
	
	//Printed question with A-D options
	printf("%s", Question1.question);
	printf("%s%s%s%s", Question1.answerA, Question1.answerB, Question1.answerC, Question1.answerD);
	
	//now to get their input
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	
	//validation function
	answer = aThroughDVal(answer);
	
	//assign to numeric value associated with the author
	*authors = question1Values(authors, answer);

	
	//check to see if more questions need to be asked
	if (numQuestions < 2) {
		name = finalCalc(authors);
		return name;
	}
	
	//2nd question
	printf("%s", Question2.question);
	
	//now give A-D options
	printf("%s%s%s%s", Question2.answerA, Question2.answerB,Question2.answerC,Question2.answerD);
	
	//now to get their input
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	
	//validation function
	answer = aThroughDVal(answer);
	
	//assign to numeric value associated with the author
	*authors = question2Values(authors, answer);
	
	//Check for more quesitons
	if (numQuestions < 3) {
		name = finalCalc(authors);
		return name;
	}
	
	//3rd Question question
	printf("%s", Question3.question);
	
	//now to get their input
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	
	//Validate input
	answer = tOrFVal(answer);

	//assign values
	*authors = question3Values(authors, answer);
	
	//check if another question is needed
	if (numQuestions < 4) {
		name = finalCalc(authors);
		return name;
	}
	
	//4th question w/ A-D options
	printf("%s", Question4.question);
	printf("%s%s%s%s", Question4.answerA, Question4.answerB, Question4.answerC, Question4.answerD);
	
	//now to get their input
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	
	//validate A-D input
	answer = aThroughDVal(answer);

	//assign values to authors
	*authors = question4Values(authors, answer);

	//Call the final calculation function
	name = finalCalc(authors);
	return name;
}

//Validation loops, check to ensure that input was right then returns the input.
int oneThrough4Val(int validate)
{
	while (validate != 1 && validate != 2 && validate != 3 && validate != 4)
	{
		printf("Invalid Entry: Please enter 1, 2, 3, or 4:\n");
		scanf_s(" %d", &validate);
	}
	return validate;
}
char aThroughDVal(char answer)
{
	while (answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D') {
		printf("\nPlease enter A, B, C, or D (case sensitive)");
		scanf_s(" %c", &answer, 1);
	}
	return answer;
}
char tOrFVal(char answer)
{
	while (answer != 'T' && answer != 'F') {
		printf("Please enter T or F (case sensitive)\n");
		scanf_s(" %c", &answer, 1);
	}
	return answer;
}

//Full value assigning functions
int question1Values(int* authors, char answer) 
{
	if (answer == 'A') {
		authors[0] = authors[0] + 2;
	}
	else if (answer == 'B') {
		++authors[1];
	}
	else if (answer == 'C') {
		++authors[2];
	}
	else
		++authors[3];
	return *authors;
}
int question2Values(int* authors, char answer)
{
	if (answer == 'A') {
		++authors[0];
	}
	else if (answer == 'B') {
		authors[1] = authors[1] + 2;
	}
	else if (answer == 'C') {
		++authors[2];
	}
	else
		++authors[3];
	return *authors;
}
int question3Values(int* authors, char answer)
{
	if (answer == 'T') {
		++authors[0];
		authors[1] = authors[1] + 2;
		++authors[3];
	}
	else
		++authors[2];

	return *authors;
}
int question4Values(int* authors, char answer)
{
	if (answer == 'A') {
		++authors[0];
	}
	else if (answer == 'B') {
		authors[1] = authors[1] + 2;
	}
	else if (answer == 'C') {
		++authors[2];
	}
	else
		++authors[3];
	
	return *authors;
}

//This is called in each of the four functions above
int finalCalc(int* summary)
{
	//compare values using a for loop to go through the array
	int i, answer = 0;
	//int a searches through the array for the highest value - than if it's the highest - answer then equals the numeric slot - per the value of the authors
	int a = summary[0];
	for (i = 0; i < 4; ++i) {
		if (a < summary[i]) {
			a = summary[i];
			answer = i;
		}
	}
	
	return answer;
}

//Function to export the answer to a .txt file
void exportAnswer(char aValue[100])
{
	//declare file name
	FILE* output;
	output = ("Author.txt", "w");
	errno_t err;
	printf("For your records, your answer has been exported to a file called Author.txt\n");
	//ensure we can open the file using stderr
	if ((err = fopen_s(&output, "Author.txt", "w")) != 0)
	{
		fprintf(stderr, "Can't write to output file Author.txt\n");
	
	}
	else
	{
		fputs(aValue, output);
		fclose(output);
	}
	

}

//Decision function to repeat the quiz or end
int repeatQuiz()
{
	char goAgain;
	int	ok;
	printf("Would you like to take the quiz again? (y/n)\n");
	scanf_s(" %c", &goAgain, 1);
	while (goAgain != 'y' && goAgain != 'n') {
		printf("Please enter y or n (case sensitive)");
		scanf_s(" %c", &goAgain, 1);
	}
	if (goAgain == 'y')
		ok = 1;
	else
		ok = 0;
	return ok;
}