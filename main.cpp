#include "heist.h"
using namespace std;

// Initial test driver for base Character, Victim, and Detective classes
int main() {
    Detective player("Agent_Halim", 100);
    Victim victim("Mr.Leonardo", "French", 'S', 1);

    player.display();
    victim.display();

    system("pause");
    return 0;
}