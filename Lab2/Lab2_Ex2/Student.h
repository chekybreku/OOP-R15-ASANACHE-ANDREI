#pragma once

class Student {
public:
    ~Student();

    const char* GetName() const;
    void SetName(const char* name);

    float GetMathGrade() const;
    float GetEnglishGrade() const;
    float GetHistoryGrade() const;
    void SetMathGrade(float grade);
    void SetEnglishGrade(float grade);
    void SetHistoryGrade(float grade);

    float GetAverageGrade() const;

    void Print();
private:
    char* m_name = nullptr;
    float m_math;
    float m_english;
    float m_history;
};
/*
Design a C++ class (following the previous problem) that reflects the properties of a student.The class should include the following :
-methods to set and get the name of the student
-methods to set and get the grade for mathematics(a grade must be a float value from 1 to 10)
-methods to set and get the grade for English(a grade must be a float value from 1 to 10)
-methods to set and get the grade for History(a grade must be a float value from 1 to 10)
-a method that retrieves the average grade
-5 global functions that compares two students in terms of name, grades, average.If two students are equal the return value of such a function will be 0. If the first student is bigger than the second one, the return value will be 1, otherwise - 1.

Make sure that you have the following :

-a header file for the class
-a cpp file for the methods specific to the class
-a header file for the global functions
-a cpp file for the global functions implementation
-a main.cpp file that shows how the methods and global functions can be used.
*/