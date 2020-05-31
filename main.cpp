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

    friend class MusicSetBuilder;
public:
    MusicSet(){};

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
                    break;
                case instruments::ukulele:
                    s += "ukulele, ";
                    break;
                case instruments::guitar:
                    s += "guitar, ";
                    break;
                case instruments::drum:
                    s += "drum, ";
                    break;
                case instruments::viola :
                    s += "viola , ";
                    break;
            }
        }

        for (auto &vec_parts : _part) {
            switch (*vec_parts) {
                case parts::strings :
                    s += "strings, ";
                    break;
                case parts::sticks :
                    s += "sticks, ";
                    break;
                case parts::wipes :
                    s += "wipes, ";
                    break;
                case parts::capo :
                    s += "capo, ";
                    break;
            }
        }

        for (auto &vec_chems : _chem) {
            switch (*vec_chems) {
                case chems::flavouring :
                    s += "flavouring, ";
                    break;
                case chems::polish :
                    s += "polish, ";
                    break;
                case chems::wax :
                    s += "wax, ";
                    break;
                case chems::varnish :
                    s += "varnish, ";
                    break;
            }
        }

        return s;
    }
};

class MusicSetBuilder {
private:
    vector<instruments> inst;
    vector<parts> part;
    vector<chems> chemistry;
public:
    void addInstrument(instruments _inst){
        inst.push_back(_inst);
    }

    void addPart(parts _part){
        part.push_back(_part);
    }

    void addChem (chems _chemistry){
        chemistry.push_back(_chemistry);
    }

    MusicSet* build(){
        MusicSet* music_set = new MusicSet();
        for (auto & instr : inst){
            music_set->_instrument.push_back(new instruments(instr));
        }
        for (auto & _parts : part){
            music_set->_part.push_back(new parts(_parts));
        }
        for (auto & _chemistry : chemistry){
            music_set->_chem.push_back(new chems(_chemistry));
        }
        return music_set;
    }
};

void userGUI(MusicSetBuilder& builder){
   builder.addInstrument(piano);
   builder.addInstrument(guitar);
   builder.addPart(strings);
   builder.addChem(polish);

    MusicSet* mus_set = builder.build();
    cout << mus_set->toString() << " it's your music set." << endl;
}

int main() {
    MusicSetBuilder new_music_set;
    MusicSetBuilder sec_music_set;
    sec_music_set.addInstrument(ukulele);
    sec_music_set.addPart(wipes);

    userGUI(new_music_set);
    userGUI(sec_music_set);
    return 0;
}
