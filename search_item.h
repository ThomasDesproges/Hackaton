#include "item.h"
#include <vector>

Item* search_item(std::vector <Item*>* liste_items,int posx, int posy){
    int n=(*liste_items).size();
    int i=0;
    Item* item=nullptr;
    while(i<n){ // je balaye la liste des items
        if ((*liste_items)[i]->is(posx,posy)){ // si cet item est celui ou je suis
            item=(*liste_items)[i];
            (*liste_items).erase((*liste_items).begin()+i);
        }
        i++;
    }
    return(item);
}
