#ifndef STUDENT_H
#define STUDENT_H
#define size 20
#define size1 3

typedef enum {CPP, WEB, AI, DevHack} LanguageTrack;
typedef enum {COMPUTER_SCIENCE, CORE_LANGUAGE, SPECIALITIES} AcademyPhase;

typedef struct {
        char name[size];
        int id;
        LanguageTrack language;
        AcademyPhase phase;
        int monthExams[size1];
        float totalScore;
        int passed;     
} Student;

void addStudent(Student *s);
void inputMonthlyExams(Student *s);
void calculateTotal(Student *s);
void check(Student *s);
void PrintStudentReport(Student *s);
int minScoreForThirdMonth(int month1, int month2);
void passedStudents(Student academy[], int size2);

#endif
