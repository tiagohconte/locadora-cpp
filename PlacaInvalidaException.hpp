#ifndef PLACA_INVALIDA_EXCEPTION
#define PLACA_INVALIDA_EXCEPTION

#include <stdexcept>

namespace locadora {
class PlacaInvalidaException : public std::runtime_error {
   public:
    const std::string& placa;

    PlacaInvalidaException(const std::string& placa);
    virtual ~PlacaInvalidaException() = default;
};
}  // namespace locadora
#endif