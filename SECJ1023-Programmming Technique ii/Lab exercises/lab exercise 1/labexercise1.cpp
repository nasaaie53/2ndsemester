// ? EXERCISE 1: INTRODUCTION TO CLASSES AND OBJECTS

// Programming Technique II

// Member 1's Name: MUHAMMAD FAIRUZ BIN HERMAN A25CS0267
// Member 2's Name: NASAAIE BIN NORISKAMAR A25CS0118
//
// Section: 02
// Member 1's Name: MUHAMMAD FAIRUZ BIN HERMAN Location: K11 WING A KTR UTM SKUDAI (i.e. where are you currently located)// 
// Member 2's Name: NASAAIE BIN NORISKAMAR  Location: K11 WING A KTR UTM SKUDAI

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________

// Video link:
// google drive : https://drive.google.com/drive/folders/1KB6X1EYrpuDGqK7hTlOvMf0ymBCZPn-O?usp=sharing


#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

class Subject{
	private : 
	string subjectName;
	string subjectCode;
	double scoreEarned;

	public :

	Subject(){
		subjectName = " ";
		subjectCode = " ";
		scoreEarned = 0.0;
	}


	Subject (string name, string code, double score){
		subjectName = name;
		subjectCode = code;
		scoreEarned = score;
}


~Subject(){}

void setSubjectName(string name){
	subjectName= name;
} 
string getSubjectName() const{
return subjectName;
}

void setSubjectCode(string code){
	subjectCode=code;
}
string getSubjectCode() const{
	return subjectCode;
}

void setScoreEarned(double score){
	scoreEarned=score;
}
double getScoreEarned() const {
	return scoreEarned;
}

string getGrade() const{
	if (scoreEarned >= 90) return "A+";
	else if (scoreEarned >= 80 ) return "A";
	else if (scoreEarned >= 75 ) return "A-";
	else if (scoreEarned >= 70 ) return "B+";
	else if (scoreEarned >= 65 ) return "B";
	else if (scoreEarned >= 60 ) return "B-";
	else if (scoreEarned >= 55 ) return "C+";
	else if (scoreEarned >= 50 ) return "C";
	else if (scoreEarned >= 45 ) return "C-";
	else if (scoreEarned >= 40 ) return "D+";
	else if (scoreEarned >= 35 ) return "D";
	else if (scoreEarned >= 30 ) return "D-";
	else return "E";
}

double getGradePoint() const {
	if (scoreEarned>=80) return 4.00;
	else if (scoreEarned>=75) return 3.67;
	else if (scoreEarned>=70) return 3.33;
	else if (scoreEarned>=65) return 3.00;
	else if (scoreEarned>=60) return 2.67;
	else if (scoreEarned>=55) return 2.33;
	else if (scoreEarned>=50) return 2.00;
	else if (scoreEarned>=45) return 1.67;
	else if (scoreEarned>=40) return 1.33;
	else if (scoreEarned>=35) return 1.00;
	else if (scoreEarned>=30) return 0.67;
	else return 0.00;
}

int getCreditHour() const {
	if (subjectCode.empty()) return 0;
	return subjectCode.back() - '0';
}

double getPointEarned() const{
	return getGradePoint() * getCreditHour();

}
};


int main()
{
	Subject sub;
	string name, code;
	double score;

	cout << "Enter the following data: " << endl;
	cout << "  Subject name => ";
	getline(cin,name);
	sub.setSubjectName(name);
	cout << endl;


	cout << "  Subject code => ";
	cin >> code;
	sub.setSubjectCode(code);
	cout << endl;

	cout << "  Score earned => ";
	cin >> score;
	sub.setScoreEarned(score);
	cout << endl;

	cout << endl
		 << endl;

	cout << "THE RESULT" << endl
		 << endl;

	cout << "Subject Code : "<< sub.getSubjectCode() << endl;
	cout << "Subject Name : " << sub.getSubjectName() << endl;
	cout << "Credit Hour  : "<< sub.getCreditHour() << endl;
	cout << "Score Earned : "<< sub.getScoreEarned() << endl;
	cout << "Grade Earned : " << sub.getGrade() << endl;

	cout << fixed << setprecision(2);
	cout << "Grade Point  : "<< sub.getGradePoint() << endl;

	if (sub.getPointEarned() == static_cast<int>(sub.getPointEarned())){
		cout << setprecision(0);
	}
	cout << "Point Earned : "<< sub.getPointEarned() << endl;
	cout << endl;

	system("pause");

	return 0;
}
