// This program will output random Powerball and 
//Mega Millions and Mississippi Math 5 lottery numbers 
//based on which of the three are chosen by the user.

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>


using namespace std;

class lottery {
private:
    string name;
    int maxnum = 69;
    int picks;
    int pballnum;
    int msmax = 35;

public:
    lottery(string n, int max, int p, int pball = 0)
    : name(n), maxnum(max), picks(p), pballnum(pball) {}

    vector<int> drawNumbers() {
        vector<int> numbers;
        random_device rn;
        mt19937 gen(rn());
        uniform_int_distribution<> dist(1, maxnum);


        while (numbers.size() < picks) {
            int num = dist(gen);
            if (find(numbers.begin(), numbers.end(), num) == numbers.end()) {
                numbers.push_back(num);

            }
        }

        sort(numbers.begin(), numbers.end());

        return numbers;
    }


    int drawBonus() const {
        if (pballnum == 0) return -1;
        random_device rn;
        mt19937 gen(rn());
        uniform_int_distribution<> dist(1, pballnum);
        return dist(gen);
    }

    void play() {
        auto nums = drawNumbers();
        cout << name << " numbers: ";
        for (int n : nums) cout <<  n << " ";
        if (pballnum > 0) cout << "|Bonus: " << drawBonus();
        cout << "\n";
    }
};



int main() {
    lottery powerball("Powerball", 69, 5, 26);
    lottery mega("Mega Millions", 70, 5, 25);
    lottery ms_match5("Mississippi Match 5", 35, 5);

    cout << "Choose a game to play:\n";
    cout << "  [1] Powerball\n";
    cout << "  [2] Mega Millions\n";
    cout << "  [3] Mississippi Match 5\n";
    cout << "  [0] Exit\n";

    int choice;

    while (true) {
        cout << "\nEnter choice: ";
        if (!(cin >> choice)) {
            cerr << "Invalid input. Exiting.\n";
            return 1;
        }
        if (choice == 0) break;

        switch (choice) {
            case 1: powerball.play(); break;
            case 2: mega.play(); break;
            case 3: ms_match5.play(); break;
            default: cout << "Please choose 0–3.\n"; break;
        }
    }

    cout << "Goodbye!\n";
    return 0;
}
