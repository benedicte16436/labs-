#include <iostream>
#include <iomanip>

using namespace std;


struct Time {
    int hours;
    int minutes;
    int seconds;
};


bool isValidTime(const Time& time) {
    return (time.hours >= 0 && time.hours <= 23 &&
        time.minutes >= 0 && time.minutes <= 59 &&
        time.seconds >= 0 && time.seconds <= 59);
}


Time addTimes(const Time& time1, const Time& time2) {
    Time result;
    result.seconds = time1.seconds + time2.seconds;
    result.minutes = time1.minutes + time2.minutes + result.seconds / 60;
    result.hours = time1.hours + time2.hours + result.minutes / 60;
    result.seconds %= 60;
    result.minutes %= 60;
    return result;
}


Time subtractTimes(const Time& time1, const Time& time2) {
    Time result;
    result.seconds = time1.seconds - time2.seconds;
    result.minutes = time1.minutes - time2.minutes;
    result.hours = time1.hours - time2.hours;

    if (result.seconds < 0) {
        result.seconds += 60;
        result.minutes--;
    }
    if (result.minutes < 0) {
        result.minutes += 60;
        result.hours--;
    }

    return result;
}




void printTime(const Time& time) {
    cout << setw(2) << setfill('0') << time.hours << ":"
        << setw(2) << setfill('0') << time.minutes << ":"
        << setw(2) << setfill('0') << time.seconds << endl;
}

int main() {
    Time time1, time2;

    cout << "Enter the first time (Hour minutes seconds): ";
    cin >> time1.hours >> time1.minutes >> time1.seconds;


    cout << "Enter the second time (Hour minutes seconds): ";
    cin >> time2.hours >> time2.minutes >> time2.seconds;

    if (!isValidTime(time1) || !isValidTime(time2)) {
        cout << "Error - Time is not correct." << endl;
        return 1;
    }

    cout << "Sum of times: ";
    printTime(addTimes(time1, time2));

    cout << "Difference of times: ";
    printTime(subtractTimes(time1, time2));

    return 0;
}
 
