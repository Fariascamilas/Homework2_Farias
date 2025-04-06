#include "Course.hpp"
#include <iostream>
#include <limits>

Student* findStudent(array<Student*, 100>& students, int record, int countStudents){
    for (int i = 0; i < countStudents; i++) {
        if (students[i] && students[i]->getRecordNumber() == record)
            return students[i];
    }
    return nullptr;
}

void listCourses(array<Course*, 16>& courses, int countCourses) {
    cout<<"Cursos disponibles:\n";
    for (int i = 0; i < countCourses; i++) {
        cout<<i<<". "<<courses[i]->getName()<<endl;
    }
    cout<<endl;
}

int main(){
    Course analisis1("Análisis I");
    Course algebra("Algebra");
    Course algoritmos("Algoritmos de programación");
    Course md("Matemática Discreta");
    Course fisica1("Física I");
    Course paradigmas("Paradigmas de programación");
    Course estadistica("Probabilidad y estadística");
    Course analisis2("Análisis II");

    array<Course*,16> courses = {&analisis1,&algebra,&algoritmos,&md,&fisica1,&paradigmas,&estadistica,&analisis2};
    int countCourses = 8;

    vector<int> grades = {10,10,8,9};
    Student s1("Juan García",25011,grades);
    Student s2("Ana López", 25012, grades);
    Student s3("Carlos Pérez", 25013, grades);
    Student s4("María Rodríguez", 25014, grades);
    Student s5("Luis Hernández", 25015, grades);
    Student s6("Elena Martínez", 25016, grades);
    Student s7("José Sánchez", 25017, grades);
    Student s8("Carmen Díaz", 25018, grades);
    Student s9("Miguel Torres", 25019, grades);
    Student s10("Sofía Romero", 25020, grades);
    Student s11("Diego Castro", 25021, grades);
    Student s12("Laura Gómez", 25022, grades);
    Student s13("Andrés Silva", 25023, grades);
    Student s14("Valeria Morales", 25024, grades);
    Student s15("Ricardo Vega", 25025, grades);

    array<Student*,100> students = {&s1, &s2, &s3, &s4, &s5, &s6, &s7, &s8, &s9, &s10, &s11, &s12, &s13, &s14, &s15};
    int countStudents = 15;
    
    cout<<"=== Bienvenido al menú de cursos de UdeSA 2025 ==="<<endl;
    cout<<"1. Inscribir estudiante a un curso"<<endl
    <<"2. Desinscribir estudiante a de curso"<<endl
    <<"3. Verificar inscripción de un estudiante"<<endl
    <<"4. Mostrar listado de estudiantes de un curso"<<endl
    <<"5. Mostrar información de un estudiante"<<endl
    <<"6. Ver estado del curso"<<endl
    <<"7. Crear una copia de un curso"<<endl
    <<"8. Salir"<<endl;
    enum OPCIONES {INSCRIBIR = 1, DESINSCRIBIR, VERIFICAR, LISTADO, INFO_E, ESTADO_C, COPIAR, SALIR};
    
    int rta;
    cout << "\nIngrese una opción: ";
    cin>>rta;
    
    while (rta != SALIR){
        switch (rta){
            case INSCRIBIR:{
                listCourses(courses, countCourses);

                cout << "Seleccione el número de curso: ";
                int idx;
                cin >> idx;
                if(idx < 0 || idx >= countCourses){
                    cout << "Curso inválido." << endl;
                    break;
                }

                cout << "Ingrese número de legajo del estudiante a inscribir: ";
                int legajo;
                cin >> legajo;
                Student* stud = findStudent(students, legajo, countStudents);
                if(!stud){
                    cout << "Estudiante no encontrado." << endl;
                    break;
                }

                shared_ptr<Student> s(stud, [](Student*){}); /*s se va a destruir cuando el contador llegue a cero pero no se hará el delete. Como el objeto al que apunta stud esta en el stack (scope local) no se debe hacer delete sobre el. (Uso funcion lambda vacía para que el deleter no haga nada con el puntero)*/
                if(courses[idx]->enrollStudent(s)){
                    cout << "Estudiante inscrito exitosamente en el curso." << endl;
                } 
                else {
                    cout << "No se pudo inscribir; el curso pudo estar lleno o hubo un error interno." << endl;
                }
                break;
            }
            case DESINSCRIBIR:{
                listCourses(courses, countCourses);

                cout << "Seleccione el número de curso: ";
                int idx;
                cin >> idx;
                if(idx < 0 || idx >= countCourses){
                    cout << "Curso inválido." << endl;
                    break;
                }

                cout << "Ingrese número de legajo del estudiante a desinscribir: ";
                int legajo;
                cin >> legajo;
                if(courses[idx]->unenrollStudent(legajo)){
                    cout << "Estudiante desinscripto exitosamente del curso." << endl;
                } else {
                    cout << "Estudiante no estaba inscripto en el curso." << endl;
                }
                break;
            }
            case VERIFICAR:{
                listCourses(courses, countCourses);

                cout << "Seleccione el número de curso: ";
                int idx;
                cin >> idx;
                if(idx < 0 || idx >= countCourses){
                    cout << "Curso inválido." << endl;
                    break;
                }

                cout << "Ingrese número de legajo del estudiante a buscar: ";
                int legajo;
                cin >> legajo;
                if(courses[idx]->isEnrolled(legajo)){
                    cout << "El estudiante está inscripto en el curso." << endl;
                } else {
                    cout << "El estudiante NO está inscripto en el curso." << endl;
                }
                break;
            }
            case LISTADO:{
                listCourses(courses, countCourses);

                cout << "Seleccione el número de curso: ";
                int idx;
                cin >> idx;
                if(idx < 0 || idx >= countCourses){
                    cout << "Curso inválido." << endl;
                    break;
                }
                courses[idx]->printCourse();
                break;
            } 
            case INFO_E: {
                cout << "Ingrese número de legajo del estudiante: ";
                int legajo;
                cin >> legajo;
                
                Student* stud = findStudent(students, legajo, countStudents);
                if(!stud){
                    cout << "Estudiante no encontrado." << endl;
                    break;
                }
                cout << "Información del estudiante:" << endl;
                cout << "Nombre: " << stud->getFullName() << endl;
                cout << "Legajo: " << stud->getRecordNumber() << endl;
                cout << "Promedio: " << stud->getGPA() << endl;
                break;
            }
            case ESTADO_C: {
                listCourses(courses, countCourses);
                
                cout << "Seleccione el número de curso para ver su estado: ";
                int idx;
                cin >> idx;
                if(idx < 0 || idx >= countCourses){
                    cout << "Curso inválido." << endl;
                    break;
                }
                
                if(courses[idx]->isFull()){
                    cout << "El curso está lleno." << endl;
                } else {
                    cout << "El curso NO está lleno." << endl;
                }
                break;
            }
            case COPIAR: {
                listCourses(courses, countCourses);
                cout << "Seleccione el número de curso a copiar: ";
                int idx;
                cin >> idx;
                if(idx < 0 || idx >= countCourses){
                    cout << "Curso inválido." << endl;
                    break;
                }
                cout << "Ingrese el nombre del nuevo curso: ";
                string nuevoNombre;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, nuevoNombre);
                
                // Se crea una copia usando el constructor de copia definido
                // Nota: la copia es shallow para la lista de estudiantes
                Course* nuevoCurso = new Course(*courses[idx], nuevoNombre);
                
                if(countCourses < courses.size()){
                    courses[countCourses++] = nuevoCurso;
                    cout << "Curso copiado exitosamente." << endl;
                } else {
                    cout << "No se pudo agregar el curso; límite alcanzado." << endl;
                    delete nuevoCurso;
                }
                break;
            }
            default:
                cout << "Opción no válida." << endl;
                break;
        }
        cout<<endl<<"=== Menú de cursos de UdeSA 2025 ==="<<endl;
        cout<<"1. Inscribir estudiante a un curso"<<endl
        <<"2. Desinscribir estudiante a de curso"<<endl
        <<"3. Verificar inscripción de un estudiante"<<endl
        <<"4. Mostrar listado de estudiantes de un curso"<<endl
        <<"5. Mostrar información de un estudiante"<<endl
        <<"6. Ver estado del curso"<<endl
        <<"7. Crear una copia de un curso"<<endl
        <<"8. Salir"<<endl;
        cout << "\nIngrese una opción: ";
        cin>>rta;
    }
    cout<<"Hasta pronto!"<<endl;
    return 0;
}