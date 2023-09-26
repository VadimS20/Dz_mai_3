#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name;
	cout << "Write path to your file" << endl;
	cin >> name;
	ifstream file(name);
	ofstream newfile("a:\\answer.txt");

	bool check = false; //проверка открытия скобок
	string s;
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, s);
			for (int i = 0; i < s.length(); i++) {
				if (check) {
					if (s[i] == '~') {
						s[i] = '-';
					}
					if (s[i] == '=') {
						s[i] = '+';
					}
					if (s[i] == '}') {
						s[i] = ' ';
						check = false;
					}
				}
				else {
					if (s[i] == '{') {
						s[i] = ' ';
						check = true;
					}
				}
			}
			newfile << s << endl;
			cout << s << "\n";
		}
	}

	return 0;
}
