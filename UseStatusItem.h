#ifndef USESTATUSITEM_H
#define USESTATUSITEM_H

#include "UseItem.h"
#include "Character.h"
#include "Status.h"
#include <string>

using namespace std;

// Class definition for UseStatusItem class
class UseStatusItem: public UseItem {
    private:
        Status* StatusEffect;
    public:
        Execute(Character* Target, Character* Actor);
};

#endif //USESTATUSITEM_H