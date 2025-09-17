// This program will output random Powerball and 
//Mega Millions lottery numbers based on which of
//the two are chosen by the user.

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

    powerball.play();
    mega.play();

    return 0;
}