//Including stdio.h and Authors.h since both are required to run this code
#include <stdio.h>
#include "Authors.h"

//Now to set up functions that will be called by the main function

int question1(int author);
int question2(int author);
int question3(int author);
int question4(int author);
int finalCalc(int summary[4]);
//Begin main function

int main(int argc, char** argv)
{
	//Variable initialization
	int numberOfQuestions = 0;
	int getAnswer = 0, finalAnswer = 0;
	char goAgain;
	//Introduce the application
	printf("Welcome to Leadership Minds. This is an interactive quiz promgram that will help pair you with an author that matches your style.");
	
	//This goto option allows me to come back to the top rather than just exit when the error handling hit
	GET_QUESTIONS:
	printf("You get to choose how in depth this quiz is. How many questions would you like asked?\n(Choose a number between 1 and 4)\n");
	scanf_s(" %d", &numberOfQuestions);
	//I chose switch cases since an int is expected and other error handling seemed really ineffective. by making the default case the error, this allows only 4 true cases
	switch (numberOfQuestions)
	{
	case 1: finalAnswer = question1(getAnswer);
		break;

	case 2: finalAnswer = question2(getAnswer);
		break;
	
	case 3: finalAnswer = question3(getAnswer);
		break;

	case 4: finalAnswer = question4(getAnswer);
		break;
	default: printf("Error - entry is invalid - defaulting to 4 questions.\n");
		finalAnswer = question4(getAnswer);
		break;
	}
	

	//now the functions have asked the questions and calculated the result and returned it here into final answer
	//Have 4 different endings, one for each author
	if (finalAnswer == 0) {
		printf("%s\n", SCOVEY);
	}
	else if (finalAnswer == 1) {
		printf("%s\n", DCARNEGIE);
	}
	else if (finalAnswer == 2) {
		printf("%s\n", JWILLINK);
	}
	else {
		printf("%s\n", AOHANIAN);
	}
	//next invite the user to go again
	REPEAT: printf("Would you like to take the quiz again? (y/n)\n");
	scanf_s(" %c", &goAgain, 1);

	if (goAgain != 'y' && goAgain != 'n') {
		printf("Please enter y or n (case sensitive)");
		goto REPEAT;
	}
	else if (goAgain == 'y') {
		goto GET_QUESTIONS;
	}
	else {
		printf("Thanks for taking the time to go through the quiz! Ending....\n");
	}
	return 0;
}

//Filling out the functions so they work when they are called

int question1(int author)
{
	//local variable declaration
	char answer;
	int authors[4] = {0, 0, 0, 0};
	int name;
	//Printed question
	printf("Choose 1: What kind of leader best describes what kind of leader you want to be?\n");
	//now give A-D options
	printf("A: A principled leader\nB: A well liked leader\nC: A no-nonsense get-to-the-point leader\nD: A breakthrough and innovative leader\n");
	//now to get their input
	GET1: 
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	if (answer == 'A') {
		++authors[0];
	}
	else if (answer == 'B') {
		++authors[1];
	}
	else if (answer == 'C') {
		++authors[2];
	}
	else if(answer == 'D') {
		++authors[3];
	}
	else {
		printf("\nPlease enter A, B, C, or D (case sensitive)");
		goto GET1;
	}
	name = finalCalc(authors);
	return name;
}

int question2(int author)
{
	//local variable declaration
	char answer;
	int authors[4] = { 0, 0, 0, 0 };
	int name;
	//Printed question
	printf("Choose 1: What kind of leader best describes what kind of leader you want to be?\n");
	//now give A-D options
	printf("A: A principled leader\nB: A well liked leader\nC: A no-nonsense get-to-the-point leader\nD: A breakthrough and innovative leader\n");
	//now to get their input
	GET1:
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	if (answer == 'A') {
		authors[0] = authors[0] + 2;
	}
	else if (answer == 'B') {
		++authors[1];
	}
	else if (answer == 'C') {
		++authors[2];
	}
	else if (answer == 'D') {
		++authors[3];
	}
	else {
		printf("\nPlease enter A, B, C, or D (case sensitive)");
		goto GET1;
	}
	//2nd question
	printf("I think that the team members I manage: \n");
	//now give A-D options
	printf("A: Need guidance and a larger perspective\nB: Have great potential if they are given the right, positive nudge\nC: Should rise up to the task and take it as if it was their own\nD: Are only the right team members if they think a little differently\n");
	//now to get their input
	GET2:
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	if (answer == 'A') {
		++authors[0];
	}
	else if (answer == 'B') {
		authors[1] = authors[1] + 2;
	}
	else if (answer == 'C') {
		++authors[2];
	}
	else if (answer == 'D') {
		++authors[3];
	}
	else {
		printf("\nPlease enter A, B, C, or D (case sensitive)");
		goto GET2;
	}
	//Call the final calculation function
	name = finalCalc(authors);
	return name;
}

int question3(int author)
{
	//local variable declaration
	char answer;
	int authors[4] = { 0, 0, 0, 0 };
	int name;
	//Printed question
	printf("Choose 1: What kind of leader best describes what kind of leader you want to be?\n");
	//now give A-D options
	printf("A: A principled leader\nB: A well liked leader\nC: A no-nonsense get-to-the-point leader\nD: A breakthrough and innovative leader\n");
	//now to get their input
GET1:
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	if (answer == 'A') {
		authors[0] = authors[0] + 2;
	}
	else if (answer == 'B') {
		++authors[1];
	}
	else if (answer == 'C') {
		++authors[2];
	}
	else if (answer == 'D') {
		++authors[3];
	}
	else {
		printf("\nPlease enter A, B, C, or D (case sensitive)");
		goto GET1;
	}
	//2nd question
	printf("I think that the team members I manage: \n");
	//now give A-D options
	printf("A: Need guidance and a larger perspective\nB: Have great potential if they are given the right, positive nudge\nC: Should rise up to the task and take it as if it was their own\nD: Are only the right team members if they think a little differently\n");
	//now to get their input
GET2:
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	if (answer == 'A') {
		++authors[0];
	}
	else if (answer == 'B') {
		authors[1] = authors[1] + 2;
	}
	else if (answer == 'C') {
		++authors[2];
	}
	else if (answer == 'D') {
		++authors[3];
	}
	else {
		printf("\nPlease enter A, B, C, or D (case sensitive)");
		goto GET2;
	}
	
	//3rd Question question
	printf("True or False: Employees and team members should be almost entirely autonomous \n");
	printf("T: True\nF: False\n");
	//now to get their input
GET3:
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	if (answer == 'T') {
		++authors[0];
		authors[1] = authors[1] + 2;
		++authors[3];
	}
	else if (answer == 'F') {
		++authors[2];

	}
	else {
		printf("\nPlease T or F (case sensitive)");
		goto GET3;
	}
	//Call the final calculation function
	name = finalCalc(authors);
	return name;
}

int question4(int author)
{
	//local variable declaration
	char answer;
	int authors[4] = { 0, 0, 0, 0 };
	int name;
	//Printed question
	printf("Choose 1: What kind of leader best describes what kind of leader you want to be?\n");
	//now give A-D options
	printf("A: A principled leader\nB: A well liked leader\nC: A no-nonsense get-to-the-point leader\nD: A breakthrough and innovative leader\n");
	//now to get their input
GET1:
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	if (answer == 'A') {
		authors[0] = authors[0] + 2;
	}
	else if (answer == 'B') {
		++authors[1];
	}
	else if (answer == 'C') {
		++authors[2];
	}
	else if (answer == 'D') {
		++authors[3];
	}
	else {
		printf("\nPlease enter A, B, C, or D (case sensitive)");
		goto GET1;
	}
	//2nd question
	printf("I think that the team members I manage: \n");
	//now give A-D options
	printf("A: Need guidance and a larger perspective\nB: Have great potential if they are given the right, positive nudge\nC: Should rise up to the task and take it as if it was their own\nD: Are only the right team members if they think a little differently\n");
	//now to get their input
GET2:
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	if (answer == 'A') {
		++authors[0];
	}
	else if (answer == 'B') {
		authors[1] = authors[1] + 2;
	}
	else if (answer == 'C') {
		++authors[2];
	}
	else if (answer == 'D') {
		++authors[3];
	}
	else {
		printf("\nPlease enter A, B, C, or D (case sensitive)");
		goto GET2;
	}

	//3rd Question question
	printf("True or False: Employees and team members should be almost entirely autonomous \n");
	printf("T: True\nF: False\n");
	//now to get their input
GET3:
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	if (answer == 'T') {
		++authors[0];
		authors[1] = authors[1] + 2;
		++authors[3];
	}
	else if (answer == 'F') {
		++authors[2];

	}
	else {
		printf("\nPlease T or F (case sensitive)");
		goto GET3;
	}
	//4th question
	printf("I am: \n");
	//now give A-D options
	printf("A: New to the workforce, but want to be a manager soon\nB: Want to lead well not only at work but at home and in other situations\nC: A leader who wants his team to self direct\nD: Focused on coming in with a new style in leadership\n");
	//now to get their input
GET4:
	scanf_s(" %c", &answer, 1);
	printf("You entered : %c \n", answer);
	if (answer == 'A') {
		++authors[0];
	}
	else if (answer == 'B') {
		authors[1] = authors[1] + 2;
	}
	else if (answer == 'C') {
		++authors[2];
	}
	else if (answer == 'D') {
		++authors[3];
	}
	else {
		printf("\nPlease enter A, B, C, or D (case sensitive)");
		goto GET4;
	}
	//Call the final calculation function
	name = finalCalc(authors);
	return name;
}


int finalCalc(int summary[4])
{
	//compare values using a for loop to go through the array
	int i, answer = 0;
	int a = summary[0];
	for (i = 0; i < 4; ++i) {
		if (a < summary[i]) {
			a = summary[i];
			answer = i;
		}
		printf("%i", answer);
	}
	
	return answer;
}