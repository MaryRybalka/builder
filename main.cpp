#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum instruments {
    piano,
    ukulele,
    guitar,
    drum,
    viola
};

enum parts {
    strings,
    sticks,
    wipes,
    capo
};

enum chems {
    flavouring,
    polish,
    wax,
    varnish
};

class MusicSet {
private:
    vector<instruments *> _instrument;
    vector<parts *> _part;
    vector<chems *> _chem;
public:
    MusicSet(instruments _instrument) : _instrument(_instrument) {};

    MusicSet(instruments _instrument, parts _part) : _instrument(_instrument), _part(_part) {};

    MusicSet(instruments _instrument, parts _part, chems _chem) : _instrument(_instrument), _part(_part),
                                                                  _chem(_chem) {};

    string toString() {
        string s = "";
        for (auto &vec_instruments : _instrument) {
            switch (*vec_instruments) {
                case instruments::piano:
                    s += "piano, ";
                case instruments::ukulele:
                    s += "ukulele, ";
                case instruments::guitar:
                    s += "guitar, ";
                case instruments::drum:
                    s += "drum, ";
                case instruments::viola :
                    s += "viola , ";
            }
        }

        for (auto &vec_parts : _part) {
            switch (*vec_parts) {
                case parts::strings :
                    s += "strings, ";
                case parts::sticks :
                    s += "sticks, ";
                case parts::wipes :
                    s += "wipes, ";
                case parts::capo :
                    s += "capo, ";
            }
        }

        for (auto &vec_chems : _chem) {
            switch (*vec_chems) {
                case chems::flavouring :
                    s += "flavouring, ";
                case chems::polish :
                    s += "polish, ";
                case chems::wax :
                    s += "wax, ";
                case chems::varnish :
                    s += "varnish, ";
            }
        }

        s+=" it's your MusicSet.";
        return s;
    }
};

class MusicSetBuilder {
private:
    vector<instruments *> inst;
    vector<parts *> part;
    vector<chems *> chemistry;
public:
    void addInstrument(){

    }

    void addInstrument(){

    }

    void addInstrument(){

    }
};

int main() {

    return 0;
}
