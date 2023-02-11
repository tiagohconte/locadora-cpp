#ifndef MARCA_HPP
#define MARCA_HPP

#include <string>
#include <list>

#include "Veiculo.hpp"

namespace locadora {
class Marca {
    friend void Veiculo::setMarca(Marca* marca);

    public:
        Marca(const std::string& nome);

        unsigned int getId() const;

        std::string getNome() const;
        void setNome(const std::string& nome);

        std::list<Veiculo *>& getVeiculos();

    private:
        static unsigned int proxId;
        unsigned int id;
        std::string nome;
        std::list<Veiculo *> veiculos;
};
}  // namespace locadora

#endif