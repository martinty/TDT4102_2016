//
// Created by tysse on 13.02.2018.
//
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

#include "CourseCatalog.h"

CourseCatalog::CourseCatalog(string fileName) {
    ifstream inStream;
    inStream.open(fileName);
    if (inStream.fail()){
        cout << "No file to read from. Your map is empty." << endl;
    } else{
        char nextChar;
        string courseName;
        string courseCode;
        inStream.get(nextChar);
        while(!inStream.eof()){
            while (nextChar != ':'){
                courseCode += nextChar;
                inStream.get(nextChar);
            }
            inStream.get(nextChar);
            while(nextChar != '\n'){
                courseName += nextChar;
                inStream.get(nextChar);
            }
            addCourse(courseCode,courseName.erase(0,1));
            courseName = "";
            courseCode = "";
            inStream.get(nextChar);
        }
        inStream.close();
    }
}

CourseCatalog::~CourseCatalog(){
    ofstream outStream("course_catalog.txt");
    outStream << *this;
    outStream.close();
}

ostream &operator<<(ostream  &os, const CourseCatalog &course){
    cout << "Courses in the course catalog for NTNU:" << endl;
    map<string, string>::const_iterator key;
    for (key = course.courses.begin(); key != course.courses.end() ; key++) {
        os << key->first << ": " << key->second << endl;
    }
    return os;
}

void CourseCatalog::removeCourse(string courseCode){
    if (courses.find(courseCode) != courses.end()){
        courses.erase(courseCode);
    } else{
        cout << courseCode << " is not in the map" << endl;
    }
}

void CourseCatalog::addCourse(string courseCode, string courseName){
    if (courses.find(courseCode) != courses.end()){
        cout << courseCode << " is already in the map" << endl;
    } else{
        courses[courseCode] = courseName;
    }
}

string CourseCatalog::getCourseName(string courseCode){
    if (courses.find(courseCode) != courses.end()){
        return courses[courseCode];
    } else{
        return courseCode + " is not in the map";
    }
}

void CourseCatalog::editCourseName(string courseCode, string courseName){
    if (courses.find(courseCode) != courses.end()){
        courses[courseCode] = courseName;
    } else{
        cout << courseCode << " is not in the map" << endl;
    }
}

