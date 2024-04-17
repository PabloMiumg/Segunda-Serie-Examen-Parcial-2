#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Empleado {
private:
    string nombre;
    string apellido;
    int edad;
    double salario;

public:
    Empleado(string nombre, string apellido, int edad, double salario) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->edad = edad;
        this->salario = salario;
    }

    string obtenerNombre() const {
        return nombre;
    }

    string obtenerApellido() const {
        return apellido;
    }

    int obtenerEdad() const {
        return edad;
    }

    double obtenerSalario() const {
        return salario;
    }
};

int main() {
    vector<Empleado> empleados;
    bool continuar = true;

    while (continuar) {
        string nombre, apellido;
        int edad;
        double salario;

        cout << "Ingrese el nombre del empleado: ";
        getline(cin, nombre);
        cout << "Ingrese el apellido del empleado: ";
        getline(cin, apellido);
        cout << "Ingrese la edad del empleado: ";
        cin >> edad;
        cout << "Ingrese el salario del empleado: ";
        cin >> salario;
        cin.ignore(); 

        Empleado empleado(nombre, apellido, edad, salario);
        empleados.push_back(empleado);

        char opcion;
        cout << "¿Desea agregar otro empleado? (s/n): ";
        cin >> opcion;
        cin.ignore(); 
        if (opcion != 's' && opcion != 'S') {
            continuar = false;
        }
    }

    ofstream archivo("empleados.txt");
    if (archivo.is_open()) {
        for (const auto& empleado : empleados) {
            archivo << empleado.obtenerNombre() << " " << empleado.obtenerApellido() << " "
                    << empleado.obtenerEdad() << " " << empleado.obtenerSalario() << endl;
        }
        archivo.close();
        cout << "Datos de empleados almacenados correctamente." << endl;
    } else {
        cerr << "Error al abrir el archivo." << endl;
    }

    return 0;
}

