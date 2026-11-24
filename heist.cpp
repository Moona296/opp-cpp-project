#include "heist.h"

// Initializes base character attributes
Character::Character(const string& n, const string& r, const string& nat)
    : charactername(n), characterrole(r), nationality(nat), isculprit(false) {
}

Character::~Character() {}
string Character::getName() const { return charactername; }
string Character::getRole() const { return characterrole; }
string Character::getNationality() const { return nationality; }
bool Character::getIsCulprit() const { return isculprit; }
void Character::setIsCulprit(bool value) { isculprit = value; }

// Victim constructor and interrogation eligibility check
Victim::Victim(const string& n, const string& nat, char letter, int pos)
    : Character(n, "Business Owner", nat), cluerowchar(Word2),
    lettercluechar(letter), boardposchar(pos), interviewed(false) {
}

void Victim::display() const {
    cout << charactername << " (" << characterrole << ") - " << nationality << " [Victim]" << endl;
}

bool Victim::canInterview(int credibility) const { return credibility >= 80; }
Clue Victim::getClue() const { return Clue(lettercluechar, boardposchar, cluerowchar); }
bool Victim::hasInterviewed() const { return interviewed; }
void Victim::setInterviewed(bool value) { interviewed = value; }

// Detective constructor and status management
Detective::Detective(const string& n, int c)
    : Character(n, "Detective", "Malay"), credibility(c), turns(0) {
}

void Detective::display() const {
    cout << charactername << " | Credibility: " << credibility << " | Turns used: " << turns << endl;
}

int Detective::getCredibility() const { return credibility; }
int Detective::getTurns() const { return turns; }
void Detective::setTurns(int value) { turns = value; }

void Detective::changeCredibility(int amount) {
    credibility += amount;
    if (credibility < 0) credibility = 0;
}
