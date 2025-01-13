#include "Person.h"
#include "functions.h"

using namespace std;
int main(int argc, char** argv) {
	int rand, n, k, id;
	int NumComp = 0;
	string name;
	
	bool isValid = true;
	Person* persons = NULL;

	cin >> rand;
	srand(rand);

	cin >> n;
	if (isValidN(n)) {
		persons = new Person[n];
		for (int i = 0; i < n; i++) {
			cin >> id;
			getchar();
			getline(cin, name);

			persons[i].setid(id);
			persons[i].setname(name);
		}
		if (sameID(persons, n)) {
			isValid = false;
		}

		cin >> k;
		if (!isValidK(k, n)) {
			isValid = false;
		}
	}
	else {
		isValid = false;
	}

	if (isValid) {
	
		program(persons, n, k);
		
	}
	else {
		cout << "invalid input" << endl;
		exit(1);
	}

}