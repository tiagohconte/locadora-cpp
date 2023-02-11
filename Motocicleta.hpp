#ifndef MOTOCICLETA_HPP
#define MOTOCICLETA_HPP

#include "Veiculo.hpp"

namespace locadora {
class Motocicleta : public Veiculo {
   public:
    Motocicleta(Marca* const marca, const std::string& modelo,
                const float custo, const unsigned short int capacidade,
                const Placa& placa, const unsigned short int cilindrada);
    virtual ~Motocicleta() = default;

    unsigned short int getCilindrada() const;
    void setCilindrada(const unsigned short int cilindrada);

   private:
    unsigned short int cilindrada;
};
}  // namespace locadora

#endif
