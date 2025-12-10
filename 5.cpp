#include <iostream>
#include <vector>
using namespace std;

string getRandomElement(const vector<string>& vec) {
    if (vec.empty()) {
        return "";
    }
    int randomIndex = rand() % vec.size();
    return vec[randomIndex];
}

int main() {
    srand(time(0));
    vector<string> names = {
        "Ivan", "Petr", "Anton", "Tolya", "Dmitriy",
        "Valera", "Aleksey", "Alexander", "Mihail"
    };

    vector<string> surnames = {
        "Smirnov", "Ivanov", "Sinyakov", "Sokolov",
        "Popov", "Novikov", "Morozov", "Karmanov", "Duvanov"
    };

    int count;
    cout << "vvedite kolichestvo ludey, kotorih nujno sgenerirovat': " << endl;
    if (!(cin >> count) || count <= 0) {
        cout << "oshibka: vvedeno nevernoe kolichestvo." << endl;
        return 1;
    }

    cout << "\n--- Spisok sluchaynih lyudey (" << count << ") ---" << endl;
    for (int i = 0; i < count; ++i) {
        string randomName = getRandomElement(names);
        string randomSurname = getRandomElement(surnames);
        cout << i + 1 << ". " << randomName << " " << randomSurname << endl;
    }

    return 0;
}
