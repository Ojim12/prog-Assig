#include <iostream>
using namespace std;


double calculateAverage(int scores[], int numScores) {
    double sum = 0;
    for (int i = 0; i < numScores; i++) {
        sum += scores[i];
    }
    return sum / numScores;
}


char determineGrade(double avgScore) {
    if (avgScore >= 90) return 'A';
    else if (avgScore >= 80) return 'B';
    else if (avgScore >= 70) return 'C';
    else if (avgScore >= 60) return 'D';
    else return 'F';
}


void displayResults(string names[], double averages[], char grades[], int numStudents) {
    cout <<endl<< "Student Results:" << endl;
    cout << "Name    "<<"Average   "<<"Grade" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << names[i] << "      " << averages[i] << "       " << grades[i] << endl;
    }
}

int main() {
    int numStudents;
    cout << "Enter the number of students: "<<endl;
    cin >> numStudents;
    
    string names[numStudents];
    double averages[numStudents];
    char grades[numStudents];
    
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter student " << i + 1 << " name: ";
        cin.ignore(); 
        getline(cin, names[i]);

        int numScores;
        cout << "Enter the number of test scores for " << names[i] << ": ";
        cin >> numScores;
        
        int scores[numScores];
        for (int j = 0; j < numScores; j++) {
            do {
                cout << "Enter score " << j + 1 << " (0-100): ";
                cin >> scores[j];
                if (scores[j] < 0 || scores[j] > 100) {
                    cout << "Score is invalid, please enter a score between 0 and 100." << endl;
                }
            } while (scores[j] < 0 || scores[j] > 100);
        }

        
        averages[i] = calculateAverage(scores, numScores);
        grades[i] = determineGrade(averages[i]);
    }

    displayResults(names, averages, grades, numStudents);
    return 0;
}
