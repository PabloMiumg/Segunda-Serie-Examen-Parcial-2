#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void buscarEmpleado(const string& nombreCompleto) {
    ifstream archivo("empleados.txt");
    if (archivo.is_open()) {
        string nombre, apellido;
        int edad;
        double salario;
        bool encontrado = false;

        while (archivo >> nombre >> apellido >> edad >> salario) {
            string nombreApellido = nombre + " " + apellido;
            if (nombreApellido == nombreCompleto) {
                encontrado = true;
                cout << "Nombre: " << nombre << endl;
                cout << "Apellido: " << apellido << endl;
                cout << "Edad: " << edad << endl;
                cout << "Salario: " << salario << endl;
                break;
            }
        }

        if (!encontrado) {
            cout << "Empleado no encontrado." << endl;
        }

        archivo.close();
    } else {
        cerr << "Error al abrir el archivo." << endl;
    }
}

int main() {
    bool continuar = true;

    while (continuar) {
        string nombreCompleto;

        cout << "Ingrese el nombre completo del empleado a buscar (nombre apellido): ";
        getline(cin, nombreCompleto);
        buscarEmpleado(nombreCompleto);

        char opcion;
        cout << "¿Desea buscar otro empleado? (s/n): ";
        cin >> opcion;
        cin.ignore(); 
        if (opcion != 's' && opcion != 'S') {
            continuar = false;
        }
    }

    return 0;
}

