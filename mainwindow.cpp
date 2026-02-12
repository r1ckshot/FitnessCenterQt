#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include <QStandardItem>

#include <QDebug>

#include <cmath>

#include <QPixmap>


//Współczynnik aktywności fizycznej (dla BMR)
#define niska_aktywnosc 1.2
#define lekka_aktywnosc 1.375
#define umiarkowana_aktywnosc 1.55
#define wysoka_aktywnosc 1.725
#define bardzo_wysoka_aktywnosc 1.9

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Ukrycie komponentów programu

    //1 Strona

    //1 Część
    ui->Plec->setVisible(false);
    ui->plec_box->setVisible(false);
    ui->Wiek->setVisible(false);
    ui->wiek->setVisible(false);
    ui->Wzrost->setVisible(false);
    ui->wzrost->setVisible(false);
    ui->Waga->setVisible(false);
    ui->waga->setVisible(false);
    ui->Aktywnosc->setVisible(false);
    ui->aktywnosc->setVisible(false);
    ui->line_2->setVisible(false);
    ui->line_3->setVisible(false);

    //Notatnik
    ui->Notatnik->setVisible(false);
    ui->Notatki->setVisible(false);
    ui->zapisz->setVisible(false);
    ui->odczytaj->setVisible(false);

    ui->wiecej->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->line_10->setVisible(false);
    ui->line_12->setVisible(false); //2 Strona
    ui->line_19->setVisible(false); //3 Strona

    //2 Część
    ui->Kalkulator_BMI->setVisible(false);
    ui->BMI_oblicz->setVisible(false);
    ui->line_5->setVisible(false);
    ui->Kalkulator_BMI_1->setVisible(false);
    ui->Wynik_BMI->setVisible(false);
    ui->Szczegoly->setVisible(false);
    ui->szczegoly_box->setVisible(false);

    //3 Część
    ui->line_4->setVisible(false);
    ui->Kalkulator_BMR->setVisible(false);
    ui->BMR_oblicz->setVisible(false);
    ui->line_7->setVisible(false);
    ui->Kalkulator_BMR_1->setVisible(false);
    ui->Wynik_BMR->setVisible(false);
    ui->line_6->setVisible(false);

    //4 Część
    ui->Nastepna_strona->setVisible(false);
    ui->Przejdz->setVisible(false);
    ui->line_8->setVisible(false);
    ui->line_9->setVisible(false);

    //2 Strona

    //1 Część
    ui->Porady_dietyczne->setVisible(false);
    ui->porady_box->setVisible(false);

    ui->porady_oblicz->setVisible(false);
    ui->line_15->setVisible(false);

    //2 Część
    ui->TDEE->setVisible(false);
    ui->TDEE_wynik->setVisible(false);

    //3 Część
    ui->Porady_dla_Ciebie->setVisible(false);
    ui->porady_dla_Ciebie->setVisible(false);

    ui->porady_list->setVisible(false);

    //4 Część
    ui->line_11->setVisible(false);
    ui->miesien->setVisible(false);
    ui->miesien_box->setVisible(false);

    ui->miesien_list->setVisible(false);
    ui->line_14->setVisible(false);

    ui->miesien_zdjecia->setVisible(false);
    ui->line_13->setVisible(false);

    //3 Strona

    //1 Część
    ui->line_16->setVisible(false);
    ui->line_17->setVisible(false);
    ui->Czy_chcesz->setVisible(false);
    ui->Powrot->setVisible(false);
    ui->Tak_zapisz->setVisible(false);
    ui->Nie_zapisz->setVisible(false);

    //2 Część
    ui->line_20->setVisible(false);
    ui->line_21->setVisible(false);
    ui->line_18->setVisible(false);
    ui->Dziekuje->setVisible(false);
    ui->strzalka_1->setVisible(false);
    ui->strzalka_2->setVisible(false);
    ui->strzalka_3->setVisible(false);
    ui->strzalka_4->setVisible(false);
    ui->exit->setVisible(false);

    //Autor
    ui->Autor->setVisible(false);

    //ProgressBar
    ostatnia_akcja = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

//1 Strona

//Wybór użytkownika
void MainWindow::on_Tak_clicked()
{
    bool ok;
        imie = QInputDialog::getText(this, tr("Wprowadz imie"), //Pobieranie imienia użytownika
                                             tr("Imie:"), QLineEdit::Normal,
                                             "", &ok);

        if (ok && !imie.isEmpty()) { //Jeżeli jest imię oraz naciśnięty przycisk Ok, to podaj nazwisko
            nazwisko = QInputDialog::getText(this, tr("Wprowadz nazwisko"),
                                             tr("Nazwisko:"), QLineEdit::Normal,
                                             "", &ok);
        }

        if(!imie.isEmpty() && !nazwisko.isEmpty()){ // Jeżeli imie oraz nazwisko nie są puste

            ui->Plec->setVisible(true);
            ui->plec_box->setVisible(true);
            ui->Notatnik->setVisible(true);

            ui->Tak->setEnabled(false); //Blokowanie wybranej radioButton
            ui->Nie->setEnabled(false);

            ui->progressBar->setValue(3); //Progress użytkownika
        }


        qDebug() << imie;
        qDebug() << nazwisko;


}

void MainWindow::on_Nie_clicked()
{
    this->close(); //Zamknięcie okna ---> Wyjście z programu
}

//Notatnik
void MainWindow::on_Notatnik_clicked(bool checked)
{
    if(checked){
        ui->Notatki->setVisible(true);
        ui->zapisz->setVisible(true);
        ui->odczytaj->setVisible(true);
        ui->wiecej->setVisible(true);

        ui->line_5->setVisible(true);
        ui->line_7->setVisible(true);
        ui->line_9->setVisible(true);
        ui->line_12->setVisible(true);
        ui->line_19->setVisible(true);
    }
    else{
        ui->Notatki->setVisible(false);
        ui->zapisz->setVisible(false);
        ui->odczytaj->setVisible(false);

        ui->wiecej->setVisible(false);
        ui->progressBar->setVisible(false);
        ui->line_10->setVisible(false);
        nacisniety = false;

        ui->line_5->setVisible(false);
        ui->line_7->setVisible(false);
        ui->line_9->setVisible(false);
        ui->line_12->setVisible(false);
        ui->line_19->setVisible(false);

        ui->Notatki->clear();
    }

}

void MainWindow::on_zapisz_clicked()
{
    QString filename = "notes.txt";
    QFile file(filename);

    // Trying to open in WriteOnly and Text mode
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
    qDebug() << " Could not open file for writing";
    return;
    }

    QTextStream out(&file);
    out<<ui->Notatki->toPlainText();

    file.flush();
    file.close();

    ui->Notatki->clear();
}

void MainWindow::on_odczytaj_clicked()
{
    QString filename = "notes.txt";
    QFile file(filename);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
    qDebug() << " Could not open the file for reading";
    return;
    }

    QTextStream in(&file);
    QString myText = in.readAll();
    ui->Notatki->setPlainText(myText);

    file.close();
}

//Progress
void MainWindow::on_wiecej_clicked()
{
    if(!nacisniety){
        ui->progressBar->setVisible(true);
        ui->line_10->setVisible(true);
        nacisniety = true;
    }
    else{
        ui->progressBar->setVisible(false);
        ui->line_10->setVisible(false);
        nacisniety = false;
    }
}

//Płeć
void MainWindow::on_mezczyzna_clicked()
{
    ui->mezczyzna->setEnabled(false); //Blokowanie wybranej radioButton
    ui->kobieta->setEnabled(false);

    mezczyzna = true; //Dla póżniejszych obliczeń
    kobieta = false;

    ui->Wiek->setVisible(true);
    ui->wiek->setVisible(true);

    ui->progressBar->setValue(7);
}

void MainWindow::on_kobieta_clicked()
{
    ui->kobieta->setEnabled(false);
    ui->mezczyzna->setEnabled(false);

    kobieta = true;
    mezczyzna = false;

    ui->Wiek->setVisible(true);
    ui->wiek->setVisible(true);

    ui->progressBar->setValue(7);
}

//Wiek
void MainWindow::on_wiek_editingFinished()
{
    wiek = ui->wiek->text().toInt();

    if (wiek <= 10 || wiek > 100){

        ui->wiek->clear();
    }

    else{

        ui->wiek->setReadOnly(true);  // blokowanie pola tekstowego po wprowadzeniu prawidłowego wieku
        ui->Wzrost->setVisible(true);
        ui->wzrost->setVisible(true);

        ui->progressBar->setValue(11);
    }


    qDebug() << wiek;
}

//Wzrost
void MainWindow::on_wzrost_editingFinished()
{
    wzrost = ui->wzrost->text().toInt();

    if (wzrost <= 100 || wzrost > 230){

        ui->wzrost->clear();
    }

    else{

        ui->wzrost->setReadOnly(true);  // blokowanie pola tekstowego po wprowadzeniu prawidłowego wieku
        ui->Waga->setVisible(true);
        ui->waga->setVisible(true);

        ui->progressBar->setValue(15);
    }


    qDebug() << wzrost;
}

//Waga
void MainWindow::on_waga_editingFinished()
{
    waga = ui->waga->text().toInt();

    if (waga <= 30 || waga > 130){

        ui->waga->clear();
    }

    else{

        ui->waga->setReadOnly(true);  // blokowanie pola tekstowego po wprowadzeniu prawidłowego wieku
        ui->Aktywnosc->setVisible(true);
        ui->aktywnosc->setVisible(true);

        ui->progressBar->setValue(20);
    }

    qDebug() << waga;
}

//Aktywność
void MainWindow::on_aktywnosc_currentIndexChanged(int index)
{

    ui->aktywnosc->setEnabled(false);
    ui->line_2->setVisible(true);
    ui->line_3->setVisible(true);

    ui->Kalkulator_BMI->setVisible(true);
    ui->BMI_oblicz->setVisible(true);

    //Aktywność dla póżniejszego obliczenia BMR
    if(index == 0){
        aktywnosc = niska_aktywnosc;
    }
    else if(index == 1){
        aktywnosc = lekka_aktywnosc;
    }
    else if(index == 2){
        aktywnosc = umiarkowana_aktywnosc;
    }
    else if(index == 3){
        aktywnosc = wysoka_aktywnosc;
    }
    else if(index == 4){
        aktywnosc = bardzo_wysoka_aktywnosc;
    }

    ui->progressBar->setValue(25);

    qDebug() << aktywnosc;
}

//Obliczenie BMI
void MainWindow::on_BMI_oblicz_clicked()
{
    BMI = waga / pow((wzrost * 0.01), 2);

    ui->Kalkulator_BMI_1->setVisible(true);

    ui->Wynik_BMI->setText(QString::number(BMI));
    ui->Wynik_BMI->setVisible(true);

    ui->Szczegoly->setVisible(true);
    ui->szczegoly_box->setVisible(true);

    ui->BMI_oblicz->setEnabled(false);

    ui->progressBar->setValue(26);
}

void MainWindow::on_Tak_BMI_clicked()
{
    QString message;

        if (BMI < 16.0) {
            message = "Stan: Wyglodzenie. Twoje BMI wynosi " + QString::number(BMI) + ". Jest to stan bardzo powazny, sugerujemy skontaktowanie sie z lekarzem.";
        }
        else if (BMI >= 16.0 && BMI < 17.0) {
            message = "Stan: Wychudzenie. Twoje BMI wynosi " + QString::number(BMI) + ". Jest to stan niezdrowy, zalecamy zwiekszenie masy ciala.";
        }
        else if (BMI >= 17.0 && BMI < 18.5) {
            message = "Stan: Niedowaga. Twoje BMI wynosi " + QString::number(BMI) + ". Zalecamy zwiekszenie masy ciala, aby poprawic swoj stan zdrowia.";
        }
        else if (BMI >= 18.5 && BMI < 25.0) {
            message = "Stan: Prawidlowa masa ciala. Twoje BMI wynosi " + QString::number(BMI) + ". Gratulacje, utrzymujesz prawidlowa mase ciala!";
        }
        else if (BMI >= 25.0 && BMI < 30.0) {
            message = "Stan: Nadwaga. Twoje BMI wynosi " + QString::number(BMI) + ". Zalecamy zmniejszenie masy ciala, aby zapobiec ewentualnym problemom zdrowotnym.";
        }
        else if (BMI >= 30.0 && BMI < 35.0) {
            message = "Stan: Otylosc I stopnia. Twoje BMI wynosi " + QString::number(BMI) + ". Jest to stan zdrowotny wymagajacy interwencji, sugerujemy skonsultowanie sie z lekarzem.";
        }
        else if (BMI >= 35.0 && BMI < 40.0) {
            message = "Stan: Otylosc II stopnia. Twoje BMI wynosi " + QString::number(BMI) + ". Jest to stan powazny, sugerujemy skonsultowanie sie z lekarzem.";
        }
        else {
            message = "Stan: Otylosc III stopnia (ekstremalna). Twoje BMI wynosi " + QString::number(BMI) + ". Jest to stan bardzo powazny, wymagajacy natychmiastowej pomocy medycznej.";
        }

        if(BMI >= 18.5 && BMI < 25.0){
            QMessageBox::information(this, "Wynik BMI", message);
        }
        else{
            QMessageBox::warning(this, "Wynik BMI", message);
        }

        ui->Tak_BMI->setEnabled(false); //Blokowanie wybranej radioButton
        ui->Nie_BMI->setEnabled(false);

        ui->line_4->setVisible(true);
        ui->Kalkulator_BMR->setVisible(true);
        ui->BMR_oblicz->setVisible(true);

        qDebug() << BMI;

        ui->progressBar->setValue(34);

}

void MainWindow::on_Nie_BMI_clicked()
{
    QMessageBox::critical(this, "Wynik BMI", "Jak chcesz :)");

    ui->Tak_BMI->setEnabled(false); //Blokowanie wybranej radioButton
    ui->Nie_BMI->setEnabled(false);

    ui->Kalkulator_BMR->setVisible(true);
    ui->BMR_oblicz->setVisible(true);
    ui->line_4->setVisible(true);

    ui->progressBar->setValue(34);
}

//Obliczenie BMR
void MainWindow::on_BMR_oblicz_clicked()
{
    if(mezczyzna){
        BMR = 10 * waga + 6.25 * wzrost - 5 * wiek + 5;
    }

    if(kobieta){
        BMR = 10 * waga + 6.25 * wzrost - 5 * wiek - 161;
    }

    ui->Kalkulator_BMR_1->setVisible(true);

    ui->Wynik_BMR->setText(QString::number(BMR));
    ui->Wynik_BMR->setVisible(true);
    ui->line_6->setVisible(true);

    ui->Nastepna_strona->setVisible(true);
    ui->Przejdz->setVisible(true);
    ui->line_8->setVisible(true);

    ui->BMR_oblicz->setEnabled(false);

    ui->progressBar->setValue(45);

    qDebug() << BMR;
}

//Następna strona
void MainWindow::on_Przejdz_clicked()
{
    ui->Porady_dietyczne->setVisible(true);
    ui->porady_box->setVisible(true);

    ui->Strona->setCurrentIndex(1); //StackWidget :)

    ui->progressBar->setValue(50);
}

//2 Strona


//Cel
void MainWindow::on_utrata_wagi_clicked()
{
    ui->utrata_wagi->setEnabled(false);
    ui->nabor_masy->setEnabled(false);
    ui->utrzymanie_wagi->setEnabled(false);

    schudnac = true;
    nabor_masy = false;
    utrzymanie = false;

    ui->porady_oblicz->setVisible(true);

    ui->progressBar->setValue(55);
}

void MainWindow::on_nabor_masy_clicked()
{
    ui->utrata_wagi->setEnabled(false);
    ui->nabor_masy->setEnabled(false);
    ui->utrzymanie_wagi->setEnabled(false);

    schudnac = false;
    nabor_masy = true;
    utrzymanie = false;

    ui->porady_oblicz->setVisible(true);

    ui->progressBar->setValue(55);
}

void MainWindow::on_utrzymanie_wagi_clicked()
{
    ui->utrata_wagi->setEnabled(false);
    ui->nabor_masy->setEnabled(false);
    ui->utrzymanie_wagi->setEnabled(false);

    schudnac = false;
    nabor_masy = false;
    utrzymanie = true;

    ui->porady_oblicz->setVisible(true);

    ui->progressBar->setValue(55);
}

//Obliczenie TDEE
//Całkowite dzienne zapotrzebowanie energetyczne.
//Jest to suma wszystkich kalorii, które organizm spala w ciągu dnia
void MainWindow::on_porady_oblicz_clicked()
{
    TDEE = BMR * aktywnosc; //Obliczenie TDEE, mnożąc BMR przez współczynnik aktywności fizycznej

    ui->TDEE->setVisible(true);
    ui->TDEE_wynik->setText(QString::number(TDEE));
    ui->TDEE_wynik->setVisible(true);

    ui->Porady_dla_Ciebie->setVisible(true);
    ui->porady_dla_Ciebie->setVisible(true);
    ui->line_15->setVisible(true);

    ui->porady_oblicz->setEnabled(false);

    ui->progressBar->setValue(63);

    qDebug() << TDEE;

}

//Obliczenie makroskładników
void MainWindow::on_porady_dla_Ciebie_clicked()
{
    if(schudnac){
        nowy_cel_kaloryczny = TDEE - 500; //Nowy cel kaloryczny: TDEE - 500 kalorii

        //Makroskładniki: 20% białka, 30% tłuszczów, 50% węglowodanów.

        bialko = (nowy_cel_kaloryczny * 0.20) / 4;
        tluszcze = (nowy_cel_kaloryczny * 0.30) / 9;      //Wszystko w gramach
        weglowodany = (nowy_cel_kaloryczny * 0.50) / 4;
    }

    if(nabor_masy){
        nowy_cel_kaloryczny = TDEE + 500; //Nowy cel kaloryczny: TDEE + 500 kalorii

        //Makroskładniki: 30% białka, 35% tłuszczów, 35% węglowodanów.

        bialko = (nowy_cel_kaloryczny * 0.30) / 4;
        tluszcze = (nowy_cel_kaloryczny * 0.35) / 9;      //Wszystko w gramach
        weglowodany = (nowy_cel_kaloryczny * 0.35) / 4;
    }

    if(utrzymanie){
        nowy_cel_kaloryczny = TDEE; //Cel kaloryczny to TDEE

        //Makroskładniki: 20% białka, 30% tłuszczów, 50% węglowodanów.

        bialko = (nowy_cel_kaloryczny * 0.20) / 4;
        tluszcze = (nowy_cel_kaloryczny * 0.30) / 9;      //Wszystko w gramach
        weglowodany = (nowy_cel_kaloryczny * 0.50) / 4;
    }

    ui->porady_list->setVisible(true);

    //Konwersja liczb na tekst
    QString cel_kaloryczny = QString::number(nowy_cel_kaloryczny);
    QString protein = QString::number(bialko);
    QString fats = QString::number(tluszcze);
    QString carbs = QString::number(weglowodany);

    //Dodawanie danych do listWidget
    ui->porady_list->addItem("Cel kaloryczny: " + cel_kaloryczny + " kalorii.");
    ui->porady_list->addItem("Bialko: " + protein + " gr.");
    ui->porady_list->addItem("Tluszcze: " + fats + " gr.");
    ui->porady_list->addItem("Weglowodany: " + carbs + " gr.");

    ui->porady_dla_Ciebie->setEnabled(false); //blokowanie przycisku

    ui->line_11->setVisible(true);
    ui->miesien->setVisible(true);
    ui->miesien_box->setVisible(true);
    ui->miesien_box->setCurrentIndex(-1); //Aby początkowy wybór nie był widoczny

    ui->progressBar->setValue(78);


}

//Wybór mięśni
void MainWindow::on_miesien_box_currentIndexChanged(int index)
{
    if(index != -1){

        ui->miesien_list->setVisible(true);
        ui->miesien_list->clear();
        ui->line_14->setVisible(true);

        miesien = index; //Póżniej będzie potrzebno
    }

    switch(index){
    case 0:
        ui->miesien_list->addItem("Bench Press");
        ui->miesien_list->addItem("Incline Bench Press");
        ui->miesien_list->addItem("Cable Crossover");
        ui->miesien_list->addItem("Butterfly");
        ui->miesien_list->addItem("Dips for Chest");
        break;
    case 1:
        ui->miesien_list->addItem("Overhead Press");
        ui->miesien_list->addItem("Dumbbell Shoulder Press");
        ui->miesien_list->addItem("Lateral Raises");
        ui->miesien_list->addItem("Front Raises");
        ui->miesien_list->addItem("Bent Over Reverse Fly");
        break;
    case 2:
        ui->miesien_list->addItem("Squats");
        ui->miesien_list->addItem("Lunges");
        ui->miesien_list->addItem("Deadlift");
        ui->miesien_list->addItem("Leg Press");
        ui->miesien_list->addItem("Leg Curls");
        break;
    case 3:
        ui->miesien_list->addItem("Tricep Dips");
        ui->miesien_list->addItem("Overhead Tricep Extension");
        ui->miesien_list->addItem("Close Grip Bench Press");
        ui->miesien_list->addItem("Diamond Push-ups");
        ui->miesien_list->addItem("Triceps Pushdown");
        break;
    case 4:
        ui->miesien_list->addItem("Pull-ups");
        ui->miesien_list->addItem("Lat Pulldown");
        ui->miesien_list->addItem("Barbell Rows");
        ui->miesien_list->addItem("Seated Cable Rows");
        ui->miesien_list->addItem("Back Extensions");
        break;
    case 5:
        ui->miesien_list->addItem("Barbell Curls");
        ui->miesien_list->addItem("Hammer Curls");
        ui->miesien_list->addItem("Incline Dumbbell Curls");
        ui->miesien_list->addItem("Preacher Curls");
        ui->miesien_list->addItem("Cable Curls");
        break;
    case 6:

        ui->line_16->setVisible(true);
        ui->line_17->setVisible(true);
        ui->line_20->setVisible(true);
        ui->Czy_chcesz->setVisible(true);
        ui->Powrot->setVisible(true);
        ui->Tak_zapisz->setVisible(true);
        ui->Nie_zapisz->setVisible(true);

        ui->Strona->setCurrentIndex(2); //Następna strona
        break;

    }

        ui->miesien_zdjecia->setVisible(true);

        if(!ostatnia_akcja){
            ui->progressBar->setValue(87);
        }

}


//Zdjęcia ćwiczeń na wybraną mięsień
void MainWindow::on_miesien_list_currentRowChanged(int currentRow)
{
    ui->line_13->setVisible(true);

    int w = ui->miesien_zdjecia->width();
    int h = ui->miesien_zdjecia->height();

    //Zdjęcia ćwiczeń na Klatkę
    QPixmap klatka0("./klatka0.jpg");
    QPixmap klatka1("./klatka1.jpg");
    QPixmap klatka2("./klatka2.jpg");
    QPixmap klatka3("./klatka3.jpg");
    QPixmap klatka4("./klatka4.jpg");

    //Zdjęcia ćwiczeń na Barki
    QPixmap barki0("./barki0.png");
    QPixmap barki1("./barki1.png");
    QPixmap barki2("./barki2.jpg");
    QPixmap barki3("./barki3.jpg");
    QPixmap barki4("./barki4.jpg");

    //Zdjęcia ćwiczeń na Nogi
    QPixmap nogi0("./nogi0.jpg");
    QPixmap nogi1("./nogi1.jpg");
    QPixmap nogi2("./nogi2.png");
    QPixmap nogi3("./nogi3.jpg");
    QPixmap nogi4("./nogi4.png");

    //Zdjęcia ćwiczeń na Triceps
    QPixmap triceps0("./triceps0.jpg");
    QPixmap triceps1("./triceps1.jpg");
    QPixmap triceps2("./triceps2.png");
    QPixmap triceps3("./triceps3.jpg");
    QPixmap triceps4("./triceps4.png");

    //Zdjęcia ćwiczeń na Plecy
    QPixmap plecy0("./plecy0.jpg");
    QPixmap plecy1("./plecy1.jpg");
    QPixmap plecy2("./plecy2.jpg");
    QPixmap plecy3("./plecy3.jpg");
    QPixmap plecy4("./plecy4.jpg");

    //Zdjęcia ćwiczeń na Biceps
    QPixmap biceps0("./biceps0.jpg");
    QPixmap biceps1("./biceps1.jpg");
    QPixmap biceps2("./biceps2.jpg");
    QPixmap biceps3("./biceps3.jpg");
    QPixmap biceps4("./biceps4.jpg");

    if(miesien == 0){ //Klatka
        switch(currentRow){
        case 0:
            ui->miesien_zdjecia->setPixmap(klatka0.scaled(w,h,Qt::KeepAspectRatio)); //Ustawienie zdjęcia
            break;
        case 1:
            ui->miesien_zdjecia->setPixmap(klatka1.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 2:
            ui->miesien_zdjecia->setPixmap(klatka2.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 3:
            ui->miesien_zdjecia->setPixmap(klatka3.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 4:
            ui->miesien_zdjecia->setPixmap(klatka4.scaled(w,h,Qt::KeepAspectRatio));
            break;
        }
    }
    else if(miesien == 1){ //Barki
        switch(currentRow){
        case 0:
            ui->miesien_zdjecia->setPixmap(barki0.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 1:
            ui->miesien_zdjecia->setPixmap(barki1.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 2:
            ui->miesien_zdjecia->setPixmap(barki2.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 3:
            ui->miesien_zdjecia->setPixmap(barki3.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 4:
            ui->miesien_zdjecia->setPixmap(barki4.scaled(w,h,Qt::KeepAspectRatio));
            break;
        }
    }
    else if(miesien == 2){ //Nogi
        switch(currentRow){
        case 0:
            ui->miesien_zdjecia->setPixmap(nogi0.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 1:
            ui->miesien_zdjecia->setPixmap(nogi1.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 2:
            ui->miesien_zdjecia->setPixmap(nogi2.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 3:
            ui->miesien_zdjecia->setPixmap(nogi3.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 4:
            ui->miesien_zdjecia->setPixmap(nogi4.scaled(w,h,Qt::KeepAspectRatio));
            break;
        }
    }
    else if(miesien == 3){ //Triceps
        switch(currentRow){
        case 0:
            ui->miesien_zdjecia->setPixmap(triceps0.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 1:
            ui->miesien_zdjecia->setPixmap(triceps1.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 2:
            ui->miesien_zdjecia->setPixmap(triceps2.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 3:
            ui->miesien_zdjecia->setPixmap(triceps3.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 4:
            ui->miesien_zdjecia->setPixmap(triceps4.scaled(w,h,Qt::KeepAspectRatio));
            break;
        }
    }
    else if(miesien == 4){ //Plecy
        switch(currentRow){
        case 0:
            ui->miesien_zdjecia->setPixmap(plecy0.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 1:
            ui->miesien_zdjecia->setPixmap(plecy1.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 2:
            ui->miesien_zdjecia->setPixmap(plecy2.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 3:
            ui->miesien_zdjecia->setPixmap(plecy3.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 4:
            ui->miesien_zdjecia->setPixmap(plecy4.scaled(w,h,Qt::KeepAspectRatio));
            break;
        }
    }
    else if(miesien == 5){ //Biceps
        switch(currentRow){
        case 0:
            ui->miesien_zdjecia->setPixmap(biceps0.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 1:
            ui->miesien_zdjecia->setPixmap(biceps1.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 2:
            ui->miesien_zdjecia->setPixmap(biceps2.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 3:
            ui->miesien_zdjecia->setPixmap(biceps3.scaled(w,h,Qt::KeepAspectRatio));
            break;
        case 4:
            ui->miesien_zdjecia->setPixmap(biceps4.scaled(w,h,Qt::KeepAspectRatio));
            break;
        }
    }
}

//3 Strona

//Poprzednia strona
void MainWindow::on_Powrot_clicked()
{
    ui->miesien_box->setCurrentIndex(-1); //Aby początkowy wybór nie był widoczny
    ui->Strona->setCurrentIndex(1);
    ui->miesien_zdjecia->clear();

    if(ostatnia_akcja){
        ui->progressBar->setValue(100);
    }
}

//Zapisanie do notatnika oraz przejście do końca
void MainWindow::on_Tak_zapisz_clicked()
{
    QString BMI_text = QString::number(BMI);
    QString BMR_text = QString::number(BMR);
    QString TDEE_text = QString::number(TDEE);

    QString cel_kaloryczny = QString::number(nowy_cel_kaloryczny);
    QString protein = QString::number(bialko);
    QString fats = QString::number(tluszcze);
    QString carbs = QString::number(weglowodany);

    ui->Notatki->append(imie + " " + nazwisko + ", wyniki: ");

    ui->Notatki->append("Twoj BMI: " + BMI_text + ".");
    ui->Notatki->append("Twoj BMR: " + BMR_text + ".");
    ui->Notatki->append("Twoj TDEE:  " + TDEE_text + ".");

    ui->Notatki->append("Cel kaloryczny: " + cel_kaloryczny + " kalorii.");
    ui->Notatki->append("Bialko: " + protein + " gr.");
    ui->Notatki->append("Tluszcze: " + fats + " gr.");
    ui->Notatki->append("Weglowodany: " + carbs + " gr.");

    ui->Tak_zapisz->setEnabled(false);
    ui->Nie_zapisz->setEnabled(false);

    ui->line_20->setVisible(true);
    ui->line_21->setVisible(true);
    ui->line_18->setVisible(true);
    ui->Dziekuje->setVisible(true);
    ui->strzalka_1->setVisible(true);
    ui->strzalka_2->setVisible(true);
    ui->strzalka_3->setVisible(true);
    ui->strzalka_4->setVisible(true);
    ui->exit->setVisible(true);

    ui->Autor->setVisible(true);
    ostatnia_akcja = true;

    ui->progressBar->setValue(100);

}

//Przejście do końca
void MainWindow::on_Nie_zapisz_clicked()
{
    ui->Tak_zapisz->setEnabled(false);
    ui->Nie_zapisz->setEnabled(false);

    ui->line_20->setVisible(true);
    ui->line_21->setVisible(true);
    ui->line_18->setVisible(true);
    ui->Dziekuje->setVisible(true);
    ui->strzalka_1->setVisible(true);
    ui->strzalka_2->setVisible(true);
    ui->strzalka_3->setVisible(true);
    ui->strzalka_4->setVisible(true);
    ui->exit->setVisible(true);

    ui->Autor->setVisible(true);
    ostatnia_akcja = true;

    ui->progressBar->setValue(100);
}

//Wyjście z programu :)
void MainWindow::on_exit_clicked()
{
    this->close();
}
