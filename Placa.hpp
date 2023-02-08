#ifndef PLACA_HPP
#define PLACA_HPP

#include <iostream>

namespace locadora {
class Placa {
    // friend std::ostream& operator<<(std::ostream& stream, const Placa& cpf);
    // friend std::istream& operator>>(std::istream& stream, Placa& cpf);

   public:
    Placa() = default;
    Placa(const std::string& valor);
    virtual ~Placa() = default;

    std::string getValor() const;
    void setValor(const std::string& valor);

    // bool operator==(const Placa& outro) const;
    // bool operator!=(const Placa& outro) const;

    // bool operator<(const Placa& outro) const;
    // bool operator>(const Placa& outro) const;
    // bool operator<=(const Placa& outro) const;
    // bool operator>=(const Placa& outro) const;

    // const Placa& operator=(const Placa& outro);
    // const Placa& operator=(const unsigned long numero);

    char operator[](short int idx) const;
    // unsigned long operator()(short int inicio, short int tam) const;

   private:
    bool validarPlaca(const std::string& placa) const;
    std::string valor;
};
}  // namespace locadora
#endif