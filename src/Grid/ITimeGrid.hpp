#ifndef ITIMEGRID_HPP
#define ITIMEGRID_HPP

class ITimeGrid {
public:
    virtual ~ITimeGrid() = default;

    // Renvoie la valeur du temps à l'index donné
    virtual int at(int index) const = 0;

    // Renvoie le nombre de points dans la grille de temps
    virtual int len() const = 0;

    // Vérifie si la grille contient un certain nombre de jours
    virtual bool has(int nDays) const = 0;
};

#endif // ITIMEGRID_HPP
