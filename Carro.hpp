#ifndef CARRO_HPP
#define CARRO_HPP

#include "Veiculo.hpp"

namespace locadora {

enum class EnumCategoria { SEDAN, HATCH, SUV };

class Carro : public Veiculo {
   public:
    Carro(Marca* const marca, const std::string& modelo, const float custo,
          const unsigned short int capacidade, const Placa& placa,
          const unsigned short int portas, const EnumCategoria categoria);

    virtual ~Carro() = default;

    unsigned short int getPortas() const;
    void setPortas(const unsigned short int portas);

    EnumCategoria getCategoria() const;
    void setCategoria(const EnumCategoria categoria);

   private:
    unsigned short int portas;
    EnumCategoria categoria;
};
}  // namespace locadora

#endif
