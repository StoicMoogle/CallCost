#include <string>
#include <iostream>
using namespace std;


double cost;
double totalCost;
int hour;
int minutes;
int duration;
char day1;
char day2;
char answer;
string dayOfWeek;
bool validDay = false;
bool validTime = false;
bool answerAgain = true;
bool validAnswer = false;

int main() {
	while (answerAgain == true) {
		validDay = false;
		validTime = false;
		validAnswer = false;

		while (validDay == false) {

			cout << "Enter the first two characters of the day of the week of the call." << endl;
			cin >> day1 >> day2;
			if ((day1 == 'm' || day1 == 'M') && (day2 == 'o' || day2 == 'O')) {
				dayOfWeek = "Monday";
				validDay = true;
			}
			else if ((day1 == 't' || day1 == 'T') && (day2 == 'u' || day2 == 'U')) {
				dayOfWeek = "Tuesday";
				validDay = true;
			}

			else if ((day1 == 'w' || day1 == 'W') && (day2 == 'e' || day2 == 'E')) {
				dayOfWeek = "Wednesday";
				validDay = true;
			}

			else if ((day1 == 't' || day1 == 'T') && (day2 == 'h' || day2 == 'H')) {
				dayOfWeek = "Thursday";
				validDay = true;
			}

			else if ((day1 == 'f' || day1 == 'F') && (day2 == 'r' || day2 == 'R')) {
				dayOfWeek = "Friday";
				validDay = true;
			}

			else if ((day1 == 's' || day1 == 'S') && (day2 == 'a' || day2 == 'A')) {
				dayOfWeek = "Saturday";
				validDay = true;
			}

			else if ((day1 == 's' || day1 == 'S') && (day2 == 'u' || day2 == 'U')) {
				dayOfWeek = "Sunday";
				validDay = true;
			}
			else { cout << "This is not a day of the week..." << endl; }
		}

		while (validTime == false)
		{
			cout << "Enter the time of the call in 24 hour notation." << endl;
			cin >> hour >> minutes;
			if (hour < 0 || hour > 23 || minutes < 0 || minutes > 59) {
				cout << "This is not a correct time..." << endl;
			}

			else {
				validTime = true;
			}
		}

		cout << "The day of the call is: " << dayOfWeek << endl;
		cout << "The time is: " << hour << ":" << minutes << endl;

		cout << "How long was your call, in minutes?" << endl;
		cin >> duration;

		if (dayOfWeek == "Saturday" || dayOfWeek == "Sunday") {
			cout << "Our weekend rates are $0.15 per minute!" << endl;
			cost = duration * 0.15;
		}

		else {
			if ((hour >= 8 && hour <= 17) || (hour == 18 && minutes == 0)) {
				cout << "Our main weekday rates are $0.40 per minute!" << endl;
				cost = duration * 0.40;
			}

			else {
				cout << "Our off-time weekday rates are $0.25 per minute!" << endl;
				cost = duration * 0.25;
			}
		}
		totalCost += cost;

		cout << "The cost of this call is: $" << cost << endl;
		cout << "The total cost of your call(s): $" << totalCost << endl;

		

		while (validAnswer == false) {
			cout << "Would you like to input another call? 'Y'/'N'" << endl;
			cin >> answer;

			if (answer == 'y' || answer == 'Y') {
				validAnswer = true;
			}

			else if (answer == 'n' || answer == 'N'){
				answerAgain = false;
				validAnswer = true;
			}

			else { cout << "That is not a correct answer..." << endl; }
		}
	}
	cout << "The total cost of your call(s): $" << totalCost << endl;
	cout << "Thanks for using our phone service." << endl;
	return 0;
}
