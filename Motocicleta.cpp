#include "Motocicleta.hpp"

namespace locadora {

Motocicleta::Motocicleta(Marca* const marca, const std::string& modelo,
                         const float custo, const unsigned short int capacidade,
                         const Placa& placa,
                         const unsigned short int cilindrada)
    : Veiculo{marca, modelo, custo, capacidade, placa},
      cilindrada{cilindrada} {}

unsigned short int Motocicleta::getCilindrada() const {
    return this->cilindrada;
}

void Motocicleta::setCilindrada(const unsigned short int cilindrada) {
    this->cilindrada = cilindrada;
}

}  // namespace locadora