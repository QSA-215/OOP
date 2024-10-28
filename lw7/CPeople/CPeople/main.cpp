#include <iostream>
#include <vector>
#include "allPeopleTypes.h"

int main()
{
    std::vector<CPerson> group;

    CPerson person;
    person.SetFirstName("Rick");
    person.SetLastName("Doh");
    person.SetMiddleName("A.");
    person.SetAddress("34 Elm Street");
    std::cout << "Person: " << person.GetFirstName() << " " << person.GetLastName() << std::endl;

    CWorker worker;
    worker.SetFirstName("John");
    worker.SetLastName("Doe");
    worker.SetMiddleName("A.");
    worker.SetAddress("1234 Elm Street");
    worker.SetSpecialty("Carpenter");
    std::cout << "Worker: " << worker.GetFirstName() << " " << worker.GetLastName() << ", Specialty: " << worker.GetSpecialty() << std::endl;

    CPupil pupil;
    pupil.SetFirstName("Mike");
    pupil.SetLastName("Dolle");
    pupil.SetMiddleName("A.");
    pupil.SetAddress("1234 Elm Street");
    pupil.SetSchoolName("MBOY COW 6");
    pupil.SetGrade("7b");
    std::cout << "Pupil: " << pupil.GetFirstName() << " " << pupil.GetLastName() << ", School: " << pupil.GetSchoolName() << ", Grade: " << pupil.GetGrade() << std::endl;

    CTeacher teacher;
    teacher.SetFirstName("Mary");
    teacher.SetLastName("Doend");
    teacher.SetMiddleName("A.");
    teacher.SetAddress("1234 Elm Street");
    teacher.SetSchoolSubject("Math");
    std::cout << "Teacher: " << teacher.GetFirstName() << " " << teacher.GetLastName() << ", School subject: " << teacher.GetSchoolSubject() << std::endl;

    CStudent student;
    student.SetFirstName("Jane");
    student.SetLastName("Smith");
    student.SetMiddleName("B.");
    student.SetAddress("5678 Oak Street");
    student.SetUniversityName("MIT");
    student.SetStudentID("123456");
    std::cout << "Student: " << student.GetFirstName() << " " << student.GetLastName() << ", University: " << student.GetUniversityName() << ", Student ID: " << student.GetStudentID() << std::endl;

    CAdvancedStudent advancedStudent;
    advancedStudent.SetFirstName("Alice");
    advancedStudent.SetLastName("Johnson");
    advancedStudent.SetMiddleName("C.");
    advancedStudent.SetAddress("9101 Pine Street");
    advancedStudent.SetUniversityName("Harvard");
    advancedStudent.SetStudentID("789012");
    advancedStudent.SetDissertationTopic("Quantum Computing");
    std::cout << "Advanced Student: " << advancedStudent.GetFirstName() << " " << advancedStudent.GetLastName() << ", University: " << advancedStudent.GetUniversityName() << ", Student ID: " << advancedStudent.GetStudentID() << ", Dissertation Topic: " << advancedStudent.GetDissertationTopic() << std::endl;

    group.push_back(person);
    group.push_back(pupil);
    group.push_back(teacher);
    group.push_back(worker);
    group.push_back(student);
    group.push_back(advancedStudent);

    return 0;
}