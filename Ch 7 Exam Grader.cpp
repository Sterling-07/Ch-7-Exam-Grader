// Ch 7 Exam Grader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

const int questions = 20;

void getAnswer(char answers[], const string& filename);
int gradeExam(char correct[], char studentAnswer[], int question[], char Answer[][2]);
void writeReport(int question[], int wrong, char Answer[][2]);

int main()
{
	char correct[questions];
	char studentAnswer[questions];

	getAnswer(correct, "CorrectAnswers.txt");
	getAnswer(studentAnswer, "StudentAnswers.txt");

	int question[questions];
	char Answer[questions][2];
	int wrong = gradeExam(correct, studentAnswer, question, Answer);

	writeReport(question, wrong, Answer);

	return 0;
}

void getAnswer(char answers[], const string& filename)
{
	ifstream inFile(filename);
	if (!inFile)
	{
		cout << "There was an error opening the file.\n";
	}

	for (int a = 0; a < questions; a++)
	{
		inFile >> answers[a];
	}

	inFile.close();
}

int gradeExam(char correct[], char studentAnswer[], int question[], char Answer[][2])
{
	int wrong = 0;

	for (int a = 0; a < questions; a++)
	{
		if (correct[a] != studentAnswer[a])
		{
			question[wrong] = a + 1;
			Answer[wrong][0] = correct[a];
			Answer[wrong][1] = studentAnswer[a];
			wrong++;
		}
	}
	
	return wrong;
}

void writeReport(int question[], int wrong, char Answer[][2])
{
	cout << "Exam Report Details\n";
	cout << "Number of questions missed: " << wrong << "\n";
	cout << "Missed questions and correct answers: \n";
	cout << "Question" << "\t" << "Correct Answer" << "\t\t" << "Your Answer\n";
	for (int a = 0; a < wrong; a++)
	{
		cout << question[a] << "\n";
	}
}
