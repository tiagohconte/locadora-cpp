#ifndef CATALOGO_HPP
#define CATALOGO_HPP

#include <list>

#include "Veiculo.hpp"

namespace locadora {
class Catalogo {
    public:
        Catalogo();
        virtual ~Catalogo() = default;

        std::list<Veiculo*> getCatalogo() const;
        
        void adicionaVeiculo(Veiculo* const veiculo);


    private:
        std::list<Veiculo*> veiculos;
};
}

#endif