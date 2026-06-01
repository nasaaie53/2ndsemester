// ? EXERCISE 2: CLASS AND OBJECT MANIPULATIONS

/// Programming Technique II

// Member 1's Name: Nasaaie Bin Noriskamar
// Member 2's Name: Muhammad Fairuz bin Herman
//
// Section: 02
// Member 1's Name: Nasaaie Bin Noriskamar   Location: K11 Ktr,Utm SKudai (i.e. where are you currently located)
// Member 2's Name: Muhammad Fairuz bin Herman    Location: K11 KTR, UTM Skudai

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________

// Video link:
//   _________

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_SUBJECT_COUNT 10

class Subject
{
private:
	string name;
	string code;
	int score;

public:
	Subject();
	int credit() const;
	string grade() const;
	double point() const;
	void print() const;

	bool operator<(const Subject& other) // TASK 3
	const;

	friend int readUserInput(Subject subjects[]); //TASK 5
};

// Define a regular function that determines the lower subject.TASK 4
Subject lower(Subject a, Subject b)
{
	if ( a < b )
	return a;
	else 
	return b;
	
}

int main()
{
	Subject subjectList[MAX_SUBJECT_COUNT];// TASK 6A

	int count = readUserInput(subjectList);// TASK 6B


	cout << endl
		 << endl
		 << "THE RESULT"
		 << endl
		 << endl;

	// Print the output table header
	cout << left << setw(15) << "Subject Code";
	cout << left << setw(20) << "Subject Name";
	cout << left << setw(10) << "Credit";
	cout << left << setw(10) << "Score";
	cout << left << setw(10) << "Grade";
	cout << left << setw(10) << "Point";
	cout << left << setw(10) << "Sub Total" << endl;
	cout << endl
		 << endl;

		 double totalPoint = 0; // TASK 6C
		 int totalCredit = 0;
		 Subject lowest;

		 for (int i = 0; i < count ; i++){
			subjectList[i].print();
			double subTotal= subjectList[i].point() * subjectList[i].credit();
			cout << left << setw(10) << fixed << setprecision(2)<< subTotal <<endl;

			totalPoint += subTotal;
			totalCredit += subjectList[i].credit();
		 

		 if (i==0) // TASK 6D
		 lowest = subjectList[i];
		else
		lowest = lower(lowest,subjectList[i]);
		}

	cout << endl;
	cout << "TOTAL POINT  : " <<totalPoint<< endl;
	cout << "TOTAL CREDIT : " <<totalCredit<< endl;

	double gpa = (totalCredit > 0)?
	(totalPoint/totalCredit):0;
	cout << "GPA          : " << fixed << setprecision(2) << gpa <<endl;

	cout << endl;
	cout << "LOWEST SUBJECT : " << endl;
	lowest.print();
	cout << endl;

	system("pause");

	return 0;
}

// The definition of the default constructor is fully given
Subject::Subject() : name(""), code(""), score(0) {}

// The definition of the getter for the 'credit()' is fully given
int Subject::credit() const { return code[7] - '0'; }

// The definition of the getter for the 'grade()' is fully given
string Subject::grade() const
{
	if (score >= 90)
		return "A+";
	if (score >= 80)
		return "A";
	if (score >= 75)
		return "A-";
	if (score >= 70)
		return "B+";
	if (score >= 65)
		return "B";
	if (score >= 60)
		return "B-";
	if (score >= 55)
		return "C+";
	if (score >= 50)
		return "C";
	if (score >= 45)
		return "C-";
	if (score >= 40)
		return "D+";
	if (score >= 35)
		return "D";
	if (score >= 30)
		return "D-";
	return "E";
}

// Define a regular function that read a list of subjects from user input. TASK 5
int readUserInput(Subject subjects[])
{
	int num;
	cout << "How many subjects do you want to enter? =>";
	cin >>num;
	cin.ignore();

	for (int i=0 ; i < num ; i++){
		cout << "\n Enter into for subject #"<< i+1<<":"<<endl;
		cout << "Subject Code =>";
		getline(cin,subjects[i].code);
		cout << "Subject name =>";
		getline(cin,subjects[i].name);
		cout <<"Score earned =>";
		cin>>subjects[i].score;
		cin.ignore();
	}
	return num;
}


double Subject :: point() const { // TASK 1
	string g=grade();
	if (g=="A+" || g== "A") return 4.00;
	if (g=="A-") return 3.67;
	if (g=="B+")return 3.33;
	if (g=="B") return 3.00;
	if (g=="B-")return 2.67;
	if (g=="C+")return 2.33;
	if (g=="C")return 2.00;
	if (g=="C-")return 1.67;
	if (g=="D+")return 1.33;
	if (g=="D")return 1.00;
	if (g=="D-")return 0.67;
	return 0.00; 
}

void Subject::print() const{ // TASK 2
	cout << left << setw(15) << code;
	cout << left << setw(20) << name;
	cout << left << setw(10) << credit();
	cout << left << setw(10) << score;
	cout << left << setw(10) << grade();
	cout << left << setw(10) << fixed <<  setprecision(2) << point(); 
}

bool Subject::operator<(const Subject& other)const{ // TASK 3
	return this->score < other.score;
}

