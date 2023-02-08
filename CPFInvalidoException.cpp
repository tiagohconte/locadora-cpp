#include "CPFInvalidoException.hpp"

namespace locadora {

CPFInvalidoException::CPFInvalidoException(const unsigned long cpf)
    : std::runtime_error{"CPF Invalido."}, cpf{cpf} {}
}