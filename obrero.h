#ifndef ACERCA_H
#define ACERCA_H

#include <QDialog>


namespace Ui {
class Obrero;
}

class Obrero : public QObject
{
    Q_OBJECT

public:

    explicit Obrero(QObject *parent = nullptr);

    Obrero(QString nombre, int horas,char jornada);
    ~Obrero();
    QString resultado();


private:
    Ui::Obrero *ui;
    int m_horas;    //Numeros de horas trabajadas
    QString m_nombre;
    char m_jornada;

    float m_salarioBruto; //Salario sin descuento
    float m_descuento;    //Valor del descuento
    float m_salarioNeto;  //Valor del salario a recibir

    QString getJornada();



};

#endif // ACERCA_H
