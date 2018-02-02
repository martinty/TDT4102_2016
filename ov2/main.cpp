#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;



void inputAndPrintInterger(){
    int x = 0;
    cout << "Skriv inn et heltall: ";
    cin >> x;
    cout << "Du skrev: " << x << endl;
}

int inputInteger(){
    int x = 0;
    cout << "Skriv inn et heltall: ";
    cin >> x;
    return x;
}

void inputIntegersAndPrintSum(){
    int x = inputInteger();
    int y = inputInteger();
    cout << "Sum av tallene: " << x+y << endl;
}

bool isOdd(int n){
    if (n%2 == 0){
        return false;
    } else{
        return true;
    }
}

void printHumanReadableTime(int time){
    int second = time%60;
    int min = ((time - second)/60)%60;
    int hour = (((time - second)/60)-min)/60;
    cout << hour << " timer, " << min << " minutter, " << second << " sekunder" << endl;
}

void inputIntegersUsingLoopAndPrintSum(){
    int sum = 0;
    cout << "Skriv inn 0 for å avslutte" << endl;
    for(;;){
        int x = inputInteger();
        if (x == 0){
            break;
        }
        sum += x;
    }
    cout << "Sum av tallene: " << sum << endl;
}

double inputDouble(){
    double x = 0;
    cout << "Skriv inn et tall: ";
    cin >> x;
    return x;
}

void nokToEuro(){
    cout << "Konventerer NOK til Euro" << endl;
    double nok = inputDouble();
    double euro = nok/9.64;
    cout << nok << " NOK blir " << setprecision(2) << fixed << euro << " Euro." << endl;
}

void gangetabell(){
    int x = 0;
    int y = 0;
    cout << "Gangetabell" << endl;
    cout << "Skriv inn bredde på tabellen: ";
    cin >> x;
    cout << "Skriv inn høyde på tabellen: ";
    cin >> y;
    for (int i = 1; i <= y; i++ ){
        for (int j = 1; j <= x; j++){
            cout << setw(10) << i*j << setw(10);
        }
        printf("\n");
    }
}

double discriminant(double a, double b, double c){
    return pow(b, 2)-4*a*c;
}

void printRealRoots(double a, double b, double c){
    double sum = discriminant(a, b, c);
    if (sum < 0){
        cout << "Ingen løsning" << endl;
    } else if (sum == 0){
        cout << "En løsning" << endl;
        cout << "x = " << (-b)/(2*a) << endl;
    } else{
        cout << "To løsninger" << endl;
        cout << "x1 = " << (-b + sqrt(sum))/(2*a) << "    x2 = " << (-b - sqrt(sum))/(2*a) << endl;
    }
}

void solveQuadraticEquation(){
    cout << "ax^2 + bx + c = 0" << endl;
    double a, b, c;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    printRealRoots(a, b, c);
}

void calculateLoanPayments(){
    cout << "Lånekalkulator" << endl;
    double totalLoan, interestRate, year;
    cout << "Lån [NOK]: ";
    cin >> totalLoan;
    cout << "Renter [%]: ";
    cin >> interestRate;
    cout << "Nedbetalingsår: ";
    cin >> year;
    double loan = totalLoan;
    cout << "År\t\tInnbetaling\t\tGjenstående lån" << endl;
    for (int i = 1; i <= year; i++){
        double payment = totalLoan/(year) + interestRate/100 * loan;
        loan -= totalLoan/year;
        cout << i << "\t\t" << payment << "\t\t\t" << loan << endl;
    }
}

void menu(){
    for(;;){
        int x = 0;
        printf("Velg funksjon:\n");
        printf("0) Avslutt\n");
        printf("1) Summer to tall\n");
        printf("2) Summer flere tall\n");
        printf("3) Konverter NOK til EURO\n");
        printf("4) Gangetabell\n");
        printf("5) Andregradsligning\n");
        printf("6) Lånekalkulator\n");
        printf("Angi valg: ");
        cin >> x;
        if (x == 0){
            break;
        } else if (x == 1){
            inputIntegersAndPrintSum();
        } else if (x == 2){
            inputIntegersUsingLoopAndPrintSum();
        } else if (x == 3){
            nokToEuro();
        } else if (x == 4){
            gangetabell();
        } else if (x == 5){
            solveQuadraticEquation();
        }else if (x == 6){
            calculateLoanPayments();
        } else{
            printf("Ditt velg er ikke mulig. Prøv på nytt igjen.\n");
        }
        printf(" \n");
    }
}

int main() {
    menu();
    return 0;
}