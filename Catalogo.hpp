#ifndef CATALOGO_HPP
#define CATALOGO_HPP

#include <list>

#include "Marca.hpp"
#include "Veiculo.hpp"

namespace locadora {
class Catalogo {
   public:
    Catalogo();
    virtual ~Catalogo() = default;

    std::list<Veiculo*> getVeiculos() const;
    std::list<Marca*> getMarcas() const;

    void adicionarVeiculo(Veiculo* const veiculo);
    void removerVeiculo(Veiculo* const veiculo);

    void adicionarMarca(Marca* const marca);
    void removerMarca(Marca* const marca);

   private:
    std::list<Veiculo*> veiculos;
    std::list<Marca*> marcas;
};
}  // namespace locadora

#endif