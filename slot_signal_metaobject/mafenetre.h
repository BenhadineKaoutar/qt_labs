#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include<QMetaObject>
#include <QString>
#include <QKeyEvent>

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT //macro

    public:
    MaFenetre();
    ~MaFenetre();

    public slots:
    void changerLargeur(int largeur);

    signals:
    void agrandissementMax();

    private:
    QLCDNumber *m_lcd; //m_lcd est un pointeur à construire par un new
    QSlider *m_slider;
    /*
    Q_INVOKABLE
    int imethod(){
        return 1;
    };
    */
    void keyPressEvent(QKeyEvent *event);

};

#endif
