#include "obrero.h"


QString Obrero::resultado()
{
    QString str;
    str = "Obrero " + m_nombre + "\n";
    str += "Horas: " + QString::number(m_horas) + "\n";
    str += "Jornada: " + getJornada() + "\n";
    str += "Salario Bruto: $" + QString::number(m_salarioBruto) + "\n";
    str += "Descuento: $" + QString::number(m_descuento) + "\n";
    str += "Salario Neto: $" + QString::number(m_salarioNeto)+"\n----------------\n";
    return str;
}


Obrero::Obrero(QString nombre, int horas, char jornada)
{
    this->m_nombre = nombre;
    this->m_horas = horas;
    this->m_jornada = jornada;
}

Obrero::Obrero(QObject *parent) : QObject(parent)
{

}
