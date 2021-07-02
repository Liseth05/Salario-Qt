#include "principal.h"
#include "ui_principal.h"

#include <QtDebug>
#include <QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //leer un archivo al iniciar el programa
    /*ui->setupUi(this);
        QFile f("/home/r/usuario.tx");
        QTextStream in(%f);
        if(!f.open(QIODevice::ReadOnly)){
            qDebug()<<"No se puede abrir el archivo";
            return;
        }
        while (!in.atEnd()) {
            qDebug("%s",qPrintable(in.readLine()));
        }
        f.close();*/

}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_actionSalir_triggered()
{
    this->close();
}

void Principal::on_cmdCalc_clicked()
{
    this->calcular();
}

void Principal::on_actionCalcular_triggered()
{
    this->on_cmdCalc_clicked();
}

void Principal::calcular()
{
    //Obtener el nombre

    QString nombre = ui->inNombre->text();
    //valida que el nombre no este vacio
    if(nombre.isEmpty())
    {
        QMessageBox::warning(this, "Salarios","No has proporcionado el nombre del obrero");
        return;
    }
    //Obtiene horas
    int horas = ui->inHoras->value();
    //Obtiene la jornada
    char jornada = '\0';
    if(ui->inMatutina->isChecked())
        jornada = 'M';
    else if(ui->inVespertina->isChecked())
        jornada = 'V';
    else if(ui->inNocturna->isChecked())
        jornada = 'N';
    CalculoSalario *s1 = new CalculoSalario(nombre, horas, jornada);
    s1->calcular();
    ui->outResultado->appendPlainText(s1->resultado());
    this->borrar();
}

void Principal::borrar()
{
    ui->inNombre->setText("");
    ui->inHoras->setValue(0);
    ui->inMatutina->setChecked(true);
    ui->inNombre->setFocus();
}

void Principal::nuevo()
{
    ui->outResultado->clear();
}

void Principal::on_actionNuevo_triggered()
{
    this->nuevo();
}

void Principal::on_actionAcerca_de_triggered()
{
    Acerca *acercaDe = new Acerca(this);
    acercaDe->setVersion(VERSION);
    acercaDe->show();
}


void Principal::on_actionGuardar_triggered()
{
    //crear un objeto QDir apartirdel directorio del usuario
    QDir directorio=QDir::home();
    //agregar al path absoluto del objeto, un nombre por defecto del archivo
    QString pathArchivo=directorio.absolutePath()+"sin_nombre.txt";
    //abrir un cuadro de dialogo para seleccionar el nombre y ubicacion del archivo a guardar
    QString fileName = QFileDialog::getSaveFileName(this,"Guardar Archivo",
                                                    pathArchivo,
                                                    "Archivo de texto(*.txt)");

    //guardar el archivo a partir del nombre arrojado por el cuadro dedialogo
    QFile f(fileName);
    //crear el objeto QTextStream (permite escribir sobre el archivo)
    QTextStream out(&f);
    //insertar abrir el archivo ya sea para escribirlo (si no existe) o para agregar texto (si existiera)
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append)){
        //si no se puede abrirmuestra mensaje de advertencia
        QMessageBox::warning(this,"Salarios","No se puede abrir el archivo"+fileName);
        //Salir de la funcion no hace nada mas
        return;
    }
    //guardar contenido del texto de resultado en el archivo
    out<<ui->outResultado->toPlainText()<<endl;
    //cerrar el archivo
    f.close();
    //mostrar mensaje en la barra de estados
    ui->statusbar->showMessage("Archivo guardado en "+ fileName,3000);
}

void Principal::on_actionAbrir_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Abrir archivo",
                                                    "c:/Ususarios", "config(*.txt)");
    QFile f(fileName);

    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QStringList datos;
    QTextStream in(&f);
    while (!in.atEnd()) {
        QString linea = in.readLine();
        datos << linea;
    }
    datos.size();
    datos.length();

    for(int i=0; i < datos.size(); i++){
        ui->outResultado->appendPlainText(datos[i]);
    }

    f.close();
}
