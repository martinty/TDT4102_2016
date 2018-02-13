//
// Created by tysse on 13.02.2018.
//

#ifndef OV8_COURSECATALOG_H
#define OV8_COURSECATALOG_H


class CourseCatalog {
private:
    map<string, string> courses;
public:
    CourseCatalog() = default;
    explicit CourseCatalog(string fileName);
    ~CourseCatalog();
    friend ostream &operator<<(ostream &os, const CourseCatalog &course);
    void removeCourse(string courseCode);
    void addCourse(string courseCode, string courseName);
    string getCourseName(string courseCode);
    void editCourseName(string courseCode, string courseName);
};


#endif //OV8_COURSECATALOG_H
