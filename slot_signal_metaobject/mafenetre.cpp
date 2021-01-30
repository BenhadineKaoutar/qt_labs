#include "MaFenetre.h"
#include<QStringList>
#include <QMetaMethod>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLabel>
#include <QDebug>


MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(620, 800);
    this->setWindowTitle("Slot_Signal_MetaObject");
    /*
    QLabel *label = new QLabel(this);
    label->setText("Slot_Signal_MetaObject");
    QFont f( "Arial", 10, QFont::Bold);
    label->setFont(f);
    */

    m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(30, 20);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(30, 60, 400, 40);
    m_slider->setRange(620, 1000);

    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int))) ;
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int)));
    QObject::connect(this, SIGNAL(agrandissementMax()), qApp, SLOT(quit()));

    const QMetaObject * _metaObject = metaObject();

    QTableWidget *table = new QTableWidget(this);
    table->setGeometry(30, 120, 555, 620);
    table->setColumnCount(3);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Type d'accès"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Type de méthode"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Type de fonction"));

    table->setRowCount(_metaObject->methodCount() + _metaObject->constructorCount());
    for(int i = 0; i < _metaObject->methodCount(); i++)
    {
        table->setVerticalHeaderItem(i, new QTableWidgetItem(_metaObject->method(i).methodSignature(),1));
        table->setItem(i, 2, new QTableWidgetItem(_metaObject->method(i).typeName()));

        if(_metaObject->method(i).access()	==	QMetaMethod::Private)	table->setItem(i, 0, new QTableWidgetItem("Privé"));
        if(_metaObject->method(i).access()	==	QMetaMethod::Protected)	table->setItem(i, 0, new QTableWidgetItem("Protégé"));
        if(_metaObject->method(i).access()	==	QMetaMethod::Public)	table->setItem(i, 0, new QTableWidgetItem("Public"));

        if(_metaObject->method(i).methodType()	==	QMetaMethod::Signal)	table->setItem(i, 1, new QTableWidgetItem("Signal"));
        if(_metaObject->method(i).methodType()	==	QMetaMethod::Slot)	table->setItem(i, 1, new QTableWidgetItem("Slot"));
        if(_metaObject->method(i).methodType()	==	QMetaMethod::Method)	table->setItem(i, 1, new QTableWidgetItem("Méthode"));
    }

}

void MaFenetre::changerLargeur(int largeur)
{
    setFixedSize(largeur, 800);
    if (largeur == 1000)
        {
            emit agrandissementMax();
    }
}

void MaFenetre::keyPressEvent(QKeyEvent *event)
{

       switch(event->key())
       {
          case Qt::Key_Q:
               qApp->quit();
               break;
          case  Qt::Key_Escape:
               qDebug()<< " u just press the esc key"<< Qt::endl;
               break;
       }

}

MaFenetre::~MaFenetre()
{
    delete m_lcd;
    delete m_slider;
}
