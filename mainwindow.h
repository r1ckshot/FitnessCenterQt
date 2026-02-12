#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    //1 Strona

    //Wybór Użytkownika
    void on_Tak_clicked();
    void on_Nie_clicked();

    //Notatnik
    void on_Notatnik_clicked(bool checked);
    void on_zapisz_clicked();
    void on_odczytaj_clicked();

    //Progress
    void on_wiecej_clicked();

    //Płeć
    void on_mezczyzna_clicked();
    void on_kobieta_clicked();

    //Wiek
    void on_wiek_editingFinished();

    //Wzrost
    void on_wzrost_editingFinished();

    //Waga
    void on_waga_editingFinished();

    //Aktywność
    void on_aktywnosc_currentIndexChanged(int index);

    //Obliczenie BMI
    void on_BMI_oblicz_clicked();

    //Szczegóły
    void on_Tak_BMI_clicked();
    void on_Nie_BMI_clicked();

    //Obliczenie BMR
    void on_BMR_oblicz_clicked();

    //Następna strona
    void on_Przejdz_clicked();

    //2 Strona


    //Cel
    void on_utrata_wagi_clicked();
    void on_nabor_masy_clicked();
    void on_utrzymanie_wagi_clicked();

    //Obliczenie TDEE
    void on_porady_oblicz_clicked();

    //Obliczenie makroskładników
    void on_porady_dla_Ciebie_clicked();

    //Wybór mięśni
    void on_miesien_box_currentIndexChanged(int index);

    //Zdjęcia ćwiczeń na wybraną mięsień
    void on_miesien_list_currentRowChanged(int currentRow);

    //3 Strona

    //Poprzednia strona
    void on_Powrot_clicked();

    //Zapisanie do notatnika oraz przejście do końca
    void on_Tak_zapisz_clicked();

    //Przejście do końca
    void on_Nie_zapisz_clicked();


    void on_exit_clicked();

private:
    Ui::MainWindow *ui;

    //Wybór Użytkownika
    QString imie; //Pola, które będą dostępne w całym programie'
    QString nazwisko;

    //Progress
    bool nacisniety;

    //Płeć
    bool mezczyzna;
    bool kobieta;

    //Dane użytkownika
    int wiek;
    float wzrost;
    float waga;
    float aktywnosc;

    //Obliczenia 1 Strona
    float BMI;
    float BMR;

    //Cel
    bool schudnac, nabor_masy, utrzymanie;

    //Obliczenia 2 Strona
    float TDEE;

    float nowy_cel_kaloryczny;
    float bialko, tluszcze, weglowodany;

    //Wybrana mięsień
    int miesien;

    //Dla progressBar
    bool ostatnia_akcja;


};

#endif // MAINWINDOW_H
