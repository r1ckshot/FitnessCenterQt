#include "mainwindow.h"
#include <QApplication>

#include <Qfile> //Klasa do odczytu i zapisu plików

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Nowa instancja(obiekt) QApplication

    //Irrorater ManjaroMix
    QFile styleSheetFile("./Diffnes.qss"); // Nowy obiekt QFile dla pliku z arkuszem styli
    styleSheetFile.open(QFile::ReadOnly); // Plik tylko do odczytu

    QString styleSheet = QLatin1String(styleSheetFile.readAll()); // Wczytanie arkuszu styli do ciągu znaków

    a.setStyleSheet(styleSheet); // Ustawienie arkuszu styli dla aplikacji


    MainWindow w; // Nowa instancja(obiekt) MainWindow
    w.show();

    return a.exec();
}
