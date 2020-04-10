#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

template <class Container>
void split1(const string& str, Container& cont)
{
	istringstream iss(str);
	copy(istream_iterator<string>(iss),
			  istream_iterator<string>(),
			  back_inserter(cont));
}

int main() {
    int n;
	char a;

	while (cin >> n, cin.ignore()) {

		map<string, map<string, bool>> menu;

		for (int i = 0; i < n; i++) {
			string linea;
			vector<string> remainder;

			getline(cin, linea);
			split1(linea, remainder);

			for (int i = 1; i < remainder.size(); ++i) {
				menu[remainder[i]][remainder[0]] = true;
			}
		}
		for (const pair<string, map<string, bool>> &item: menu) {
			cout << item.first << " ";
			for (const pair<string, bool> &name: item.second) {
				cout << name.first << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
    return 0;
}
