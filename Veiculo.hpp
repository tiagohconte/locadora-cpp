#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <string> 

namespace locadora {
class Veiculo {
    public:
        Veiculo(std::string &modelo, float custo);
        virtual ~Veiculo() = default;

        unsigned int getId() const;
        std::string getModelo() const;
        void setModelo(const std::string& modelo);
        float getCusto() const;
        void setCusto(float custo);

    private:
        static unsigned int proxId;
        unsigned int id;
        std::string modelo;
        float custo;
        // Marca
        // Placa
};
}

#endif
