#include "ListTimeGrid.hpp"


ListTimeGrid::ListTimeGrid(const PnlVect* datesInDays) {
    datesInDays_ = pnl_vect_copy(datesInDays);
}

ListTimeGrid::~ListTimeGrid() {
    if (datesInDays_ != nullptr) {
        pnl_vect_free(&datesInDays_);
    }
}


int ListTimeGrid::at(int index) const {
    return GET(datesInDays_, index);
}

int ListTimeGrid::len() const {
    return datesInDays_->size;
}

bool ListTimeGrid::has(int nDays) const {
    for (int i = 0; i < datesInDays_->size; i++) {
        if (GET(datesInDays_, i) == nDays) {
            return true;
        }
    }
    return false;
}

