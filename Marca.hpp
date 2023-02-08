#ifndef MARCA_HPP
#define MARCA_HPP

#include <string>

namespace locadora {
class Marca {
   public:
    Marca(const std::string& nome);

    std::string getNome() const;
    void setNome(const std::string& nome);

   private:
    std::string nome;
    // vetor de veículos
};
}  // namespace locadora

#endif