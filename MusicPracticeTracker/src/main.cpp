
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Enum for difficulty
enum Difficulty {
    EASY = 1,
    MEDIUM,
    HARD
};

// Song class
class Song {
private:
    int id;
    string name;
    string instruments;
    int dailygoals;
    int completedMinutes;
    Difficulty difficulty;

    static int totalSongs;

public:

    // Setters
    void setID(int songID) {
        id = songID;
    }

    void setName(string songName) {
        name = songName;
    }

    void setInstruments(string songInstruments) {
        instruments = songInstruments;
    }

    void setDailyGoals(int goal) {
        dailygoals = goal;
    }

    void setCompletedMinutes(int minutes) {
        completedMinutes = minutes;
    }

    void setDifficulty(Difficulty level) {
        difficulty = level;
    }

    // Getters
    int getID() {
        return id;
    }

    string getName() {
        return name;
    }

    string getInstruments() {
        return instruments;
    }

    int getDailyGoals() {
        return dailygoals;
    }

    int getCompletedMinutes() {
        return completedMinutes;
    }

    // This pointer
    void showAddress() {
        cout << "Object address: " << this << endl;
    }

    // Display song
    void displaysong() {
        cout << "\nSong ID: " << id;
        cout << "\nSong Name: " << name;
        cout << "\nInstruments: " << instruments;
        cout << "\nDaily Goal: " << dailygoals << " minutes";
        cout << "\nCompleted Practice: " << completedMinutes << " minutes";

        cout << "\nDifficulty: ";

        if (difficulty == EASY)
            cout << "Easy";
        else if (difficulty == MEDIUM)
            cout << "Medium";
        else
            cout << "Hard";

        cout << "\n------------------------------\n";
    }

    // Static functions
    static void showTotalSongs() {
        cout << "\nTotal Songs: " << totalSongs << endl;
    }

    static void increaseTotalSongs() {
        totalSongs++;
    }

    static void decreaseTotalSongs() {
        totalSongs--;
    }
};

// Static member definition
int Song::totalSongs = 0;


// Search song by ID
int searchSong(Song songs[], int count, int searchID) {

    for (int i = 0; i < count; i++) {
        if (songs[i].getID() == searchID) {
            return i;
        }
    }

    return -1;
}


// Add song
void addSong(Song songs[], int &count) {

    if (count >= 100) {
        cout << "\nSong storage is full!\n";
        return;
    }

    int id, goal, minutes, level;
    string name, instruments;

    cout << "\nEnter Song ID: ";
    cin >> id;

    if (searchSong(songs, count, id) != -1) {
        cout << "\nThis Song ID already exists!\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Song Name: ";
    getline(cin, name);

    cout << "Enter Instrument: ";
    getline(cin, instruments);

    cout << "Enter Daily Goal: ";
    cin >> goal;

    cout << "Enter Completed Minutes: ";
    cin >> minutes;

    cout << "\n1. Easy\n2. Medium\n3. Hard\n";
    cout << "Enter Difficulty: ";
    cin >> level;

    if (goal <= 0 || minutes < 0 || level < 1 || level > 3) {
        cout << "\nInvalid input! Song not added.\n";
        return;
    }

    songs[count].setID(id);
    songs[count].setName(name);
    songs[count].setInstruments(instruments);
    songs[count].setDailyGoals(goal);
    songs[count].setCompletedMinutes(minutes);
    songs[count].setDifficulty((Difficulty)level);

    count++;

    Song::increaseTotalSongs();

    cout << "\nSong added successfully!\n";
}


// View all songs
void viewSongs(Song songs[], int count) {

    if (count == 0) {
        cout << "\nNo songs available.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        songs[i].displaysong();
    }
}


// Find song
void findSong(Song songs[], int count) {

    int id;

    cout << "\nEnter Song ID: ";
    cin >> id;

    int index = searchSong(songs, count, id);

    if (index == -1) {
        cout << "\nSong not found!\n";
    }
    else {
        cout << "\nSong found!\n";
        songs[index].displaysong();
    }
}


// Update song
void updateSong(Song songs[], int count) {

    int id;

    cout << "\nEnter Song ID to update: ";
    cin >> id;

    int index = searchSong(songs, count, id);

    if (index == -1) {
        cout << "\nSong not found!\n";
        return;
    }

    int goal, minutes, level;
    string name, instruments;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter New Song Name: ";
    getline(cin, name);

    cout << "Enter New Instrument: ";
    getline(cin, instruments);

    cout << "Enter New Daily Goal: ";
    cin >> goal;

    cout << "Enter Completed Minutes: ";
    cin >> minutes;

    cout << "Enter Difficulty (1-Easy, 2-Medium, 3-Hard): ";
    cin >> level;

    if (goal <= 0 || minutes < 0 || level < 1 || level > 3) {
        cout << "\nInvalid input! Details not updated.\n";
        return;
    }

    songs[index].setName(name);
    songs[index].setInstruments(instruments);
    songs[index].setDailyGoals(goal);
    songs[index].setCompletedMinutes(minutes);
    songs[index].setDifficulty((Difficulty)level);

    cout << "\nSong updated successfully!\n";
}


// Delete song
void deleteSong(Song songs[], int &count) {

    int id;

    cout << "\nEnter Song ID to delete: ";
    cin >> id;

    int index = searchSong(songs, count, id);

    if (index == -1) {
        cout << "\nSong not found!\n";
        return;
    }

    for (int i = index; i < count - 1; i++) {
        songs[i] = songs[i + 1];
    }

    count--;

    Song::decreaseTotalSongs();

    cout << "\nSong deleted successfully!\n";
}


// Calculate total practice
int calculateTotalPractice(Song songs[], int count) {

    int total = 0;

    for (int i = 0; i < count; i++) {
        total += songs[i].getCompletedMinutes();
    }

    return total;
}


// Recursion
int recursiveSum(int number) {

    if (number == 0) {
        return 0;
    }

    return number + recursiveSum(number - 1);
}


// Pointer demonstration
void pointerDemo() {

    int number = 50;
    int *ptr = &number;

    cout << "\nOriginal value: " << number << endl;
    cout << "Value using pointer: " << *ptr << endl;

    *ptr = 100;

    cout << "Updated value: " << number << endl;
}


// Reference demonstration
void referenceDemo() {

    int number = 10;
    int &ref = number;

    cout << "\nOriginal value: " << number << endl;

    ref = 25;

    cout << "Value after reference update: " << number << endl;
}


// Main function
int main() {

    Song songs[100];

    int count = 0;
    int choice;

    do {

        cout << "\n================================";
        cout << "\n     MUSIC PRACTICE TRACKER";
        cout << "\n================================";

        cout << "\n1. Add Song";
        cout << "\n2. View All Songs";
        cout << "\n3. Search Song";
        cout << "\n4. Update Song";
        cout << "\n5. Delete Song";
        cout << "\n6. Total Practice Minutes";
        cout << "\n7. Total Songs";
        cout << "\n8. Pointer Demonstration";
        cout << "\n9. Reference Demonstration";
        cout << "\n10. Recursion Demonstration";
        cout << "\n11. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addSong(songs, count);
                break;

            case 2:
                viewSongs(songs, count);
                break;

            case 3:
                findSong(songs, count);
                break;

            case 4:
                updateSong(songs, count);
                break;

            case 5:
                deleteSong(songs, count);
                break;

            case 6:
                cout << "\nTotal Practice Minutes: "
                     << calculateTotalPractice(songs, count) << endl;
                break;

            case 7:
                Song::showTotalSongs();
                break;

            case 8:
                pointerDemo();
                break;

            case 9:
                referenceDemo();
                break;

            case 10: {
                int number;

                cout << "\nEnter a positive number: ";
                cin >> number;

                if (number >= 0 && number <= 100) {
                    cout << "Recursive Sum: "
                         << recursiveSum(number) << endl;
                }
                else {
                    cout << "Enter a number between 0 and 100.\n";
                }

                break;
            }

            case 11:
                cout << "\nThank you for using Music Practice Tracker!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 11);

    return 0;
}