#ifndef CARRO_HPP
#define CARRO_HPP

#include <unordered_map>

#include "Veiculo.hpp"

namespace locadora {

enum class EnumCategoria { CAMINHONETE, HATCH, SEDAN, SUV };
static std::unordered_map<EnumCategoria, std::string> nomeCategoria = {
      {EnumCategoria::CAMINHONETE, "Caminhonete"},
      {EnumCategoria::HATCH, "Hatch"},
      {EnumCategoria::SEDAN, "Sedan"},
      {EnumCategoria::SUV, "SUV"}
};

class Carro : public Veiculo {
   public:
    Carro(Marca* const marca, const std::string& modelo, const float custo,
          const unsigned short int capacidade, const Placa& placa,
          const unsigned short int portas, const EnumCategoria categoria);

    Carro(Marca* const marca, const std::string& modelo, const float custo,
          const unsigned short int capacidade, const std::string& placa,
          const unsigned short int portas, const EnumCategoria categoria);

    virtual ~Carro() = default;

    unsigned short int getPortas() const;
    void setPortas(const unsigned short int portas);

    EnumCategoria getCategoria() const;
    void setCategoria(const EnumCategoria categoria);
    std::string getNomeCategoria() const;

   private:
    unsigned short int portas;
    EnumCategoria categoria;
};
}  // namespace locadora

#endif
