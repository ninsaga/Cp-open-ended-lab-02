#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct books {
    string title;
    string author;
    int publication_year;
    string genre;
};


void input_details(books details[6]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 1; j <= 25; j++) {
            cout << "-";
        }
        cout << endl;
        cout << "Details for book " << i + 1 << endl;
        for (int j = 1; j <= 25; j++) {
            cout << "-";
        }
        cout << endl;
        cout << "Title: ";
        cin.ignore();
        getline(cin, details[i].title);
        cout << "Author: ";
        getline(cin, details[i].author);
        cout << "Publication year: ";
        while (!(cin >> details[i].publication_year)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid year: ";
        }
        bool flag = false;
        do {
            cout << "Genre (fiction/non-fiction): ";
            cin >> details[i].genre;
            if (details[i].genre == "fiction" || details[i].genre == "non-fiction") {
                flag = true;
            }
            else {
                cout << "Enter correct input (fiction/non fiction)" << endl;
            }
        } while (!flag);
    }
}


void categories(books details[6], books fiction[3], books nonFiction[3]) {
    int f_count = 0;
    int nf_count = 0;
    for (int i = 0; i < 6; i++) {
        if (details[i].genre == "fiction") {
            fiction[f_count++] = details[i];
        }
        else {
            nonFiction[nf_count++] = details[i];
        }
    }
}

books find_earliest(books details[], int num) {
    books earliest = details[0];
    for (int i = 1; i < num; i++) {
        if (details[i].publication_year < earliest.publication_year) {
            earliest = details[i];
        }
    }
    return earliest;
}

void display(books details) {
    cout << "Title: " << details.title << endl;
    cout << "Author: " << details.author << endl;
    cout << "Publication year: " << details.publication_year << endl;
    cout << "Genre: " << details.genre << endl;
}

int main() {
    books details[6];
    books fiction[3];
    books nonFiction[3];

    input_details(details);
    categories(details, fiction, nonFiction);

    books earliest_fiction = find_earliest(fiction, 3);
    books earliest_nonFiction = find_earliest(nonFiction, 3);
    for (int j = 1; j <= 25; j++) {
        cout << "-";
    }
    cout << endl;
    cout << "Earliest fiction book: " << endl;
    display(earliest_fiction);
    for (int j = 1; j <= 25; j++) {
        cout << "-";
    }
    cout << endl;
    cout << "Earliest non-fiction book: " << endl;
    display(earliest_nonFiction);
    for (int j = 1; j <= 25; j++) {
        cout << "-";
    }
    cout << endl;
    cout << "All Books: " << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 1; j <= 25; j++) {
            cout << "-";
        }
        cout << endl;
        display(details[i]);
        for (int j = 1; j <= 25; j++) {
            cout << "-";
        }
        cout << endl;
    }

    return 0;
}

