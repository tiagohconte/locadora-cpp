#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <string>

#include "Placa.hpp"

namespace locadora {

enum class EnumStatus { DISPONIVEL, INDISPONIVEL };

class Marca;
class Veiculo {
    public:
     Veiculo(Marca* const marca, const std::string& modelo, const float custo,
             const unsigned short int capacidade, const Placa& placa);

     Veiculo(Marca* const marca, const std::string& modelo, const float custo,
             const unsigned short int capacidade, const std::string& placa);

     virtual ~Veiculo() = default;

     unsigned int getId() const;

     const Marca* getMarca() const;
     void setMarca(Marca* const marca);

     std::string getModelo() const;
     void setModelo(const std::string& modelo);

     float getCusto() const;
     void setCusto(const float custo);

     unsigned short int getCapacidade() const;
     void setCapacidade(const unsigned short int capacidade);

     const Placa& getPlaca() const;
     void setPlaca(const Placa& placa);

     EnumStatus getStatus() const;
     void setStatus(const EnumStatus status);

    private:
        static unsigned int proxId;
        unsigned int id;
        Marca *marca;
        std::string modelo;
        float custo;
        unsigned short int capacidade;
        Placa placa;
        EnumStatus status;
};
}

#endif
