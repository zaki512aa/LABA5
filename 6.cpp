#include <iostream>
#include <vector>
using namespace std;

vector<string> findMatchingStrings(const vector<string>& data, const string& query) {
    vector<string> matches;
    for (const string& str : data) {

        if (str.find(query) != string::npos) {

            matches.push_back(str);
        }
    }
    return matches;
}

int main() {
    int n;
    cout << "vvedite kolichestvo strok s dannimi: ";

    if (!(cin >> n) || n <= 0) {
        cout << "oshibka: vvedeno nevernoe kolichestvo." << endl;
        return 1;
    }
    cin.ignore();

    vector<string> dataStrings;
    string line;
    cout << "vvedite " << n << " strok dannih:" << endl;

    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        dataStrings.push_back(line);
    }

    string searchQuery;
    cout << "\nvvedite poiskovuyu stroku: ";
    getline(cin, searchQuery);

    vector<string> foundStrings = findMatchingStrings(dataStrings, searchQuery);

    cout << "\n--- Naydennie stroki ---" << endl;

    for (const string& str : foundStrings) {
        cout << str << endl;
    }

    return 0;
}
