#ifndef VEICULO_INDISPONIVEL_EXCEPTION
#define VEICULO_INDISPONIVEL_EXCEPTION

#include <stdexcept>
#include "Veiculo.hpp"

namespace locadora {
class VeiculoIndisponivelException : public std::runtime_error {
   public:
    const Veiculo* veiculo;

    VeiculoIndisponivelException(const Veiculo* veiculo);
    virtual ~VeiculoIndisponivelException() = default;
};
}  // namespace locadora
#endif