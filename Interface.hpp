#ifndef INTERFACE_HPP
#define INTERFACE_HPP

namespace locadora {

class Interface {
   public:
    Interface() = delete;
    virtual ~Interface() = default;

    static void cadastrarCliente();
    static void cadastrarMarca();
    static void cadastrarVeiculo();
};
}  // namespace locadora

#endif