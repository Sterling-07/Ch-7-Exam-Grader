// Ch 7 Exam Grader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int questions = 20;

void getAnswer(char answers[], const string& filename);
int gradeExam(char correct[], char studentAnswer[], int question[], char Answer[][2]);
void writeReport(int question[], int wrong, char Answer[][2], double percentageGrade);

int main()
{
	char correct[questions];
	char studentAnswer[questions];

	getAnswer(correct, "CorrectAnswers.txt");
	getAnswer(studentAnswer, "StudentAnswers.txt");

	int question[questions];
	char Answer[questions][2];
	int wrong = gradeExam(correct, studentAnswer, question, Answer);

	double percentageGrade = ((questions - wrong) * 1.0/questions) * 100.0;
	writeReport(question, wrong, Answer, percentageGrade);

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

void writeReport(int question[], int wrong, char Answer[][2], double percentageGrade)
{
	cout << "Exam Report Details\n";
	cout << "Number of questions missed: " << wrong << "\n";
	cout << "Missed questions and correct answers: \n";
	cout << "Question" << setw(18) << "Correct Answer" << setw(18) << "Your Answer\n";
	for (int a = 0; a < wrong; a++)
	{
		cout << setw(4) << question[a] << setw(15) << Answer[a][0] << setw(17) << Answer[a][1];
		cout << "\n";
	}

	cout << "Test Score: " << percentageGrade << "%\n";
	if (percentageGrade < 70)
	{
		cout << "You failed the exam.\n";
	}
	else
	{
		cout << "You passed the exam.\n";
	}
}
