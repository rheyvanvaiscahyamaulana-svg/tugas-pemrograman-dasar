#include <iostream>
#include <string>

using namespace std;

const int NUM_STUDENTS = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void readData(studentType students[], int size);
void assignGrade(studentType students[], int size);
int findHighestScore(const studentType students[], int size);
void printHighestScorers(const studentType students[], int size, int highestScore);
void printReport(const studentType students[], int size);

int main() {
    studentType classList[NUM_STUDENTS];
    int highestScore;

    readData(classList, NUM_STUDENTS);
    assignGrade(classList, NUM_STUDENTS);
    printReport(classList, NUM_STUDENTS);

    highestScore = findHighestScore(classList, NUM_STUDENTS);

    cout << "\n--- Laporan Nilai Tertinggi ---" << endl;
    cout << "Nilai Tes Tertinggi: " << highestScore << endl;

    printHighestScorers(classList, NUM_STUDENTS, highestScore);

    return 0;
}

void readData(studentType students[], int size) {
    cout << "=============================================" << endl;
    cout << "Entri Data Nilai " << size << " Mahasiswa" << endl;
    cout << "=============================================" << endl;

    for (int i = 0; i < size; i++) {
        cout << "\n--- Mahasiswa " << (i + 1) << " ---" << endl;
        cout << "Masukkan Nama Depan : ";
        cin >> students[i].studentFName;

        cout << "Masukkan Nama Belakang: ";
        cin >> students[i].studentLName;

        cout << "Masukkan Nilai Tes (0-100): ";
        cin >> students[i].testScore;

        while (students[i].testScore < 0 || students[i].testScore > 100) {
            cout << "Nilai tidak valid. Masukkan nilai antara 0 dan 100: ";
            cin >> students[i].testScore;
        }

        students[i].grade = ' ';
    }
    cout << "\n...Entri data selesai...\n" << endl;
}

void assignGrade(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        int score = students[i].testScore;

        if (score >= 90) {
            students[i].grade = 'A';
        } else if (score >= 80) {
            students[i].grade = 'B';
        } else if (score >= 70) {
            students[i].grade = 'C';
        } else if (score >= 60) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }
}

int findHighestScore(const studentType students[], int size) {
    int maxScore = students[0].testScore;

    for (int i = 1; i < size; i++) {
        if (students[i].testScore > maxScore) {
            maxScore = students[i].testScore;
        }
    }
    return maxScore;
}

void printHighestScorers(const studentType students[], int size, int highestScore) {
    cout << "Mahasiswa dengan nilai tertinggi (" << highestScore << "):" << endl;
    
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << "- " << students[i].studentLName << ", "
                 << students[i].studentFName << endl;
        }
    }
}
void printReport(const studentType students[], int size) {
    cout << "\n=============================================" << endl;
    cout << "Laporan Nilai Lengkap" << endl;
    cout << "=============================================" << endl;

    cout << "Nama, Nilai, Grade" << endl;
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        cout << students[i].studentLName << ", " << students[i].studentFName;
        cout << ", " << students[i].testScore;
        cout << ", " << students[i].grade << endl;
    }
}

