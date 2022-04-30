#ifndef _VECTEUR_HPP_
#define _VECTEUR_HPP_
#include <array>
#include <cmath>
#include <cassert>

class Vecteur
{
public:
    Vecteur()
        : m_coefs{0,0}
    {}
    Vecteur(double x, double y) // Vecteur v(1,1); ou Vecteur* v = new Vecteur(1,1); 
        :   m_coefs{x,y}
    {}

    ~Vecteur() = default;

    double& operator[](int i) // u[2] = 3;
    {
        assert(i>=0); assert(i<2);
        return m_coefs[i];
    }

    double const& operator[](int i) const // auto a =u[1]
    {
        assert(i>=0); assert(i<2);
        return m_coefs[i];
    }

    Vecteur operator + ( Vecteur const& u ) const
    {
        return {m_coefs[0]+u.m_coefs[0],
                m_coefs[1]+u.m_coefs[1]};
    }
    Vecteur operator - ( Vecteur const& u ) const
    {
        return {m_coefs[0]-u.m_coefs[0],
                m_coefs[1]-u.m_coefs[1]};
    }

    Vecteur& operator= (Vecteur const& u){
        m_coefs[0] = u.m_coefs[0];
        m_coefs[1] = u.m_coefs[1];

        return *this; // renvoie le contenue de l'adresse (l'objet pointé par this)
    }
    operator std::string() const 
    {
        return std::string("<") + std::to_string(m_coefs[0]) + ", "
                                + std::to_string(m_coefs[1]) + ">";
    }
    double norme(){
        return sqrt(m_coefs[0]*m_coefs[0] + m_coefs[1]*m_coefs[1]);
    }
private:
    std::array<double,2> m_coefs;
};

inline Vecteur operator * ( double alpha, Vecteur const& u )
{
    return { alpha*u[0], alpha*u[1] };
}
inline Vecteur operator * ( Vecteur const& u, double alpha )
{
    return { alpha*u[0], alpha*u[1] };
}
#endif