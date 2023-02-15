#include "Veiculo.hpp"
#include "Marca.hpp"

namespace locadora {

unsigned int Veiculo::proxId{0};

Veiculo::Veiculo(Marca* const marca, const std::string& modelo,
                 const float custo, const unsigned short int capacidade,
                 const Placa& placa)
    : id{Veiculo::proxId},
      marca{nullptr},
      modelo{modelo},
      custo{custo},
      capacidade{capacidade},
      placa{placa},
      status{EnumStatus::DISPONIVEL} {
    Veiculo::proxId++;
    this->setMarca(marca);
}

Veiculo::Veiculo(Marca* const marca, const std::string& modelo,
                 const float custo, const unsigned short int capacidade,
                 const std::string& placa)
    : id{Veiculo::proxId},
      marca{nullptr},
      modelo{modelo},
      custo{custo},
      capacidade{capacidade},
      placa{placa},
      status{EnumStatus::DISPONIVEL} {
    Veiculo::proxId++;
    this->setMarca(marca);
}

unsigned int Veiculo::getId() const { return id; }

const Marca* Veiculo::getMarca() const { return this->marca; }

void Veiculo::setMarca(Marca* const marca) {
    if (this->marca != nullptr) {
        this->marca->veiculos.remove(this);
    }
    this->marca = marca;
    if (this->marca != nullptr) {
        this->marca->veiculos.push_back(this);
    }
}

std::string Veiculo::getModelo() const { return this->modelo; }

void Veiculo::setModelo(const std::string& modelo) { this->modelo = modelo; }

float Veiculo::getCusto() const { return this->custo; }

void Veiculo::setCusto(float custo) { this->custo = custo; }

unsigned short int Veiculo::getCapacidade() const { return this->capacidade; }

void Veiculo::setCapacidade(const unsigned short int capacidade) { this->capacidade = capacidade; }

const Placa& Veiculo::getPlaca() const { return this->placa; }

void Veiculo::setPlaca(const Placa& placa) { this->placa = placa; }

EnumStatus Veiculo::getStatus() const { return this->status; }

void Veiculo::setStatus(const EnumStatus status) { this->status = status; }

std::ostream& operator<<(std::ostream& stream, const locadora::Veiculo& veiculo) {
    stream << "ID: " << veiculo.getId() << '\n';
    stream << "Placa: " << veiculo.getPlaca() << '\n';
    if (veiculo.getMarca() != nullptr)
        stream << "Marca: " << veiculo.getMarca()->getNome() << '\n';
    else
        stream << "Sem marca" << '\n';

    stream << "Modelo: " << veiculo.getModelo() << '\n';
    stream << "Custo: " << veiculo.getCusto() << '\n';
    stream << "Capacidade: " << veiculo.getCapacidade() << '\n';

    return stream;
}
}