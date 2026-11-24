#ifndef HEIST_H
#define HEIST_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Enumerations for game states, menu options, and Scrabble rows
enum WordRow { Word1, Word2 };
enum GameState { Menu, Playing, Won, Lost, Exit };
enum MenuChoice { NewGame = 1, ViewLeaderScoreBoard, About, Rules, ExitGame };

// Struct utilized to represent a single letter tile on the board
struct Tile {
    char tileletter;
    bool filled;
    Tile(char letter = ' ', bool state = false)
        : tileletter(letter), filled(state) {
    }
};

// Struct utilized as a carrier to pass clue letters and positions
struct Clue {
    char clueletter;
    int clueposition;
    WordRow cluerow;
    Clue(char letter = ' ', int position = 0, WordRow row = Word1)
        : clueletter(letter), clueposition(position), cluerow(row) {
    }
};

// Struct utilized to store cottage location details
struct Location {
    string locname;
    char letterclueloc;
    int boardposloc;
    WordRow locrow;
    bool locsearchflag;
    Location(string name = "", char letter = ' ', int pos = 0,
        WordRow row = Word1, bool searched = false)
        : locname(name), letterclueloc(letter), boardposloc(pos),
        locrow(row), locsearchflag(searched) {
    }
};

// Class Begin: Abstract Base Class Character
class Character {
protected:
    string charactername, characterrole, nationality;
    bool isculprit;
public:
    Character(const string&, const string&, const string&);
    virtual ~Character();
    virtual void display() const = 0;
    string getName() const;
    string getRole() const;
    string getNationality() const;
    bool getIsCulprit() const;
    void setIsCulprit(bool);
};

// Class Begin: Victim Class derived from Character
class Victim : public Character {
    WordRow cluerowchar;
    char lettercluechar;
    int boardposchar;
    bool interviewed;
public:
    Victim(const string&, const string&, char, int);
    void display() const;
    bool canInterview(int) const;
    Clue getClue() const;
    bool hasInterviewed() const;
    void setInterviewed(bool);
};

// Class Begin: Detective Class (Player) derived from Character
class Detective : public Character {
    int credibility, turns;
public:
    Detective(const string&, int);
    void display() const;
    int getCredibility() const;
    int getTurns() const;
    void setTurns(int);
    void changeCredibility(int);
};

#endif#pragma once
