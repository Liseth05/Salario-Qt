#include "principal.h"
#include <QApplication>
#include <QTranslator>
#include <QInputDialog>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    QTranslator traduccion;
    //    traduccion.load(":Salario"+QLocale::system().name()+".qm");

    //Crea un objeto para manejar las traducciones
    QTranslator traduccion;
    //Crear lista de idiomas
    QStringList idiomas;
    idiomas<< "Ruso" << "Italiano" << "Español";
    //Soliticar al usuario que elija el usuario
    QString idiomaSel = QInputDialog::getItem(NULL, "Idioma", "Seleccione el idioma: ", idiomas);
    //Evaluar el idioma seleccionado
    if(idiomaSel == "Ruso")
        //Cargar un idioma
        traduccion.load(":/Recursos/Salario_ru_RU.qm");
    else if (idiomaSel == "Italiano")
        traduccion.load(":/Recursos/Salario_it_IT.qm");
    else
        traduccion.load(":/Recursos/Salario_es_EC.qm");

    //Establecer un idioma a la aplicacion
    a.installTranslator(&traduccion);
    Principal w;
    w.show();
    return a.exec();
}
