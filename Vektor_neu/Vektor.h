//
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

#ifndef Vektor_H
#define Vektor_H

/**
 * @brief A vector in R^3
 */
class Vektor
{
   public:

	//Konstruktor
    Vektor(double x, double y, double z);
    //Destruktor
    ~Vektor();



    //Methoden:
    // 3 Funktionen die die Werte von x, y und z zurueckgeben
    double getX() const;
    double getY() const;
    double getZ() const;
      
    // Vektor addition/subtraktion
    Vektor sub(const Vektor& input) const;
    Vektor add(const Vektor& input) const;
    
    //Norm
    double length() const;

    //Orthogonalitaetstest
    bool ortho(const Vektor& input) const;

    //Skalarprodukt
    double scalarProd(const Vektor& input) const;

    //Winkel zws. zwei Vektoren in grad
    double angle(const Vektor& input) const;
    
    //Rotationmatrix
    void rotateAroundZ(const double rad);
    
    void ausgabe() const;

   private:
    double x;
    double y;
    double z;

};


#endif
