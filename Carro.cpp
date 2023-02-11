#include "Carro.hpp"

namespace locadora {

Carro::Carro(Marca* const marca, const std::string& modelo, const float custo,
             const unsigned short int capacidade, const Placa& placa,
             const unsigned short int portas, const EnumCategoria categoria)
    : Veiculo{marca, modelo, custo, capacidade, placa},
      portas{portas},
      categoria{categoria} {}

Carro::Carro(Marca* const marca, const std::string& modelo, const float custo,
             const unsigned short int capacidade, const std::string& placa,
             const unsigned short int portas, const EnumCategoria categoria)
    : Veiculo{marca, modelo, custo, capacidade, placa},
      portas{portas},
      categoria{categoria} {}

unsigned short int Carro::getPortas() const { return this->portas; }

void Carro::setPortas(const unsigned short int portas) {
    this->portas = portas;
}

EnumCategoria Carro::getCategoria() const { return this->categoria; }

void Carro::setCategoria(const EnumCategoria categoria) {
    this->categoria = categoria;
}

std::string Carro::getNomeCategoria() const{
    std::unordered_map<EnumCategoria, std::string> nomeCategoria = {
        {EnumCategoria::CAMINHONETE, "Caminhonete"},
        {EnumCategoria::HATCH, "Hatch"},
        {EnumCategoria::SEDAN, "Sedan"},
        {EnumCategoria::SUV, "SUV"}
    };
    return nomeCategoria[this->getCategoria()];
}
}  // namespace locadora