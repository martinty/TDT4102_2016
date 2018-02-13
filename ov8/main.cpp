#include <iostream>
#include <map>
using namespace std;

#include "utilities.h"
#include "CourseCatalog.h"

int main() {

    string fileName  = "words.txt";
    string fileName2 = "course_catalog.txt";
    string fileName3 = "text.txt";

    //createAndWriteToFile(fileName);
    //readFromFileAndAddLineNumbers(fileName);
    //readFromFileAndMakeStatistic(fileName);

    //CourseCatalog course(fileName2);
    //course.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    //course.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    //course.addCourse("TMA4100", "Matematikk 1");
    //cout << course << endl;

    wordStatisticFromFile(fileName3);

    return 0;
}

