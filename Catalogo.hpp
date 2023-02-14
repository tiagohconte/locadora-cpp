#ifndef CATALOGO_HPP
#define CATALOGO_HPP

#include <list>

#include "Cliente.hpp"
#include "Marca.hpp"
#include "Veiculo.hpp"

namespace locadora {
class Catalogo {
   public:
    Catalogo();
    virtual ~Catalogo() = default;

    std::list<Cliente*> getClientes() const;
    std::list<Marca*> getMarcas() const;
    std::list<Veiculo*> getVeiculos() const;

    void adicionarCliente(Cliente* const cliente);
    void removerCliente(Cliente* const cliente);
    Cliente* getClienteByCPF(const CPF& cpf) const;

    void adicionarMarca(Marca* const marca);
    void removerMarca(Marca* const marca);
    Marca* getMarcaById(const unsigned int id) const;

    void adicionarVeiculo(Veiculo* const veiculo);
    void removerVeiculo(Veiculo* const veiculo);

   private:
    std::list<Cliente*> clientes;
    std::list<Marca*> marcas;
    std::list<Veiculo*> veiculos;
};
}  // namespace locadora

#endif