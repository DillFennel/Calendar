#include <iostream>
#include <iomanip>
#include <map>
#include <string>
 
using namespace std;
 
//Писала Мазурова Карина
pair <int, int> input() {
    int month = 0;
    int year = 0;
    while ( month < 1 || month > 12 ) {cout<<"Введите номер месяца"<<endl;cin >> month;}
while (year < 1919 || year > 2069) {cout<<"Введите номер года"<<endl;cin >> year;}
return {month, year};
}

bool is_year_leap(int year){ //Функция проверяет, високосный ли год
    return ((year%100!=0 & year%4==0) || (year%400==0));
} 
int number_of_days_in_month(int month, int year){ //Функция проверяет, правда ли что в месяце 31 день
    int m_days[12] = {31, 28 + is_year_leap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return m_days[month-1];
}

//Писал Сейфулаев Руслан
pair <int,int> calculate_the_shift_of_Monday_and_the_number_of_days(int month, int year) { //Функция вычисляет сдвиг первого дня месяца и количество дней в нем, а затем возвращает эти данные. На вход подаем номер месяца и номер года 
    int move = 2;
    int number_of_days = number_of_days_in_month(month, year);
    while(month-1>0){
        move += number_of_days_in_month(month-1, year);
        month--;
    }
    while(year>1919){
        move += 365 + is_year_leap(year);
        year--;
    }
    return {number_of_days, move%7}; 
}
//Писала Петрушина Юлия
void print(int month, int year, int number_of_days, int move){
    map <int, string> name_of_month = { {1,"Январь"}, {2,"Февраль"}, {3,"Май"}, {4,"Апрель"}, {5,"Март"}, {6,"Июнь"}, {7,"Июль"}, {8,"Август"}, {9,"Сентябрь"}, {10,"Октябрь"}, {11,"Ноябрь"}, {12,"Декабрь"}};
    cout<<endl;
    cout<<name_of_month[month]<<' '<<year<<endl;
    cout<<"  ПН  ВТ  СР  ЧТ  ПТ  СБ  ВС"<<endl;
    int first_day = move;
    while(move > 0){
        cout<<"    ";
        move--;
    }
    int count = 1;
    for( int i = first_day; i<7; i++){
        cout<<setw(4)<<count;
        count++;
    }
    cout<<endl;
    while(count<=number_of_days){
        for(int i=0; i<7; i++){
            if(count<=number_of_days){
                cout<<setw(4)<<count;
                count++;
            }
        }
        cout<<endl;
    }
}
int main()
{
    int month, year, number_of_days, move;
    pair <int, int> input_return = input();
    month = input_return.first;
    year = input_return.second;
    pair <int, int> calculate_return = 
        calculate_the_shift_of_Monday_and_the_number_of_days(month, year);
    number_of_days = calculate_return.first;
    move = calculate_return.second;
    print(month, year, number_of_days, move);
    return 0;
}

