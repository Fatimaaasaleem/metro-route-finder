#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void toLowerCase(string &str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void searchStation(const vector<string> &stations, string start, string end)
{
    toLowerCase(start);
    toLowerCase(end);

    int startIndex = -1, endIndex = -1;

    for (int i = 0; i < stations.size(); i++)
    {
        string stationLower = stations[i];
        toLowerCase(stationLower);

        if (stationLower == start)
            startIndex = i;
        if (stationLower == end)
            endIndex = i;
    }

    if (startIndex == -1 || endIndex == -1)
    {
        cout << "Start or end station not found.\n";
        return;
    }

    int time = 0;
    if (startIndex > endIndex)
    {
        cout << "Stations from " << stations[startIndex] << " back to " << stations[endIndex] << ":\n";
        for (int i = startIndex; i >= endIndex; i--)
        {
            cout <<i+1<<" : " <<stations[i] << endl;
            time += 2;
        }
    }
    else
    {
        cout << "Stations from " << stations[startIndex] << " to " << stations[endIndex] << ":\n";
        for (int i = startIndex; i <= endIndex; i++)
        {
            cout <<i+1<<" : " <<stations[i] << endl;
            time += 2;
        }
    }

    cout << "The time it will take to reach from " << stations[startIndex] << " to " << stations[endIndex] << " is approximately :" << time << " minutes\n";
}

struct Node {
    string station;
    Node *next;
    Node *prev;
};

class Queue {
private:
    Node *head;
    Node *tail;

public:
    Queue() {
        head = tail = nullptr; 
    }

   
    void enqueue(string station) {
        Node *newNode = new Node;
        newNode->station = station;

        if (head == nullptr) {
            
            newNode->next = newNode;
            newNode->prev = newNode;
            head = tail = newNode;
        } else {
          
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode; 
        }
    }
};
class redMetro
{
public:
    Node *head;
    Queue ddl;
    vector<string> stations;

    redMetro()
    {
        head = nullptr;
        stations = {"saddar", "marrir chowk", "liaquat bagh", "committee chowk", "waris khan", "chandni chowk", "rehmanabad",
                    "6th road", "shamsabad", "faizabad", "ijp", "potohar", "khayaban e johar", "faiz ahmed faiz", "kashmir highway", "chaman",
                    "ibn e sina", "katchehry", "pims", "stock exchange", "7th avenue", "shaheed millat", "parade ground", "pak scretariat"};

        for (const string &station : stations)
        {
            ddl.enqueue(station);
        }
    }
};

class greenMetro
{
public:
    Node *head;
    Queue ddl;
    vector<string> stations;

    greenMetro()
    {
        head = nullptr;
        stations = {"pims", "sohan", "kuri road", "khanna pull", "gangal stop", "koral chowk", "gulberg"};

        for (const string &station : stations)
        {
            ddl.enqueue(station);
        }
    }
};

class blueMetro
{
public:
    Node *head;
    Queue ddl;
    vector<string> stations;

    blueMetro()
    {
        head = nullptr;
        stations = {"pims", "cda headquarters", "aabpara", "mna hostel", "serena hotel", "lake view park", "bari imam", "malpur", "shadara", "dhok jilnal", "barakahu"};

        for (const string &station : stations)
        {
            ddl.enqueue(station);
        }
    }
};

class orangeMetro
{
public:
    Node *head;
    Queue ddl;
    vector<string> stations;

    orangeMetro()
    {
        head = nullptr;
        stations = {"faiz ahmed faiz", "g-9", "high court", "police foundation", "nust", "golra mor", "gt road", "airport"};

        for (const string &station : stations)
        {
            ddl.enqueue(station);
        }
    }
};

int main()
{
    redMetro red;
    greenMetro green;
    blueMetro blue;
    orangeMetro orange;

    string start, end;

    cout << "What station do you want to start from in red metro?\n";
    getline(cin, start);

    cout << "What station do you want to end on?\n";
    getline(cin, end);

    searchStation(red.stations, start, end);
    string blueStart,blueEnd;
     cout << "What station do you want to start from in blue metro?\n";
    getline(cin, blueStart);

    cout << "What station do you want to end on?\n";
    getline(cin, blueEnd);

    searchStation(blue.stations, blueStart, blueEnd);
    string orangeStart,orangeEnd;
     cout << "What station do you want to start from in orange metro?\n";
    getline(cin, orangeStart);

    cout << "What station do you want to end on?\n";
    getline(cin, orangeEnd);

    searchStation(orange.stations, orangeStart, orangeEnd);
    string greenStart,greenEnd;
     cout << "What station do you want to start from in green metro?\n";
    getline(cin, greenStart);

    cout << "What station do you want to end on?\n";
    getline(cin, greenEnd);

    searchStation(green.stations, greenStart, greenEnd);

    return 0;
}
