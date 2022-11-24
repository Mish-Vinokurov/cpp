
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student;

struct Lesson {
    vector<Student*> students_list;
    string name;

    Lesson(string n) {
        name = n;
    }
    void append_students(Student* tmp);
};
struct Student {
    vector<Lesson*> lesson_list;
    string name;

    Student(string n){
        name = n;
    }
    void apend_lesson(Lesson* tmp);
};


void Student::apend_lesson(Lesson* tmp)
{
    lesson_list.push_back(tmp);
    tmp->students_list.push_back(this);
}


void Lesson::append_students(Student* tmp)
{
    students_list.push_back(tmp);
    tmp->lesson_list.push_back(this);
}


int main() {

    vector<Student> student;
    vector<Lesson> lesson;

    student.push_back(Student("Hruh"));
    student.push_back(Student("Geremy"));
    student.push_back(Student("Mortimer"));
    student.push_back(Student("Gregory"));
    student.push_back(Student("Boban"));
    student.push_back(Student("Ramzan"));
    student.push_back(Student("Zelebobster"));
    student.push_back(Student("Arselajab"));
    student.push_back(Student("Lorense-Ate_Zigi"));
    student.push_back(Student("BabaRahman"));
    lesson.push_back(Lesson("BlackMagic")); 
    lesson.push_back(Lesson("Cooking")); 
    lesson.push_back(Lesson("Fighting")); 
    lesson.push_back(Lesson("IT"));
    lesson.push_back(Lesson("Chemestry")); 
    lesson.push_back(Lesson("Litrball")); 
    lesson.push_back(lesson("Geograghy"));
    lesson.push_back(lesson("Burning"));
    lesson.push_back(lesson("Religion"));


    student[0].apend_lesson(&lesson[0]);
    student[0].apend_lesson(&lesson[1]);
    student[1].apend_lesson(&lesson[8]);
    student[1].apend_lesson(&lesson[3]);
    student[2].apend_lesson(&lesson[6]);
    student[2].apend_lesson(&lesson[3]);
    student[3].apend_lesson(&lesson[4]);
    student[3].apend_lesson(&lesson[1]);
    student[4].apend_lesson(&lesson[2]);
    student[4].apend_lesson(&lesson[7]);
    student[5].apend_lesson(&lesson[6]);
    student[5].apend_lesson(&lesson[0]);
    student[6].apend_lesson(&lesson[0]);
    student[6].apend_lesson(&lesson[8]);
    student[6].apend_lesson(&lesson[2]);
    student[7].apend_lesson(&lesson[3]);
    student[7].apend_lesson(&lesson[5]);
    student[7].apend_lesson(&lesson[4]);
    student[8].apend_lesson(&lesson[6]);
    student[8].apend_lesson(&lesson[7]);
    student[9].apend_lesson(&lesson[0]);
    student[9].apend_lesson(&lesson[1]);


    cout << "BlackMagic fans: ";
    for (int i = 0; i < lesson[0].students_list.size(); ++i) 
    {
        std::cout << lesson[0].students_list[i]->name;
        if (i != lesson[0].students_list.size() - 1) std::cout << ", ";
    }

    cout << "\n";

    cout << "Average Burning enjoyers: ";
    for (int i = 0; i < lesson[7].students_list.size(); ++i) 
    {
        std::cout << lesson[7].students_list[i]->name;
        if (i != lesson[7].students_list.size() - 1) std::cout << ", ";
    }
    cout << "\n";

    cout << "Zelebobster interests: ";
    for (int i = 0; i < student[0].lesson_list.size(); ++i) 
    {
        std::cout << student[0].lesson_list[i]->name;
        if (i != student[0].lesson_list.size() - 1) std::cout << ", ";
    }
}
