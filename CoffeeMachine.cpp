#include <iostream>
using namespace std;
class OldCoffeeMachine {
public:
    void selectA() {
        cout << "Coffee flavor one from old machine" << "\n";
    }
    void selectB() {
        cout << "Coffee flavor two from old machine" << "\n";
    }
};

class CoffeeMachineInterface {
public:
    void chooseFirstSelection() {
        cout << "Coffee flavor one from new machine" << "\n";
    }
    void chooseSecondSelection() {
        cout << "Coffee flavor two from new machine" << "\n";
    }
};

class CoffeeTouchscreenAdapter : public CoffeeMachineInterface {
private:
    OldCoffeeMachine* oldVendingMachine;
public:
    CoffeeTouchscreenAdapter(OldCoffeeMachine* oldMachine) {
        oldVendingMachine = oldMachine;
    }
    void chooseFirstSelection() {
        oldVendingMachine->selectA();
    }
    void chooseSecondSelection() {
        oldVendingMachine->selectB();
    }
};

int main() {
    OldCoffeeMachine* oldVendingMachine = new OldCoffeeMachine;
    CoffeeMachineInterface* newMachine = new CoffeeMachineInterface;
    CoffeeTouchscreenAdapter* oldMachine = new CoffeeTouchscreenAdapter(oldVendingMachine);

    newMachine->chooseFirstSelection();
    newMachine->chooseSecondSelection();
    oldMachine->chooseFirstSelection();
    oldMachine->chooseSecondSelection();

    return 0;
}