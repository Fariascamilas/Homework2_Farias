#include "Timer.hpp"
#include <iostream>
#include <limits>

void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            clearBuffer();
            return value;
        }
        cout << "Input inválido. Por favor ingrese un número." << endl;
        clearBuffer();
    }
}

// test inicialización
void testInitialization() {
    cout << "\n===== TEST DE INICIALIZACION DE TIMER =====\n";
    
    // default
    cout << "\nTest a) Inicialización default (sin parametros):\n";
    Timer t1;
    cout << "Timer dafault: ";
    t1.getTime();
    
    // solo horas
    cout << "\nTest b) Inicializar solo con horas:\n";
    int hours;
    while (true) {
        hours = getValidInt("Ingrese la hora (1-12): ");
        try {
            Timer t2(hours);
            cout << "Timer solo con horas: ";
            t2.getTime();
            break;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    
    cout << "\nTest c) Inicializar con horas y minutos:\n";
    int minutes;
    while (true) {
        hours = getValidInt("Ingrese la hora (1-12): ");
        minutes = getValidInt("Ingrese los minutos (0-59): ");
        try {
            Timer t3(hours, minutes);
            cout << "Timer con horas y minutos: ";
            t3.getTime();
            break;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    
    // horas, minutos y segundos
    cout << "\nTest d) Inicializar con horas, minutos y segundos:\n";
    int seconds;
    while (true) {
        hours = getValidInt("Ingrese horas (1-12): ");
        minutes = getValidInt("Ingrese minutos (0-59): ");
        seconds = getValidInt("Ingrese segundos (0-59): ");
        try {
            Timer t4(hours, minutes, seconds);
            cout << "Timer con horas, minutos y segundos: ";
            t4.getTime();
            break;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    
    // horas, minutos, segundos y am/pm
    cout << "\nTest e) Inicializar con horas, minutos, segundoss, y AM/PM:\n";
    int meridian;
    while (true) {
        hours = getValidInt("Ingrese horas (1-12): ");
        minutes = getValidInt("Ingrese minutos (0-59): ");
        seconds = getValidInt("Ingrese segundos (0-59): ");
        meridian = getValidInt("Ingrese 0 para AM o 1 para PM: ");
        bool isPm = (meridian == 1);
        
        try {
            Timer t5(hours, minutes, seconds, isPm);
            cout << "Timer completo: ";
            t5.getTime();
            cout << "En formato 24 hs: ";
            t5.getTime24H();
            break;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

// Test getters y setters
void testGettersSetters() {
    cout << "\n===== Tests Getters y Setters =====\n";
    
    // Crear timer para modificar
    Timer timer(12, 30, 45, true);
    cout << "Valores iniciales del timer: ";
    timer.getTime();
    
    cout << "\nComponentes individuales:\n";
    cout << "Horas: ";
    timer.getHours();
    cout << "Minutos: ";
    timer.getMinutes();
    cout << "Segundos: ";
    timer.getSeconds();
    cout << "Meridiano: ";
    timer.getMeridian();
    
    // Test setters 
    cout << "\nTest setting individual components:\n";
    
    // Set horas
    while (true) {
        int newHours = getValidInt("Ingrese nueva hora (1-12): ");
        try {
            timer.setHours(newHours);
            cout << "Hora actualizada. Nuevo horario: ";
            timer.getTime();
            break;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    
    // Set minutos
    while (true) {
        int newMinutes = getValidInt("Ingrese los minutos (0-59): ");
        try {
            timer.setMinutes(newMinutes);
            cout << "Minutos actualizados. Nuevo horario: ";
            timer.getTime();
            break;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    
    // Set seguntos
    while (true) {
        int newSeconds = getValidInt("Ingrese nuevos segundos (0-59): ");
        try {
            timer.setSeconds(newSeconds);
            cout << "Segundos actualizados. Nuevo horario: ";
            timer.getTime();
            break;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    
    // Set meridiano
    int meridian = getValidInt("Ingrese 0 para AM o 1 para PM: ");
    timer.setMeridian(meridian == 1);
    cout << "Meridiano actualizado. Nuevo horario: ";
    timer.getTime();
    
    // Mostrar formato 24 hs
    cout << "\nTiempo final en formato 24 hs: ";
    timer.getTime24H();
}

// Test manejo de errores
void testErrorHandling() {
    cout << "\n===== Tests de Manejo de errores =====\n";
    
    Timer timer;
    
    // Test hora invalida
    cout << "\nTesteando hora invalida:\n";
    int invalidHours = getValidInt("Ingresar una hora invalida (fuera de 1-12): ");
    try {
        timer.setHours(invalidHours);
        cout << "No se detecto el error (inesperado)" << endl;
    } catch (const exception& e) {
        cout << "Error encontrado (esperado): " << e.what() << endl;
    }
    
    // Test minutos invalidos
    cout << "\nTesteando minutos invalidos:\n";
    int invalidMinutes = getValidInt("Ingresar minutos invalidos (fuera de 0-59): ");
    try {
        timer.setMinutes(invalidMinutes);
        cout << "No se detecto el error (inesperado)" << endl;
    } catch (const exception& e) {
        cout << "Error encontrado (esperado): " << e.what() << endl;
    }
    
    // Test segundos invalidos
    cout << "\nTesteando segundos invalidos:\n";
    int invalidSeconds = getValidInt("Ingresar segundos invalidos (fuera de 0-59): ");
    try {
        timer.setSeconds(invalidSeconds);
        cout << "No se detecto el error (inesperado)" << endl;
    } catch (const exception& e) {
        cout << "Error encontrado (esperado): " << e.what() << endl;
    }
}

int main() {
    cout << "===== Programa de Testing para clase Timer =====\n";
    
    int choice;
    bool running = true;
    
    while (running) {
        cout << "\nMenú:\n";
        cout << "1. Test de Inicialización de Timer\n";
        cout << "2. Test de Getters y Setters\n";
        cout << "3. Test de Manejo de Errores\n";
        cout << "4. Salir\n";
        cout << "Elija una opción (1-4): ";
        
        if (!(cin >> choice)) {
            cout << "Input no válido. Por favor intentelo de nuevo.\n";
            clearBuffer();
            continue;
        }
        clearBuffer();
        
        switch (choice) {
            case 1:
                testInitialization();
                break;
            case 2:
                testGettersSetters();
                break;
            case 3:
                testErrorHandling();
                break;
            case 4:
                cout << "Saliendo del programa. Nos vemos! :)\n";
                running = false;
                break;
            default:
                cout << "Eleccion no valida. Intentelo de nuevo.\n";
        }
    }
    
    return 0;
}